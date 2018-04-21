#include "StdAfx.h"
#include "Scene.h"


CScene::CScene()
{
	//初始化选图图形位置矩形
	int cur = 0;
	int offsetY = 0;
	for (int i=0; i<4; i++)
	{
		int offsetX = 0;
		for (int j=0; j<3; j++)
		{
			rectVertexs[cur] = RectF((REAL)(95+offsetX), (REAL)(55+offsetY), VERTEXWIDTH, VERTEXHEIGTH);
			offsetX += (ROWSTEP+VERTEXWIDTH);
			cur++;
		}
		offsetY += (LINESTEP + VERTEXHEIGTH);
	}

	//计算选图图形所需要的页数
	pageNum = LEVELNUM/LEVELNUMPERPAGE;
	if (LEVELNUM % LEVELNUMPERPAGE != 0)
	{
		pageNum++;
	}
}


CScene::~CScene(void)
{
	//释放音量设置按钮图片资源
	delete m_volUI.pNormalVol;
	delete m_volUI.pSelectVol;
	delete m_volUI.pNormalNoVal;
	delete m_volUI.pSelectNoVol;
	
	//释放最下化按钮图片
	delete m_minUI.pNormalMin;
	delete m_minUI.pSelectMin;

	//释放关闭按钮图片资源
	delete m_closeUI.pNormalClose;
	delete m_closeUI.pSelectClose;

	//释放开始界面图片资源
	delete m_startUI.pBackground;
	delete m_startUI.pNormalTrain;
	delete m_startUI.pNormalLevel;
	delete m_startUI.pSelectTrain;
	delete m_startUI.pSelectLevel;

}


void CScene::InitScene( HWND hWnd )
{
	CRect rect;
	GetClientRect(hWnd, &rect);
	clientRect = RectF((REAL)rect.left, (REAL)rect.top, (REAL)rect.Width(), (REAL)rect.Height());

	LoadVolSetingImg();
	LoadMinCloseImg();
	LoadStartGameImg();
	LoadPhotoVertexsImg();
	LoadTrainGamingImg();
	LoadTrainChooseVertexsImg();
	LoadLevelGamingImg();
	LoadGameSuccessImg();
	LoadGameFailureImg();

}

void CScene::DrawStartUI(Graphics* pGraphics, bool hasVol)
{
	pGraphics->DrawImage(m_startUI.pBackground, clientRect);
	DrawMinCloseUI(pGraphics);
	pGraphics->DrawImage(m_startUI.isSelectLevel?m_startUI.pSelectLevel:m_startUI.pNormalLevel, m_startUI.levelModeRect);
	pGraphics->DrawImage(m_startUI.isSelectTrain?m_startUI.pSelectTrain:m_startUI.pNormalTrain, m_startUI.trainModeRect);
	
	if (hasVol)
	{
		pGraphics->DrawImage(m_volUI.isSelect?m_volUI.pSelectVol:m_volUI.pNormalVol, m_volUI.volRect);
	}
	else
	{
		pGraphics->DrawImage(m_volUI.isSelect?m_volUI.pSelectNoVol:m_volUI.pNormalNoVal, m_volUI.volRect);
	}
}
                          
void CScene::DrawLevelGameUI( Graphics* pGraphics, bool hasVol, UINT level)
{
	pGraphics->DrawImage(m_level_gameUI.pBackground, clientRect);
	DrawMinCloseUI(pGraphics);
	pGraphics->DrawImage(m_photoUI.pPhotos[level-1],m_photoUI.photoRect);		//贴人物头像和目标图形
	pGraphics->DrawImage(m_level_gameUI.pLevels[level-1], m_level_gameUI.levelRect);		//贴相应关卡数图片
	pGraphics->DrawImage(m_level_gameUI.isSelectSubmit?m_level_gameUI.pSelectSubmit:m_level_gameUI.pNormalSubmit, m_level_gameUI.submitRect); //贴提交按钮图片
	pGraphics->DrawImage(m_backUI.isSelect?m_backUI.pSelectBack:m_backUI.pNormalBack, m_backUI.backRect);

	if (hasVol)
	{
		pGraphics->DrawImage(m_volUI.isSelect?m_volUI.pSelectVol:m_volUI.pNormalVol, m_volUI.volRect);
	}
	else
	{
		pGraphics->DrawImage(m_volUI.isSelect?m_volUI.pSelectNoVol:m_volUI.pNormalNoVal, m_volUI.volRect);
	}
}

