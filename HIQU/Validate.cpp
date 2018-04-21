

#include "stdafx.h"
#include "Validate.h"//
#include "Trapezoid.h"
#include "Pentagon.h"
#include "Trangle.h"


bool ValidateGraph1(CTrangle triangle,CTrapezoid smallTrape,CTrapezoid bigTrape,CPentagon penTango)
{
	if (CTool::GetDistance(penTango.GetPointA(),bigTrape.GetPointD())<=MAXDISTANCE && CTool::GetDistance(penTango.GetPointB(),bigTrape.GetPointC())<=MAXDISTANCE
		&&CTool::GetDistance(penTango.GetPointC(),smallTrape.GetPointD())<=MAXDISTANCE&&CTool::GetDistance(penTango.GetPointD(),smallTrape.GetPointA())<=MAXDISTANCE
		&&(CTool::GetDistance(triangle.GetPointA(),smallTrape.GetPointC())<=MAXDISTANCE||CTool::GetDistance(triangle.GetPointC(),smallTrape.GetPointC())<=MAXDISTANCE)
		&&(CTool::GetDistance(triangle.GetPointA(),smallTrape.GetPointB())<=MAXDISTANCE||CTool::GetDistance(triangle.GetPointC(),smallTrape.GetPointB())<=MAXDISTANCE)
		&&(CTool::GetDistance(penTango.GetPointE(),triangle.GetPointA())<=MAXDISTANCE||CTool::GetDistance(penTango.GetPointE(),triangle.GetPointC())<=MAXDISTANCE)
		&&CTool::GetDistance(penTango.GetPointE(),smallTrape.GetPointB())<=MAXDISTANCE)
	{
		return true;
	}
	if(CTool::GetDistance(bigTrape.GetPointD(),smallTrape.GetPointC())<=MAXDISTANCE&&CTool::GetDistance(bigTrape.GetPointC(),smallTrape.GetPointB())<=MAXDISTANCE
		&&CTool::GetDistance(penTango.GetPointE(),bigTrape.GetPointC())<=MAXDISTANCE&&CTool::GetDistance(penTango.GetPointE(),smallTrape.GetPointB())<=MAXDISTANCE
		&&CTool::GetDistance(penTango.GetPointD(),smallTrape.GetPointA())<=MAXDISTANCE&&CTool::GetDistance(penTango.GetPointC(),smallTrape.GetPointD())<=MAXDISTANCE
		&&(CTool::GetDistance(penTango.GetPointB(),triangle.GetPointA())<=MAXDISTANCE||CTool::GetDistance(penTango.GetPointB(),triangle.GetPointC())<=MAXDISTANCE)
		&&(CTool::GetDistance(penTango.GetPointA(),triangle.GetPointA())<=MAXDISTANCE||CTool::GetDistance(penTango.GetPointA(),triangle.GetPointC())<=MAXDISTANCE))
	{
		return true;
	}

	return false;
}

