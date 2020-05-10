#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "DEFS.h"
#include "Figures\CFigure.h"
#include "GUI\input.h"
#include "GUI\output.h"

//Main class that manages everything in the application.
class ApplicationManager
{
	enum { MaxFigCount = 200 };	//Max no of figures

private:
	int FigCount;		//Actual number of figures
	CFigure* FigList[MaxFigCount];	//List of all figures (Array of pointers)

	CFigure* SelectedFig; //Pointer to the selected figure
	CFigure* Clipboard;   //Pointer to the copied/cut figure

	//Pointers to Input and Output classes
	Input *pIn;
	Output *pOut;
	bool CutOrCopy;
	bool SOUND;
	CFigure* CopyArray[MaxFigCount];
	int size;

public:	
	ApplicationManager(); 
	~ApplicationManager();
	
	// -- Action-Related Functions
	//Reads the input command from the user and returns the corresponding action type
	ActionType GetUserAction() const;
	void ExecuteAction(ActionType) ; //Creates an action and executes it
	
	// -- Figures Management Functions
	void AddFigure(CFigure* pFig);          //Adds a new figure to the FigList
	CFigure *GetFigure(int x, int y) const; //Search for a figure given a point inside the figure
	void setSelectedfig(CFigure* c);
	CFigure* getSelected();
	void DeleteSelectedFigure();
	int getSelectedFigIndex() const;
	void SetSound();
	bool getSound();

	int GetFigCount()const;//return number of figures in figure list
	int GetEllipseCount()const;//return number of ellipses in figure list
	int GetLineCount()const;//return number of lines in figure list
	int GetRectangleCount()const;//return number of Rectangles in figure list
	int GetRhombusCount()const;//return number of Rhombuses in figure list
	int GetTriangleCount()const;//return number of Triangles in figure list
	void DrawNewInterface(CFigure**Array1, int size1) const;//Draw all figures in the array user pass to
	void CopyFigList();//make a copy of FigList array 
	CFigure* GetPickedFigure();
	void DeleteCopyArray(CFigure**Array, int size);
	int GetBlackCount()const;
	int GetWhiteCount()const;
	int GetRedCount()const;
	int GetGreenCount()const;
	int GetBlueCount()const;
	void UpdateArray();
	void GetDelPickedFigure();


	void GetInfo(CFigure* c);
	color GetColor(int &test);
	float GetScalingFactor();
	//int getindex(CFigure* c);          // function used for bringing figure to back or front
	void swaplist(int i, int type);    // function used for bringing figure to back or front
	int getFigCount() const;
	void SaveAll(ofstream &);
	void DeleteAllFigs();
	void Save_By_Type(ActionType A, ofstream &out);
	void SetClipboard(CFigure * c);
	CFigure* GetClipboard();
	bool IsCutOrCopy();
	void SetIsCutOrCopy(bool x);


		
	// -- Interface Management Functions
	Input *GetInput() const; //Return pointer to the input
	Output *GetOutput() const; //Return pointer to the output
	void UpdateInterface() const;	//Redraws all the drawing window	
};

#endif