
// HiquView.cpp : CHiquView ���ʵ��
//

#include "stdafx.h"
#include "HIQU.h"
#include "HiquView.h"
#include "PlayMusic.h"

#define WM_INIT 101			//��ʼ����ͼ����Ϣ

//#ifdef _DEBUG
//#define new DEBUG_NEW
//#endif


// CHiquView

CHiquView::CHiquView()
	:bkBmp(L"res\\Gameing.png"),
	mainBmp(L"res\\Main.png"),
	chooseMode(L"res\\ChooseMode.png"),
	successBmp(L"res\\Success.png")
{
	m_bIsInit = false;
	isLBDown = false;
	m_bIsMove = false; 
	curPage = 1;
	mode = 0;
}

CHiquView::~CHiquView()
{
	delete pGraphics;
	delete pTempGraphics;
	delete pBitmap;
}

BEGIN_MESSAGE_MAP(CHiquView, CWnd)
	ON_WM_PAINT()
	ON_WM_CREATE()
	ON_MESSAGE(WM_INIT, &CHiquView::OnInitial)
	ON_WM_KEYUP()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
	ON_WM_LBUTTONDBLCLK()
	ON_WM_ERASEBKGND()
	ON_WM_TIMER()
	ON_WM_MOUSELEAVE()
END_MESSAGE_MAP()



// CHiquView ��Ϣ�������

BOOL CHiquView::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(NULL, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW+1), NULL);
	return TRUE;
}

void CHiquView::OnPaint() 
{
	CPaintDC dc(this); // ���ڻ��Ƶ��豸������

	if (m_bIsInit) OnRender(GetDC()->GetSafeHdc());
}

int CHiquView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	
	PostMessage(WM_INIT);

	return 0;

}

//��ʼ��
afx_msg LRESULT CHiquView::OnInitial(WPARAM wParam, LPARAM lParam)
{
	//��ʼ����ͼ��Դ
	InitDrawResource();
	
	//��ʼ��������
	m_scene.InitScene(this->GetSafeHwnd());

	//��ʼ����Ϸ״̬����Ч����
	mode = START;
	InitMusic();

	
	//��ʼ������ͼ��
	InitVtertexs();

	//�ػ�
	OnRender(GetDC()->GetSafeHdc());

	
	return 0;
}

//�Ҽ���תѡ��ͼ��
void CHiquView::OnRButtonUp(UINT nFlags, CPoint point)
{
	if (trangle.isInVertex(point))
	{
		trangle.Rotate();
		PlayKeyMusic();
		Invalidate(FALSE);
		CWnd::OnRButtonUp(nFlags, point);
		return;
	}
	if (smallTrapezoid.isInVertex(point))
	{
		smallTrapezoid.Rotate();
		PlayKeyMusic();
		Invalidate(FALSE);
		CWnd::OnRButtonUp(nFlags, point);
		return;
	}
	if (bigTrapezoid.isInVertex(point))
	{
		bigTrapezoid.Rotate();
		PlayKeyMusic();
		Invalidate(FALSE);
		CWnd::OnRButtonUp(nFlags, point);
		return;
	}
	if (pentagon.isInVertex(point))
	{
		pentagon.Rotate();
		PlayKeyMusic();
		Invalidate(FALSE);
		CWnd::OnRButtonUp(nFlags, point);
		return;
	}

	CWnd::OnRButtonUp(nFlags, point);
}