bool ValidateGraph2(CTrangle triangle,CTrapezoid smallTrape,CTrapezoid bigTrape,CPentagon penTango)
{
	if (CTool::GetDistance(triangle.GetPointB(),bigTrape.GetPointB())<=MAXDISTANCE&&CTool::GetDistance(bigTrape.GetPointA(),penTango.GetPointA())<=MAXDISTANCE
		&&CTool::GetDistance(penTango.GetPointC(),smallTrape.GetPointD())<=MAXDISTANCE&&CTool::GetDistance(penTango.GetPointD(),smallTrape.GetPointA())<=MAXDISTANCE
		&&(CTool::GetDistance(penTango.GetPointA(),triangle.GetPointA())<=MAXDISTANCE||CTool::GetDistance(penTango.GetPointA(),triangle.GetPointC())<=MAXDISTANCE)
		&&(CTool::GetDistance(penTango.GetPointB(),triangle.GetPointA())<=MAXDISTANCE||CTool::GetDistance(penTango.GetPointB(),triangle.GetPointC())<=MAXDISTANCE)
		&&(CTool::GetDistance(bigTrape.GetPointA(),triangle.GetPointA())<=MAXDISTANCE||CTool::GetDistance(bigTrape.GetPointA(),triangle.GetPointC())<=MAXDISTANCE)
		&&CTool::GetDistance(penTango.GetPointE(),smallTrape.GetPointB())<=MAXDISTANCE)
	{
		return true;
	}
	if(CTool::GetDistance(penTango.GetPointC(),smallTrape.GetPointD())<=MAXDISTANCE&&CTool::GetDistance(penTango.GetPointD(),smallTrape.GetPointA())<=MAXDISTANCE
		&&CTool::GetDistance(penTango.GetPointE(),smallTrape.GetPointB())<=MAXDISTANCE&&CTool::GetDistance(smallTrape.GetPointC(),bigTrape.GetPointA())<=MAXDISTANCE
		&&(CTool::GetDistance(bigTrape.GetPointA(),triangle.GetPointA())<=MAXDISTANCE||CTool::GetDistance(bigTrape.GetPointA(),triangle.GetPointC())<=MAXDISTANCE)
		&&(CTool::GetDistance(smallTrape.GetPointB(),triangle.GetPointA())<=MAXDISTANCE||CTool::GetDistance(smallTrape.GetPointB(),triangle.GetPointC())<=MAXDISTANCE)
		&&(CTool::GetDistance(smallTrape.GetPointC(),triangle.GetPointA())<=MAXDISTANCE||CTool::GetDistance(smallTrape.GetPointC(),triangle.GetPointC())<=MAXDISTANCE)
		&&(CTool::GetDistance(penTango.GetPointE(),triangle.GetPointA())<=MAXDISTANCE||CTool::GetDistance(penTango.GetPointE(),triangle.GetPointC())<=MAXDISTANCE))
	{
		return true;
	}
	if (CTool::GetDistance(triangle.GetPointB(),bigTrape.GetPointB())<=MAXDISTANCE&&CTool::GetDistance(bigTrape.GetPointC(),smallTrape.GetPointB())<=MAXDISTANCE
		&&CTool::GetDistance(bigTrape.GetPointC(),penTango.GetPointE())<=MAXDISTANCE&&CTool::GetDistance(smallTrape.GetPointB(),penTango.GetPointE())<=MAXDISTANCE
		&&CTool::GetDistance(penTango.GetPointD(),smallTrape.GetPointA())<=MAXDISTANCE&&CTool::GetDistance(penTango.GetPointC(),smallTrape.GetPointD())<=MAXDISTANCE
		&&(CTool::GetDistance(bigTrape.GetPointA(),triangle.GetPointA())<=MAXDISTANCE||CTool::GetDistance(bigTrape.GetPointA(),triangle.GetPointC())<=MAXDISTANCE)
		&&CTool::GetDistance(smallTrape.GetPointC(),bigTrape.GetPointD())<=MAXDISTANCE)
	{
		return true;
	}
	if(CTool::GetDistance(smallTrape.GetPointB(),penTango.GetPointE())<=MAXDISTANCE&&CTool::GetDistance(penTango.GetPointB(),bigTrape.GetPointC())<=MAXDISTANCE
		&&CTool::GetDistance(smallTrape.GetPointA(),penTango.GetPointD())<=MAXDISTANCE&&CTool::GetDistance(smallTrape.GetPointD(),penTango.GetPointC())<=MAXDISTANCE
		&&(CTool::GetDistance(bigTrape.GetPointA(),triangle.GetPointA())<=MAXDISTANCE||CTool::GetDistance(bigTrape.GetPointA(),triangle.GetPointC())<=MAXDISTANCE)
		&&CTool::GetDistance(penTango.GetPointA(),bigTrape.GetPointD())<=MAXDISTANCE&&CTool::GetDistance(bigTrape.GetPointB(),triangle.GetPointB())<=MAXDISTANCE)
	{
		return true;
	}
	return false;
}

