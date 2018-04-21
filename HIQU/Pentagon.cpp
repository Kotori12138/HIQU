#include "StdAfx.h"
#include "Pentagon.h"
#include "Tool.h"


CPentagon::CPentagon(void)
{
}


CPentagon::~CPentagon(void)
{
}

// 初始化五边形
void CPentagon::Init(PointF A, PointF B, PointF C, PointF D, PointF E,USHORT angle, HDC hDc)
{
	this->A = A;
	this->B = B;
	this->C = C;
	this->D = D;
	this->E = E;
	this->angle = angle;
	drawRect.X = A.X;
	drawRect.Y = A.Y - 80;
	drawRect.Width = 226;
	drawRect.Height = 80;
	this->hDc = hDc;
	pGraphics = new Graphics(hDc);
	pBmp = new Bitmap(L"res\\板子\\Pentagon.png");
	isFront = true;
}

// 移动
void CPentagon::Move(int offsetX, int offsetY)
{
	this->A.X += offsetX;
	this->A.Y += offsetY;
	this->B.X += offsetX;
	this->B.Y += offsetY;
	this->C.X += offsetX;
	this->C.Y += offsetY;
	this->D.X += offsetX;
	this->D.Y += offsetY;
	this->E.X += offsetX;
	this->E.Y += offsetY;
	drawRect.X += offsetX;
	drawRect.Y += offsetY;
}

// 翻转
void CPentagon::Reverse(void)
{
	pBmp->RotateFlip(RotateNoneFlipY);
	PointF temp1;
	PointF temp2;
	CTool::Axisymmetry(B, A, E);
	CTool::Axisymmetry(C, A, E);
	CTool::Axisymmetry(D, A, E);
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
void CPentagon::Rotate(void)
{
	angle += 45;
	angle %= 360;

	CTool::Rotate(A, 45, B);
	CTool::Rotate(A, 45, C);
	CTool::Rotate(A, 45, D);
	CTool::Rotate(A, 45, E);
}

// DrawPentagon
void CPentagon::Draw(Graphics *bkGraphics)
{
	Matrix m;
	PointF p;
	p.X = A.X;
	p.Y = A.Y;
	m.RotateAt(angle, p, MatrixOrderAppend);
	bkGraphics->SetTransform(&m);

	Color color(100,220,110);
	Pen pen(color);
	//bkGraphics->DrawRectangle(&pen,drawRect);

	bkGraphics->DrawImage(pBmp, drawRect);

	bkGraphics->ResetTransform();

	PointF pt[5] = {A,B,C,D,E};
	bkGraphics->DrawPolygon(&pen, pt, 5);
}

// 判断点是否在五边形内
bool CPentagon::isInVertex(CPoint p)
{
	PointF pt[5] = {A,B,C,D,E};
	if (CTool::isInVertex(p, pt, 5))
		return true;
	else
		return false;
}

//
PointF CPentagon::GetPointA()
{
	return A;
}
PointF CPentagon::GetPointB()
{
	return B;
}
PointF CPentagon::GetPointC()
{
	return C;
}
PointF CPentagon::GetPointD()
{
	return D;
}

PointF CPentagon::GetPointE()
{
	return E;
}