// �϶�ͼ�� �رճ��� ��С������ ���̱任
void CHiquView::OnLButtonDown(UINT nFlags, CPoint point)
{
	if(mode != SGL_LEVEL_GAME_SUCCESS  && mode != SGL_LEVEL_GAME_FAILURE && mode != SGL_TRAIN_GAME_SUCCESS && mode != SGL_TRAIN_GAME_FAILURE)
	{
		//������С���͹ر�
		OnMinClosed(point);

		//��Ч����
		SetMusicSwitch(point);
	}
	
	if (mode == START)
	{
		//���봳��ģʽ
		if (CTool::GetCRect(m_scene.m_startUI.levelModeRect).PtInRect(point))
		{
			mode = SGL_LEVEL_GAMING;
			CConfig::ReadRank(L"Config.ini", level);
			InitVtertexs();
			if (musicSwitch)
			{
				CPlayMusic::StopStartMusic();
				CPlayMusic::PlayGameMusic();
			}
			Invalidate(FALSE);
		}

		//������ϰģʽ
		if (CTool::GetCRect(m_scene.m_startUI.trainModeRect).PtInRect(point))
		{
			mode = SGL_TRAIN;
			//mode = SGL_TRAIN_GAMING;
			Invalidate(FALSE);
		}
	}	
	else if (mode == SGL_LEVEL_GAMING)
	{
		//������ذ�ť
		if (CTool::GetCRect(m_scene.m_backUI.backRect).PtInRect(point))
		{
			mode = START;
			if (musicSwitch)
			{
				CPlayMusic::StopGameMusic();
				CPlayMusic::PlayStartMusic();
			}
			Invalidate(FALSE);
		}

		//����ύ��ť
		if(CTool::GetCRect(m_scene.m_level_gameUI.submitRect).PtInRect(point))
		{
			if (validate.ValidateGraph(trangle,smallTrapezoid,bigTrapezoid,pentagon,level))
			{
				mode = SGL_LEVEL_GAME_SUCCESS;
				CConfig::WriteRank(L"Config.ini", level+1);
				if(musicSwitch)
				{
					CPlayMusic::StopGameMusic(); //�ر���Ϸ��������
					CPlayMusic::StopVictoryMusic();//�ر�ʤ������
					CPlayMusic::PlayVictoryMusic();//����ʤ������
				}
				Invalidate(FALSE);
			}
			else
			{
				mode = SGL_LEVEL_GAME_FAILURE;
				if(musicSwitch)
				{
					CPlayMusic::StopGameMusic(); //�ر���Ϸ��������
					CPlayMusic::StopFailureMusic();
					CPlayMusic::PlayFailureMusic();
				}
				Invalidate(FALSE);
				
			}
		}
	
		VertexLButtonDown(point);
	}
	else if (mode == SGL_TRAIN)
	{
		//��һҳ�����
		if (CTool::GetCRect(m_scene.m_trainModeUI.beforeRect).PtInRect(point))
		{
			if (curPage > 1)
			{
				curPage--;
			}
			Invalidate(FALSE);
		}

		//��һҳ�����
		if (CTool::GetCRect(m_scene.m_trainModeUI.nextRect).PtInRect(point))
		{
			if (curPage < m_scene.pageNum)
			{
				curPage++;
			}
			Invalidate(FALSE);
		}

		//���ر����
		if (CTool::GetCRect(m_scene.m_backUI.backRect).PtInRect(point))
		{
			mode = START;
			curPage = 1; //���³�ʼ��
			Invalidate(FALSE);
		}

		//Ŀ��ͼ�α����
		for (int i=(curPage-1)*LEVELNUM; i<(curPage-1)*LEVELNUM+m_scene.GetVertexNumByPage(curPage); i++)
		{
			if (CTool::GetCRect(m_scene.m_trainModeUI.vertexs[i].rectVertex).PtInRect(point))//��ֹ����ػ�
			{
				mode = SGL_TRAIN_GAMING;
				train_level = m_scene.m_trainModeUI.vertexs[i].level;
				InitVtertexs();
				if (musicSwitch)
				{
					CPlayMusic::StopStartMusic();
					CPlayMusic::PlayGameMusic();
				}
				Invalidate(FALSE);
				break;
			}
		}

	}
	else if (mode == SGL_TRAIN_GAMING)
	{
		//���ر����
		if (CTool::GetCRect(m_scene.m_backUI.backRect).PtInRect(point))
		{
			mode = SGL_TRAIN;
			curPage = 1; //���³�ʼ��
			if (musicSwitch)
			{
				CPlayMusic::StopGameMusic();
				CPlayMusic::PlayStartMusic();
			}
			Invalidate(FALSE);
		}

		//����ύ��ť
		if (CTool::GetCRect(m_scene.m_train_gameUI.submitRect).PtInRect(point))
		{
			if (validate.ValidateGraph(trangle, smallTrapezoid, bigTrapezoid, pentagon, train_level))
			{
				mode = SGL_TRAIN_GAME_SUCCESS;
				if(musicSwitch)
				{
					CPlayMusic::StopGameMusic(); //�ر���Ϸ��������
					CPlayMusic::StopVictoryMusic();//�ر�ʤ������
					CPlayMusic::PlayVictoryMusic();//����ʤ������
				}
				Invalidate(FALSE);
			}
			else
			{
				mode = SGL_TRAIN_GAME_FAILURE;
				if(musicSwitch)
				{
					CPlayMusic::StopGameMusic();//�ر���Ϸ��������
					CPlayMusic::StopFailureMusic();//�ر�ʧ������
					CPlayMusic::PlayFailureMusic();//����ʧ������
				}
				Invalidate(FALSE);
			}
		}

		VertexLButtonDown(point);
	}
	else if (mode == SGL_LEVEL_GAME_SUCCESS)
	{
		if (CTool::GetCRect(m_scene.m_successUI.backRect).PtInRect(point))
		{
			mode = START;
			if (musicSwitch)
			{
				CPlayMusic::StopGameMusic();
				CPlayMusic::PlayStartMusic();
			}
			Invalidate(FALSE);
		}
		else if (CTool::GetCRect(m_scene.m_successUI.nextRect).PtInRect(point)) //�����һ��
		{
			mode = SGL_LEVEL_GAMING;
			level++;
			InitVtertexs();
			Invalidate(FALSE);
		}
	}
	else if (mode == SGL_LEVEL_GAME_FAILURE)
	{
		if(CTool::GetCRect(m_scene.m_failureUI.backRect).PtInRect(point))//�������
		{
			mode = START;
			if (musicSwitch)
			{
				CPlayMusic::StopGameMusic();
				CPlayMusic::PlayStartMusic();
			}
			Invalidate(FALSE);
		}
		else if(CTool::GetCRect(m_scene.m_failureUI.continueRect).PtInRect(point))//�������
		{
			mode = SGL_LEVEL_GAMING;
			if(musicSwitch)
			{
				CPlayMusic::PlayGameMusic();
			}
			Invalidate(FALSE);
		}
	}
	else if(mode == SGL_TRAIN_GAME_SUCCESS)
	{
		if (CTool::GetCRect(m_scene.m_successUI.backRect).PtInRect(point))//�������
		{
			mode = SGL_TRAIN;
			if (musicSwitch)
			{
				CPlayMusic::StopGameMusic();
				CPlayMusic::PlayStartMusic();
			}
			Invalidate(FALSE);
		}
		else if (CTool::GetCRect(m_scene.m_successUI.continueRect).PtInRect(point))//�������
		{
			mode = SGL_TRAIN_GAMING;
			if (musicSwitch)
			{
				CPlayMusic::PlayGameMusic();
			}
			Invalidate(FALSE);
		}
	}
	else if(mode == SGL_TRAIN_GAME_FAILURE)
	{
		if(CTool::GetCRect(m_scene.m_failureUI.backRect).PtInRect(point))//�������
		{
			mode = SGL_TRAIN;
			if (musicSwitch)
			{
				CPlayMusic::StopGameMusic();
				CPlayMusic::PlayStartMusic();
			}
			Invalidate(FALSE);
		}
		else if(CTool::GetCRect(m_scene.m_failureUI.continueRect).PtInRect(point))//�������
		{
			mode = SGL_TRAIN_GAMING;
			if (musicSwitch)
			{
				CPlayMusic::PlayGameMusic();
			}
			Invalidate(FALSE);
		}
	}
	 
	//�϶�����
	CRect rect(0,0,760,40);
	if (rect.PtInRect(point))
	{
		m_bIsMove = true; 
		m_CenterPt = point; 
	}
	  

	CWnd::OnLButtonDown(nFlags, point);
}