bool ValidateGraph3(CTrangle triangle,CTrapezoid smallTrape,CTrapezoid bigTrape,CPentagon penTango)
{
	if(CTool::GetDistance(bigTrape.GetPointC(),penTango.GetPointA())<=MAXDISTANCE&&CTool::GetDistance(bigTrape.GetPointD(),penTango.GetPointB())<=MAXDISTANCE
		&&CTool::GetDistance(penTango.GetPointE(),smallTrape.GetPointB())<=MAXDISTANCE&&CTool::GetDistance(penTango.GetPointD(),smallTrape.GetPointA())<=MAXDISTANCE
		&&(CTool::GetDistance(smallTrape.GetPointC(),triangle.GetPointA())<=MAXDISTANCE||CTool::GetDistance(smallTrape.GetPointC(),triangle.GetPointC())<=MAXDISTANCE)
		&&(CTool::GetDistance(smallTrape.GetPointB(),triangle.GetPointA())<=MAXDISTANCE||CTool::GetDistance(smallTrape.GetPointB(),triangle.GetPointC())<=MAXDISTANCE)
		&&CTool::GetDistance(penTango.GetPointC(),smallTrape.GetPointD())<=MAXDISTANCE)
	{
		return true;
	}
	if(CTool::GetDistance(bigTrape.GetPointC(),smallTrape.GetPointC())<=MAXDISTANCE&&CTool::GetDistance(bigTrape.GetPointD(),smallTrape.GetPointB())<=MAXDISTANCE
		&&CTool::GetDistance(bigTrape.GetPointD(),penTango.GetPointE())<=MAXDISTANCE&&CTool::GetDistance(penTango.GetPointE(),smallTrape.GetPointB())<=MAXDISTANCE
		&&CTool::GetDistance(smallTrape.GetPointA(),penTango.GetPointD())<=MAXDISTANCE&&CTool::GetDistance(smallTrape.GetPointD(),penTango.GetPointC())<=MAXDISTANCE
		&&(CTool::GetDistance(penTango.GetPointB(),triangle.GetPointA())<=MAXDISTANCE)||CTool::GetDistance(penTango.GetPointB(),triangle.GetPointC())<=MAXDISTANCE
		&&(CTool::GetDistance(penTango.GetPointA(),triangle.GetPointA())<=MAXDISTANCE||CTool::GetDistance(penTango.GetPointA(),triangle.GetPointC())<=MAXDISTANCE))
	{
		return true;
	}
	return false;
}

bool ValidateGraph4(CTrangle triangle,CTrapezoid smallTrape,CTrapezoid bigTrape,CPentagon penTango)
{
	if(CTool::GetDistance(bigTrape.GetPointD(),penTango.GetPointA())<=MAXDISTANCE&&CTool::GetDistance(penTango.GetPointE(),smallTrape.GetPointB())<=MAXDISTANCE
		&&CTool::GetDistance(penTango.GetPointD(),smallTrape.GetPointA())<=MAXDISTANCE&&CTool::GetDistance(penTango.GetPointC(),smallTrape.GetPointD())<=MAXDISTANCE
		&&(CTool::GetDistance(penTango.GetPointC(),triangle.GetPointA())<=MAXDISTANCE||CTool::GetDistance(penTango.GetPointC(),triangle.GetPointC())<=MAXDISTANCE)
		&&(CTool::GetDistance(smallTrape.GetPointD(),triangle.GetPointA())<=MAXDISTANCE||CTool::GetDistance(smallTrape.GetPointD(),triangle.GetPointC())<=MAXDISTANCE)
		&&(CTool::GetDistance(smallTrape.GetPointC(),triangle.GetPointA())<=MAXDISTANCE||CTool::GetDistance(smallTrape.GetPointC(),triangle.GetPointC())<=MAXDISTANCE))
	{
		return true;
	}
	return false;
}

