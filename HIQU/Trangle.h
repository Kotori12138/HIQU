#pragma once
class CTrangle
{
public:
	CTrangle(void);
	~CTrangle(void);
private:
	PointF A;		//
	PointF B;		//ֱ�Ƕ���
	PointF C;		//
	USHORT angle;	//�����Ƕ�
	Bitmap* pImg;	//Ҫ���Ƶ�ͼ��
	HDC hDc;		//�ڴ�DC
	Graphics *pGraphics;
public:
	Rect drawRect;	//����ͼ�ε�λ��
	// ��ʼ��������
	void Init(PointF A, PointF B, PointF C, USHORT angle, HDC hDc);
	// �ƶ�
	void Move(int offsetX, int offsetY);
	// ��ת
	void Reverse(void);
	// ˳ʱ����ת45��
	void Rotate(void);
	// DrawTrangle
	void Draw(Graphics *bkGraphics);
	// �жϵ��Ƿ�����������
	bool isInVertex(CPoint point);

	PointF GetPointA();
	PointF GetPointB();
	PointF GetPointC();

};

