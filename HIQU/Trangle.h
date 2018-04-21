#pragma once
class CTrangle
{
public:
	CTrangle(void);
	~CTrangle(void);
private:
	PointF A;		//
	PointF B;		//直角顶点
	PointF C;		//
	USHORT angle;	//所处角度
	Bitmap* pImg;	//要绘制的图形
	HDC hDc;		//内存DC
	Graphics *pGraphics;
public:
	Rect drawRect;	//绘制图形的位置
	// 初始化三角型
	void Init(PointF A, PointF B, PointF C, USHORT angle, HDC hDc);
	// 移动
	void Move(int offsetX, int offsetY);
	// 翻转
	void Reverse(void);
	// 顺时针旋转45°
	void Rotate(void);
	// DrawTrangle
	void Draw(Graphics *bkGraphics);
	// 判断点是否在三角型内
	bool isInVertex(CPoint point);

	PointF GetPointA();
	PointF GetPointB();
	PointF GetPointC();

};

