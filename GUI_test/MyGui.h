#pragma once

#include "stdafx.h"

class CMyGui : public CWindowWnd, public INotifyUI
{
public:
	CMyGui(void);
	~CMyGui(void);

private:
	CPaintManagerUI m_pm;

private:
	int Init();

public:
	LRESULT HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam);
};

