// Machine generated IDispatch wrapper class(es) created with ClassWizard

#include "stdafx.h"
#include "htdl.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// _HTDL properties

/////////////////////////////////////////////////////////////////////////////
// _HTDL operations
//这是一个测试函数
//返回值为空，如果能弹出动态库的提示框，就表示调用成功！
VARIANT _HTDL::VBTestFun()
{
	VARIANT result;
	InvokeHelper(0x60030000, DISPATCH_METHOD, VT_VARIANT, (void*)&result, NULL);
	return result;
}

/*
函数功能：读卡函数，
函数返回：是一个字符串:返回字符串分割：厂家(1)，卡号(14).本次日期(8),上次日期(8)，气表类型(1),卡状态(2),气量(...)>32+2+...
返回值说明：1，串口错误。	2，设备错误。3，卡型错误。
	4.核对密码错误。5，非本厂数据卡。6.参数范围错误。7.注册文件错误。-1操作错误
参数说明：port，端口号，也叫串口号，如果串口1，传入0即可;
	 baud:波特率，常用的是9600；
	Meter气表类型，1(一体表);2(分体表);3(工业表)
*/
CString _HTDL::ReadCard(short port, long baud, short Meter)
{
	CString result;
	static BYTE parms[] =
		VTS_I2 VTS_I4 VTS_I2;
	InvokeHelper(0x60030001, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms,
		port, baud, Meter);
	return result;
}

/*
函数功能：读IC卡的卡号
函数返回：是一个字符串:正常返回是一个14位的字符串，是卡号，如果非14位，请参考下面返回值说明
返回值说明：1，串口错误。	2，设备错误。3，卡型错误。
	4.核对密码错误。5，非本厂数据卡。6.参数范围错误。7.注册文件错误。-1操作错误
参数说明：port，端口号，也叫串口号，如果串口1，传入0即可;
	 baud:波特率，常用的是9600；
*/
CString _HTDL::ReadIC(short port, long baud)
{
	CString result;
	static BYTE parms[] =
		VTS_I2 VTS_I4;
	InvokeHelper(0x60030002, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms,
		port, baud);
	return result;
}

/*
函数功能：读卡上气量的函数
函数返回：是一个字符串:正常返回是字符串，
	前俩位如果是字母“kh”表示是开户卡，请插表之后再操作卡。
	如果是"gq"表示卡上有气量的充值卡，
	如果不是"kh"或者"gq",默认为卡上没有气量的卡。
返回值说明：1，串口错误。	2，设备错误。3，卡型错误。
	4.核对密码错误。5，非本厂数据卡。6.参数范围错误。7.注册文件错误。-1操作错误
参数说明：port，端口号，也叫串口号，如果串口1，传入0即可;
	 baud:波特率，常用的是9600；
	 Meter气表类型，1(一体表);2(分体表);3(工业表)
*/
CString _HTDL::ReadGasM(short port, long baud, short Meter)
{
	CString result;
	static BYTE parms[] =
		VTS_I2 VTS_I4 VTS_I2;
	InvokeHelper(0x60030003, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms,
		port, baud, Meter);
	return result;
}

/*
函数功能：读卡上气量的函数
函数返回：是一个字符串:正常返回是字符串，
	前俩位如果是字母“kh”表示是开户卡，请插表之后再操作卡。
	如果是"gq"表示卡上有气量的充值卡，
	如果不是"kh"或者"gq",默认为卡上没有气量的卡。
返回值说明：1，串口错误。	2，设备错误。3，卡型错误。
	4.核对密码错误。5，非本厂数据卡。6.参数范围错误。7.注册文件错误。-1操作错误
参数说明：port，端口号，也叫串口号，如果串口1，传入0即可;
	 baud:波特率，常用的是9600；
	 Meter气表类型，1(一体表);2(分体表);3(工业表)
备注说明：与函数ReadGasM的区别在于，不需要传入Meter参数，因为这个参数是从卡上直接获取，
	如果卡上没有此参数信息，就会读不出气量。为了兼容以前版本的动态库而写的过渡函数。
*/
CString _HTDL::ReadGas(short port, long baud)
{
	CString result;
	static BYTE parms[] =
		VTS_I2 VTS_I4;
	InvokeHelper(0x60030004, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms,
		port, baud);
	return result;
}
/*
函数功能：读报警限的函数
函数返回：是一个字符串:正常返回是字符串，
返回值说明：1，串口错误。	2，设备错误。3，卡型错误。
	4.核对密码错误。5，非本厂数据卡。6.参数范围错误。7.注册文件错误。-1操作错误
参数说明：port，端口号，也叫串口号，如果串口1，传入0即可;
	 baud:波特率，常用的是9600；
*/
CString _HTDL::ReadAlertM(short port, long baud, short Meter)
{
	CString result;
	static BYTE parms[] =
		VTS_I2 VTS_I4 VTS_I2;
	InvokeHelper(0x60030005, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms,
		port, baud, Meter);
	return result;
}