void CScene::DrawMinCloseUI( Graphics* pGraphics )
{
	pGraphics->DrawImage(m_minUI.isSelect?m_minUI.pSelectMin:m_minUI.pNormalMin, m_minUI.minRect);
	pGraphics->DrawImage(m_closeUI.isSelect?m_closeUI.pSelectClose:m_closeUI.pNormalClose, m_closeUI.closeRect);
}

void CScene::DrawTrainChooseVertex( Graphics* pGraphics, bool hasVol, UINT page )
{
	pGraphics->DrawImage(m_trainModeUI.pBackground, clientRect);
	DrawMinCloseUI(pGraphics);

	//如果页数大于当前有的页数 则页数自动设为当前有的页数
	if (page > pageNum)
	{
		page = pageNum;
	}
	else if (page < 1)
	{
		page = 1;
	}
	
	//绘制选图图形
	for (int i=(page-1)*LEVELNUMPERPAGE; i<(page-1)*LEVELNUMPERPAGE+GetVertexNumByPage(page); i++)
	{
		pGraphics->DrawImage(m_trainModeUI.vertexs[i].isSelect?m_trainModeUI.vertexs[i].pSelectVertex:m_trainModeUI.vertexs[i].pNormalVertex,
			m_trainModeUI.vertexs[i].rectVertex);
	}
	
	//绘制上一页 下一页 和 当前页数
	pGraphics->DrawImage(m_trainModeUI.isBeforeSelect?m_trainModeUI.pSelectBefore:m_trainModeUI.pNoramlBefore, m_trainModeUI.beforeRect);
	pGraphics->DrawImage(m_trainModeUI.isNextSelect?m_trainModeUI.pSelectNext:m_trainModeUI.pNormalNext, m_trainModeUI.nextRect);

	pGraphics->DrawImage(m_trainModeUI.pPages[page-1], m_trainModeUI.pageRect);

	pGraphics->DrawImage(m_backUI.isSelect?m_backUI.pSelectBack:m_backUI.pNormalBack, m_backUI.backRect);
	if (hasVol)
	{
		pGraphics->DrawImage(m_volUI.isSelect?m_volUI.pSelectVol:m_volUI.pNormalVol, m_volUI.volRect);
	}
	else
	{
		pGraphics->DrawImage(m_volUI.isSelect?m_volUI.pSelectNoVol:m_volUI.pNormalNoVal, m_volUI.volRect);
	}
}

void CScene::DrawTrainGameUI( Graphics* pGraphics, bool hasVol, UINT level)
{
	pGraphics->DrawImage(m_train_gameUI.pBackground, clientRect);
	DrawMinCloseUI(pGraphics);
	pGraphics->DrawImage(m_photoUI.pPhotos[level-1],m_photoUI.photoRect);		//贴人物头像和目标图形
	pGraphics->DrawImage(m_train_gameUI.pLevel, m_train_gameUI.levelRect);		//贴相应关卡数图片
	pGraphics->DrawImage(m_train_gameUI.isSelectSubmit?m_train_gameUI.pSelectSubmit:m_train_gameUI.pNormalSubmit, m_train_gameUI.submitRect); //贴提交按钮图片
	pGraphics->DrawImage(m_backUI.isSelect?m_backUI.pSelectBack:m_backUI.pNormalBack, m_backUI.backRect);

	if (hasVol)
	{
		pGraphics->DrawImage(m_volUI.isSelect?m_volUI.pSelectVol:m_volUI.pNormalVol, m_volUI.volRect);
	}
	else
	{
		pGraphics->DrawImage(m_volUI.isSelect?m_volUI.pSelectNoVol:m_volUI.pNormalNoVal, m_volUI.volRect);
	}
}

void CScene::DrawGameSuccessUI( Graphics* pGraphics, bool type)
{
	pGraphics->DrawImage(m_successUI.pBackground,RectF(220, 180,(REAL)m_successUI.pBackground->GetWidth(),(REAL)m_successUI.pBackground->GetHeight()));
	pGraphics->DrawImage(m_successUI.isSelectBack?m_successUI.pSelectBack:m_successUI.pNormalBack,m_successUI.backRect);
	if (type)
	{
		pGraphics->DrawImage(m_successUI.isSelectNext?m_successUI.pSelectNext:m_successUI.pNormalNext,m_successUI.nextRect);
	}
	else
	{
		pGraphics->DrawImage(m_successUI.isSelectContinue?m_successUI.pSelectContinue:m_successUI.pNormalContinue, m_successUI.continueRect);
	}
}

