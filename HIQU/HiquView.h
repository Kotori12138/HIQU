
// HiquView.h : CHiquView 类的接口
//


#pragma once
#include "Trangle.h"
#include "Pentagon.h"
#include "Trapezoid.h"
#include "Validate.h"
#include "Scene.h"
#include "Config.h"


// CHiquView 窗口
enum GameMode
{
	START = 0,					//游戏开始界面
	SGL_LEVEL = 1,				//游戏闯关模式 
	SGL_LEVEL_GAMING = 2,		//闯关模式 游戏进行
	SGL_TRAIN = 3,				//单机版练习模式
	SGL_TRAIN_GAMING = 4,		//单机版练习模式 游戏进行
	SGL_LEVEL_GAME_SUCCESS = 5,	//闯关游戏 游戏成功 
	SGL_LEVEL_GAME_FAILURE = 6,		//闯关游戏 游戏失败
	SGL_TRAIN_GAME_SUCCESS = 7,	//练习模式游戏成功
	SGL_TRAIN_GAME_FAILURE = 8,//练习模式 游戏失败
};

enum Vertex
{
	TRANGLE = 0,	  //三角形
	SMALLTRAPE = 1,   //小四边形
	BIGTRAPE = 2,	  //大四边形
	PENTAGON = 3	  //五边形
};

class CHiquView : public CWnd
{
// 构造
public:
	CHiquView();
// 实现
public:
	virtual ~CHiquView();

// 重写
protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

private:

	CScene m_scene;					//场景界面绘制

	CTrangle trangle;				//三角形类
	CPentagon pentagon;				//五边形类
	CTrapezoid smallTrapezoid;		//小梯形类
	CTrapezoid bigTrapezoid;		//大梯形类
	Bitmap bkBmp;					//背景图片
	Bitmap mainBmp;					//主界面
	Bitmap chooseMode;				//模式选择
	Bitmap successBmp;				//成功界面
	byte selectedVertex;			//选中图形 
	bool isLBDown;					//左键是否按下
	CPoint lbDown;					//记录左键按下位置
	CValidate validate;				//验证图形
	UINT level;						//通关模式当前卡数
	UINT train_level;				//选图模式当前目标图形对应的关卡
	byte mode;						//流程控制  
	Graphics *pGraphics;			//重绘主绘图类
	Graphics *pTempGraphics;		//重绘缓存绘图类
	Bitmap *pBitmap;
	BOOL   m_bIsMove;                 //是否处于移动状态   
	CPoint   m_CenterPt;           //移动点中心 
	bool musicSwitch;				//游戏音效开关
	UINT curPage;					//选图的当前页数


	// 生成的消息映射函数
protected:
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg LRESULT OnInitial(WPARAM wParam, LPARAM lParam);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);

private:
	//重绘函数
	void OnRender(HDC hdc);

	//初始化绘图资源
	void InitDrawResource();

	//初始化音效开关  配置文件中获取
	void InitMusic();

	//初始化游戏板子图形
	void InitVtertexs();

	//处理最下化和关闭
	void OnMinClosed(CPoint point);

	//音效设置
	void SetMusicSwitch(CPoint point);
	
	//最下化、关闭 音量设置 鼠标滤过
	void MinCloseMusicHover(CPoint point);

	//游戏启动界面鼠标滤过处理
	void StartGameHover(CPoint point);

	//闯关游戏进行界面鼠标滤过处理
	void LevelGamingHover(CPoint point);

	//练习模式游戏进行界面鼠标滤过处理
	void TrainGamingHover(CPoint point);

	//返回键鼠标滤过处理
	void BackHover(CPoint point);

	//游戏练习模式选图界面鼠标滤过处理
	void ChooseVertexsHover(CPoint point);

	//游戏成功界面 鼠标滤过处理
	void GameSuccessHover(CPoint point);

	//游戏失败界面 鼠标滤过处理
	void GameFailureHover(CPoint point);

	//鼠标拖拽窗口处理
	void DockWindow(CPoint point);
	
	//图形移动
	void VertexMove(CPoint point);

	//播放鼠标滤过 图形反转 旋转声音
	void PlayKeyMusic();

	//板子图形鼠标左键按下处理
	void VertexLButtonDown(CPoint point);

	//是否初始化资源
	bool m_bIsInit;
public:
	afx_msg void OnMouseLeave();
};