void CHiquView::OnMouseMove(UINT nFlags, CPoint point)
{
	//����mouseleave��Ӧ
	TRACKMOUSEEVENT trackm;  
	ZeroMemory(&trackm, sizeof TRACKMOUSEEVENT);  
	trackm.cbSize = sizeof TRACKMOUSEEVENT;  
	trackm.dwFlags = TME_HOVER | TME_LEAVE;  
	trackm.hwndTrack = m_hWnd;  
	trackm.dwHoverTime = 10;
	TrackMouseEvent(&trackm); 

	SetCapture();

	if(mode != SGL_LEVEL_GAME_SUCCESS  && mode != SGL_LEVEL_GAME_FAILURE && mode != SGL_TRAIN_GAME_SUCCESS && mode != SGL_TRAIN_GAME_FAILURE)
	{
		MinCloseMusicHover(point);
	}

	if (mode == START)
	{
		StartGameHover(point);
	}
	else if(mode == SGL_LEVEL_GAMING)
	{
		LevelGamingHover(point);
	}
	else if (mode == SGL_TRAIN)
	{
		ChooseVertexsHover(point);
	}
	else if (mode == SGL_TRAIN_GAMING)
	{
		TrainGamingHover(point);
	}
	else if (mode == SGL_LEVEL_GAMING)
	{
		GameSuccessHover(point);
	}
	else if (mode == SGL_LEVEL_GAME_SUCCESS || mode == SGL_TRAIN_GAME_SUCCESS)
	{
		GameSuccessHover(point);
	}
	else if (mode == SGL_LEVEL_GAME_FAILURE || mode == SGL_TRAIN_GAME_FAILURE)
	{
		GameFailureHover(point);
	}
	 

	VertexMove(point);

	DockWindow(point);

	CWnd::OnMouseMove(nFlags, point);
}