void CScene::DrawGameFailureUI( Graphics* pGraphics )
{
	pGraphics->DrawImage(m_failureUI.pBackground,RectF(230,130,(REAL)m_failureUI.pBackground->GetWidth(),(REAL)m_failureUI.pBackground->GetHeight()));
	pGraphics->DrawImage(m_failureUI.isSelectBack?m_failureUI.pSelectBack:m_failureUI.pNormalBack,m_failureUI.backRect);
	pGraphics->DrawImage(m_failureUI.isSelectContinue?m_failureUI.pSelectContinue:m_failureUI.pNormalContinue,m_failureUI.continueRect);
}

void CScene::LoadVolSetingImg()
{
	m_volUI.pNormalVol = new Bitmap(L"res\\Vol.png");
	m_volUI.pSelectVol = new Bitmap(L"res\\VolSelect.png");
	m_volUI.pNormalNoVal = new Bitmap(L"res\\NoVol.png");
	m_volUI.pSelectNoVol = new Bitmap(L"res\\NoVolSelect.png");
	m_volUI.volRect = RectF((REAL)(clientRect.Width - m_volUI.pNormalVol->GetWidth())-10, 45, (REAL)m_volUI.pNormalVol->GetWidth(), (REAL)m_volUI.pNormalVol->GetHeight());
	m_volUI.isSelect = false;
}

void CScene::LoadMinCloseImg()
{
	//加载最下化按钮图片
	m_minUI.pNormalMin = new Bitmap(L"res\\MinNormal.png");
	m_minUI.pSelectMin = new Bitmap(L"res\\MinSelect.png");
	m_minUI.minRect = RectF((REAL)(clientRect.Width-m_minUI.pNormalMin->GetWidth()*2-3), 1, (REAL)m_minUI.pNormalMin->GetWidth(), (REAL)m_minUI.pNormalMin->GetHeight());
	m_minUI.isSelect = false;

	//加载关闭按钮图片
	m_closeUI.pNormalClose = new Bitmap(L"res\\Close.png");
	m_closeUI.pSelectClose = new Bitmap(L"res\\CloseSelect.png");
	m_closeUI.closeRect =  RectF((REAL)(clientRect.Width - m_closeUI.pNormalClose->GetWidth()), 1, (REAL)m_closeUI.pNormalClose->GetWidth(), (REAL)m_closeUI.pNormalClose->GetHeight());
	m_closeUI.isSelect = false;
}

void CScene::LoadStartGameImg()
{
	//加载开始界面图片
	m_startUI.pBackground = new Bitmap(L"res\\Start.png");
	m_startUI.pNormalLevel = new Bitmap(L"res\\SingleMode.png");
	m_startUI.pSelectLevel = new Bitmap(L"res\\SingleModeSelect.png");
	m_startUI.pNormalTrain = new Bitmap(L"res\\MultiMode.png");
	m_startUI.pSelectTrain = new Bitmap(L"res\\MultiModeSelect.png");
	m_startUI.levelModeRect = RectF(90, 370, (REAL)m_startUI.pNormalLevel->GetWidth(),  (REAL)m_startUI.pNormalLevel->GetHeight());
	m_startUI.trainModeRect = RectF((REAL)(clientRect.Width - 90 - m_startUI.pNormalTrain->GetWidth()), 370, (REAL)m_startUI.pNormalTrain->GetWidth(), (REAL)m_startUI.pNormalTrain->GetHeight());
	m_startUI.isSelectLevel = false;
	m_startUI.isSelectTrain = false;
}

void CScene::LoadLevelGamingImg()
{
	m_level_gameUI.pBackground = new Bitmap(L"res\\Gaming.png");

	CString filePath;
	//加载游戏关卡图片
	for (int i=0; i<LEVELNUM; i++)
	{
		filePath.Format(L"res\\Level\\%d.png", i+1);
		m_level_gameUI.pLevels.push_back(new Bitmap(filePath));
	}
	m_level_gameUI.levelRect = RectF((REAL)((clientRect.Width-m_level_gameUI.pLevels[0]->GetWidth())/2),35,(REAL)m_level_gameUI.pLevels[0]->GetWidth(),(REAL)m_level_gameUI.pLevels[0]->GetHeight());

	//加载提交按钮图片
	m_level_gameUI.pNormalSubmit = new Bitmap(L"res\\Submit.png");
	m_level_gameUI.pSelectSubmit = new Bitmap(L"res\\SubmitSelect.png");

	m_level_gameUI.submitRect = RectF((REAL)(clientRect.Width - m_level_gameUI.pSelectSubmit->GetWidth()+7), 
		(REAL)(clientRect.Height - m_level_gameUI.pSelectSubmit->GetHeight()+10), 130,45);
	m_level_gameUI.isSelectSubmit = false;

	//加载返回按钮图形
	m_backUI.pNormalBack = new Bitmap(L"res\\Back.png");
	m_backUI.pSelectBack = new Bitmap(L"res\\BackSelect.png");
	m_backUI.backRect = RectF(10,(REAL)(clientRect.Height-m_backUI.pNormalBack->GetHeight()-5),(REAL)m_backUI.pNormalBack->GetWidth(),(REAL)m_backUI.pNormalBack->GetHeight());
	m_backUI.isSelect = false;

}

