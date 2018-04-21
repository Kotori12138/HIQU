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

	//��Ϸ�������ð�ť
	struct StructVolConfig
	{
		Bitmap* pNormalVol;
		Bitmap* pSelectVol;
		Bitmap* pNormalNoVal;
		Bitmap* pSelectNoVol;
		RectF volRect;
		bool isSelect;
	}m_volUI;

	//��Ϸ������С����ť
	struct StructMinUI
	{
		Bitmap* pNormalMin;
		Bitmap* pSelectMin;
		RectF minRect;
		bool isSelect;
	}m_minUI;

	//��Ϸ������󻯰�ť
	struct StructCloseUI
	{
		Bitmap* pNormalClose;
		Bitmap* pSelectClose;
		RectF closeRect;
		bool isSelect;
	}m_closeUI;

	//��Ϸ���ؼ�ͼƬ
	struct StructBack
	{
		Bitmap* pNormalBack;
		Bitmap* pSelectBack;
		RectF backRect;
		bool isSelect;
	}m_backUI;

	//ͷ��ͼƬ
	struct StructPhoto
	{
		vector<Bitmap*> pPhotos;
		RectF photoRect;
	}m_photoUI;

	//ѡͼͼ��ͼƬ
	struct StructVertex
	{
		Bitmap* pNormalVertex;
		Bitmap* pSelectVertex;
		RectF rectVertex;                  
		UINT level;				//��Ӧ�Ĺؿ���
		bool isSelect;
	};

	//��ϰģʽѡ��ͼ�ν���
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


	//��ʼ��Ϸ����ͼƬ
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
	

	//�ؿ�ģʽ��Ϸ����ͼ��
	struct StructLevelGame
	{
		Bitmap* pBackground;	//����ͼƬ
		vector<Bitmap*> pLevels;		//�ؿ�ͼƬ
		Bitmap* pNormalSubmit;	//�ύͼƬ Ĭ��
		Bitmap* pSelectSubmit;	//�ύͼƬ ѡ��
		RectF levelRect;		//�ؿ�ͼƬճ������
		RectF submitRect;		//�ύͼƬճ������
		bool isSelectSubmit;	//�ύͼƬ�Ƿ�ѡ��
	}m_level_gameUI;

	struct StructTrainGame
	{
		Bitmap* pBackground; //����ͼƬ
		Bitmap* pLevel;		//�ؿ�ͼƬ
		Bitmap* pNormalSubmit;	//�ύͼƬ Ĭ��
		Bitmap* pSelectSubmit;	//�ύͼƬ ѡ��
		RectF levelRect;		//�ؿ�ͼƬճ������
		RectF submitRect;		//�ύͼƬճ������
		bool isSelectSubmit;	//�ύͼƬ�Ƿ�ѡ��
	}m_train_gameUI;

	struct StructSuccess
	{
		Bitmap* pBackground;		//����ͼƬ
		Bitmap* pNormalBack;		//���ؼ�
		Bitmap* pSelectBack;		//ѡ�з��ؼ�
		Bitmap* pNormalNext;		//��һ��
		Bitmap* pSelectNext;		//ѡ����һ��
		Bitmap* pNormalContinue;	//������ťͼƬ
		Bitmap* pSelectContinue;	//ѡ�������ťͼƬ
		RectF backRect;				//���ؼ�����
		RectF nextRect;				//��һ�ؼ�����	
		RectF continueRect;			//����������
		bool isSelectBack;			//���ؼ��Ƿ�ѡ��
		bool isSelectNext;			//��һ�ؼ��Ƿ�ѡ��
		bool isSelectContinue;		//��������ťѡ��
	}m_successUI;

	struct StructFailure
	{
		Bitmap* pBackground;		//����ͼƬ	
		Bitmap* pNormalBack;		//���ؼ�
		Bitmap* pSelectBack;		//ѡ�з��ؼ�
		Bitmap* pNormalContinue;	//������ťͼƬ
		Bitmap* pSelectContinue;	//ѡ�м�����ťͼƬ
		RectF backRect;				//���ؼ�����
		RectF continueRect;			//����������
		bool isSelectBack;			//���ؼ��Ƿ�ѡ��
		bool isSelectContinue;		//��������ťѡ��
	}m_failureUI;

	UINT pageNum;

	//��ʼ����Ϸ����
	void InitScene(HWND hWnd);
	
	//������Ϸ��ʼ����
	void DrawStartUI(Graphics* pGraphics, bool hasVol);
	
	//������Ϸѡ�ؽ���
	void DrawChooseModeUI(Graphics* pGraphics, bool hasVol);

	//���ƴ�����Ϸ�����н���
	void DrawLevelGameUI(Graphics* pGraphics,  bool hasVol, UINT level);

	//������Ϸѡͼ����
	void DrawTrainChooseVertex(Graphics* pGraphics, bool hasVol, UINT page);

	//������ϰģʽ����
	void DrawTrainGameUI(Graphics* pGraphics, bool hasVol, UINT level);

	//������Ϸ�ɹ�����  type true��ʾ���سɹ����� false��ʾʧ�ܳɹ�����
	void DrawGameSuccessUI(Graphics* pGraphics, bool type);

	//������Ϸʧ�ܽ���
	void DrawGameFailureUI(Graphics* pGraphics);

	//��ȡѡͼͼ��ÿҳ��ͼ�θ���
	UINT GetVertexNumByPage(UINT page);

private:

	//�����������ð�ťͼƬ
	void LoadVolSetingImg();

	//�������»��͹رհ�ťͼƬ
	void LoadMinCloseImg();

	//���ؿ�ʼ��Ϸ����ͼƬ
	void LoadStartGameImg();

	//���ش�����Ϸ���н���ͼƬ
	void LoadLevelGamingImg();

	//����ͷ���Ŀ��ͼ��ͼƬ
	void LoadPhotoVertexsImg();

	//������ϰģʽѡͼ����ͼƬ
	void LoadTrainChooseVertexsImg();

	//������ϰģʽ��Ϸ����ͼƬ
	void LoadTrainGamingImg();

	//���سɹ�����ͼƬ
	void LoadGameSuccessImg();

	//������Ϸʧ�ܽ���ͼƬ
	void LoadGameFailureImg();

	//���ƹرպ���С����ť
	void DrawMinCloseUI(Graphics* pGraphics);

	

};

