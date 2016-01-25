// HJICCtl.cpp : Implementation of the CHJICCtrl ActiveX Control class.

#include "stdafx.h"
#include "HJIC.h"
#include "HJICCtl.h"
#include "HJICPpg.h"
#include "Mwic_32.h"
#include "LdIcCard.h"


#include "XIAN_RQ_SharedLib120407.h"
 
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


IMPLEMENT_DYNCREATE(CHJICCtrl, COleControl)


/////////////////////////////////////////////////////////////////////////////
// Message map

BEGIN_MESSAGE_MAP(CHJICCtrl, COleControl)
	//{{AFX_MSG_MAP(CHJICCtrl)
	// NOTE - ClassWizard will add and remove message map entries
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG_MAP
	ON_OLEVERB(AFX_IDS_VERB_PROPERTIES, OnProperties)
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// Dispatch map

BEGIN_DISPATCH_MAP(CHJICCtrl, COleControl)
	//{{AFX_DISPATCH_MAP(CHJICCtrl)
	DISP_FUNCTION(CHJICCtrl, "LoadConfigFile", LoadConfigFile, VT_EMPTY, VTS_NONE)
	DISP_FUNCTION(CHJICCtrl, "LoadLibraries", LoadLibraries, VT_EMPTY, VTS_NONE)
	DISP_FUNCTION(CHJICCtrl, "LoadFunctionPointers", LoadFunctionPointers, VT_EMPTY, VTS_NONE)
	DISP_FUNCTION(CHJICCtrl, "AoteReadCard", AoteReadCard, VT_I4, VTS_NONE)
	DISP_FUNCTION(CHJICCtrl, "AoteSellGas", AoteSellGas, VT_I4, VTS_BSTR VTS_BSTR VTS_R8 VTS_R8 VTS_R8 VTS_I4 VTS_R8 VTS_BSTR VTS_R8)
	DISP_FUNCTION(CHJICCtrl, "AoteRollBackGas", AoteRollBackGas, VT_I4, VTS_BSTR VTS_BSTR VTS_R8 VTS_R8 VTS_R8 VTS_I4 VTS_R8 VTS_BSTR VTS_R8)
	DISP_FUNCTION(CHJICCtrl, "AoteReNewCard", AoteReNewCard, VT_I4, VTS_BSTR VTS_BSTR VTS_R8 VTS_R8 VTS_R8 VTS_I4 VTS_R8 VTS_BSTR VTS_R8)
	DISP_FUNCTION(CHJICCtrl, "AoteFormatCard", AoteFormatCard, VT_I4, VTS_BSTR)
	DISP_FUNCTION(CHJICCtrl, "GetCardId", GetCardId, VT_BSTR, VTS_NONE)
	DISP_FUNCTION(CHJICCtrl, "GetFactory", GetFactory, VT_BSTR, VTS_NONE)
	DISP_FUNCTION(CHJICCtrl, "GetGas", GetGas, VT_I4, VTS_NONE)
	DISP_FUNCTION(CHJICCtrl, "GetTimes", GetTimes, VT_I4, VTS_NONE)
	DISP_FUNCTION(CHJICCtrl, "Init", Init, VT_I4, VTS_BSTR VTS_BSTR VTS_I4 VTS_I4 VTS_I4)
	//}}AFX_DISPATCH_MAP
	DISP_FUNCTION_ID(CHJICCtrl, "AboutBox", DISPID_ABOUTBOX, AboutBox, VT_EMPTY, VTS_NONE)
END_DISPATCH_MAP()


/////////////////////////////////////////////////////////////////////////////
// Event map

BEGIN_EVENT_MAP(CHJICCtrl, COleControl)
	//{{AFX_EVENT_MAP(CHJICCtrl)
	// NOTE - ClassWizard will add and remove event map entries
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_EVENT_MAP
END_EVENT_MAP()


/////////////////////////////////////////////////////////////////////////////
// Property pages

// TODO: Add more property pages as needed.  Remember to increase the count!
BEGIN_PROPPAGEIDS(CHJICCtrl, 1)
	PROPPAGEID(CHJICPropPage::guid)
END_PROPPAGEIDS(CHJICCtrl)


/////////////////////////////////////////////////////////////////////////////
// Initialize class factory and guid

IMPLEMENT_OLECREATE_EX(CHJICCtrl, "HJIC.HJICCtrl.1",
	0x1315ab82, 0x6541, 0x4bc2, 0x80, 0xc1, 0xdd, 0x29, 0x29, 0x50, 0x9f, 0x20)


