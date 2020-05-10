#ifndef CLINE_H
#define CLINE_H

#include "Figures/CFigure.h"
class CLine :public CFigure
{
private:
	Point Corner1;
	Point Corner2;
	double getslope();
public:
	CLine(Point, Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	virtual bool IsInside(Point p);
	virtual void PrintInfo(Output*pOut);
	virtual void Save(ofstream &out);
	virtual void Load(ifstream &in);
	virtual Point GetShift(Point & p2);
	virtual CFigure* DrawPaste(Point p1, Point p2);
	virtual CFigure* First();
};
#endif;

