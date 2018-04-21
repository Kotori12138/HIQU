#pragma once
class CPlayMusic
{
public:
	CPlayMusic(void);
	~CPlayMusic(void);

	//����������Ϸ����  ѭ������
	static bool PlayStartMusic();

	//ֹͣ���Ų���������Ϸ����  
	static bool StopStartMusic();

	//������Ϸ�����е�����	ѭ������
	static bool PlayGameMusic();

	//ֹͣ������Ϸ�����е�����
	static bool StopGameMusic();

	//������Ϸ�������� ����һ��
	static bool PlayKeyMusic();
	
	//ֹͣ������Ϸ��������
	static bool StopKeyMusic();

	//������Ϸʤ������  ����һ��
	static bool PlayVictoryMusic();
	
	//ֹͣ������Ϸʤ������
	static bool StopVictoryMusic();

	//������Ϸʧ������ ����һ��
	static bool PlayFailureMusic();

	//ֹͣ������Ϸʧ������
	static bool StopFailureMusic();
};