bool ValidateGraph5(CTrangle triangle,CTrapezoid smallTrape,CTrapezoid bigTrape,CPentagon penTango)
{
	if(CTool::GetDistance(penTango.GetPointE(),smallTrape.GetPointB())<=MAXDISTANCE&&CTool::GetDistance(penTango.GetPointD(),smallTrape.GetPointA())<=MAXDISTANCE
		&&CTool::GetDistance(smallTrape.GetPointD(),bigTrape.GetPointC())<=MAXDISTANCE&&CTool::GetDistance(penTango.GetPointC(),smallTrape.GetPointD())<=MAXDISTANCE
		&&(CTool::GetDistance(bigTrape.GetPointB(),triangle.GetPointA())<=MAXDISTANCE||CTool::GetDistance(bigTrape.GetPointB(),triangle.GetPointC())<=MAXDISTANCE)
		&&CTool::GetDistance(penTango.GetPointC(),bigTrape.GetPointC())<=MAXDISTANCE&&CTool::GetDistance(bigTrape.GetPointA(),triangle.GetPointB())<=MAXDISTANCE
		&&CTool::GetDistance(bigTrape.GetPointD(),smallTrape.GetPointC())<=MAXDISTANCE)
	{
		return true;
	}
	if(CTool::GetDistance(smallTrape.GetPointA(),penTango.GetPointD())<=MAXDISTANCE&&CTool::GetDistance(smallTrape.GetPointB(),penTango.GetPointE())<=MAXDISTANCE
		&&CTool::GetDistance(penTango.GetPointC(),smallTrape.GetPointD())<=MAXDISTANCE&&CTool::GetDistance(penTango.GetPointA(),bigTrape.GetPointD())<=MAXDISTANCE
		&&(CTool::GetDistance(bigTrape.GetPointB(),triangle.GetPointA())<=MAXDISTANCE||CTool::GetDistance(bigTrape.GetPointB(),triangle.GetPointC())<=MAXDISTANCE)
		&&CTool::GetDistance(bigTrape.GetPointA(),triangle.GetPointB())<=MAXDISTANCE&&CTool::GetDistance(bigTrape.GetPointC(),penTango.GetPointE())<=117)
	{
		return true;
	}
	if(CTool::GetDistance(smallTrape.GetPointA(),penTango.GetPointD())<=MAXDISTANCE&&CTool::GetDistance(smallTrape.GetPointB(),penTango.GetPointE())<=MAXDISTANCE
		&&CTool::GetDistance(penTango.GetPointC(),smallTrape.GetPointD())<=MAXDISTANCE&&CTool::GetDistance(bigTrape.GetPointA(),triangle.GetPointB())<=MAXDISTANCE
		&&(CTool::GetDistance(bigTrape.GetPointB(),triangle.GetPointA())<=MAXDISTANCE||CTool::GetDistance(bigTrape.GetPointB(),triangle.GetPointC())<=MAXDISTANCE)
		&&(CTool::GetDistance(penTango.GetPointA(),triangle.GetPointA())<=MAXDISTANCE||CTool::GetDistance(penTango.GetPointA(),triangle.GetPointC())<=MAXDISTANCE)
		&&(CTool::GetDistance(penTango.GetPointE(),triangle.GetPointA())<=117||CTool::GetDistance(penTango.GetPointA(),triangle.GetPointC())<=117)
		&&CTool::GetDistance(penTango.GetPointA(),bigTrape.GetPointB())<=MAXDISTANCE)
	{
		return true;
	}
	if(CTool::GetDistance(penTango.GetPointE(),smallTrape.GetPointB())<=MAXDISTANCE&&CTool::GetDistance(penTango.GetPointD(),smallTrape.GetPointA())<=MAXDISTANCE
		&&CTool::GetDistance(penTango.GetPointC(),smallTrape.GetPointD())<=MAXDISTANCE&&CTool::GetDistance(bigTrape.GetPointA(),triangle.GetPointB())<=MAXDISTANCE
		&&(CTool::GetDistance(penTango.GetPointC(),triangle.GetPointA())<=MAXDISTANCE||CTool::GetDistance(penTango.GetPointC(),triangle.GetPointC())<=MAXDISTANCE)
		&&(CTool::GetDistance(smallTrape.GetPointD(),triangle.GetPointA())<=MAXDISTANCE||CTool::GetDistance(smallTrape.GetPointD(),triangle.GetPointC())<=MAXDISTANCE)
		&&(CTool::GetDistance(smallTrape.GetPointC(),triangle.GetPointA())<=MAXDISTANCE||CTool::GetDistance(smallTrape.GetPointC(),triangle.GetPointC())<=MAXDISTANCE)
		&&(CTool::GetDistance(bigTrape.GetPointB(),triangle.GetPointA())<=MAXDISTANCE||CTool::GetDistance(bigTrape.GetPointB(),triangle.GetPointC())<=MAXDISTANCE)
		&&CTool::GetDistance(smallTrape.GetPointC(),bigTrape.GetPointB())<=MAXDISTANCE)
	{
		return true;
	}
	return false;
}

