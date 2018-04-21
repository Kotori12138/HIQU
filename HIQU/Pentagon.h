#pragma once
//#include "gdiplustypes.h"
class CPentagon
{
public:
	CPentagon(void);
	~CPentagon(void);

	Rect drawRect;	//����ͼ�ε�λ��

	// ��ʼ�������
	void Init(PointF A, PointF B, PointF C, PointF D, PointF E,USHORT angle, HDC hDc);
	// �ƶ�
	void Move(int offsetX, int offsetY);
	// ��ת
	void Reverse(void);
	// ˳ʱ����ת45��
	void Rotate(void);
	// DrawPentagon
	void Draw(Graphics *bkGraphics);
	// �жϵ��Ƿ����������
	bool isInVertex(CPoint point);

	//
	PointF GetPointA();
	PointF GetPointB();
	PointF GetPointC();
	PointF GetPointD();
	PointF GetPointE();

private:
	PointF A;
	PointF B;
	PointF C;
	PointF D;
	PointF E;
	bool isFront;	//ͼ���������� true-��
	USHORT angle;	//�����Ƕ�
	Bitmap* pBmp;	//Ҫ���Ƶ�ͼ��
	HDC hDc;		//�ڴ�DC
	Graphics *pGraphics;
};

