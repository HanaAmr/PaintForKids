#ifndef UI_INFO_H
#define UI_INFO_H

#include "..\CMUgraphicsLib\CMUgraphics.h"

//User Interface information file.
//This file contains info that is needed by Input and Output classes to
//handle the user interface

enum GUI_MODE	//Graphical user interface mode
{
	MODE_DRAW,	//Drawing mode (startup mode)
	MODE_PLAY	//Playing mode
};


enum DrawMenuItem //The items of the Draw menu (you should add more items)
{
	//Note: Items are ordered here as they appear in menu
	//If you want to change the menu items order, change the order here
	ITM_RECT,		//Recangle item in menu
	ITM_TRIANGLE,
	ITM_LINE,
	ITM_ELLIPSE,
	ITM_RHOMBUS,
	ITM_SELECT,
	ITM_DRAWCOLOR,
	ITM_FILLCOLOR,
	ITM_COLORBLACK,
	ITM_COLORWHITE,
	ITM_COLORRED,
	ITM_COLORGREEN,
	ITM_COLORBLUE,
	ITM_DELETE,
	ITM_COPY,
	ITM_CUT,
	ITM_PASTE,
	ITM_SAVEGRAPH,
	ITM_SAVEBYTYPE,
	ITM_LOAD,
	ITM_PLAY,
	ITM_BRINGTOFRONT,
	ITM_SOUND,


	//TODO: Add more items names here-DONE

	ITM_EXIT,		//Exit item

	DRAW_ITM_COUNT		//no. of menu items ==> This should be the last line in this enum

};

enum PlayMenuItem //The items of the Play menu (you should add more items)
{
	//Note: Items are ordered here as they appear in menu
	//If you want to change the menu items order, change the order here

	//TODO: Add more items names here
	ITM_FIGURETYPE,
	ITM_FIGURECOLOR,
	ITM_DRAW,
	ITM_EXIT2,
	PLAY_ITM_COUNT		//no. of menu items ==> This should be the last line in this enum

};





__declspec(selectany) //This line to prevent "redefinition error"

struct UI_Info	//User Interface Info.
{
	GUI_MODE InterfaceMode;

	int	width, height,	    //Window width and height
		wx, wy,			//Window starting coordinates
		StatusBarHeight,	//Status Bar Height
		ToolBarHeight,		//Tool Bar Height (distance from top of window to bottom line of toolbar)
		MenuItemWidth;		//Width of each item in toolbar menu


	color DrawColor;		//Drawing color
	color FillColor;		//Filling color
	color HighlightColor;	//Highlighting color
	color MsgColor;			//Messages color
	color BkGrndColor;		//Background color
	color StatusBarColor;	//Status bar color
	int PenWidth;			//width of the pen that draws shapes
	bool Isfilled;          //checks whether the the figures should be filled

	/// Add more members if needed

}UI;	//create a global object UI

#endif