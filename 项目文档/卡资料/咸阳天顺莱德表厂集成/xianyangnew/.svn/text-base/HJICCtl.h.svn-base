#if !defined(AFX_HJICCTL_H__7F203670_32C6_4187_B105_1AE00532FB38__INCLUDED_)
#define AFX_HJICCTL_H__7F203670_32C6_4187_B105_1AE00532FB38__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// HJICCtl.h : Declaration of the CHJICCtrl ActiveX Control class.

/////////////////////////////////////////////////////////////////////////////
// CHJICCtrl : See HJICCtl.cpp for implementation.

class CHJICCtrl : public COleControl
{
	DECLARE_DYNCREATE(CHJICCtrl)

// Constructor
public:
	CHJICCtrl();

	//卡状态
	enum
	{
		OK = 0,				//卡状态正常
		CommError = 1,		//串口错误
	};

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHJICCtrl)
	public:
	virtual void OnDraw(CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid);
	virtual void DoPropExchange(CPropExchange* pPX);
	virtual void OnResetState();
	//}}AFX_VIRTUAL

// Implementation
protected:
	~CHJICCtrl();

	DECLARE_OLECREATE_EX(CHJICCtrl)    // Class factory and guid
	DECLARE_OLETYPELIB(CHJICCtrl)      // GetTypeInfo
	DECLARE_PROPPAGEIDS(CHJICCtrl)     // Property page IDs
	DECLARE_OLECTLTYPE(CHJICCtrl)		// Type name and misc status

// Message maps
	//{{AFX_MSG(CHJICCtrl)
		// NOTE - ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

// Dispatch maps
	//{{AFX_DISPATCH(CHJICCtrl)
	afx_msg void LoadConfigFile();
	afx_msg void LoadLibraries();
	afx_msg void LoadFunctionPointers();
	afx_msg long AoteReadCard();
	afx_msg long AoteSellGas(LPCTSTR factory, LPCTSTR cardno, double gas, double money, double curprice, long times, double newprice, LPCTSTR datetime, double coemption);
	afx_msg long AoteRollBackGas(LPCTSTR factory, LPCTSTR cardno, double gas, double money, double curprice, long time, double newprice, LPCTSTR datetime, double coemption);
	afx_msg long AoteReNewCard(LPCTSTR factory, LPCTSTR cardno, double gas, double money, double curprice, long times, double newprice, LPCTSTR datetime, double coemption);
	afx_msg long AoteFormatCard(LPCTSTR factory);
	afx_msg BSTR GetCardId();
	afx_msg BSTR GetFactory();
	afx_msg long GetGas();
	afx_msg long GetTimes();
	afx_msg long Init(LPCTSTR factory, LPCTSTR cardno, long gas, long times, long price);
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()

	afx_msg void AboutBox();

// Event maps
	//{{AFX_EVENT(CHJICCtrl)
	//}}AFX_EVENT
	DECLARE_EVENT_MAP()

// Dispatch and event IDs
public:
	CString PortToString(int port);
	int ReadFactory();
	enum {
	//{{AFX_DISP_ID(CHJICCtrl)
	dispidLoadConfigFile = 1L,
	dispidLoadLibraries = 2L,
	dispidLoadFunctionPointers = 3L,
	dispidAoteReadCard = 4L,
	dispidAoteSellGas = 5L,
	dispidAoteRollBackGas = 6L,
	dispidAoteReNewCard = 7L,
	dispidAoteFormatCard = 8L,
	dispidGetCardId = 9L,
	dispidGetFactory = 10L,
	dispidGetGas = 11L,
	dispidGetTimes = 12L,
	dispidInit = 13L,
	//}}AFX_DISP_ID
	};
private:
	//端口号
	int CommPort;
	//波特率
	int BaudRate;
	//卡号
	char CardNo[80];
    //气量
    long Gas;
    //次数
	long Times;
	//厂家
	char Factory[80];


};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HJICCTL_H__7F203670_32C6_4187_B105_1AE00532FB38__INCLUDED)