/*
函数功能：读报警限的函数
函数返回：是一个字符串:正常返回是字符串，
返回值说明：1，串口错误。	2，设备错误。3，卡型错误。
	4.核对密码错误。5，非本厂数据卡。6.参数范围错误。7.注册文件错误。-1操作错误
参数说明：port，端口号，也叫串口号，如果串口1，传入0即可;
	 baud:波特率，常用的是9600；
备注说明：与函数ReadGasM的区别在于，不需要传入Meter参数，因为这个参数是从卡上直接获取，
	如果卡上没有此参数信息，就会读不出气量。为了兼容以前版本的动态库而写的过渡函数。
*/
CString _HTDL::ReadAlert(short port, long baud)
{
	CString result;
	static BYTE parms[] =
		VTS_I2 VTS_I4;
	InvokeHelper(0x60030006, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms,
		port, baud);
	return result;
}

/*
函数功能：读气表类型函数
函数返回：是一个字符串:正常返回是字符串，
返回值说明：1，串口错误。	2，设备错误。3，卡型错误。
	4.核对密码错误。5，非本厂数据卡。6.参数范围错误。7.注册文件错误。-1操作错误
参数说明：port，端口号，也叫串口号，如果串口1，传入0即可;
	 baud:波特率，常用的是9600；
*/
CString _HTDL::ReadMeter(short port, long baud)
{
	CString result;
	static BYTE parms[] =
		VTS_I2 VTS_I4;
	InvokeHelper(0x60030007, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms,
		port, baud);
	return result;
}
/*
函数功能：读总购气量的函数
函数返回：是一个字符串:正常返回是字符串，
返回值说明：1，串口错误。	2，设备错误。3，卡型错误。
	4.核对密码错误。5，非本厂数据卡。6.参数范围错误。7.注册文件错误。-1操作错误
参数说明：port，端口号，也叫串口号，如果串口1，传入0即可;
	 baud:波特率，常用的是9600；
备注说明：与函数ReadAmountGasM的区别在于，不需要传入Meter参数，因为这个参数是从卡上直接获取，
	如果卡上没有此参数信息，就会读不出气量。为了兼容以前版本的动态库而写的过渡函数。
*/
CString _HTDL::ReadAmountGas(short port, long baud)
{
	CString result;
	static BYTE parms[] =
		VTS_I2 VTS_I4;
	InvokeHelper(0x60030008, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms,
		port, baud);
	return result;
}
/*
函数功能：读总购气量的函数
函数返回：是一个字符串:正常返回是字符串，
返回值说明：1，串口错误。	2，设备错误。3，卡型错误。
	4.核对密码错误。5，非本厂数据卡。6.参数范围错误。7.注册文件错误。-1操作错误
参数说明：port，端口号，也叫串口号，如果串口1，传入0即可;
	 baud:波特率，常用的是9600；
*/
CString _HTDL::ReadAmountGasM(short port, long baud, short Meter)
{
	CString result;
	static BYTE parms[] =
		VTS_I2 VTS_I4 VTS_I2;
	InvokeHelper(0x60030009, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms,
		port, baud, Meter);
	return result;
}
/*
函数功能：读购气次数的函数
函数返回：是一个字符串:正常返回是字符串，
返回值说明：1，串口错误。	2，设备错误。3，卡型错误。
	4.核对密码错误。5，非本厂数据卡。6.参数范围错误。7.注册文件错误。-1操作错误
参数说明：port，端口号，也叫串口号，如果串口1，传入0即可;
	 baud:波特率，常用的是9600；
*/
CString _HTDL::ReadAmountTimes(short port, long baud)
{
	CString result;
	static BYTE parms[] =
		VTS_I2 VTS_I4;
	InvokeHelper(0x6003000a, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms,
		port, baud);
	return result;
}
/*
函数功能：读上次购气日期
函数返回：是一个字符串:正常返回是字符串，
返回值说明：1，串口错误。	2，设备错误。3，卡型错误。
	4.核对密码错误。5，非本厂数据卡。6.参数范围错误。7.注册文件错误。-1操作错误
参数说明：port，端口号，也叫串口号，如果串口1，传入0即可;
	 baud:波特率，常用的是9600；
*/
CString _HTDL::ReadLastDate(short port, long baud)
{
	CString result;
	static BYTE parms[] =
		VTS_I2 VTS_I4;
	InvokeHelper(0x6003000b, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms,
		port, baud);
	return result;
}
/*
函数功能：读本次购气日期
函数返回：是一个字符串:正常返回是字符串，
返回值说明：1，串口错误。	2，设备错误。3，卡型错误。
	4.核对密码错误。5，非本厂数据卡。6.参数范围错误。7.注册文件错误。-1操作错误
参数说明：port，端口号，也叫串口号，如果串口1，传入0即可;
	 baud:波特率，常用的是9600；
*/
CString _HTDL::ReadThisDate(short port, long baud)
{
	CString result;
	static BYTE parms[] =
		VTS_I2 VTS_I4;
	InvokeHelper(0x6003000c, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms,
		port, baud);
	return result;
}
/*
函数功能：制开户卡函数
函数返回：返回值为0的话，表示执行成功
返回值说明：1，串口错误。	2，设备错误。3，卡型错误。
	4.核对密码错误。5，非本厂数据卡。6.参数范围错误。7.注册文件错误。-1操作错误
参数说明：port，端口号，也叫串口号，如果串口1，传入0即可;
	 baud:波特率，常用的是9600；
	 Meter气表类型，1(一体表);2(分体表);3(工业表)
	 Gas：充值气量
	 IC:IC卡号，必须是14位的字符串
	 Alert:一体表一般传入5，其他表型可以参考表的口径流量值。
*/
short _HTDL::NewCard(short port, long baud, short Meter, double Gas, LPCTSTR IC, double Alert)
{
	short result;
	static BYTE parms[] =
		VTS_I2 VTS_I4 VTS_I2 VTS_R8 VTS_BSTR VTS_R8;
	InvokeHelper(0x6003000d, DISPATCH_METHOD, VT_I2, (void*)&result, parms,
		port, baud, Meter, Gas, IC, Alert);
	return result;
}
/*
函数功能：写购气函数
函数返回：返回值为0的话，表示执行成功
返回值说明：1，串口错误。	2，设备错误。3，卡型错误。
	4.核对密码错误。5，非本厂数据卡。6.参数范围错误。7.注册文件错误。-1操作错误
参数说明：port，端口号，也叫串口号，如果串口1，传入0即可;
	 baud:波特率，常用的是9600；
	 Meter气表类型，1(一体表);2(分体表);3(工业表)
	 Gas：充值气量
	 IC:IC卡号，必须是14位的字符串
	 Alert:一体表一般传入5，其他表型可以参考表的口径流量值，例如如果是50口径的流量计，可以传入50.
	 GasType=1 购气模式；GasType=2 补气模式；GasType=3 退气
*/
short _HTDL::BuyGasM(short port, long baud, double Gas, short Meter, double Alert, double GasType)
{
	short result;
	static BYTE parms[] =
		VTS_I2 VTS_I4 VTS_R8 VTS_I2 VTS_R8 VTS_R8;
	InvokeHelper(0x6003000e, DISPATCH_METHOD, VT_I2, (void*)&result, parms,
		port, baud, Gas, Meter, Alert, GasType);
	return result;
}
/*
函数功能：写购气函数
函数返回：返回值为0的话，表示执行成功
返回值说明：1，串口错误。	2，设备错误。3，卡型错误。
	4.核对密码错误。5，非本厂数据卡。6.参数范围错误。7.注册文件错误。-1操作错误
参数说明：port，端口号，也叫串口号，如果串口1，传入0即可;
	 baud:波特率，常用的是9600；
	 Gas：充值气量
	 IC:IC卡号，必须是14位的字符串
	 Alert:一体表一般传入5，其他表型可以参考表的口径流量值，例如如果是50口径的流量计，可以传入50.
	 GasType=1 购气模式；GasType=2 补气模式；GasType=3 退气
*/
short _HTDL::BuyGas(short port, long baud, double Gas, double Alert, double GasType)
{
	short result;
	static BYTE parms[] =
		VTS_I2 VTS_I4 VTS_R8 VTS_R8 VTS_R8;
	InvokeHelper(0x6003000f, DISPATCH_METHOD, VT_I2, (void*)&result, parms,
		port, baud, Gas, Alert, GasType);
	return result;
}
/*
函数功能：补卡函数
函数返回：返回值为0的话，表示执行成功
返回值说明：1，串口错误。	2，设备错误。3，卡型错误。
	4.核对密码错误。5，非本厂数据卡。6.参数范围错误。7.注册文件错误。-1操作错误
参数说明：port，端口号，也叫串口号，如果串口1，传入0即可;
	 baud:波特率，常用的是9600；
	 Meter气表类型，1(一体表);2(分体表);3(工业表)
	 Gas：充值气量
	 IC:IC卡号，必须是14位的字符串
	 Alert:一体表一般传入5，其他表型可以参考表的口径流量值，例如如果是50口径的流量计，可以传入50.
	 CardStatus    1_开户卡；2_购气卡；3_用户卡；4_补开户卡；5_补购气卡；6_补用户卡；7_退户卡；
	LastDate：上次购气日期，例如2013-10-08就传入20131008
	AmountGas,总购气量
	AmountTimes,购气次数
*/
short _HTDL::CardInit(short port, long baud, short Meter, double Gas, LPCTSTR IC, double Alert, short CardStatus, LPCTSTR LastDate, double AmountGas, double AmountTimes)
{
	short result;
	static BYTE parms[] =
		VTS_I2 VTS_I4 VTS_I2 VTS_R8 VTS_BSTR VTS_R8 VTS_I2 VTS_BSTR VTS_R8 VTS_R8;
	InvokeHelper(0x60030010, DISPATCH_METHOD, VT_I2, (void*)&result, parms,
		port, baud, Meter, Gas, IC, Alert, CardStatus, LastDate, AmountGas, AmountTimes);
	return result;
}
/*
函数功能：擦除IC卡数据，将IC卡置为卡上数据清除，
函数返回：返回值为0的话，表示执行成功
返回值说明：1，串口错误。	2，设备错误。3，卡型错误。
	4.核对密码错误。5，非本厂数据卡。6.参数范围错误。7.注册文件错误。-1操作错误
参数说明：port，端口号，也叫串口号，如果串口1，传入0即可;
	 baud:波特率，常用的是9600； 
*/
short _HTDL::ClearCard(short port, long baud)
{
	short result;
	static BYTE parms[] =
		VTS_I2 VTS_I4;
	InvokeHelper(0x60030011, DISPATCH_METHOD, VT_I2, (void*)&result, parms,
		port, baud);
	return result;
}
/*
函数功能：卡开锁功能函数，如果卡上的气量不能输入表，或者重置卡上的气表类型，都执行此函数可以解决
函数返回：返回值为0的话，表示执行成功
返回值说明：1，串口错误。	2，设备错误。3，卡型错误。
	4.核对密码错误。5，非本厂数据卡。6.参数范围错误。7.注册文件错误。-1操作错误
参数说明：port，端口号，也叫串口号，如果串口1，传入0即可;
	 baud:波特率，常用的是9600； 
	 Meter气表类型，1(一体表);2(分体表);3(工业表)
*/
short _HTDL::OpenCard(short port, long baud, LPCTSTR IC, short Meter)
{
	short result;
	static BYTE parms[] =
		VTS_I2 VTS_I4 VTS_BSTR VTS_I2;
	InvokeHelper(0x60030012, DISPATCH_METHOD, VT_I2, (void*)&result, parms,
		port, baud, IC, Meter);
	return result;
}
/*
函数功能：刷新卡上的气表信息
函数返回：返回值为0的话，表示执行成功
返回值说明：1，串口错误。	2，设备错误。3，卡型错误。
	4.核对密码错误。5，非本厂数据卡。6.参数范围错误。7.注册文件错误。-1操作错误
参数说明：port，端口号，也叫串口号，如果串口1，传入0即可;
	 baud:波特率，常用的是9600； 
	 Meter气表类型，1(一体表);2(分体表);3(工业表)
*/
short _HTDL::FreshCardMeter(short port, long baud, short Meter)
{
	short result;
	static BYTE parms[] =
		VTS_I2 VTS_I4 VTS_I2;
	InvokeHelper(0x60030013, DISPATCH_METHOD, VT_I2, (void*)&result, parms,
		port, baud, Meter);
	return result;
}
/*
函数功能：判断IC卡厂家是否是本厂的卡，空卡默认非本厂的卡
函数返回：返回值为0的话，表示执行成功
返回值说明：1，串口错误。	2，设备错误。3，卡型错误。
	4.核对密码错误。5，非本厂数据卡。6.参数范围错误。7.注册文件错误。-1操作错误
参数说明：port，端口号，也叫串口号，如果串口1，传入0即可;
	 baud:波特率，常用的是9600； 
	 Meter气表类型，1(一体表);2(分体表);3(工业表)
*/
CString _HTDL::ReadFac(short port, long baud)
{
	CString result;
	static BYTE parms[] =
		VTS_I2 VTS_I4;
	InvokeHelper(0x60030014, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms,
		port, baud);
	return result;
}
//此函数不做说明，为功能测试函数
CString _HTDL::GetGas1(short port, long baud, short Meter)
{
	CString result;
	static BYTE parms[] =
		VTS_I2 VTS_I4 VTS_I2;
	InvokeHelper(0x60030015, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms,
		port, baud, Meter);
	return result;
}
//此函数不做说明，为功能测试函数
CString _HTDL::GetAlert(short port, long baud, short Meter)
{
	CString result;
	static BYTE parms[] =
		VTS_I2 VTS_I4 VTS_I2;
	InvokeHelper(0x60030016, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms,
		port, baud, Meter);
	return result;
}
