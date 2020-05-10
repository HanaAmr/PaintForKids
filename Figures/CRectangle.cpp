#include "CRectangle.h"


CRectangle::CRectangle(Point P1, Point P2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
}
	

void CRectangle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawRect(Corner1, Corner2, FigGfxInfo, Selected);
}


bool CRectangle::IsInside(Point p)
{
	if (p.x >= Corner1.x && p.x <= Corner2.x && p.y >= Corner1.y && p.y <= Corner2.y  || p.x >= Corner2.x && p.x <= Corner1.x && p.y >= Corner2.y && p.y <= Corner1.y  || p.x >= Corner1.x && p.x <= Corner2.x && p.y >= Corner2.y && p.y <= Corner1.y  || p.x >= Corner2.x && p.x <= Corner1.x && p.y >= Corner1.y && p.y <= Corner2.y)
		return true;
	return false;
}

void CRectangle::PrintInfo(Output* pOut)
{
	std::string x = std::to_string(Corner1.x);                                   //changing figure's info into string
	std::string y = std::to_string(Corner1.y);
	std::string x2 = std::to_string(Corner2.x);
	std::string y2 = std::to_string(Corner2.y);
	std::string width = std::to_string(abs(Corner2.x-Corner1.x));
	std::string height = std::to_string(abs(Corner2.y - Corner1.y));
	std::string id = std::to_string(ID);
	string s = CFigure::PrintColor();

	pOut->PrintMessage(" Rectangle Selected.. ID="+id+" Start Point:(" +x+ (",")+y+")  End Point:("+x2+","+y2+")  Width= "+width+" Height= "+height +"  "+ s);
	
}

void CRectangle::Resize(float f)
{
	Corner2.x = Corner1.x+f*(Corner2.x-Corner1.x);
	Corner2.y =Corner1.y+f*(Corner2.y - Corner1.y);
}
void CRectangle::Save(ofstream &out)
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
	out << "RECT" << "  " << ID << "  " << Corner1.x << "  " << Corner1.y << "  " << Corner2.x << "  " << Corner2.y << "  " << Color << "  " << Fill << endl;

}

void CRectangle::Load(ifstream &in)
{
	Selected = false;
	string DrawColor, FillColor;
	in >> ID;
	in >> Corner1.x >> Corner1.y >> Corner2.x >> Corner2.y;
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
Point CRectangle::GetShift(Point & p2) {
	Point Ref;
	Ref.x = abs(Corner1.x - p2.x);
	Ref.y = abs(Corner1.y - p2.y);
	return Ref;


}
CFigure*CRectangle::DrawPaste(Point p1, Point p2)
{
	Point p4, p3;
	p4.x = Corner1.x + p1.x;
	p4.y = Corner1.y + p1.y;
	p3.x = Corner2.x + p1.x;
	p3.y = Corner2.y + p1.y;
	GfxInfo Copied_Cut_Info = (this->FigGfxInfo);
	CRectangle * NewRectangle = new CRectangle(p2, p3, Copied_Cut_Info);
	if (p4.y <= UI.ToolBarHeight || p4.y >= UI.height - UI.StatusBarHeight || p3.y <= UI.ToolBarHeight || p3.y >= UI.height - UI.StatusBarHeight)
	{
		return NULL;
	}
	return NewRectangle;
}
CFigure*CRectangle::First() {
	CRectangle* saved;
	saved = new CRectangle(this->Corner1, this->Corner2, this->FigGfxInfo);
	return saved;
}
