
// HIQU.h : HIQU Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������
#include "PlayMusic.h"

// CHIQUApp:
// �йش����ʵ�֣������ HIQU.cpp
//

class CHIQUApp : public CWinApp
{
public:
	CHIQUApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP();
	ULONG_PTR gdiplusToken;

public:
	CPlayMusic playmusic;
};

extern CHIQUApp theApp;
