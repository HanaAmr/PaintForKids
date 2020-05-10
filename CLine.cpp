#include "CLine.h"



double CLine::getslope()
{
	int deltaY = Corner2.y - Corner1.y;
	int deltaX = Corner2.x - Corner1.x;
	double slope = (double)deltaY / deltaX;
	return slope;
	//return (double)((Corner2.y - Corner1.y) / (Corner2.x - Corner1.x));
}

CLine::CLine(Point P1, Point P2, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	FigGfxInfo.isFilled = false;
}

void CLine::Draw(Output* pOut) const
{
	//Call Output::DrawLine to draw a line on the screen	
	pOut->DrawLine(Corner1, Corner2, FigGfxInfo, Selected);
}

bool CLine::IsInside(Point p)
{
	if ((abs((p.x-Corner1.x)*getslope()+Corner1.y-p.y)) < 5 )
		return true;
	return false;
}

void CLine::PrintInfo(Output * pOut)
{
	std::string x = std::to_string(Corner1.x);                       //changing figure's info into string
	std::string y = std::to_string(Corner1.y);
	std::string x2 = std::to_string(Corner2.x);
	std::string y2 = std::to_string(Corner2.y);
	std::string id = std::to_string(ID);
	string s = CFigure::PrintColor();


	pOut->PrintMessage(" Line Selected..ID= "+id+" Start Point:(" + x + (",") + y + ")  End Point:(" + x2 + "," + y2 + ")"+"  "+s);
}
void CLine::Save(ofstream &out)
{
	string Color;

	if (int(FigGfxInfo.DrawClr.ucRed) == 0 && int(FigGfxInfo.DrawClr.ucGreen) == 0 && int(FigGfxInfo.DrawClr.ucBlue) == 0)
		Color = "BLACK";
	if (int(FigGfxInfo.DrawClr.ucRed) == 255 && int(FigGfxInfo.DrawClr.ucGreen) == 0 && int(FigGfxInfo.DrawClr.ucBlue) == 0)
		Color = "RED";
	if (int(FigGfxInfo.DrawClr.ucRed) == 0 && int(FigGfxInfo.DrawClr.ucGreen) == 255 && int(FigGfxInfo.DrawClr.ucBlue) == 0)
		Color = "GREEN";
	if (int(FigGfxInfo.DrawClr.ucRed) == 0 && int(FigGfxInfo.DrawClr.ucGreen) == 0 && int(FigGfxInfo.DrawClr.ucBlue) == 255)
		Color = "BLUE";
	if (int(FigGfxInfo.DrawClr.ucRed) == 255 && int(FigGfxInfo.DrawClr.ucGreen) == 255 && int(FigGfxInfo.DrawClr.ucBlue) == 255)
		Color = "WHITE";

	//saving the parameters of the figure
	out << "LINE" << "  " << getID() << "  " << Corner1.x << "  " << Corner1.y << "  " << Corner2.x << "  " << Corner2.y << "  " << Color << endl;

}

void CLine::Load(ifstream &in)
{
	Selected = false;
	in >> ID;
	in >> Corner1.x >> Corner1.y >> Corner2.x >> Corner2.y;

	string DrawColor;
	in >> DrawColor;
	if (DrawColor == "BLACK")
	{
		FigGfxInfo.DrawClr = BLACK;
	}
	else if (DrawColor == "RED")
	{
		FigGfxInfo.DrawClr = RED;
	}
	else if (DrawColor == "GREEN")
	{
		FigGfxInfo.DrawClr = GREEN;
	}
	else if (DrawColor == "BLUE")
	{
		FigGfxInfo.DrawClr = BLUE;
	}
	else if (DrawColor == "WHITE")
	{
		FigGfxInfo.DrawClr = WHITE;
	}
	FigGfxInfo.isFilled = false;


}
Point CLine::GetShift(Point & p2) {
	Point Ref;
	Ref.x = abs(Corner1.x - p2.x);
	Ref.y = abs(Corner1.y - p2.y);
	return Ref;


}
CFigure*CLine::DrawPaste(Point p1, Point p2)
{
	GfxInfo Copied_Cut_Info = (this->FigGfxInfo);
	Point p4, p3;
	p4.x = Corner1.x + p1.x;
	p4.y = Corner1.y + p1.y;
	p3.x = Corner2.x + p1.x;
	p3.y = Corner2.y + p1.y;
	CLine * NewLine = new CLine(p4, p3, Copied_Cut_Info);
	if (p4.y <= UI.ToolBarHeight || p4.y >= UI.height - UI.StatusBarHeight || p3.y <= UI.ToolBarHeight || p3.y >= UI.height - UI.StatusBarHeight)
		return NULL;
	return NewLine;
}
CFigure*CLine::First() {
	CLine* saved;
	saved = new CLine(this->Corner1, this->Corner2, this->FigGfxInfo);
	return saved;
}

