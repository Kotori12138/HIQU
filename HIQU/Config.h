#pragma once
class CConfig
{
public:
	CConfig(void);
	~CConfig(void);

	//读取音效开关配置
	static bool ReadMusicSwitch(CString fileName, bool& musicSwitch);

	//读取通关记录配置
	static bool ReadRank(CString fileName, UINT& rank);

	//写入音效开关配置
	static bool WriteMusicSwitch(CString fileName, const bool& musicSwitch);

	//写入通关记录配置
	static bool WriteRank(CString fileName, const UINT& rank);
};

