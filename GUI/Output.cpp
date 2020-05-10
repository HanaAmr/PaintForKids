#include "Output.h"


Output::Output()
{
	//Initialize user interface parameters
	UI.InterfaceMode = MODE_DRAW;

	UI.width = 1480;
	UI.height = 650;
	UI.wx = 5;
	UI.wy = 5;


	UI.StatusBarHeight = 50;
	UI.ToolBarHeight = 50;
	UI.MenuItemWidth = 60;

	UI.DrawColor = BLUE;	//Drawing color
	UI.FillColor = GREEN;	//Filling color
	UI.MsgColor = RED;		//Messages color
	UI.BkGrndColor = LIGHTGOLDENRODYELLOW;	//Background color
	UI.HighlightColor = MAGENTA;	//This color should NOT be used to draw figures. use if for highlight only
	UI.StatusBarColor = TURQUOISE;
	UI.PenWidth = 3;	//width of the figures frames


	//Create the output window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);
	//Change the title
	pWind->ChangeTitle("Paint for Kids - Programming Techniques Project");

	CreateDrawToolBar();
	CreateStatusBar();
}


Input* Output::CreateInput() const
{
	Input* pIn = new Input(pWind);
	return pIn;
}

void Output::setDrawColor(color C)
{
	UI.DrawColor = C;
}
void Output::setFillColor(color c)
{
	
	UI.FillColor = c;
	setIsFilled(true);
}

//======================================================================================//
//								Interface Functions										//
//======================================================================================//

window* Output::CreateWind(int w, int h, int x, int y) const
{
	window* pW = new window(w, h, x, y);
	pW->SetBrush(UI.BkGrndColor);
	pW->SetPen(UI.BkGrndColor, 1);
	pW->DrawRectangle(0, UI.ToolBarHeight, w, h);
	return pW;
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateStatusBar() const
{
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearStatusBar() const
{
	//Clear Status bar by drawing a filled white rectangle
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateDrawToolBar() const
{
	UI.InterfaceMode = MODE_DRAW;

	//You can draw the tool bar icons in any way you want.
	//Below is one possible way

	//First prepare List of images for each menu item
	//To control the order of these images in the menu, 
	//reoder them in UI_Info.h ==> enum DrawMenuItem
	string MenuItemImages[DRAW_ITM_COUNT];

	MenuItemImages[ITM_RECT] = "images\\MenuItems\\RECTANGLE.jpg";
	MenuItemImages[ITM_TRIANGLE] = "images\\MenuItems\\TRIANGLE.jpg";
	MenuItemImages[ITM_LINE] = "images\\MenuItems\\LINE.jpg";
	MenuItemImages[ITM_ELLIPSE] = "images\\MenuItems\\ELLIPSE.jpg";
	MenuItemImages[ITM_RHOMBUS] = "images\\MenuItems\\RHOMBUS.jpg";
	MenuItemImages[ITM_SELECT] = "images\\MenuItems\\SELECT.jpg";
	MenuItemImages[ITM_DRAWCOLOR] = "images\\MenuItems\\DRAW.jpg";
	MenuItemImages[ITM_FILLCOLOR] = "images\\MenuItems\\FILL.jpg";
	MenuItemImages[ITM_COLORBLACK] = "images\\MenuItems\\BLACK.jpg";
	MenuItemImages[ITM_COLORWHITE] = "images\\MenuItems\\WHITE.jpg";
	MenuItemImages[ITM_COLORRED] = "images\\MenuItems\\RED.jpg";
	MenuItemImages[ITM_COLORGREEN] = "images\\MenuItems\\GREEN.jpg";
	MenuItemImages[ITM_COLORBLUE] = "images\\MenuItems\\BLUE.jpg";
	MenuItemImages[ITM_DELETE] = "images\\MenuItems\\DELETE.jpg";
	MenuItemImages[ITM_COPY] = "images\\MenuItems\\COPY.jpg";
	MenuItemImages[ITM_CUT] = "images\\MenuItems\\CUT.jpg";
	MenuItemImages[ITM_PASTE] = "images\\MenuItems\\PASTE.jpg";
	MenuItemImages[ITM_SAVEGRAPH] = "images\\MenuItems\\SAVEGRAPH.jpg";
	MenuItemImages[ITM_SAVEBYTYPE] = "images\\MenuItems\\SAVEBYTYPE.jpg";
	MenuItemImages[ITM_LOAD] = "images\\MenuItems\\LOAD.jpg";
	MenuItemImages[ITM_BRINGTOFRONT] = "images\\MenuItems\\BringBackFront.jpg";
	MenuItemImages[ITM_SOUND] = "images\\MenuItems\\Sound.jpg";
	MenuItemImages[ITM_PLAY] = "images\\MenuItems\\SWITCH.jpg";
	MenuItemImages[ITM_EXIT] = "images\\MenuItems\\EXIT.jpg";


	//TODO: Prepare images for each menu item and add it to the list-NOTDONE

	//Draw menu item one image at a time
	for (int i = 0; i < DRAW_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i*UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);



	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);

}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::CreatePlayToolBar() const
{
	UI.InterfaceMode = MODE_PLAY;

	string MenuItemImages[PLAY_ITM_COUNT];
	MenuItemImages[ITM_FIGURETYPE] = "images\\MenuItems\\HIDEBYTYPE (1).jpg";
	MenuItemImages[ITM_FIGURECOLOR] = "images\\MenuItems\\FIGUREBYCOLOR.jpg";
	MenuItemImages[ITM_DRAW] = "images\\MenuItems\\SWITCH.jpg";
	MenuItemImages[ITM_EXIT2] = "images\\MenuItems\\EXIT.jpg";
	///TODO: write code to create Play mode menu-NOTDONE



	pWind->SetPen(WHITE, 1);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0, 0, UI.width, UI.ToolBarHeight);

	//Play menu item one image at a time
	for (int i = 0; i < PLAY_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i*UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);



	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);

}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::ClearDrawArea() const
{
	pWind->SetPen(UI.BkGrndColor, 1);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(0, UI.ToolBarHeight, UI.width, UI.height - UI.StatusBarHeight);

}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::PrintMessage(string msg) const	//Prints a message on status bar
{
	ClearStatusBar();	//First clear the status bar

	pWind->SetPen(UI.MsgColor, 50);
	pWind->SetFont(20, BOLD, BY_NAME, "Arial");
	pWind->DrawString(10, UI.height - (int)(UI.StatusBarHeight / 1.5), msg);
}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntDrawColor() const	//get current drawing color
{
	return UI.DrawColor;
}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntFillColor() const	//get current filling color
{
	return UI.FillColor;
}
//////////////////////////////////////////////////////////////////////////////////////////

