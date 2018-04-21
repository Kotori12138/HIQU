#include "StdAfx.h"
#include "Config.h"


CConfig::CConfig(void)
{
}


CConfig::~CConfig(void)
{
}

bool CConfig::ReadMusicSwitch( CString fileName, bool& musicSwitch )
{
	wchar_t systemPath[MAX_PATH];
	GetCurrentDirectoryW(MAX_PATH, systemPath);
	CString configFilePath , defaultFilePath;
	configFilePath.Format(L"%s\\%s", systemPath, fileName);	

	CFileFind fileFind;
	if (fileFind.FindFile(configFilePath) == FALSE)
	{
		return false;
	}
	
	CString appName = L"设置";

	CString strSwitch;
	::GetPrivateProfileStringW(appName, L"音效开关", L"关", strSwitch.GetBuffer(MAX_PATH), MAX_PATH, configFilePath);

	if (strSwitch == L"开")
	{
		musicSwitch = true;
	}
	else
	{
		musicSwitch = false;
	}

	return true;
}

bool CConfig::ReadRank( CString fileName, UINT& rank )
{
	wchar_t systemPath[MAX_PATH];
	GetCurrentDirectoryW(MAX_PATH, systemPath);
	CString configFilePath;
	configFilePath.Format(L"%s\\%s", systemPath, fileName);	

	CFileFind fileFind;
	if (fileFind.FindFile(configFilePath) == FALSE)
	{	
		return false;
	}

	rank = ::GetPrivateProfileIntW(L"游戏记录", L"通关记录", 1, configFilePath);

	return true;
}

bool CConfig::WriteMusicSwitch( CString fileName, const bool& musicSwitch )
{
	wchar_t systemPath[MAX_PATH];
	GetCurrentDirectoryW(MAX_PATH, systemPath);
	CString configFilePath;
	configFilePath.Format(L"%s\\%s", systemPath, fileName);	

	CFileFind fileFind;
	if (fileFind.FindFile(configFilePath) == FALSE)
	{	
		return false;
	}

	CString appName = L"设置";

	if (musicSwitch == true)
	{
		if (::WritePrivateProfileStringW(appName, L"音效开关", L"开", configFilePath) == FALSE)
		{
			return false;
		}
	}
	else
	{
		if (::WritePrivateProfileStringW(appName, L"音效开关", L"关", configFilePath) == FALSE)
		{
			return false;
		}
	}

	return true;
}

bool CConfig::WriteRank( CString fileName, const UINT& rank )
{
	wchar_t systemPath[MAX_PATH];
	GetCurrentDirectoryW(MAX_PATH, systemPath);
	CString configFilePath;
	configFilePath.Format(L"%s\\%s", systemPath, fileName);	

	CFileFind fileFind;
	if (fileFind.FindFile(configFilePath) == FALSE)
	{
		return false;
	}

	if (::WritePrivateProfileStringW(L"游戏记录", L"通关记录", (_bstr_t)rank, configFilePath) == FALSE)
	{
		return false;
	}
	return true;
}
