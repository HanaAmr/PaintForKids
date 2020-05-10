#pragma once

#include "Figures/CFigure.h"

class CTriangle : public CFigure
{
private:
	Point Corner1;
	Point Corner2;
	Point Corner3;
public:
	CTriangle(Point, Point,Point, GfxInfo FigureGfxInfo);
	virtual bool IsInside(Point p);
	virtual void Draw(Output* pOut) const;
	virtual void PrintInfo(Output*pOut);
	virtual void Save(ofstream &out);
	virtual void Load(ifstream &in);
	virtual Point GetShift(Point & p2);
	virtual CFigure* DrawPaste(Point p1, Point p2);
	virtual CFigure* First();
};

