#include "stdafx.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	CPaintManagerUI::SetInstance(hInstance);
	CPaintManagerUI::SetResourcePath(CPaintManagerUI::GetInstancePath());

	HRESULT Hr = ::CoInitialize(NULL);
	if( FAILED(Hr) ) return 0;

	CMyGui* pMyGui = new CMyGui();
	if(pMyGui == NULL) return 0;
	pMyGui->Create(NULL, "MyGui", UI_WNDSTYLE_DIALOG, 0);
	pMyGui->CenterWindow();
	pMyGui->ShowWindow(true);

	 CPaintManagerUI::MessageLoop();

	::CoUninitialize();

	return 0;
}