void CHiquView::OnLButtonUp(UINT nFlags, CPoint point)
{
	if (isLBDown)
	{
		isLBDown = false;
	}
	if (m_bIsMove)
	{
		 m_bIsMove = false; 
	}
	CWnd::OnLButtonUp(nFlags, point);
}

// ˫����תͼ��
void CHiquView::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	if (trangle.isInVertex(point))
	{
		trangle.Reverse();
		PlayKeyMusic();
		Invalidate(FALSE);
	}
	else if (smallTrapezoid.isInVertex(point))
	{
		smallTrapezoid.Reverse();
		PlayKeyMusic();
		Invalidate(FALSE);
	}
	else if (bigTrapezoid.isInVertex(point))
	{
		bigTrapezoid.Reverse();
		PlayKeyMusic();
		Invalidate(FALSE);
	}
	else if (pentagon.isInVertex(point))
	{
		pentagon.Reverse();
		PlayKeyMusic();
		Invalidate(FALSE);
	}

	CWnd::OnLButtonDblClk(nFlags, point);
}

//
BOOL CHiquView::OnEraseBkgnd(CDC* pDC)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	return TRUE;
	//return CWnd::OnEraseBkgnd(pDC);
}

//
void CHiquView::OnRender(HDC hdc)
{
 	if (mode == START) //��Ϸ��ʼ����
	{
		m_scene.DrawStartUI(pTempGraphics, musicSwitch);  //������Ϸ��ʼ����
	}
	else if (mode == SGL_LEVEL)
	{
		//pGraphics->DrawImage(&chooseMode, Rect(rect.left, rect.top, rect.Width(), rect.Height()));
	}
	else if (mode == SGL_LEVEL_GAMING || mode == SGL_LEVEL_GAME_SUCCESS || mode == SGL_LEVEL_GAME_FAILURE)
	{
		m_scene.DrawLevelGameUI(pTempGraphics, musicSwitch, level);
		pentagon.Draw(pTempGraphics);
		bigTrapezoid.Draw(pTempGraphics);
		smallTrapezoid.Draw(pTempGraphics);
		trangle.Draw(pTempGraphics);
		if(mode == SGL_LEVEL_GAME_SUCCESS)
		{
			m_scene.DrawGameSuccessUI(pTempGraphics, TRUE);
		}
		if (mode == SGL_LEVEL_GAME_FAILURE)
		{
			m_scene.DrawGameFailureUI(pTempGraphics);
		}
	}
	else if (mode == SGL_TRAIN)
	{
		m_scene.DrawTrainChooseVertex(pTempGraphics, musicSwitch, curPage);
	}
	else if(mode == SGL_TRAIN_GAMING || mode == SGL_TRAIN_GAME_SUCCESS || mode == SGL_TRAIN_GAME_FAILURE)
	{
		m_scene.DrawTrainGameUI(pTempGraphics, musicSwitch, train_level);
		pentagon.Draw(pTempGraphics);
		bigTrapezoid.Draw(pTempGraphics);
		smallTrapezoid.Draw(pTempGraphics);
		trangle.Draw(pTempGraphics);
		if(mode == SGL_TRAIN_GAME_SUCCESS)
		{
			m_scene.DrawGameSuccessUI(pTempGraphics, FALSE);
		}
		if (mode == SGL_TRAIN_GAME_FAILURE)
		{
			m_scene.DrawGameFailureUI(pTempGraphics);
		}
	}

	CachedBitmap cacheBitmap(pBitmap, this->pGraphics);
	this->pGraphics->DrawCachedBitmap(&cacheBitmap,0,0);
	this->pGraphics->ReleaseHDC(GetDC()->GetSafeHdc());
}


