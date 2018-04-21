#include "StdAfx.h"
#include "Trangle.h"
#include "Tool.h"

CTrangle::CTrangle(void)
{
}

CTrangle::~CTrangle(void)
{
}

// 初始化三角型
void CTrangle::Init(PointF A, PointF B, PointF C, USHORT angle, HDC hDc)
{
	this->A = A;
	this->B = B;
	this->C = C;
	this->angle = angle;
	drawRect.X = A.X;
	drawRect.Y = A.Y;
	drawRect.Width = 80;
	drawRect.Height = 80;
	this->hDc = hDc;
	pGraphics = new Graphics(hDc);
	pImg = new Bitmap(L"res\\板子\\Trangle.png");
}

// 移动
void CTrangle::Move(int offsetX, int offsetY)
{
	this->A.X += offsetX;
	this->A.Y += offsetY;
	this->B.X += offsetX;
	this->B.Y += offsetY;
	this->C.X += offsetX;
	this->C.Y += offsetY;
	drawRect.X += offsetX;
	drawRect.Y += offsetY;
}

// 翻转
void CTrangle::Reverse(void)
{
	pImg->RotateFlip(Rotate90FlipX);

	CTool::Axisymmetry(B, A, C);
}

// 顺时针旋转45°
void CTrangle::Rotate(void)
{
	angle += 45;
	angle %= 360;
	
	CTool::Rotate(A, 45, B);
	CTool::Rotate(A, 45, C);
}

// DrawTrangle
void CTrangle::Draw(Graphics *bkGraphics)
{
	Matrix m;
	PointF p;
	p.X = A.X;
	p.Y = A.Y;
	m.RotateAt(angle, p, MatrixOrderAppend);
	bkGraphics->SetTransform(&m);

	Color color(100,220,110);
	Pen pen(color);
	//pGraphics->DrawRectangle(&pen,drawRect);

	bkGraphics->DrawImage(pImg, drawRect);

	bkGraphics->ResetTransform();

	PointF pt[3] = {A,B,C};
	bkGraphics->DrawPolygon(&pen, pt, 3);
}


// 判断点是否在三角型内
bool CTrangle::isInVertex(CPoint p)
{
	PointF pt[3] = {A,B,C};
	if (CTool::isInVertex(p, pt, 3))
		return true;
	else
		return false;
}

//
PointF CTrangle::GetPointA()
{
	return A;
}
PointF CTrangle::GetPointB()
{
	return B;
}
PointF CTrangle::GetPointC()
{
	return C;
}

