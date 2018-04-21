#pragma once
class CTool
{
public:
	CTool(void);
	~CTool(void);

	//判断鼠标位置是否在图形内
	static bool isInVertex(CPoint mousePoint, PointF* vertexPoints, byte n);

	// 以basePoint、point所在射线为轴顺时针旋转angle°，更新point的坐标
	static void Rotate(const PointF &basePoint,const USHORT &angle, PointF &point);

	// 求点A关于点B、C所在直线的对称点，更新点A
	static void Axisymmetry(PointF& A, const PointF& B, const PointF& C);

	//获得P1和P2两点的距离
	static double GetDistance(const PointF& p1, const PointF& p2);

	//将CRect转换成RectF
	static CRect GetCRect(const RectF& rect);
};