void CHiquView::OnMouseLeave()
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	m_bIsMove = false;
	lbDown = false;
	CWnd::OnMouseLeave();
}

void CHiquView::InitDrawResource()
{
	//��ʼ���ػ�����Ҫ����Դ ����ÿ�ζ���д����  ���Ч��
	CRect rect;
	GetClientRect(&rect);
	pGraphics = new Graphics(this->GetSafeHwnd());
	pBitmap = new Bitmap(rect.Width(), rect.Height());
	pTempGraphics = Graphics::FromImage(pBitmap);
	m_bIsInit = true;
}

void CHiquView::InitMusic()
{
	if(CConfig::ReadMusicSwitch(L"Config.ini", musicSwitch))
	{
		if (musicSwitch)
		{
			CPlayMusic::PlayStartMusic();
		}
	}
	else
	{
		MessageBox(L"�����ļ�������");
	}
}

void CHiquView::InitVtertexs()
{
	//��ʼ��ͼ��
	pentagon.Init(PointF(580, 640), PointF(660, 560), PointF(772, 560), PointF(749, 583), PointF(806, 640), 0, GetDC()->GetSafeHdc());
	smallTrapezoid.Init(PointF(190,560),PointF(190,640),PointF(303,640),PointF(223,560), 0, GetDC()->GetSafeHdc(), true);
	bigTrapezoid.Init(PointF(580,210),PointF(580,290),PointF(806,290),PointF(726,210), 0, GetDC()->GetSafeHdc(), false);
	trangle.Init(PointF(190, 210), PointF(190, 290), PointF(270, 290), 0, GetDC()->GetSafeHdc());
}

void CHiquView::OnMinClosed( CPoint point )
{
	if (CTool::GetCRect(m_scene.m_minUI.minRect).PtInRect(point)) //�����С����ť
	{
		::ShowWindow(this->GetParentFrame()->GetSafeHwnd(), SW_SHOWMINIMIZED);
	}
	else if (CTool::GetCRect(m_scene.m_closeUI.closeRect).PtInRect(point)) //����رհ�ť
	{
		this->GetParentFrame()->PostMessageW(WM_CLOSE);
	}
}

void CHiquView::SetMusicSwitch( CPoint point )
{
	//��Ч����
	if (CTool::GetCRect(m_scene.m_volUI.volRect).PtInRect(point))
	{
		if (musicSwitch)
		{
			if (mode == START || mode == SGL_LEVEL || mode == SGL_TRAIN)
			{
				CPlayMusic::StopStartMusic();
			}
			else if (mode == SGL_LEVEL_GAMING || mode == SGL_TRAIN_GAMING)
			{
				CPlayMusic::StopGameMusic();
			}
		}
		else
		{
			if (mode == START || mode == SGL_LEVEL || mode == SGL_TRAIN)
			{
				CPlayMusic::PlayStartMusic();
			}
			else if (mode == SGL_LEVEL_GAMING || mode == SGL_TRAIN_GAMING)
			{
				CPlayMusic::PlayGameMusic();
			}
		}
		musicSwitch = !musicSwitch;
		CConfig::WriteMusicSwitch(L"Config.ini", musicSwitch);
		Invalidate(FALSE);
	}
}

