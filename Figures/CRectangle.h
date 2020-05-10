#ifndef CRECT_H
#define CRECT_H

#include "CFigure.h"


class CRectangle : public CFigure
{
private:
	Point Corner1;	
	Point Corner2;
public:
	CRectangle(Point , Point, GfxInfo FigureGfxInfo );
	virtual void Draw(Output* pOut) const;
	virtual bool IsInside(Point p);
	virtual void PrintInfo(Output* pOut);
	void Resize(float f);
	virtual void Save(ofstream &out);
	virtual void Load(ifstream &in);	//Load the figure parameters to the file
	virtual Point GetShift(Point & p2);
	virtual CFigure* DrawPaste(Point p1, Point p2);
	virtual CFigure*First();

};

#endif