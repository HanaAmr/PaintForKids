#include "CRhombus.h"



CRhombus::CRhombus(Point P1, GfxInfo FigureGfxInfo) : CFigure(FigureGfxInfo)
{
	Corner1 = P1;
}


bool CRhombus::IsInside(Point p)
{
	Point p1, p2, p3, p4;
	p1.x = Corner1.x;
	p1.y = Corner1.y + 80;
	p2.x = Corner1.x + 80;
	p2.y = Corner1.y;
	p3.x = Corner1.x;
	p3.y = Corner1.y - 80;
	p4.x = Corner1.x - 80;
	p4.y = Corner1.y;
	double A1 = area(p1, p2, p);
	double A2 = area(p2, p3, p);
	double A3 = area(p3, p4, p);
	double A4 = area(p4, p1, p);
	double A = 0.5 * 160 * 160;
	if (A == (A1 + A2 + A3 + A4))
		return true;
	return false;
}


void CRhombus::Draw(Output* pOut) const
{
	//Call Output::DrawRhombus to draw a rhombus on the screen	
	pOut->DrawRhombus(Corner1, FigGfxInfo, Selected);
}

void CRhombus::PrintInfo(Output*pOut)
{
	std::string x = std::to_string(Corner1.x);                                     //changing figure's info into string
	std::string y = std::to_string(Corner1.y);
	std::string id = std::to_string(ID);
	string s = CFigure::PrintColor();


	pOut->PrintMessage(" Rhombus Selected..ID= " + id + " Centre Point:(" + x + (",") + y + ") Length of diagonals=160"+ "  "+s);

}
void CRhombus::Save(ofstream &out)

{
	string Color, Fill;

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


	if (FigGfxInfo.isFilled)
	{
		if (int(FigGfxInfo.FillClr.ucRed) == 0 && int(FigGfxInfo.FillClr.ucGreen) == 0 && int(FigGfxInfo.FillClr.ucBlue) == 0)
			Fill = "BLACK";
		if (int(FigGfxInfo.FillClr.ucRed) == 255 && int(FigGfxInfo.FillClr.ucGreen) == 0 && int(FigGfxInfo.FillClr.ucBlue) == 0)
			Fill = "RED";
		if (int(FigGfxInfo.FillClr.ucRed) == 0 && int(FigGfxInfo.FillClr.ucGreen) == 255 && int(FigGfxInfo.FillClr.ucBlue) == 0)
			Fill = "GREEN";
		if (int(FigGfxInfo.FillClr.ucRed) == 0 && int(FigGfxInfo.FillClr.ucGreen) == 0 && int(FigGfxInfo.FillClr.ucBlue) == 255)
			Fill = "BLUE";
		if (int(FigGfxInfo.FillClr.ucRed) == 255 && int(FigGfxInfo.FillClr.ucGreen) == 255 && int(FigGfxInfo.FillClr.ucBlue) == 255)
			Fill = "WHITE";
	}
	else
		Fill = "NO_FILL";

	//saving the parameters in file
	out << "RHOMBUS" << "  " << ID << "  " << Corner1.x << "  " << Corner1.y << "  " << Color << "  " << Fill << endl;

}

void CRhombus::Load(ifstream &in)
{
	Selected = false;
	string DrawColor, FillColor;
	in >> ID;
	in >> Corner1.x >> Corner1.y;
	in >> DrawColor >> FillColor;
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

	if (FillColor == "NO_FILL")
	{
		FigGfxInfo.isFilled = false;
		FigGfxInfo.FillClr = LIGHTGOLDENRODYELLOW;
	}
	else
	{
		FigGfxInfo.isFilled = true;
		if (FillColor == "BLACK")
		{
			FigGfxInfo.FillClr = BLACK;
		}
		else if (FillColor == "RED")
		{
			FigGfxInfo.FillClr = RED;
		}
		else if (FillColor == "GREEN")
		{
			FigGfxInfo.FillClr = GREEN;
		}
		else if (FillColor == "BLUE")
		{
			FigGfxInfo.FillClr = BLUE;
		}
		else if (FillColor == "WHITE")
		{
			FigGfxInfo.FillClr = WHITE;
		}

	}
}
Point CRhombus::GetShift(Point & p2) {
	Point p1;
	p1.x = 0;
	p1.y = 0;
	return p1;
}
CFigure* CRhombus::DrawPaste(Point p1, Point p2)
{
	GfxInfo Copied_Cut_Info = (this->FigGfxInfo);
	CRhombus * NewRhombus = new CRhombus(p2, Copied_Cut_Info);
	if (p2.y - 80 <= UI.ToolBarHeight || p2.y + 80 >= UI.height - UI.StatusBarHeight)
		return NULL;
	return NewRhombus;
}
CFigure*CRhombus::First() {
	CRhombus* saved;
	saved = new CRhombus(this->Corner1, this->FigGfxInfo);
	return saved;
}

