
// HIQU.h : HIQU 应用程序的主头文件
//
#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"       // 主符号
#include "PlayMusic.h"

// CHIQUApp:
// 有关此类的实现，请参阅 HIQU.cpp
//

class CHIQUApp : public CWinApp
{
public:
	CHIQUApp();


// 重写
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// 实现

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP();
	ULONG_PTR gdiplusToken;

public:
	CPlayMusic playmusic;
};

extern CHIQUApp theApp;