/////////////////////////////////////////////////////////////////////////////
// Type library ID and version

IMPLEMENT_OLETYPELIB(CHJICCtrl, _tlid, _wVerMajor, _wVerMinor)


/////////////////////////////////////////////////////////////////////////////
// Interface IDs

const IID BASED_CODE IID_DHJIC =
		{ 0xa629521d, 0x24af, 0x405f, { 0x8b, 0xfb, 0x5a, 0xf4, 0xc9, 0x2d, 0x25, 0x55 } };
const IID BASED_CODE IID_DHJICEvents =
		{ 0x379bda5d, 0xe530, 0x48cc, { 0x89, 0x7d, 0x33, 0x34, 0xb8, 0x91, 0x42, 0xb6 } };


/////////////////////////////////////////////////////////////////////////////
// Control type information

static const DWORD BASED_CODE _dwHJICOleMisc =
	OLEMISC_ACTIVATEWHENVISIBLE |
	OLEMISC_SETCLIENTSITEFIRST |
	OLEMISC_INSIDEOUT |
	OLEMISC_CANTLINKINSIDE |
	OLEMISC_RECOMPOSEONRESIZE;

IMPLEMENT_OLECTLTYPE(CHJICCtrl, IDS_HJIC, _dwHJICOleMisc)


/////////////////////////////////////////////////////////////////////////////
// CHJICCtrl::CHJICCtrlFactory::UpdateRegistry -
// Adds or removes system registry entries for CHJICCtrl

BOOL CHJICCtrl::CHJICCtrlFactory::UpdateRegistry(BOOL bRegister)
{
	// TODO: Verify that your control follows apartment-model threading rules.
	// Refer to MFC TechNote 64 for more information.
	// If your control does not conform to the apartment-model rules, then
	// you must modify the code below, changing the 6th parameter from
	// afxRegApartmentThreading to 0.

	if (bRegister)
		return AfxOleRegisterControlClass(
			AfxGetInstanceHandle(),
			m_clsid,
			m_lpszProgID,
			IDS_HJIC,
			IDB_HJIC,
			afxRegApartmentThreading,
			_dwHJICOleMisc,
			_tlid,
			_wVerMajor,
			_wVerMinor);
	else
		return AfxOleUnregisterClass(m_clsid, m_lpszProgID);
}


/////////////////////////////////////////////////////////////////////////////
// CHJICCtrl::CHJICCtrl - Constructor

CHJICCtrl::CHJICCtrl()
{
	InitializeIIDs(&IID_DHJIC, &IID_DHJICEvents);
    //加载配置文件
	LoadConfigFile();
	//加载动态库
	LoadLibraries();
	//加载函数
    LoadFunctionPointers();
}


/////////////////////////////////////////////////////////////////////////////
// CHJICCtrl::~CHJICCtrl - Destructor

CHJICCtrl::~CHJICCtrl()
{
   
}


/////////////////////////////////////////////////////////////////////////////
// CHJICCtrl::OnDraw - Drawing function

void CHJICCtrl::OnDraw(
			CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid)
{
	// TODO: Replace the following code with your own drawing code.
	pdc->FillRect(rcBounds, CBrush::FromHandle((HBRUSH)GetStockObject(WHITE_BRUSH)));
	pdc->Ellipse(rcBounds);
}


/////////////////////////////////////////////////////////////////////////////
// CHJICCtrl::DoPropExchange - Persistence support

void CHJICCtrl::DoPropExchange(CPropExchange* pPX)
{
	ExchangeVersion(pPX, MAKELONG(_wVerMinor, _wVerMajor));
	COleControl::DoPropExchange(pPX);

	// TODO: Call PX_ functions for each persistent custom property.

}


/////////////////////////////////////////////////////////////////////////////
// CHJICCtrl::OnResetState - Reset control to default state

void CHJICCtrl::OnResetState()
{
	COleControl::OnResetState();  // Resets defaults found in DoPropExchange

	// TODO: Reset any other control state here.
}


/////////////////////////////////////////////////////////////////////////////
// CHJICCtrl::AboutBox - Display an "About" box to the user

void CHJICCtrl::AboutBox()
{
	CDialog dlgAbout(IDD_ABOUTBOX_HJIC);
	dlgAbout.DoModal();
}


/////////////////////////////////////////////////////////////////////////////
// CHJICCtrl message handlers

