#pragma once

#include "vector"
using namespace std;

#define	PHOTONUM 6
#define	LEVELNUM 10
#define LEVELNUMPERPAGE 12
#define ROWSTEP 70
#define LINESTEP 20
#define VERTEXWIDTH 187
#define VERTEXHEIGTH 131

class CScene
{
public:
	CScene();
	~CScene(void);

	RectF rectVertexs[LEVELNUMPERPAGE];

	RectF clientRect;

	//游戏音量设置按钮
	struct StructVolConfig
	{
		Bitmap* pNormalVol;
		Bitmap* pSelectVol;
		Bitmap* pNormalNoVal;
		Bitmap* pSelectNoVol;
		RectF volRect;
		bool isSelect;
	}m_volUI;

	//游戏顶部最小化按钮
	struct StructMinUI
	{
		Bitmap* pNormalMin;
		Bitmap* pSelectMin;
		RectF minRect;
		bool isSelect;
	}m_minUI;

	//游戏顶部最大化按钮
	struct StructCloseUI
	{
		Bitmap* pNormalClose;
		Bitmap* pSelectClose;
		RectF closeRect;
		bool isSelect;
	}m_closeUI;

	//游戏返回键图片
	struct StructBack
	{
		Bitmap* pNormalBack;
		Bitmap* pSelectBack;
		RectF backRect;
		bool isSelect;
	}m_backUI;

	//头像图片
	struct StructPhoto
	{
		vector<Bitmap*> pPhotos;
		RectF photoRect;
	}m_photoUI;

	//选图图形图片
	struct StructVertex
	{
		Bitmap* pNormalVertex;
		Bitmap* pSelectVertex;
		RectF rectVertex;                  
		UINT level;				//对应的关卡数
		bool isSelect;
	};

	//练习模式选择图形界面
	struct StructTrainMode
	{
		Bitmap* pBackground;
		StructVertex vertexs[LEVELNUM];
		Bitmap* pNoramlBefore;
		Bitmap* pSelectBefore;
		Bitmap* pNormalNext;
		Bitmap* pSelectNext;
		vector<Bitmap*> pPages;
		RectF beforeRect;
		RectF nextRect;
		RectF pageRect;
		bool isBeforeSelect;
		bool isNextSelect;
	}m_trainModeUI;


	//开始游戏界面图片
	struct StructStartUI
	{
		Bitmap* pBackground;
		Bitmap* pNormalLevel;
		Bitmap* pSelectLevel;
		Bitmap* pNormalTrain;
		Bitmap* pSelectTrain;
		RectF levelModeRect;
		RectF trainModeRect;
		bool isSelectLevel;
		bool isSelectTrain;
	}m_startUI;
	

	//关卡模式游戏进行图形
	struct StructLevelGame
	{
		Bitmap* pBackground;	//背景图片
		vector<Bitmap*> pLevels;		//关卡图片
		Bitmap* pNormalSubmit;	//提交图片 默认
		Bitmap* pSelectSubmit;	//提交图片 选中
		RectF levelRect;		//关卡图片粘贴区域
		RectF submitRect;		//提交图片粘贴区域
		bool isSelectSubmit;	//提交图片是否被选中
	}m_level_gameUI;

	struct StructTrainGame
	{
		Bitmap* pBackground; //背景图片
		Bitmap* pLevel;		//关卡图片
		Bitmap* pNormalSubmit;	//提交图片 默认
		Bitmap* pSelectSubmit;	//提交图片 选中
		RectF levelRect;		//关卡图片粘贴区域
		RectF submitRect;		//提交图片粘贴区域
		bool isSelectSubmit;	//提交图片是否被选中
	}m_train_gameUI;

	struct StructSuccess
	{
		Bitmap* pBackground;		//背景图片
		Bitmap* pNormalBack;		//返回键
		Bitmap* pSelectBack;		//选中返回键
		Bitmap* pNormalNext;		//下一关
		Bitmap* pSelectNext;		//选择下一关
		Bitmap* pNormalContinue;	//继续按钮图片
		Bitmap* pSelectContinue;	//选择继续按钮图片
		RectF backRect;				//返回键区域
		RectF nextRect;				//下一关键区域	
		RectF continueRect;			//继续键区域
		bool isSelectBack;			//返回键是否选中
		bool isSelectNext;			//下一关键是否选中
		bool isSelectContinue;		//继续键按钮选择
	}m_successUI;

	struct StructFailure
	{
		Bitmap* pBackground;		//背景图片	
		Bitmap* pNormalBack;		//返回键
		Bitmap* pSelectBack;		//选中返回键
		Bitmap* pNormalContinue;	//继续按钮图片
		Bitmap* pSelectContinue;	//选中继续按钮图片
		RectF backRect;				//返回键区域
		RectF continueRect;			//继续键区域
		bool isSelectBack;			//返回键是否选中
		bool isSelectContinue;		//继续键按钮选择
	}m_failureUI;

	UINT pageNum;

	//初始化游戏场景
	void InitScene(HWND hWnd);
	
	//绘制游戏开始界面
	void DrawStartUI(Graphics* pGraphics, bool hasVol);
	
	//绘制游戏选关界面
	void DrawChooseModeUI(Graphics* pGraphics, bool hasVol);

	//绘制闯关游戏进行中界面
	void DrawLevelGameUI(Graphics* pGraphics,  bool hasVol, UINT level);

	//绘制游戏选图界面
	void DrawTrainChooseVertex(Graphics* pGraphics, bool hasVol, UINT page);

	//绘制练习模式界面
	void DrawTrainGameUI(Graphics* pGraphics, bool hasVol, UINT level);

	//绘制游戏成功界面  type true表示闯关成功界面 false表示失败成功界面
	void DrawGameSuccessUI(Graphics* pGraphics, bool type);

	//绘制游戏失败界面
	void DrawGameFailureUI(Graphics* pGraphics);

	//获取选图图形每页的图形个数
	UINT GetVertexNumByPage(UINT page);

private:

	//加载音量设置按钮图片
	void LoadVolSetingImg();

	//加载最下化和关闭按钮图片
	void LoadMinCloseImg();

	//加载开始游戏界面图片
	void LoadStartGameImg();

	//加载闯关游戏进行界面图片
	void LoadLevelGamingImg();

	//加载头像和目标图形图片
	void LoadPhotoVertexsImg();

	//加载练习模式选图界面图片
	void LoadTrainChooseVertexsImg();

	//加载练习模式游戏进行图片
	void LoadTrainGamingImg();

	//加载成功界面图片
	void LoadGameSuccessImg();

	//加载游戏失败界面图片
	void LoadGameFailureImg();

	//绘制关闭和最小化按钮
	void DrawMinCloseUI(Graphics* pGraphics);

	

};

