
// HiquView.h : CHiquView ��Ľӿ�
//


#pragma once
#include "Trangle.h"
#include "Pentagon.h"
#include "Trapezoid.h"
#include "Validate.h"
#include "Scene.h"
#include "Config.h"


// CHiquView ����
enum GameMode
{
	START = 0,					//��Ϸ��ʼ����
	SGL_LEVEL = 1,				//��Ϸ����ģʽ 
	SGL_LEVEL_GAMING = 2,		//����ģʽ ��Ϸ����
	SGL_TRAIN = 3,				//��������ϰģʽ
	SGL_TRAIN_GAMING = 4,		//��������ϰģʽ ��Ϸ����
	SGL_LEVEL_GAME_SUCCESS = 5,	//������Ϸ ��Ϸ�ɹ� 
	SGL_LEVEL_GAME_FAILURE = 6,		//������Ϸ ��Ϸʧ��
	SGL_TRAIN_GAME_SUCCESS = 7,	//��ϰģʽ��Ϸ�ɹ�
	SGL_TRAIN_GAME_FAILURE = 8,//��ϰģʽ ��Ϸʧ��
};

enum Vertex
{
	TRANGLE = 0,	  //������
	SMALLTRAPE = 1,   //С�ı���
	BIGTRAPE = 2,	  //���ı���
	PENTAGON = 3	  //�����
};

class CHiquView : public CWnd
{
// ����
public:
	CHiquView();
// ʵ��
public:
	virtual ~CHiquView();

// ��д
protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

private:

	CScene m_scene;					//�����������

	CTrangle trangle;				//��������
	CPentagon pentagon;				//�������
	CTrapezoid smallTrapezoid;		//С������
	CTrapezoid bigTrapezoid;		//��������
	Bitmap bkBmp;					//����ͼƬ
	Bitmap mainBmp;					//������
	Bitmap chooseMode;				//ģʽѡ��
	Bitmap successBmp;				//�ɹ�����
	byte selectedVertex;			//ѡ��ͼ�� 
	bool isLBDown;					//����Ƿ���
	CPoint lbDown;					//��¼�������λ��
	CValidate validate;				//��֤ͼ��
	UINT level;						//ͨ��ģʽ��ǰ����
	UINT train_level;				//ѡͼģʽ��ǰĿ��ͼ�ζ�Ӧ�Ĺؿ�
	byte mode;						//���̿���  
	Graphics *pGraphics;			//�ػ�����ͼ��
	Graphics *pTempGraphics;		//�ػ滺���ͼ��
	Bitmap *pBitmap;
	BOOL   m_bIsMove;                 //�Ƿ����ƶ�״̬   
	CPoint   m_CenterPt;           //�ƶ������� 
	bool musicSwitch;				//��Ϸ��Ч����
	UINT curPage;					//ѡͼ�ĵ�ǰҳ��


	// ���ɵ���Ϣӳ�亯��
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
	//�ػ溯��
	void OnRender(HDC hdc);

	//��ʼ����ͼ��Դ
	void InitDrawResource();

	//��ʼ����Ч����  �����ļ��л�ȡ
	void InitMusic();

	//��ʼ����Ϸ����ͼ��
	void InitVtertexs();

	//�������»��͹ر�
	void OnMinClosed(CPoint point);

	//��Ч����
	void SetMusicSwitch(CPoint point);
	
	//���»����ر� �������� ����˹�
	void MinCloseMusicHover(CPoint point);

	//��Ϸ������������˹�����
	void StartGameHover(CPoint point);

	//������Ϸ���н�������˹�����
	void LevelGamingHover(CPoint point);

	//��ϰģʽ��Ϸ���н�������˹�����
	void TrainGamingHover(CPoint point);

	//���ؼ�����˹�����
	void BackHover(CPoint point);

	//��Ϸ��ϰģʽѡͼ��������˹�����
	void ChooseVertexsHover(CPoint point);

	//��Ϸ�ɹ����� ����˹�����
	void GameSuccessHover(CPoint point);

	//��Ϸʧ�ܽ��� ����˹�����
	void GameFailureHover(CPoint point);

	//�����ק���ڴ���
	void DockWindow(CPoint point);
	
	//ͼ���ƶ�
	void VertexMove(CPoint point);

	//��������˹� ͼ�η�ת ��ת����
	void PlayKeyMusic();

	//����ͼ�����������´���
	void VertexLButtonDown(CPoint point);

	//�Ƿ��ʼ����Դ
	bool m_bIsInit;
public:
	afx_msg void OnMouseLeave();
};