bool ValidateGraph6(CTrangle triangle,CTrapezoid smallTrape,CTrapezoid bigTrape,CPentagon penTango)
{
	if(CTool::GetDistance(bigTrape.GetPointD(),penTango.GetPointA())<=MAXDISTANCE&&CTool::GetDistance(bigTrape.GetPointC(),penTango.GetPointB())<=MAXDISTANCE
		&&CTool::GetDistance(penTango.GetPointC(),smallTrape.GetPointD())<=MAXDISTANCE&&CTool::GetDistance(penTango.GetPointD(),smallTrape.GetPointA())<=MAXDISTANCE
		&&(CTool::GetDistance(penTango.GetPointC(),triangle.GetPointA())<=MAXDISTANCE||CTool::GetDistance(penTango.GetPointC(),triangle.GetPointC())<=MAXDISTANCE)
		&&(CTool::GetDistance(smallTrape.GetPointC(),triangle.GetPointA())<=MAXDISTANCE||CTool::GetDistance(smallTrape.GetPointC(),triangle.GetPointC())<=MAXDISTANCE)
		&&(CTool::GetDistance(smallTrape.GetPointD(),triangle.GetPointA())<=MAXDISTANCE||CTool::GetDistance(smallTrape.GetPointD(),triangle.GetPointC())<=MAXDISTANCE)
		&&CTool::GetDistance(penTango.GetPointE(),smallTrape.GetPointB())<=MAXDISTANCE)
	{
		return true;
	}
	return false;
}

bool ValidateGraph7(CTrangle triangle,CTrapezoid smallTrape,CTrapezoid bigTrape,CPentagon penTango)
{
	if(CTool::GetDistance(penTango.GetPointA(),smallTrape.GetPointB())<=MAXDISTANCE&&CTool::GetDistance(penTango.GetPointB(),smallTrape.GetPointC())<=MAXDISTANCE
		&&CTool::GetDistance(penTango.GetPointB(),bigTrape.GetPointD())<=MAXDISTANCE&&CTool::GetDistance(smallTrape.GetPointC(),bigTrape.GetPointD())<=MAXDISTANCE
		&&(CTool::GetDistance(bigTrape.GetPointA(),triangle.GetPointA())<=20||CTool::GetDistance(bigTrape.GetPointA(),triangle.GetPointC())<=20)
		&&(CTool::GetDistance(bigTrape.GetPointB(),triangle.GetPointA())<=20||CTool::GetDistance(bigTrape.GetPointB(),triangle.GetPointC())<=20))
	{
		return true;
	}
	return false;
}

bool ValidateGraph8(CTrangle triangle,CTrapezoid smallTrape,CTrapezoid bigTrape,CPentagon penTango)
{
	if(CTool::GetDistance(penTango.GetPointC(),smallTrape.GetPointD())<=MAXDISTANCE&&CTool::GetDistance(penTango.GetPointD(),smallTrape.GetPointA())<=MAXDISTANCE
		&&CTool::GetDistance(penTango.GetPointE(),smallTrape.GetPointB())<=MAXDISTANCE&&CTool::GetDistance(bigTrape.GetPointB(),smallTrape.GetPointC())<=MAXDISTANCE
		&&(CTool::GetDistance(penTango.GetPointE(),triangle.GetPointA())<=MAXDISTANCE||CTool::GetDistance(penTango.GetPointE(),triangle.GetPointC())<=MAXDISTANCE)
		&&(CTool::GetDistance(bigTrape.GetPointB(),triangle.GetPointA())<=MAXDISTANCE||CTool::GetDistance(bigTrape.GetPointB(),triangle.GetPointC())<=MAXDISTANCE)
		&&(CTool::GetDistance(smallTrape.GetPointB(),triangle.GetPointA())<=MAXDISTANCE||CTool::GetDistance(smallTrape.GetPointB(),triangle.GetPointC())<=MAXDISTANCE)
		&&(CTool::GetDistance(smallTrape.GetPointC(),triangle.GetPointA())<=MAXDISTANCE||CTool::GetDistance(smallTrape.GetPointC(),triangle.GetPointC())<=MAXDISTANCE))
	{
		return true;
	}
	return false;
}

