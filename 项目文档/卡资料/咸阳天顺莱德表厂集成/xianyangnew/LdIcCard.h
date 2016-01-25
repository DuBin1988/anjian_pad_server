// LdIcCard.h : main header file for the LDICCARD DLL
//

#if !defined(AFX_LDICCARD_H__B307BABB_C696_48CD_B4C3_881E111F4716__INCLUDED_)
#define AFX_LDICCARD_H__B307BABB_C696_48CD_B4C3_881E111F4716__INCLUDED_

// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the W32ICC_EXPORTS
// symbol defined on the command line. this symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// W32ICC_API functions as being imported from a DLL, wheras this DLL sees symbols
// defined with this macro as being exported.
#ifdef LDICCARD_EXPORTS
#define LDICCARD_API extern "C" __declspec(dllexport)
#else
#define LDICCARD_API extern "C" __declspec(dllimport)
#endif


/***********************************接口错误码定义**************************************************************/

enum 
{	
	  ERR_SUCC            =  0,  //操作成功,必须实现
		
		ERR_UNREG           = -1,  //不是注册用户(对于有需要注册才可以使用的动态库的厂商)
		
		ERR_COM             = -2,  //端口初始化失败,必须实现
		
		ERR_ICREADER        = -3,  //读设备状态失败,读卡器是否准备好
		
		ERR_NOCARD          = -4,  //无卡,必须实现
		
		ERR_PASSTIMES       = -5,  //密码错误计数超过阈值
		
		ERR_BADCARD         = -6,  //该卡已经损坏或者插反或者卡无效或者不识别
		
		ERR_READ            = -7,  //读卡错误
		
		ERR_NEWCARD         = -8,  //空白卡
		
		ERR_PASS            = -9,  //核对密码错误。
		
		ERR_NOTMINE          = -10,  //该卡不是本系统卡,即其它厂商的卡
		
		ERR_BAKGAS          = -11,  //备份气量不正确
		
		ERR_CLOSECOM        = -12,  //关闭通讯端口失败
		
		ERR_WRITE           = -13,  //写卡失败
		
		ERR_MAXBUY          = -14,  //气量超限
		
		ERR_CARDNUM         = -15,  //传入卡号与卡上不一致
		
		ERR_NOTBINDING      = -16,  //开户卡未插入表内实现绑定即进行购气
		
		ERR_NOTUSERCARD     = -17,  //不是开户卡或者购气卡，可能是厂商特殊功能卡
		
		ERR_NOTEXPECTEDCARD = -18,  //不是期望的指定卡类型
		
		ERR_CRCERROR        = -19,  //卡数据校验错误

		ERR_PARAMETER       = -20,  //传入参数错误,厂商扩展错误标示
		
		ERR_NOTBLANKCARD    = -21,  //不是空白卡
		
		ERR_NOTSUPPORT      = -100,  //非本厂商驱动支持的IC卡片
	
};



/// <summary>
/// IC卡开户,初始化卡
/// </summary>
/// <param name="commPort"></param>
/// <param name="baudRate"></param>
/// <param name="cardNo">卡号10位,否则报错</param>
/// <param name="gasAmount">单位0.1m3,跟金额不一样</param>
/// <param name="gasMoney">单位0.01元</param>
/// <param name="gasPrice">单位0.01元</param>
/// <param name="priceDate">单价生效日期，如2009-08-08</param>
/// <returns>0成功,其他失败</returns>
LDICCARD_API short _stdcall InitCardEx(int commPort, int baudRate, LPCTSTR cardNo, long gasAmount, long gasMoney ,long gasPrice, const char * priceDate );

/// <summary>
/// IC卡售气
/// </summary>
/// <param name="commPort"></param>
/// <param name="baudRate"></param>
/// <param name="cardNo">卡号10位,否则报错</param>
/// <param name="gasAmount">单位0.1m3,跟金额不一样</param>
/// <param name="gasMoney">单位0.01元</param>
/// <param name="gasPrice">单位0.01元</param>
/// <param name="priceDate">单价生效日期，如2009-08-08</param>
/// <returns>0成功,其他失败</returns>
LDICCARD_API short _stdcall SellGasEx(int commPort, int baudRate, LPCTSTR cardNo, long gasAmount, long totalCount, long gasMoney ,long gasPrice, const char * priceDate );

/// <summary>
/// IC卡补卡
/// </summary>
/// <param name="commPort"></param>
/// <param name="baudRate"></param>
/// <param name="cardNo">卡号10位,否则报错</param>
/// <param name="gasAmount">单位0.1m3,跟金额不一样</param>
/// <param name="gasMoney">单位0.01元</param>
/// <param name="gasPrice">单位0.01元</param>
/// <param name="priceDate">单价生效日期，如2009-08-08</param>
/// <returns>0成功,其他失败</returns>
LDICCARD_API short _stdcall RenewCardEx(int commPort, int baudRate, LPCTSTR cardNo, long gasAmount, long totalCount, long gasMoney ,long gasPrice,const char *  priceDate );

