// JYZW.cpp : Defines the initialization routines for the DLL.
//

#include "stdafx.h"
#include "JYZW.h"
#include "Mwic_32.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

//
//	Note!
//
//		If this DLL is dynamically linked against the MFC
//		DLLs, any functions exported from this DLL which
//		call into MFC must have the AFX_MANAGE_STATE macro
//		added at the very beginning of the function.
//
//		For example:
//
//		extern "C" BOOL PASCAL EXPORT ExportedFunction()
//		{
//			AFX_MANAGE_STATE(AfxGetStaticModuleState());
//			// normal function body here
//		}
//
//		It is very important that this macro appear in each
//		function, prior to any calls into MFC.  This means that
//		it must appear as the first statement within the 
//		function, even before any object variable declarations
//		as their constructors may generate calls into the MFC
//		DLL.
//
//		Please see MFC Technical Notes 33 and 58 for additional
//		details.
//

/////////////////////////////////////////////////////////////////////////////
// CJYZWApp

BEGIN_MESSAGE_MAP(CJYZWApp, CWinApp)
	//{{AFX_MSG_MAP(CJYZWApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// base functions

void LongToBCD(long val, unsigned char *bcd, int len)
{
	int low, i;
	for(i = 0; i < len; i++)
	{
		if(i % 2 == 0)
			low = val % 10;
		else
			bcd[len/2-i/2-1] = (val % 10) * 16 + low;
		val = val / 10;
	}
}

long BCDToLong( unsigned char *BCD, int len)
{
	long  sum =0;
	int i;
	for(i=0; i<len;i++)
        {                  
		sum = sum*100;
		sum +=  ( (BCD[i]>>4)& 0x0f )* 10;
		sum += BCD[i]&0x0f;
	}

	return sum;
}

/////////////////////////////////////////////////////////////////////////////
// CJYZWApp construction

CJYZWApp::CJYZWApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

//厂家判断
extern "C" __declspec(dllexport) int __stdcall rdcompany(int icdev, char* isTrue, int len)
{
	turn_on((void*)icdev);
	//读卡内容，解密
	BYTE buffer[0xFF];
	if(srd_4442((void*)icdev, 0x32, 8, buffer) != 0)
	{
		turn_off((void*)icdev);
		return -1;
	};
	if(buffer[0] == 0x54 && buffer[1] == 0xB8 && buffer[2] == 0x96 && buffer[3] == 0x33 &&
		buffer[4] == 0x5B && buffer[5] == 0x87 && buffer[6] == 0x8F && buffer[7] == 0xEA)
	{
		isTrue[0] = '0';
	}
	else 
	{
		isTrue[0] = '1';
	}
	turn_off((void*)icdev);
 	return 0;
}


//读卡
extern "C" __declspec(dllexport) int __stdcall readCard(int icdev, char* cardNo, char* customeNo,
	char* orderdate, double* orderAmount, long* orders, double* orderTotal,
	char* fgs, char* glz, char* type, int len)
{
	turn_on((void*)icdev);

	BYTE buffer[0xFF];
	if(srd_4442((void*)icdev, 0x50, 0x10, buffer) != 0)
	{
		turn_off((void*)icdev);
		return -1;
	};
	
	//解密
	for(int i = 0; i < 0x10; i++)
	{
		buffer[i] = buffer[i] ^ (0x50 + i);
	}

	//取出卡号
	long cardno = BCDToLong(buffer, 4);
	//取出气量
	long gas = buffer[4] * 256 * 256 + buffer[6] * 256 + buffer[8];
	gas = gas / 100;
	//看回读位
	if(buffer[0x0f] == 0xAA)
	{
		gas = 0;
	}
	//取出购气次数
	int times = buffer[0x0A];

	//把相关参数返回
	sprintf(cardNo, "%d", cardno); //卡号
	*orderAmount = (double)gas;		//气量
	*orders = times;				//购气次数

	turn_off((void*)icdev);
	return 0;
}

//购气
extern "C" __declspec(dllexport) int __stdcall writeOrders(int icdev, char* cardNo, char* customeNo,
	char* orderdate, int orderNum, double orderAmount, double orderTotal,
	char* keyCode)
{
	int i;
	turn_on((void*)icdev);

	//读卡内容，解密
	BYTE buffer[0xFF];
	if(srd_4442((void*)icdev, 0x50, 0x20, buffer) != 0)
	{
		turn_off((void*)icdev);
		return -1;
	};
	
	//解密
	for(i = 0; i < 0x10; i++)
	{
		buffer[i] = buffer[i] ^ (0x50 + i);
	}
	
	//写气量
	long gas = (long)orderAmount * 100;
	buffer[0x8] = gas%256; 
	buffer[0x6] = gas/256%256;  
	buffer[0x4] = gas/256/256;

	//写购气次数
	buffer[0x0A] = buffer[0x0A] + 1;

	//写标志位
	buffer[0x0D] = 0xC3;
	buffer[0x0E] = 0xD4;
	buffer[0x0F] = 0xFF;

	//写校验和
	BYTE sum = 0;
	for(i = 0x0; i <= 0x10; i++)
	{
		sum += buffer[i];
	}
	buffer[0x11] = sum;
	
	//校验卡密码
	BYTE key[3];
	key[0] = buffer[5];
	key[1] = buffer[7];
	key[2] = buffer[9];
	if(csc_4442((void*)icdev, 3, key) != 0)
	{
		turn_off((void*)icdev);
		return -1;
	};

	//加密
	for(i = 0x0; i <= 0x11; i++)
	{
		buffer[i] = buffer[i] ^ (0x50 + i);
	}

	//写卡
	if(swr_4442((void*)icdev, 0x50, 0x12, buffer) != 0)
	{
		turn_off((void*)icdev);
		return -1;
	};

	turn_off((void*)icdev);
	return 0;
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CJYZWApp object

CJYZWApp theApp;

BOOL CJYZWApp::InitInstance() 
{
	return CWinApp::InitInstance();
}