void CHiquView::MinCloseMusicHover( CPoint point )
{
	//�رհ�ť
	if (CTool::GetCRect(m_scene.m_closeUI.closeRect).PtInRect(point))
	{
		if (!m_scene.m_closeUI.isSelect) //��ֹ����ػ�
		{
			m_scene.m_closeUI.isSelect = true;
			Invalidate(FALSE);
			PlayKeyMusic();
		}
	}
	else if(m_scene.m_closeUI.isSelect)//��ֹ����ػ�
	{
		m_scene.m_closeUI.isSelect = false;
		Invalidate(FALSE); 
	}

	//���»���ť
	if(CTool::GetCRect(m_scene.m_minUI.minRect).PtInRect(point))
	{
		if (!m_scene.m_minUI.isSelect)//��ֹ����ػ�
		{
			m_scene.m_minUI.isSelect = true;
			Invalidate(FALSE);
			PlayKeyMusic();
		}
	}
	else if(m_scene.m_minUI.isSelect)//��ֹ����ػ�
	{
		m_scene.m_minUI.isSelect = false;
		Invalidate(FALSE);
	}

	//�������ð�ť
	if (CTool::GetCRect(m_scene.m_volUI.volRect).PtInRect(point))
	{
		if (!m_scene.m_volUI.isSelect)//��ֹ����ػ�
		{
			m_scene.m_volUI.isSelect = true;
			Invalidate(FALSE);
			PlayKeyMusic();
		}
	}
	else if(m_scene.m_volUI.isSelect)//��ֹ����ػ�
	{
		m_scene.m_volUI.isSelect = false;
		Invalidate(FALSE);
	}
}

void CHiquView::StartGameHover( CPoint point )
{
	if (CTool::GetCRect(m_scene.m_startUI.levelModeRect).PtInRect(point))
	{ 
		if (!m_scene.m_startUI.isSelectLevel)//��ֹ����ػ�
		{
			m_scene.m_startUI.isSelectLevel = true;
			Invalidate(FALSE);
			PlayKeyMusic();
		}
	}
	else if (m_scene.m_startUI.isSelectLevel)//��ֹ����ػ�
	{
		m_scene.m_startUI.isSelectLevel = false;
		Invalidate(FALSE);

	}

	if (CTool::GetCRect(m_scene.m_startUI.trainModeRect).PtInRect(point))
	{
		if (!m_scene.m_startUI.isSelectTrain)//��ֹ����ػ�
		{
			m_scene.m_startUI.isSelectTrain = true;
			Invalidate(FALSE);
			PlayKeyMusic();
		}
	}
	else if(m_scene.m_startUI.isSelectTrain)//��ֹ����ػ�
	{
		m_scene.m_startUI.isSelectTrain = false;
		Invalidate(FALSE);
	}
}

void CHiquView::LevelGamingHover( CPoint point )
{
	if(CTool::GetCRect(m_scene.m_level_gameUI.submitRect).PtInRect(point))
	{
		if (!m_scene.m_level_gameUI.isSelectSubmit)//��ֹ����ػ�
		{
			m_scene.m_level_gameUI.isSelectSubmit = true;
			Invalidate(FALSE);
			PlayKeyMusic();
		}
	}
	else if(m_scene.m_level_gameUI.isSelectSubmit)//��ֹ����ػ�
	{
		m_scene.m_level_gameUI.isSelectSubmit = false;
		Invalidate(FALSE);
	}
	
	BackHover(point);
}

void CHiquView::TrainGamingHover( CPoint point )
{
	if(CTool::GetCRect(m_scene.m_train_gameUI.submitRect).PtInRect(point))
	{
		if (!m_scene.m_train_gameUI.isSelectSubmit)//��ֹ����ػ�
		{
			m_scene.m_train_gameUI.isSelectSubmit = true;
			Invalidate(FALSE);
			PlayKeyMusic();
		}
	}
	else if(m_scene.m_train_gameUI.isSelectSubmit)//��ֹ����ػ�
	{
		m_scene.m_train_gameUI.isSelectSubmit = false;
		Invalidate(FALSE);
	}

	BackHover(point);
}

