#pragma once
class CTool
{
public:
	CTool(void);
	~CTool(void);

	//�ж����λ���Ƿ���ͼ����
	static bool isInVertex(CPoint mousePoint, PointF* vertexPoints, byte n);

	// ��basePoint��point��������Ϊ��˳ʱ����תangle�㣬����point������
	static void Rotate(const PointF &basePoint,const USHORT &angle, PointF &point);

	// ���A���ڵ�B��C����ֱ�ߵĶԳƵ㣬���µ�A
	static void Axisymmetry(PointF& A, const PointF& B, const PointF& C);

	//���P1��P2����ľ���
	static double GetDistance(const PointF& p1, const PointF& p2);

	//��CRectת����RectF
	static CRect GetCRect(const RectF& rect);
};
