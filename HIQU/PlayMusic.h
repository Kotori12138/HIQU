#pragma once
class CPlayMusic
{
public:
	CPlayMusic(void);
	~CPlayMusic(void);

	//播放启动游戏音乐  循环播放
	static bool PlayStartMusic();

	//停止播放播放启动游戏音乐  
	static bool StopStartMusic();

	//播放游戏进行中的音乐	循环播放
	static bool PlayGameMusic();

	//停止播放游戏进行中的音乐
	static bool StopGameMusic();

	//播放游戏按键音乐 播放一次
	static bool PlayKeyMusic();
	
	//停止播放游戏按键音乐
	static bool StopKeyMusic();

	//播放游戏胜利音乐  播放一次
	static bool PlayVictoryMusic();
	
	//停止播放游戏胜利音乐
	static bool StopVictoryMusic();

	//播放游戏失败音乐 播放一次
	static bool PlayFailureMusic();

	//停止播放游戏失败音乐
	static bool StopFailureMusic();
};