void CScene::LoadTrainChooseVertexsImg()
{
	m_trainModeUI.pBackground = new Bitmap(L"res\\TrainBk.png");

	//将选图顺序打乱
	int cur = 0;
	CString filePath;
	for (int i=0; i<LEVELNUM; i++)
	{
		if (i % 3 == 0)
		{
			filePath.Format(L"res\\Vertex\\%d.png", i+1);
			m_trainModeUI.vertexs[cur].pNormalVertex = new Bitmap(filePath);
			filePath.Format(L"res\\Vertex\\%d-单击.png", i+1);
			m_trainModeUI.vertexs[cur].pSelectVertex = new Bitmap(filePath);
			m_trainModeUI.vertexs[cur].level = i+1;
			m_trainModeUI.vertexs[cur].rectVertex = rectVertexs[cur];
			m_trainModeUI.vertexs[cur].isSelect = false;  
			cur++;
		}
	}
	for (int i=0; i<LEVELNUM; i++)
	{
		if (i % 3 == 1)
		{
			filePath.Format(L"res\\Vertex\\%d.png", i+1);
			m_trainModeUI.vertexs[cur].pNormalVertex = new Bitmap(filePath);
			filePath.Format(L"res\\Vertex\\%d-单击.png", i+1);
			m_trainModeUI.vertexs[cur].pSelectVertex = new Bitmap(filePath);
			m_trainModeUI.vertexs[cur].level = i+1;
			m_trainModeUI.vertexs[cur].rectVertex = rectVertexs[cur];
			m_trainModeUI.vertexs[cur].isSelect = false; 
			cur++;
		}
	}
	for (int i=0; i<LEVELNUM; i++)
	{
		if (i % 3 == 2)
		{
			filePath.Format(L"res\\Vertex\\%d.png", i+1);
			m_trainModeUI.vertexs[cur].pNormalVertex = new Bitmap(filePath);
			filePath.Format(L"res\\Vertex\\%d-单击.png", i+1);
			m_trainModeUI.vertexs[cur].pSelectVertex = new Bitmap(filePath);
			m_trainModeUI.vertexs[cur].level = i+1;
			m_trainModeUI.vertexs[cur].rectVertex = rectVertexs[cur];
			m_trainModeUI.vertexs[cur].isSelect = false; 
			cur++;
		}
	}

	m_trainModeUI.pNoramlBefore = new Bitmap(L"res\\Before.png");
	m_trainModeUI.pSelectBefore = new Bitmap(L"res\\BeforeSelect.png");
	m_trainModeUI.beforeRect = RectF(210,660,(REAL)m_trainModeUI.pNoramlBefore->GetWidth(),(REAL)m_trainModeUI.pNoramlBefore->GetHeight());
	m_trainModeUI.isBeforeSelect = false;

	m_trainModeUI.pNormalNext = new Bitmap(L"res\\Next.png");
	m_trainModeUI.pSelectNext = new Bitmap(L"res\\NextSelect.png");
	m_trainModeUI.nextRect = RectF(540,660,(REAL)m_trainModeUI.pNormalNext->GetWidth(),(REAL)m_trainModeUI.pNormalNext->GetHeight());
	m_trainModeUI.isNextSelect = false;

	for (int i=0; i<pageNum; i++)
	{
		filePath.Format(L"res\\page%d.png", i+1);
		m_trainModeUI.pPages.push_back(new Bitmap(filePath));
	}
	m_trainModeUI.pageRect = RectF(417,650,(REAL)m_trainModeUI.pPages[0]->GetWidth(),(REAL)m_trainModeUI.pPages[0]->GetHeight());
}

