#include "stdafx.h"
#include "MyGui.h"

CMyGui::CMyGui(void)
{
}


CMyGui::~CMyGui(void)
{
}

LRESULT CMyGui::HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	if(uMsg == WM_CREATE)
	{
		m_pm.Init(m_hWnd);
		CDialogBuilder builder;
		CControlUI* pRoot = builder.Create(_T("MyGui.xml"), (UINT)0, NULL, &m_pm);
		ASSERT(pRoot && "Failed to parse XML");
		m_pm.AttachDialog(pRoot);
		m_pm.AddNotifier(this);

		if(Init() != 0) ASSERT("Failed to init"); 

		return 0;
	}
	else if(uMsg == WM_DESTROY) 
	{
		::PostQuitMessage(0L);
	}
	else if(uMsg == WM_NCACTIVATE) 
	{
		if(!::IsIconic(*this)) return (wParam == 0)?TRUE:FALSE;
	}

	LRESULT lRes = 0;
	if(m_pm.MessageHandler(uMsg, wParam, lParam, lRes)) return lRes;

	return CWindowWnd::HandleMessage(uMsg, wParam, lParam);
}

int CMyGui::Init()
{
	return 0;
}