int Output::getCrntPenWidth() const		//get current pen width
{
	return UI.PenWidth;
}

void Output::setIsFilled(bool b)
{
	UI.Isfilled = b;
}

bool Output::getIsFilled()
{
	return UI.Isfilled;
}


//======================================================================================//
//								Figures Drawing Functions								//
//======================================================================================//

void Output::DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = RectGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (RectGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else
		style = FRAME;


	pWind->DrawRectangle(P1.x, P1.y, P2.x, P2.y, style);

}
void Output::DrawTriangle(Point P1, Point P2, Point P3, GfxInfo TriGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = TriGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (TriGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(TriGfxInfo.FillClr);
	}
	else
		style = FRAME;


	pWind->DrawTriangle(P1.x, P1.y, P2.x, P2.y, P3.x, P3.y, style);

}

void Output::DrawRhombus(Point P1, GfxInfo RhomGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = RhomGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (RhomGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(RhomGfxInfo.FillClr);
	}
	else
		style = FRAME;
	int px[4] = { P1.x, P1.x + 80 , P1.x ,P1.x - 80 };
	int py[4] = { P1.y + 80, P1.y , P1.y - 80 ,P1.y };


	pWind->DrawPolygon(px, py, 4, style);

}

void Output::DrawEllipse(Point P1, GfxInfo EllGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = EllGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (EllGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(EllGfxInfo.FillClr);
	}
	else
		style = FRAME;



	pWind->DrawEllipse(P1.x - 100, P1.y + 70, P1.x + 100, P1.y - 70, style);

}

void Output::DrawLine(Point P1, Point P2, GfxInfo LineGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = LineGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	style = FRAME;
	/*if (LineGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(LineGfxInfo.FillClr);
	}
	else
		style = FRAME;*/


	pWind->DrawLine(P1.x, P1.y, P2.x, P2.y, style);

}

//////////////////////////////////////////////////////////////////////////////////////////
Output::~Output()
{
	delete pWind;
}


