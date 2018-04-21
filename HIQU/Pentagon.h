#pragma once
//#include "gdiplustypes.h"
class CPentagon
{
public:
	CPentagon(void);
	~CPentagon(void);

	Rect drawRect;	//绘制图形的位置

	// 初始化五边形
	void Init(PointF A, PointF B, PointF C, PointF D, PointF E,USHORT angle, HDC hDc);
	// 移动
	void Move(int offsetX, int offsetY);
	// 翻转
	void Reverse(void);
	// 顺时针旋转45°
	void Rotate(void);
	// DrawPentagon
	void Draw(Graphics *bkGraphics);
	// 判断点是否在五边形内
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
	bool isFront;	//图形所处的面 true-正
	USHORT angle;	//所处角度
	Bitmap* pBmp;	//要绘制的图形
	HDC hDc;		//内存DC
	Graphics *pGraphics;
};

