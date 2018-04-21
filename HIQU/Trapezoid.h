#pragma once
class CTrapezoid
{
public:
	CTrapezoid(void);
	~CTrapezoid(void);

	Rect drawRect;	//����ͼ�ε�λ��

	// ��ʼ������
	void Init(PointF A, PointF B, PointF C, PointF D, USHORT angle, HDC hDc, bool type);
	// �ƶ�
	void Move(int offsetX, int offsetY);
	// ��ת
	void Reverse(void);
	// ˳ʱ����ת45��
	void Rotate(void);
	// DrawTrapezoid
	void Draw(Graphics *bkGraphics);
	// �жϵ��Ƿ���������
	bool isInVertex(CPoint point);

	PointF GetPointA();
	PointF GetPointB();
	PointF GetPointC();
	PointF GetPointD();

private:
	PointF A;
	PointF B;
	PointF C;
	PointF D;
	bool isFront;	//ͼ���������� true-��
	USHORT angle;	//�����Ƕ�
	Bitmap* pBmp;	//Ҫ���Ƶ�ͼ��
	HDC hDc;		//�ڴ�DC
	Graphics *pGraphics;
};

