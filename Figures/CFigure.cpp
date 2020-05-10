#include "CFigure.h"


int CFigure::count = 0;
CFigure::CFigure(GfxInfo FigureGfxInfo)
{ 
	FigGfxInfo = FigureGfxInfo;	//Default status is non-filled.
	Selected = false;
	count++;
	ID = count;
}

int CFigure::getID() const
{
	return ID;
}
color CFigure::GetFillColor()const
{
	return FigGfxInfo.FillClr;
}

void CFigure::SetSelected(bool s)
{	Selected = s; }

bool CFigure::IsSelected() const
{	return Selected; }


void CFigure::ChngDrawClr(color Dclr)
{	FigGfxInfo.DrawClr = Dclr; }

void CFigure::ChngFillClr(color Fclr)
{	
	FigGfxInfo.isFilled = true;
	FigGfxInfo.FillClr = Fclr; 
}

string CFigure::PrintColor()
{
	string s;
	if (UI.DrawColor == BLACK)
		s = "Drawing color is BLACK";
	else if (UI.DrawColor == BLUE)
		s = "Drawing color is BLUE";
	else if (UI.DrawColor == GREEN)
		s = "Drawing color is GREEN";
	else if (UI.DrawColor == RED)
		s = "Drawing color is RED";
	else if (UI.DrawColor == WHITE)
		s = "Drawing color is WHITE";

	string d;
	if (FigGfxInfo.isFilled == true)
	{
		if (UI.FillColor == BLACK)
			d = "Filling color is BLACK";
		else if (UI.FillColor == BLUE)
			d = "Filling color is BLUE";
		else if (UI.FillColor == GREEN)
			d = "Filling color is GREEN";
		else if (UI.FillColor == RED)
			d = "Filling color is RED";
		else if (UI.FillColor == WHITE)
			d = "Filling color is WHITE";
	}
	else 
		d = " Figure is not filled";
	
	string color = s +"  "+ d;

	return color;
}
double CFigure::area(Point p1, Point p2, Point p3)
{
	return abs((p1.x*(p2.y - p3.y) + p2.x*(p3.y - p1.y) + p3.x*(p1.y - p2.y)) / 2);
}


