// HJICPpg.cpp : Implementation of the CHJICPropPage property page class.

#include "stdafx.h"
#include "HJIC.h"
#include "HJICPpg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


IMPLEMENT_DYNCREATE(CHJICPropPage, COlePropertyPage)


/////////////////////////////////////////////////////////////////////////////
// Message map

BEGIN_MESSAGE_MAP(CHJICPropPage, COlePropertyPage)
	//{{AFX_MSG_MAP(CHJICPropPage)
	// NOTE - ClassWizard will add and remove message map entries
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// Initialize class factory and guid

IMPLEMENT_OLECREATE_EX(CHJICPropPage, "HJIC.HJICPropPage.1",
	0x3bb1cea0, 0x13af, 0x4e0a, 0xb4, 0x4, 0x60, 0x15, 0x30, 0x7a, 0x42, 0x42)


/////////////////////////////////////////////////////////////////////////////
// CHJICPropPage::CHJICPropPageFactory::UpdateRegistry -
// Adds or removes system registry entries for CHJICPropPage

BOOL CHJICPropPage::CHJICPropPageFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(),
			m_clsid, IDS_HJIC_PPG);
	else
		return AfxOleUnregisterClass(m_clsid, NULL);
}


/////////////////////////////////////////////////////////////////////////////
// CHJICPropPage::CHJICPropPage - Constructor

CHJICPropPage::CHJICPropPage() :
	COlePropertyPage(IDD, IDS_HJIC_PPG_CAPTION)
{
	//{{AFX_DATA_INIT(CHJICPropPage)
	// NOTE: ClassWizard will add member initialization here
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA_INIT
}


/////////////////////////////////////////////////////////////////////////////
// CHJICPropPage::DoDataExchange - Moves data between page and properties

void CHJICPropPage::DoDataExchange(CDataExchange* pDX)
{
	//{{AFX_DATA_MAP(CHJICPropPage)
	// NOTE: ClassWizard will add DDP, DDX, and DDV calls here
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA_MAP
	DDP_PostProcessing(pDX);
}


/////////////////////////////////////////////////////////////////////////////
// CHJICPropPage message handlers
