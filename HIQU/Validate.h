#pragma once

#include "Trapezoid.h"
#include "Pentagon.h"
#include "Trangle.h"
#include "Tool.h"

#define GRAPHNUMS 100	//

#define  MAXDISTANCE 10

typedef bool (*pValidateGraph)(CTrangle ,CTrapezoid ,CTrapezoid ,CPentagon );  

class CValidate 
{
	
public:
	CValidate();
	virtual ~CValidate();

private:
	pValidateGraph *pValidateGraphs;

public:

	bool ValidateGraph(CTrangle triangle,CTrapezoid smallTrape,CTrapezoid bigTrape,CPentagon penTango,unsigned short graphID);

};