bool ValidateGraph9(CTrangle triangle,CTrapezoid smallTrape,CTrapezoid bigTrape,CPentagon penTango)
{
	if(CTool::GetDistance(penTango.GetPointC(),smallTrape.GetPointD())<=MAXDISTANCE&&CTool::GetDistance(penTango.GetPointA(),bigTrape.GetPointC())<=MAXDISTANCE
		&&CTool::GetDistance(penTango.GetPointD(),smallTrape.GetPointA())<=MAXDISTANCE&&CTool::GetDistance(penTango.GetPointE(),smallTrape.GetPointB())<=MAXDISTANCE
		&&(CTool::GetDistance(penTango.GetPointE(),triangle.GetPointA())<=MAXDISTANCE||CTool::GetDistance(penTango.GetPointE(),triangle.GetPointC())<=MAXDISTANCE)
		&&(CTool::GetDistance(smallTrape.GetPointB(),triangle.GetPointA())<=MAXDISTANCE||CTool::GetDistance(smallTrape.GetPointB(),triangle.GetPointC())<=MAXDISTANCE)
		&&(CTool::GetDistance(smallTrape.GetPointC(),triangle.GetPointA())<=MAXDISTANCE||CTool::GetDistance(smallTrape.GetPointC(),triangle.GetPointC())<=MAXDISTANCE))
	{
		return true;
	}
	return false;
}

bool ValidateGraph10(CTrangle triangle,CTrapezoid smallTrape,CTrapezoid bigTrape,CPentagon penTango)
{
	if(CTool::GetDistance(bigTrape.GetPointC(),penTango.GetPointA())<=MAXDISTANCE&&CTool::GetDistance(penTango.GetPointE(),smallTrape.GetPointB())<=MAXDISTANCE
		&&CTool::GetDistance(penTango.GetPointD(),smallTrape.GetPointA())<=MAXDISTANCE&&CTool::GetDistance(penTango.GetPointC(),smallTrape.GetPointD())<=MAXDISTANCE
		&&(CTool::GetDistance(penTango.GetPointC(),triangle.GetPointA())<=MAXDISTANCE||CTool::GetDistance(penTango.GetPointC(),triangle.GetPointC())<=MAXDISTANCE)
		&&(CTool::GetDistance(smallTrape.GetPointD(),triangle.GetPointA())<=MAXDISTANCE||CTool::GetDistance(smallTrape.GetPointD(),triangle.GetPointC())<=MAXDISTANCE)
		&&(CTool::GetDistance(smallTrape.GetPointC(),triangle.GetPointA())<=MAXDISTANCE||CTool::GetDistance(smallTrape.GetPointC(),triangle.GetPointC())<=MAXDISTANCE)
		&&CTool::GetDistance(bigTrape.GetPointD(),penTango.GetPointE())<=117)
	{
		return true;
	}
	return false;
}

bool CValidate::ValidateGraph(CTrangle triangle,CTrapezoid smallTrape,CTrapezoid bigTrape,CPentagon penTango,unsigned short graphID)
{
	if (pValidateGraphs[graphID-1](triangle, smallTrape, bigTrape, penTango))
	{
		return true;
	}
	return false;
}

CValidate::CValidate()
{
	pValidateGraphs = new pValidateGraph[GRAPHNUMS];
	pValidateGraphs[0] = ValidateGraph1;
	pValidateGraphs[1] = ValidateGraph2;
	pValidateGraphs[2] = ValidateGraph3;
	pValidateGraphs[3] = ValidateGraph4;
	pValidateGraphs[4] = ValidateGraph5;
	pValidateGraphs[5] = ValidateGraph6;
	pValidateGraphs[6] = ValidateGraph7;
	pValidateGraphs[7] = ValidateGraph8;
	pValidateGraphs[8] = ValidateGraph9;
	pValidateGraphs[9] = ValidateGraph10;
}

CValidate::~CValidate()
{
}
