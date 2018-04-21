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
	
	CString appName = L"����";

	CString strSwitch;
	::GetPrivateProfileStringW(appName, L"��Ч����", L"��", strSwitch.GetBuffer(MAX_PATH), MAX_PATH, configFilePath);

	if (strSwitch == L"��")
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

	rank = ::GetPrivateProfileIntW(L"��Ϸ��¼", L"ͨ�ؼ�¼", 1, configFilePath);

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

	CString appName = L"����";

	if (musicSwitch == true)
	{
		if (::WritePrivateProfileStringW(appName, L"��Ч����", L"��", configFilePath) == FALSE)
		{
			return false;
		}
	}
	else
	{
		if (::WritePrivateProfileStringW(appName, L"��Ч����", L"��", configFilePath) == FALSE)
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

	if (::WritePrivateProfileStringW(L"��Ϸ��¼", L"ͨ�ؼ�¼", (_bstr_t)rank, configFilePath) == FALSE)
	{
		return false;
	}
	return true;
}