void CHiquView::GameSuccessHover( CPoint point )
{
	if (CTool::GetCRect(m_scene.m_successUI.backRect).PtInRect(point))
	{
		if (!m_scene.m_successUI.isSelectBack)//��ֹ����ػ�
		{
			m_scene.m_successUI.isSelectBack = true;
			Invalidate(FALSE);
			PlayKeyMusic();
		}
	}
	else if (m_scene.m_successUI.isSelectBack)//��ֹ����ػ�
	{
		m_scene.m_successUI.isSelectBack = false;
		Invalidate(FALSE);
	}

	if (mode == SGL_LEVEL_GAME_SUCCESS)
	{
		if (CTool::GetCRect(m_scene.m_successUI.nextRect).PtInRect(point))
		{
			if(!m_scene.m_successUI.isSelectNext)
			{
				m_scene.m_successUI.isSelectNext = true;
				Invalidate(FALSE);
				PlayKeyMusic();
			}
		}
		else if(m_scene.m_successUI.isSelectNext)
		{
			m_scene.m_successUI.isSelectNext = false;
			Invalidate(FALSE);
		}
	}
	else if(mode == SGL_TRAIN_GAME_SUCCESS)
	{
		if(CTool::GetCRect(m_scene.m_successUI.continueRect).PtInRect(point))
		{
			if(!m_scene.m_successUI.isSelectContinue)
			{
				m_scene.m_successUI.isSelectContinue = true;
				Invalidate(FALSE);
				PlayKeyMusic();
			}
			else if(m_scene.m_successUI.isSelectContinue)
			{
				m_scene.m_successUI.isSelectContinue = false;
				Invalidate(FALSE);
			}
		}
	}
}

void CHiquView::GameFailureHover( CPoint point )
{
	if(CTool::GetCRect(m_scene.m_failureUI.backRect).PtInRect(point))
	{
		if (!m_scene.m_failureUI.isSelectBack)
		{
			m_scene.m_failureUI.isSelectBack = true;
			Invalidate(FALSE);
			PlayKeyMusic();
		}
	}
	else if (m_scene.m_failureUI.isSelectBack)
	{
		m_scene.m_failureUI.isSelectBack = false;
		Invalidate(FALSE);
	}

	if (CTool::GetCRect(m_scene.m_failureUI.continueRect).PtInRect(point))
	{
		if (!m_scene.m_failureUI.isSelectContinue)
		{
			m_scene.m_failureUI.isSelectContinue = true;
			Invalidate(FALSE);
			PlayKeyMusic();
		}
	}
	else if (m_scene.m_failureUI.isSelectContinue)
	{
		m_scene.m_failureUI.isSelectContinue = false;
		Invalidate(FALSE);
	}
}

void CHiquView::BackHover( CPoint point )
{
	if(CTool::GetCRect(m_scene.m_backUI.backRect).PtInRect(point))
	{
		if (!m_scene.m_backUI.isSelect)//��ֹ����ػ�
		{
			m_scene.m_backUI.isSelect = true;
			Invalidate(FALSE);
			PlayKeyMusic();
		}	
	}
	else if(m_scene.m_backUI.isSelect)//��ֹ����ػ�
	{
		m_scene.m_backUI.isSelect = false;
		Invalidate(FALSE);
	}
}

