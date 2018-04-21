#include "StdAfx.h"
#include "PlayMusic.h"
#include <windows.h>
#include <mmsystem.h>
#pragma comment(lib, "WINMM.LIB")



CPlayMusic::CPlayMusic(void)
{
}


CPlayMusic::~CPlayMusic(void)
{
}

//��ʼ����
bool CPlayMusic::PlayStartMusic()
{
	CString strMusicFile=_T("res\\music\\start.wav");//MP3�ļ���·��
	mciSendString (_T("open \"") +strMusicFile+_T("\" type MPEGVideo alias PSMusic"),NULL, 0, 0); // ���ļ���ȡ������PSMusic��
	mciSendString (_T("play PSMusic repeat"),NULL, 0, 0);//ѭ������
	return true;
}

bool CPlayMusic::StopStartMusic()
{
	mciSendString (_T("close PSMusic"),NULL, 0, 0);//ֹͣ����
	return true;
}

//��Ϸ����������
bool CPlayMusic::PlayGameMusic()
{
	CString strMusicFile=_T("res\\music\\play.mp3");//MP3�ļ���
	mciSendString (_T("open \"") +strMusicFile+_T("\" type MPEGVideo alias PGMusic"),NULL, 0, 0); // ��
	mciSendString (_T("play PGMusic repeat"),NULL, 0, 0);//ѭ������
	return true;
}

bool CPlayMusic::StopGameMusic()
{
	mciSendString (_T("close PGMusic"),NULL, 0, 0);//ֹͣ����
	return true;
}

//�������
bool CPlayMusic::PlayKeyMusic()
{
	CString strMusicFile=_T("res\\music\\key.wav");//MP3�ļ���
	mciSendString (_T("open \"") +strMusicFile+_T("\" type MPEGVideo alias PKMusic"),NULL, 0, 0); // ��
	mciSendString (_T("play PKMusic "),NULL, 0, 0);//��ͨ����
	return true;
}

bool CPlayMusic::StopKeyMusic()
{
	mciSendString (_T("close PKMusic"),NULL, 0, 0);//ֹͣ����
	return true;
}

//ʤ������

bool CPlayMusic::PlayVictoryMusic()
{
	CString strMusicFile=_T("res\\music\\victory.wav");//MP3�ļ���
	mciSendString (_T("open \"") +strMusicFile+_T("\" type MPEGVideo alias PVMusic"),NULL, 0, 0); // ��
	mciSendString (_T("play PVMusic "),NULL, 0, 0);//��ͨ����
	return true;
}

bool CPlayMusic::StopVictoryMusic()
{
	mciSendString (_T("close PVMusic"),NULL, 0, 0);//ֹͣ����
	return true;
}

//ʧ������

bool CPlayMusic::PlayFailureMusic()
{
	CString strMusicFile=_T("res\\music\\failure.wav");//MP3�ļ���
	mciSendString (_T("open \"") +strMusicFile+_T("\" type MPEGVideo alias PFMusic"),NULL, 0, 0); // ��
	mciSendString (_T("play PFMusic "),NULL, 0, 0);//��ͨ����
	return true;
}

bool CPlayMusic::StopFailureMusic()
{
	mciSendString (_T("close PFMusic"),NULL, 0, 0);//ֹͣ����
	return true;
}
