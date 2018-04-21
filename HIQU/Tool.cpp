#include "StdAfx.h"
#include <math.h>
#include "Tool.h"

#define PI 3.141592654
#define MIN(x,y) (x < y ? x : y)
#define MAX(x,y) (x > y ? x : y)
#define f(x,y)	(X * x + Y * y + Z)

CTool::CTool(void)
{
}


CTool::~CTool(void)
{
}

//�ж����λ���Ƿ���ͼ����
bool CTool::isInVertex(CPoint mousePoint, PointF* vertexPoints, byte N)
{
	int counter = 0;
	int i;
	double xinters;
	PointF p1,p2;

	p1 = vertexPoints[0];
	for (i=1;i<=N;i++) {
		p2 = vertexPoints[i % N];
		if (mousePoint.y > MIN(p1.Y,p2.Y)) { //��
			if (mousePoint.y <= MAX(p1.Y,p2.Y)) { //��
				if (mousePoint.x <= MAX(p1.X,p2.X)) { //��
					if (p1.Y != p2.Y) { //�򵥺���ƽ��X���������
						xinters = (mousePoint.y-p1.Y)*(p2.X-p1.X)/(p2.Y-p1.Y)+p1.X;
						if (p1.X == p2.X || mousePoint.x <= xinters)
							counter++;
					}
				}
			}
		}
		p1 = p2;
	}

	if (counter % 2 == 0)
		return false;
	else
		return true;

}

// ��basePoint��point��������Ϊ��˳ʱ����תangle�㣬����point������
void CTool::Rotate(const PointF &basePoint,const USHORT &angle, PointF &point)
{
	PointF temp = point - basePoint;
	point.X = (REAL)(temp.X * cos(PI*angle/180) - temp.Y * sin(PI*angle/180));
	point.Y = (REAL)(temp.Y * sin(PI*angle/180) + temp.X * cos(PI*angle/180));
	point = point + basePoint;
}

// ���A���ڵ�B��C����ֱ�ߵĶԳƵ㣬���µ�A
void CTool::Axisymmetry(PointF& A, const PointF& B, const PointF& C)
{
	//��B��C����ֱ��һ�㷽��Xx+Yy+Z=0
	float X,Y,Z;
	X = C.Y - B.Y;
	Y = B.X - C.X;
	Z = C.X * B.Y - B.X * C.Y;

	//��A�ĶԳƵ�
	PointF temp = A;

	A.X = temp.X - 2 * X * f(temp.X,temp.Y) / (X * X + Y * Y);
	A.Y = temp.Y - 2 * Y * f(temp.X,temp.Y) / (X * X + Y * Y);
}

//���P1��P2����ľ���
double CTool::GetDistance(const PointF& p1, const PointF& p2)
{

	return sqrt((p1.X-p2.X)*(p1.X-p2.X)+(p1.Y-p2.Y)*(p1.Y-p2.Y)*1.0);
}

//��CRectת����RectF
CRect CTool::GetCRect( const RectF& rect)
{
	return CRect((INT)rect.X, (INT)rect.Y, (INT)(rect.X+rect.Width), (INT)(rect.Y+rect.Height));
}