void CHiquView::ChooseVertexsHover( CPoint point )
{
	//��һҳ����˹�����
	if (CTool::GetCRect(m_scene.m_trainModeUI.beforeRect).PtInRect(point))
	{
		if (!m_scene.m_trainModeUI.isBeforeSelect)//��ֹ����ػ�
		{
			m_scene.m_trainModeUI.isBeforeSelect = true;
			Invalidate(FALSE);
			PlayKeyMusic();
		}
	}
	else if(m_scene.m_trainModeUI.isBeforeSelect)
	{
		m_scene.m_trainModeUI.isBeforeSelect = false;
		Invalidate(FALSE);
	}

	//��һҳ����˹�����
	if (CTool::GetCRect(m_scene.m_trainModeUI.nextRect).PtInRect(point))
	{
		if (!m_scene.m_trainModeUI.isNextSelect)//��ֹ����ػ�
		{
			m_scene.m_trainModeUI.isNextSelect = true;
			Invalidate(FALSE);
			PlayKeyMusic();
		}
	}
	else if(m_scene.m_trainModeUI.isNextSelect)
	{
		m_scene.m_trainModeUI.isNextSelect = false;
		Invalidate(FALSE);
	}

	for (int i=(curPage-1)*LEVELNUM; i<(curPage-1)*LEVELNUM+m_scene.GetVertexNumByPage(curPage); i++)
	{
		bool flag  = false;	 //��־�Ƿ����Ѿ��˹���ͼ��
		if (CTool::GetCRect(m_scene.m_trainModeUI.vertexs[i].rectVertex).PtInRect(point))//��ֹ����ػ�
		{
			if (!m_scene.m_trainModeUI.vertexs[i].isSelect)
			{
				m_scene.m_trainModeUI.vertexs[i].isSelect = true;
				Invalidate(FALSE);
				PlayKeyMusic();
			}
			flag = true;
		}
		else if (m_scene.m_trainModeUI.vertexs[i].isSelect)
		{
			m_scene.m_trainModeUI.vertexs[i].isSelect = false;
			Invalidate(FALSE);
		}

		if (flag)//�Լ����˹���ͼ�� �������ѭ��
		{
			break;
		}
	}

	BackHover(point);
}

void CHiquView::DockWindow( CPoint point )
{
	//�ƶ�����
	if   (m_bIsMove)   
	{   
		//��ȡ�ƶ�ƫ����   
		int  nX = point.x - m_CenterPt.x;   
		int  nY = point.y - m_CenterPt.y;   

		//���ڴ����ƶ�״̬   
		CRect  rect;
		GetWindowRect(&rect);   
		rect.OffsetRect(nX,nY);

		//�жϴ����Ƿ��Ƴ�����Ļ��
		int screenwidth_real=GetSystemMetrics(SM_CXSCREEN);
		int screenheight_real=GetSystemMetrics(SM_CYSCREEN);
		if (rect.top>screenheight_real-100||rect.right<200||rect.left>screenwidth_real-100)
		{
			return;
		}

		GetParentFrame()->SetWindowPos(NULL, rect.left, rect.top, rect.Width(), rect.Height(), SWP_NOSIZE);  
	}
}

void CHiquView::VertexMove( CPoint point )
{
	if (isLBDown)
	{
		if (abs(point.x-lbDown.x)>1 || abs(point.y-lbDown.y)>1)
		{
			switch(selectedVertex)
			{
			case TRANGLE:
				{
					trangle.Move(point.x-lbDown.x,point.y-lbDown.y);
					break;
				}
			case SMALLTRAPE:
				{
					smallTrapezoid.Move(point.x-lbDown.x,point.y-lbDown.y);
					break;
				}
			case BIGTRAPE:
				{
					bigTrapezoid.Move(point.x-lbDown.x,point.y-lbDown.y);
					break;
				}
			case PENTAGON:
				{	
					pentagon.Move(point.x-lbDown.x,point.y-lbDown.y);
					break;
				}
			}

			Invalidate(FALSE);
			lbDown = point;
		}
	}
}

void CHiquView::PlayKeyMusic()
{
	if (musicSwitch)//������갴������
	{
		CPlayMusic::StopKeyMusic();
		CPlayMusic::PlayKeyMusic();
	}
}
           
void CHiquView::VertexLButtonDown( CPoint point )
{
	if (pentagon.isInVertex(point))
	{
		selectedVertex = PENTAGON;
		isLBDown = true;
		lbDown = point;
	}
	if (bigTrapezoid.isInVertex(point))
	{
		selectedVertex = BIGTRAPE;
		isLBDown = true;
		lbDown = point;
	}
	if (smallTrapezoid.isInVertex(point))
	{
		selectedVertex = SMALLTRAPE;
		isLBDown = true;
		lbDown = point;
	}
	if (trangle.isInVertex(point))
	{
		selectedVertex = TRANGLE;
		isLBDown = true;
		lbDown = point;
	}
}