void CScene::LoadTrainGamingImg()
{
	m_train_gameUI.pBackground = new Bitmap(L"res\\Gaming.png");
	m_train_gameUI.pLevel = new Bitmap(L"res\\train.png");
	m_train_gameUI.levelRect =  RectF((REAL)((clientRect.Width-m_train_gameUI.pLevel->GetWidth())/2),35,(REAL)m_train_gameUI.pLevel->GetWidth(),(REAL)m_train_gameUI.pLevel->GetHeight());

	//加载提交按钮图片
	m_train_gameUI.pNormalSubmit = new Bitmap(L"res\\Submit.png");
	m_train_gameUI.pSelectSubmit = new Bitmap(L"res\\SubmitSelect.png");

	m_train_gameUI.submitRect = RectF((REAL)(clientRect.Width - m_train_gameUI.pSelectSubmit->GetWidth()+7), 
		(REAL)(clientRect.Height - m_train_gameUI.pSelectSubmit->GetHeight()+10), 130,45);
	m_train_gameUI.isSelectSubmit = false;

	//加载返回按钮图形
	m_backUI.pNormalBack = new Bitmap(L"res\\Back.png");
	m_backUI.pSelectBack = new Bitmap(L"res\\BackSelect.png");
	m_backUI.backRect = RectF(10,(REAL)(clientRect.Height-m_backUI.pNormalBack->GetHeight()-5),(REAL)m_backUI.pNormalBack->GetWidth(),(REAL)m_backUI.pNormalBack->GetHeight());
	m_backUI.isSelect = false;
}

void CScene::LoadPhotoVertexsImg()
{
	//加载头像和目标图形
	CString filePath;

	for (int i=0; i<LEVELNUM; i++)
	{
		filePath.Format(L"res\\Photo\\%d.png", i+1);
		m_photoUI.pPhotos.push_back(new Bitmap(filePath));
	}
	m_photoUI.photoRect = RectF(10, 50, (REAL)m_photoUI.pPhotos[0]->GetWidth(), (REAL)m_photoUI.pPhotos[0]->GetHeight());
}

void CScene::LoadGameSuccessImg()
{
	m_successUI.pBackground = new Bitmap(L"res\\Success\\Success.png");
	m_successUI.pNormalBack = new Bitmap(L"res\\Success\\Back.png");
	m_successUI.pNormalNext = new Bitmap(L"res\\Success\\Next.png");
	m_successUI.pSelectBack = new Bitmap(L"res\\Success\\SelectBack.png");
	m_successUI.pSelectNext = new Bitmap(L"res\\Success\\SelectNext.png");
	m_successUI.pNormalContinue = new Bitmap(L"res\\Success\\Continue.png");
	m_successUI.pSelectContinue = new Bitmap(L"res\\Success\\SelectContinue.png");

	m_successUI.backRect = RectF(375,430,(REAL)m_successUI.pNormalBack->GetWidth(),(REAL)m_successUI.pNormalBack->GetHeight());
	m_successUI.nextRect = RectF(375,500,(REAL)m_successUI.pNormalNext->GetWidth(),(REAL)m_successUI.pNormalNext->GetHeight());
	m_successUI.continueRect = RectF(375,500,(REAL)m_successUI.pNormalNext->GetWidth(),(REAL)m_successUI.pNormalNext->GetHeight());

	m_successUI.isSelectBack = false;
	m_successUI.isSelectNext = false;
	m_successUI.isSelectContinue = false;
}

void CScene::LoadGameFailureImg()
{
	m_failureUI.pBackground = new Bitmap(L"res\\Failure\\Failure.png");
	m_failureUI.pNormalBack = new Bitmap(L"res\\Failure\\Back.png");
	m_failureUI.pSelectBack = new Bitmap(L"res\\Failure\\SelectBack.png");
	m_failureUI.pNormalContinue = new Bitmap(L"res\\Failure\\Continue.png");
	m_failureUI.pSelectContinue = new Bitmap(L"res\\Failure\\SelectContinue.png");
	m_failureUI.backRect = RectF(365,400,(REAL)m_failureUI.pNormalBack->GetWidth(),(REAL)m_failureUI.pNormalBack->GetHeight());
	m_failureUI.continueRect = RectF(365,480,(REAL)m_failureUI.pNormalContinue->GetWidth(),(REAL)m_failureUI.pNormalContinue->GetHeight());
	m_failureUI.isSelectBack = false;
	m_failureUI.isSelectContinue = false;
}

UINT CScene::GetVertexNumByPage( UINT page )
{
	if (page >= pageNum)
	{
		return LEVELNUM % LEVELNUMPERPAGE;
	}
	
	return LEVELNUMPERPAGE;
}



