#include "stdafx.h"
#include "MyGui.h"

//#define NO_USE_XML
#define USE_XML

CMyGui::CMyGui(void)
{
}


CMyGui::~CMyGui(void)
{
}

void CMyGui::OnPrepare()
{

}

void CMyGui::Notify(TNotifyUI& msg)
{
	if(msg.sType == _T("windowinit")) OnPrepare();

#ifdef NO_USE_XML
	else if(msg.sType == _T("click")) 
	{
		if(msg.pSender->GetName() == _T("closebtn")) 
		{
			Close();
		}
	}
#endif



}

LRESULT CMyGui::HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	if(uMsg == WM_CREATE)
	{
		m_pm.Init(m_hWnd);

#ifdef NO_USE_XML
		CControlUI *pButton = new CButtonUI;
		pButton->SetName(_T("closebtn"));
		pButton->SetBkColor(0xFFFF0000);
		m_pm.AttachDialog(pButton);
#endif

#ifdef USE_XML
		CDialogBuilder builder;
		CControlUI* pRoot = builder.Create(_T("MyGui.xml"), (UINT)0, NULL, &m_pm);
		ASSERT(pRoot && "Failed to parse XML");
		m_pm.AttachDialog(pRoot);
#endif

		m_pm.AddNotifier(this);

		if(Init() != 0) ASSERT("Failed to init"); 

		return 0;
	}
	else if(uMsg == WM_DESTROY) 
	{
		::PostQuitMessage(0);
	}
	else if(uMsg == WM_NCACTIVATE) 
	{
		if(!::IsIconic(*this)) return (wParam == 0)?TRUE:FALSE;
	}
	else if( uMsg == WM_NCCALCSIZE ) 
	{
		return 0;
	}
	else if( uMsg == WM_NCPAINT )
	{
		return 0;
	}


	LRESULT lRes = 0;
	if(m_pm.MessageHandler(uMsg, wParam, lParam, lRes)) return lRes;

	return CWindowWnd::HandleMessage(uMsg, wParam, lParam);
}

int CMyGui::Init()
{
	return 0;
}