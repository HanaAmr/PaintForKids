#pragma once
#include "Figures/CFigure.h"

class CRhombus : public CFigure
{
private:
	Point Corner1;
public:
	CRhombus(Point, GfxInfo FigureGfxInfo);
	virtual bool IsInside(Point p);
	virtual void Draw(Output* pOut) const;
	virtual void PrintInfo(Output*pOut);
	virtual void Save(ofstream &out);
	virtual void Load(ifstream &in);
	virtual Point GetShift(Point & p2);
	virtual CFigure* DrawPaste(Point p1, Point p2);
	virtual CFigure* First();

};

