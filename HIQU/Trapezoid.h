#pragma once
class CTrapezoid
{
public:
	CTrapezoid(void);
	~CTrapezoid(void);

	Rect drawRect;	//绘制图形的位置

	// 初始化梯形
	void Init(PointF A, PointF B, PointF C, PointF D, USHORT angle, HDC hDc, bool type);
	// 移动
	void Move(int offsetX, int offsetY);
	// 翻转
	void Reverse(void);
	// 顺时针旋转45°
	void Rotate(void);
	// DrawTrapezoid
	void Draw(Graphics *bkGraphics);
	// 判断点是否在梯形内
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
	bool isFront;	//图形所处的面 true-正
	USHORT angle;	//所处角度
	Bitmap* pBmp;	//要绘制的图形
	HDC hDc;		//内存DC
	Graphics *pGraphics;
};

