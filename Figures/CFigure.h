#ifndef CFIGURE_H
#define CFIGURE_H

#include "..\defs.h"
#include "..\GUI\Output.h"
#include "string"
#include <fstream>

//Base class for all figures
class CFigure
{
protected:
	int ID;		//Each figure has an ID
	bool Selected;	//true if the figure is selected.
	GfxInfo FigGfxInfo;	//Figure graphis info
	static int count;
	double area(Point p1, Point p2, Point p3);

	
	/// Add more parameters if needed.

public:
	CFigure(GfxInfo FigureGfxInfo);
	int getID() const;
	virtual color GetFillColor()const;


	void SetSelected(bool s);	//select/unselect the figure
	bool IsSelected() const;	//check whether fig is selected

	virtual void Draw(Output* pOut) const  = 0 ;		//Draw the figure
	
	void ChngDrawClr(color Dclr);	//changes the figure's drawing color
	void ChngFillClr(color Fclr);	//changes the figure's filling color
	virtual bool IsInside(Point p)=0 ;
	virtual void PrintInfo(Output* pOut)=0;
	string PrintColor();
	virtual void Resize(float f) 
	{}
	virtual void Save(ofstream &out) = 0;
	virtual void Load(ifstream &in) = 0;
	virtual CFigure* DrawPaste(Point p1,Point p2) = 0;
	virtual Point GetShift(Point & p2) = 0;
	virtual CFigure* First() = 0;


	///The following functions should be supported by the figure class
	///It should be overridden by each inherited figure

	///Decide the parameters that you should pass to each function	


	//virtual void Save(ofstream &OutFile) = 0;	//Save the figure parameters to the file
	//virtual void Load(ifstream &Infile) = 0;	//Load the figure parameters to the file

	//virtual void PrintInfo(Output* pOut) = 0;	//print all figure info on the status bar
};

#endif