/// <summary>
/// IC卡退气，只支持完全退气,不支持部分退气
/// </summary>
/// <param name="commPort"></param>
/// <param name="baudRate"></param>
/// <param name="cardNo">卡号10位,否则报错</param>
/// <param name="gasAmount">单位0.1m3,跟金额不一样</param>
/// <param name="gasMoney">单位0.01元</param>
/// <param name="gasPrice">单位0.01元</param>
/// <param name="priceDate">单价生效日期，如2009-08-08</param>
/// <returns>0成功,其他失败</returns>
LDICCARD_API short _stdcall ReturnGasEx(int commPort, int baudRate, LPCTSTR cardNo, long gasAmount, long totalCount, long gasMoney ,long gasPrice,const char *  priceDate );


/// <summary>
/// IC卡读卡
/// </summary>
/// <param name="commPort"></param>
/// <param name="baudRate"></param>
/// <param name="cardID">卡号10位,调用者至少保证有11 char的缓冲区,否则溢出</param>
/// <param name="gasQuantity">单位0.1m3,跟金额不一样</param>
/// <param name="totalSellingCount">单位0.01元</param>
/// <param name="gasMoney">单位0.01元</param>
/// <param name="gasPrice">单位0.01元</param>
/// <returns>0成功,其他失败</returns>
LDICCARD_API short _stdcall ReadCardEx(int commPort, int baudRate, char* cardID, long* gasQuantity, long* totalSellingCount,long* gasMoney ,long* gasPrice );

/// <summary>
/// 是否本厂商的卡
/// </summary>
/// <param name="commPort"></param>
/// <param name="baudRate"></param>
/// <returns>0是,其他不是</returns>
LDICCARD_API short _stdcall IsMineEx(int commPort, int baudRate);

/// <summary>
/// 是否本厂商的卡,作用完全等同IsMineEx,纯粹为了兼容
/// </summary>
/// <param name="commPort"></param>
/// <param name="baudRate"></param>
/// <returns>0是,其他不是</returns>
//LDICCARD_API short _stdcall IsMine(int commPort, int baudRate);

/// <summary>
/// 制作清零卡
/// </summary>
/// <param name="commPort"></param>
/// <param name="baudRate"></param>
/// <returns>0成功,其他失败</returns>
LDICCARD_API short _stdcall ClearCardEx(int commPort, int baudRate);


/// <summary>
/// 制作清零卡，作用完全等同ClearCardEx,纯粹为了兼容
/// </summary>
/// <param name="commPort"></param>
/// <param name="baudRate"></param>
/// <returns>0成功,其他失败</returns>
//LDICCARD_API short _stdcall ClearCard(int commPort, int baudRate);

/// <summary>
/// 制作管理卡
/// </summary>
/// <param name="commPort"></param>
/// <param name="baudRate"></param>
/// <returns>0成功,其他失败</returns>
LDICCARD_API short _stdcall GLCardEx(int commPort, int baudRate);


/// <summary>
/// 制作管理卡，作用完全等同GLCardEx,纯粹为了兼容
/// </summary>
/// <param name="commPort"></param>
/// <param name="baudRate"></param>
/// <returns>0成功,其他失败</returns>
//LDICCARD_API short _stdcall GLCard(int commPort, int baudRate);

/// <summary>
/// 制作维修卡
/// </summary>
/// <param name="commPort"></param>
/// <param name="baudRate"></param>
/// <returns>0成功,其他失败</returns>
LDICCARD_API short _stdcall WXCardEx(int commPort, int baudRate);


/// <summary>
/// 制作维修卡，作用完全等同WXCardEx,纯粹为了兼容
/// </summary>
/// <param name="commPort"></param>
/// <param name="baudRate"></param>
/// <returns>0成功,其他失败</returns>
//LDICCARD_API short _stdcall WXCard(int commPort, int baudRate);



/// <summary>
/// 制作特殊卡
/// </summary>
/// <param name="commPort"></param>
/// <param name="baudRate"></param>
/// <returns>0成功,其他失败</returns>
LDICCARD_API short _stdcall SpCardEx(int commPort, int baudRate);


/// <summary>
/// 制作特殊卡，作用完全等同SpCardEx
/// </summary>
/// <param name="commPort"></param>
/// <param name="baudRate"></param>
/// <returns>0成功,其他失败</returns>
//LDICCARD_API short _stdcall SpCard(int commPort, int baudRate);


/// <summary>
/// 刷新卡
/// </summary>
/// <param name="commPort"></param>
/// <param name="baudRate"></param>
/// <returns>0成功,其他失败</returns>
LDICCARD_API short _stdcall NewCardEx(int commPort, int baudRate);

/// <summary>
/// 设置IC读卡器类型,0实达读卡器,1明华读卡器,其他德诚读卡器
/// </summary>
/// <param name="commPort"></param>
/// <returns></returns>
LDICCARD_API void _stdcall SetIcReader(int type );

/// <summary>
/// 读取当前IC读卡器类型,0实达读卡器,1明华读卡器,其他德诚读卡器
/// </summary>
/// <param name="commPort"></param>
/// <returns></returns>
LDICCARD_API int _stdcall GetIcReader( );



/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LDICCARD_H__B307BABB_C696_48CD_B4C3_881E111F4716__INCLUDED_)
