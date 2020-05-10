#include "CTriangle.h"




CTriangle::CTriangle(Point P1, Point P2, Point P3, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	Corner3 = P3;
}

bool CTriangle::IsInside(Point p)
{
	double A = area(Corner1, Corner2, Corner3);
	double A1 = area(p, Corner2, Corner3);
	double A2 = area(Corner1, p, Corner3);
	double A3 = area(Corner1, Corner2, p);
	if (A == A1 + A2 + A3)
		return true;
	return false;
}
void CTriangle::Draw(Output* pOut) const
{
	//Call Output::DrawTriangle to draw a triangle on the screen	
	pOut->DrawTriangle(Corner1, Corner2,Corner3, FigGfxInfo, Selected);
}

void CTriangle::PrintInfo(Output*pOut)
{
	std::string x = std::to_string(Corner1.x);                                       //changing figure's info into string
	std::string y = std::to_string(Corner1.y);
	std::string x2 = std::to_string(Corner2.x);
	std::string y2 = std::to_string(Corner2.y);
	std::string x3 = std::to_string(Corner3.x);
	std::string y3 = std::to_string(Corner3.y);
	std::string id = std::to_string(ID);
	string s = CFigure::PrintColor();


	pOut->PrintMessage("Triangle Selected.. ID= " + id + " Corner 1=(" + x + "," + y + ")  Corner 2=(" + x2 + "," + y2 + ")  Corner 3=(" + x3 + "," + y3 + ")"+ "  "+s );
}
void CTriangle::Save(ofstream &out)

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

	out << "TRIANG" << "  " << ID << "  " << Corner1.x << "  " << Corner1.y << "  " << Corner2.x << "  " << Corner2.y << "  " << Corner3.x << "  " << Corner3.y << "  " << Color << "  " << Fill << endl;

}

void CTriangle::Load(ifstream &in)
{
	Selected = false;
	string DrawColor, FillColor;
	in >> ID;
	in >> Corner1.x >> Corner1.y >> Corner2.x >> Corner2.y >> Corner3.x >> Corner3.y;
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
Point CTriangle::GetShift(Point & p2) {
	Point p1;
	p1.x = p2.x - Corner1.x;
	p1.y = p2.y - Corner1.y;
	return p1;
}
CFigure* CTriangle::DrawPaste(Point p1, Point p2)
{
	Point p5, p3, p4;
	p4.x = Corner1.x + p1.x;
	p4.y = Corner1.y + p1.y;
	p5.x = Corner2.x + p1.x;
	p5.y = Corner2.y + p1.y;
	p3.x = Corner3.x + p1.x;
	p3.y = Corner3.y + p1.y;
	GfxInfo Copied_Cut_Info = (this->FigGfxInfo);
	CTriangle * NewTriangle = new CTriangle(p4, p5, p3, Copied_Cut_Info);
	if (p4.y <= UI.ToolBarHeight || p4.y >= UI.height - UI.StatusBarHeight || p3.y <= UI.ToolBarHeight || p3.y >= UI.height - UI.StatusBarHeight || p5.y <= UI.ToolBarHeight || p5.y >= UI.height - UI.StatusBarHeight)
		return NULL;
	return  NewTriangle;
}
CFigure*CTriangle::First() {
	CTriangle* saved;
	saved = new CTriangle(this->Corner1, this->Corner2, this->Corner3, this->FigGfxInfo);
	return saved;
}

