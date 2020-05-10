#ifndef DEFS_H
#define DEFS_H

#include "CMUgraphicsLib\CMUgraphics.h"

//This file contains some global constants and definitions to be used in the project.
enum ActionType //The actions supported (you can add more if needed)
{

	DRAW_RECT,		//Draw Rectangle
	DRAW_TRI,		//Draw Triangle
	DRAW_LINE,		//Draw Line
	DRAW_ELLIPSE,		//Draw Ellipse
	DRAW_RHOMBUS,		//Draw Rhombus
	SELECT,         //Select Items
	CHNG_DRAW_CLR,	//Change the drawing color
	CHNG_FILL_CLR,	//Change the filling color
	COLORBLACK,     //Change color to black
	COLORWHITE,     //Change color to white
	COLORRED,     //Change color to red
	COLORGREEN,     //Change color to green
	COLORBLUE,     //Change color to blue
	DEL,			//Delete a figure(s)
	COPY,        //Copy figure
	CUT,           //Cut figure 
	PASTE,       //Paste figure
	SAVE,			//Save the whole graph to a file
	SAVE_BY_TYPE,	//Save the all the figures that have a specific type
	LOAD,			//Load a graph from a file

	TO_PLAY,			//Switch interface to Play mode
	BringToBack_Front,
	Sound,

	EXIT,			//Exit the application
	EMPTY,			//A click on empty place in the toolbar

	DRAWING_AREA,	//A click on the drawing area
	PLAYING_AREA,   //A click on the playing area
	STATUS,			//A click on the status bar

	FIGURE_TYPE, //a click on figure type
	FIGURE_COLOR,//A click on figure color
	TO_DRAW,		//Switch interface to Draw mode
	

	///TODO: Add more action types (if needed)-DONE
};

struct Point	//To be used for figures points
{
	int x, y;
};

struct GfxInfo	//Graphical info of each figure (you may add more members)
{
	color DrawClr;	//Draw color of the figure
	color FillClr;	//Fill color of the figure
	bool isFilled;	//Figure Filled or not
	int BorderWdth;	//Width of figure borders

};

#endif