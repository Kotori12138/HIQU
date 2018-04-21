#pragma once
class CConfig
{
public:
	CConfig(void);
	~CConfig(void);

	//��ȡ��Ч��������
	static bool ReadMusicSwitch(CString fileName, bool& musicSwitch);

	//��ȡͨ�ؼ�¼����
	static bool ReadRank(CString fileName, UINT& rank);

	//д����Ч��������
	static bool WriteMusicSwitch(CString fileName, const bool& musicSwitch);

	//д��ͨ�ؼ�¼����
	static bool WriteRank(CString fileName, const UINT& rank);
};

