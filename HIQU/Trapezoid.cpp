#include "StdAfx.h"
#include "Trapezoid.h"
#include "Tool.h"

CTrapezoid::CTrapezoid(void)
{
}


CTrapezoid::~CTrapezoid(void)
{
}

// 初始化梯形
void CTrapezoid::Init(PointF A, PointF B, PointF C, PointF D, USHORT angle, HDC hDc, bool type)
{
	this->A = A;
	this->B = B;
	this->C = C;
	this->D = D;
	this->angle = angle;
	drawRect.X = A.X;
	drawRect.Y = A.Y;
	this->hDc = hDc;
	pGraphics = new Graphics(hDc);
	if (type)
	{
		drawRect.Width = 113;
		drawRect.Height = 80;
		pBmp = new Bitmap(L"res\\板子\\SmallEchelons.png");
	}
	else
	{
		drawRect.Width = 226;
		drawRect.Height = 80;
		pBmp = new Bitmap(L"res\\板子\\BigEchelons.png");
	}
	isFront = true;
}

// 移动
void CTrapezoid::Move(int offsetX, int offsetY)
{
	this->A.X += offsetX;
	this->A.Y += offsetY;
	this->B.X += offsetX;
	this->B.Y += offsetY;
	this->C.X += offsetX;
	this->C.Y += offsetY;
	this->D.X += offsetX;
	this->D.Y += offsetY;
	drawRect.X += offsetX;
	drawRect.Y += offsetY;
}

// 翻转
void CTrapezoid::Reverse(void)
{
	pBmp->RotateFlip(RotateNoneFlipY);
	PointF temp1;
	PointF temp2;
	CTool::Axisymmetry(A, B, C);
	CTool::Axisymmetry(D, B, C);
	//CTool::Axisymmetry(D, A, E);
	if (isFront)
	{
		drawRect.Y += 80;
	}
	else
	{
		drawRect.Y -= 80;
	}
	isFront = !isFront;
}

// 顺时针旋转45°
void CTrapezoid::Rotate(void)
{
	angle += 45;
	angle %= 360;

	CTool::Rotate(B, 45, A);
	CTool::Rotate(B, 45, C);
	CTool::Rotate(B, 45, D);
}

// DrawTrapezoid
void CTrapezoid::Draw(Graphics *bkGraphics)
{
	Matrix m;
	PointF p;
	p.X = B.X;
	p.Y = B.Y;
	m.RotateAt(angle, p, MatrixOrderAppend);
	bkGraphics->SetTransform(&m);

	Color color(100,220,110);
	Pen pen(color);
	//bkGraphics->DrawRectangle(&pen,drawRect);

	
	bkGraphics->DrawImage(pBmp, drawRect);

	bkGraphics->ResetTransform();

	PointF pt[4] = {A,B,C,D};
	bkGraphics->DrawPolygon(&pen, pt, 4);
}

// 判断点是否在梯形内
bool CTrapezoid::isInVertex(CPoint p)
{
	PointF pt[4] = {A,B,C,D};
	if (CTool::isInVertex(p, pt, 4))
		return true;
	else
		return false;
}

//
PointF CTrapezoid::GetPointA()
{
	return A;
}
PointF CTrapezoid::GetPointB()
{
	return B;
}
PointF CTrapezoid::GetPointC()
{
	return C;
}
PointF CTrapezoid::GetPointD()
{
	return D;
}