void CHJICCtrl::LoadConfigFile() 
{
	FILE * fp = fopen("c:\\gas.ini", "r");
	// 没有文件，采用默认值
	if( fp == NULL)
	{
		CommPort = 0;
		BaudRate = 9600;
		::MessageBox(NULL, "c盘没有配置文件gas.ini,采用默认串口1,波特率9600", "错误", MB_OK);
	 	return;
	}
	fscanf(fp, "%d %d %d", &CommPort, &BaudRate);
	fclose(fp);
}


//加载dll
void CHJICCtrl::LoadLibraries() 
{
	

}

//加载函数
void CHJICCtrl::LoadFunctionPointers() 
{

}


//读卡
long CHJICCtrl::AoteReadCard() 
{

   	//莱德读卡
	if(IsMineEx(CommPort,BaudRate) == 0)
	{
	   	long money;
		long price;
		int ren = ReadCardEx(CommPort, BaudRate, (char *)CardNo, &Gas,&Times,&money ,&price );
		if(ren == 0)
		{
			Gas = Gas/10;
			strcpy(Factory,"LaiDe");
			return ren;
		}
		else
		{
			return -1;	
		}
	}

	//天顺
	char isTrue[1];
	HANDLE m_fd = ic_init(CommPort, 9600);
	if (m_fd < 0)
	{
		return -1;
	}
	int ret  = rdcompany((int)m_fd,isTrue ,2);
	//读卡成功
	if(ret == 0)
	{
		//确认天顺卡
		if (isTrue[0] == '0')
		{
			strcpy(Factory, "TianShun");	
         	char customeNo[30];
			char orderdate[30];
			char fgs[30];
			char glz[30];
			char type[30];
			double tempgas;
			double temptotalgas;
			unsigned __int64 temptimes;
			ret = readCard((int)m_fd, CardNo ,customeNo ,orderdate,&tempgas, &temptimes , &temptotalgas, fgs, glz,type,9);

			Gas =	(long)tempgas;
			Times = (long)temptimes;
			ic_exit(m_fd);
			return ret;

		}
		else
		{
			ic_exit(m_fd);
			return -1;
		}

	}

    ic_exit(m_fd);
	return -1;	

}


//售气函数
long CHJICCtrl::AoteSellGas(LPCTSTR factory, LPCTSTR cardno, double gas, double money, double curprice, long times, double newprice, LPCTSTR datetime, double coemption) 
{	
	//天顺售气

	if (strcmp(factory, "TianShun") == 0)
	{
       	char customeNo[30];
		char orderdate[30];
		double temptotalgas;
		char keycode[30];
		//打开串口
		HANDLE m_fd = ic_init(CommPort, 9600);
		if (m_fd < 0)
		{
			return -1;
		}

	    int	ret = writeOrders((int)m_fd, (char *)cardno ,0 ,orderdate,times, (double)gas , temptotalgas, keycode);
		ic_exit(m_fd);

		return ret;	
	}
	else if(strcmp(factory,"LaiDe") == 0)
	{
		long gasl = (long)((gas * 10) + 0.5 );
     	long gasmoneyl= (long)((money * 100) +0.5);
        long pricel = (long)((newprice * 100) +0.5);
		//开户
		if(times == 1)
		{
		  int r = NewCardEx(CommPort,BaudRate);
		  return InitCardEx(CommPort,BaudRate,cardno,gasl,gasmoneyl,pricel,datetime);
		}
		//售气
		else
		{
	      return SellGasEx(CommPort,BaudRate,cardno,gasl,times,gasmoneyl,pricel,datetime);
		}
	}
	return -1;
}

 
//退气函数
long CHJICCtrl::AoteRollBackGas(LPCTSTR factory, LPCTSTR cardno, double gas, double money, double curprice, long time, double newprice, LPCTSTR datetime, double coemption) 
{


	//天顺售气

	if (strcmp(factory, "TianShun") == 0)
	{
       	char customeNo[30];
		char orderdate[30];
		double temptotalgas;
		char keycode[30];
		//打开串口
		HANDLE m_fd = ic_init(CommPort, 9600);
		if (m_fd < 0)
		{
			return -1;
		}

	    int	ret = writeOrders((int)m_fd, (char *)cardno ,0 ,orderdate,time, 0 , temptotalgas, keycode);
		ic_exit(m_fd);

		return ret;	
	}
		//莱德
	else if(strcmp(factory,"LaiDe") == 0)
	{
       	long gasl = (long)((gas * 10) + 0.5 );
     	long gasmoneyl= (long)((money * 100) +0.5);
        long pricel = (long)((newprice * 100) +0.5);
		return ReturnGasEx(CommPort, BaudRate,  cardno,  gasl,  time,   gasmoneyl ,pricel,datetime);
	}

	return -1;
}




