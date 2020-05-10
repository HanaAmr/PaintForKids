#include "AddLineAction.h"
#include "CLine.h"

#include "ApplicationManager.h"

#include "GUI\input.h"
#include "GUI\Output.h"



AddLineAction::AddLineAction(ApplicationManager *pApp) :Action(pApp)
{
	if (pManager->getSound() == true)
		sndPlaySound(TEXT("Sound\\Line.wav"), SND_FILENAME | SND_ASYNC);
}
void AddLineAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Line: Click at first point");

	//Read 1st point and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);
	while (P1.y <= UI.ToolBarHeight || P1.y >= UI.height - UI.StatusBarHeight)
	{
		pOut->PrintMessage("New Line: Wrong place..Reclick at first point");
		pIn->GetPointClicked(P1.x, P1.y);
	}

	pOut->PrintMessage("New Line: Click at second point");

	//Read 2nd point and store in point P2
	pIn->GetPointClicked(P2.x, P2.y);
	while (P2.y <= UI.ToolBarHeight || P2.y >= UI.height - UI.StatusBarHeight)
	{
		pOut->PrintMessage("New Line: Wrong place..Reclick at second point");
		pIn->GetPointClicked(P2.x, P2.y);
	}

	LineGfxInfo.isFilled = pOut->getIsFilled();	//default is not filled
	//get drawing, filling colors and pen width from the interface
	LineGfxInfo.DrawClr = pOut->getCrntDrawColor();
	LineGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();
}
void AddLineAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();

	//Create a line with the parameters read from the user
	CLine *L = new CLine(P1, P2, LineGfxInfo);

	//Add the line to the list of figures
	pManager->AddFigure(L);
}

AddLineAction::~AddLineAction()
{
}
