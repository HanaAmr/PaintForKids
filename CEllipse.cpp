#include "CEllipse.h"
#include "math.h"



CEllipse::CEllipse(Point P1, GfxInfo FigureGfxInfo) : CFigure(FigureGfxInfo)
{
	Corner1 = P1;
}

void CEllipse::Draw(Output* pOut) const
{
	//Call Output::DrawEllipse to draw a ellipse on the screen	
	pOut->DrawEllipse(Corner1,FigGfxInfo, Selected);
}

bool CEllipse::IsInside(Point p)
{
	if ((((pow((p.x - Corner1.x), 2)) / (100 * 100)) + ((pow((p.y - Corner1.y), 2)) / (70 * 70))) <= 1)
		return true;
	return false;
}
void CEllipse::PrintInfo(Output*pOut)
{
	std::string x = std::to_string(Corner1.x);                //changing figure's info into string
	std::string y = std::to_string(Corner1.y);
	std::string id = std::to_string(ID);
	string s = CFigure::PrintColor();


	pOut->PrintMessage(" Ellipse Selected..ID= " + id + " Centre Point:(" + x + (",") + y + ") Major axis=200  Minor axis=140"+"  "+s);

}
void CEllipse::Save(ofstream &out)

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
	out << "ELLIPSE" << "  " << ID << "  " << Corner1.x << "  " << Corner1.y << "  " << Color << "  " << Fill << "  " << endl;

}

void CEllipse::Load(ifstream &in)
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
Point CEllipse::GetShift(Point & p2) {
	Point p1;
	p1.x = 0;
	p1.y = 0;
	return p1;
}
CFigure* CEllipse::DrawPaste(Point p1, Point p2) {

	GfxInfo Copied_Cut_Info = (this->FigGfxInfo);
	CEllipse * NewEllipse = new CEllipse(p2, Copied_Cut_Info);
	if (p2.y - 70 <= UI.ToolBarHeight || p2.y + 70 >= UI.height - UI.StatusBarHeight)
		return NULL;
	return NewEllipse;

}
CFigure*CEllipse::First() {
	CEllipse* saved;
	saved = new CEllipse(this->Corner1, this->FigGfxInfo);
	return saved;
}