//补卡
long CHJICCtrl::AoteReNewCard(LPCTSTR factory, LPCTSTR cardno, double gas, double money, double curprice, long times, double newprice, LPCTSTR datetime, double coemption) 
{

	if (strcmp(factory, "TianShun") == 0)
	{
       
		CString tempgas;
	    tempgas.Format("%f",gas);  
	
		CString temptimes;
	    temptimes.Format("%d",times);  

		//打开串口
		HANDLE m_fd = ic_init(CommPort, 9600);
		if (m_fd < 0)
		{
			return -1;
		}
	 
		int	ret = BuOrdersCard((int)m_fd, (char *)cardno ,  (char *)(LPCTSTR)tempgas , (char *)(LPCTSTR)temptimes);
		ic_exit(m_fd);

		return ret;	
	}
		//莱德补卡
  	else  if(strcmp(factory,"LaiDe") == 0)
	{
 	 	long gasl = (long)((gas * 10) + 0.5 );
     	long gasmoneyl= (long)((money * 100) +0.5);
        long pricel = (long)((newprice * 100) +0.5);
 		 
 		return RenewCardEx(CommPort, BaudRate,  cardno, gasl, times, gasmoneyl ,pricel,datetime );
 	}
	return -1;
}



 

//格式化卡
long CHJICCtrl::AoteFormatCard(LPCTSTR factory) 
{
	//天顺卡格式化
	if (strcmp(factory, "TianShun") == 0)
	{
		char keycode[30];
		//打开串口
		HANDLE m_fd = ic_init(CommPort, 9600);
		if (m_fd < 0)
		{
			return -1;
		}

	    int	ret = clearCard ((int)m_fd, keycode);
		ic_exit(m_fd);

		return ret;	
	}	
	 //莱德
	else if(strcmp(factory,"LaiDe") == 0)
	 {
	   return NewCardEx(CommPort,BaudRate);
	 }

	return -1;
}



//返回卡号
BSTR CHJICCtrl::GetCardId() 
{
	CString strResult;
    strResult = CardNo;
	return strResult.AllocSysString();
}

//返回厂家
BSTR CHJICCtrl::GetFactory() 
{	
	CString strResult;
	strResult = Factory;
	return strResult.AllocSysString();
}

//返回气量
long CHJICCtrl::GetGas() 
{
	return Gas;
}

//返回次数
long CHJICCtrl::GetTimes() 
{
	return Times;
}

//从卡上读厂家信息，厂家信息放入Factory中，返回的是卡的状态，如串口错误等
int CHJICCtrl::ReadFactory()
{
	HANDLE m_fd = ic_init(0, 9600);
	if (m_fd < 0)
	{
		return CommError;
	}
	//检测是否4442卡
	if (chk_4442(m_fd) == 0)
	{
		strcpy(Factory, "ChangLin");
		ic_exit(m_fd);
		return OK;
	}
	//24C04卡
	if(chk_24c04(m_fd) == 0)
	{
		strcpy(Factory, "YaPuIC");
		ic_exit(m_fd);
		return OK;
	}
	//系统无法检查的厂家
	strcpy(Factory, "Unknow");
	ic_exit(m_fd);
	return OK;
}

//把串口号转换成COM1等字符串
CString CHJICCtrl::PortToString(int port)
{
	CString s;
	s.Format("COM%d", port + 1);
	return s;
}

//发初始化卡
long CHJICCtrl::Init(LPCTSTR factory, LPCTSTR cardno, long gas, long times, long price) 
{

	if (strcmp(factory, "TianShun") == 0)
	{
       	char customeNo[30];
		char orderdate[30];
		double orderTotal;
		char fgs[30];
		char glz[30];
		char type[30];
		double tempgas;
		double temptotalgas;
		unsigned __int32 temptimes;
		char keycode[30];

		temptimes = times;

		//打开串口
		HANDLE m_fd = ic_init(CommPort, 9600);
		if (m_fd < 0)
		{
			return -1;
		}
		 int	ret1 = clearCard ((int)m_fd, keycode);

	    int	ret = makeCard((int)m_fd, (char *)cardno ,customeNo ,orderdate,times, (double)gas , temptotalgas, fgs, glz,keycode);
		ic_exit(m_fd);

		return ret;	
	}
	return 0;
}
