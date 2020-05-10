#include "AddTriAction.h"
#include "CTriangle.h"

#include "ApplicationManager.h"

#include "GUI\input.h"
#include "GUI\Output.h"


AddTriAction::AddTriAction(ApplicationManager * pApp) :Action(pApp)
{
	if (pManager->getSound() == true)
		sndPlaySound(TEXT("Sound\\Triangle.wav"), SND_FILENAME | SND_ASYNC);
}

void AddTriAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Triangle: Click at first corner");

	//Read 1st corner and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);
	while (P1.y <= UI.ToolBarHeight || P1.y >= UI.height - UI.StatusBarHeight)
	{
		pOut->PrintMessage("New Triangle: Wrong place..Reclick at first corner");
		pIn->GetPointClicked(P1.x, P1.y);
	}

	pOut->PrintMessage("New Triangle: Click at second corner");

	//Read 2nd corner and store in point P2
	pIn->GetPointClicked(P2.x, P2.y);
	while (P2.y <= UI.ToolBarHeight || P2.y >= UI.height - UI.StatusBarHeight)
	{
		pOut->PrintMessage("New Tritangle: Wrong place..Reclick at second corner");
		pIn->GetPointClicked(P2.x, P2.y);
	}

	pOut->PrintMessage("New Triangle: Click at third corner");

	//Read 3st corner and store in point P3
	pIn->GetPointClicked(P3.x, P3.y);
	while (P3.y <= UI.ToolBarHeight || P3.y >=UI.height- UI.StatusBarHeight)
	{
		pOut->PrintMessage("New Triangle: Wrong place..Reclick at third corner");
		pIn->GetPointClicked(P3.x, P3.y);
	}

	TriGfxInfo.isFilled = pOut->getIsFilled();	//default is not filled
	//get drawing, filling colors and pen width from the interface
	TriGfxInfo.DrawClr = pOut->getCrntDrawColor();
	TriGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

//Execute the action
void AddTriAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();

	//Create a triangle with the parameters read from the user
	CTriangle *T = new CTriangle(P1, P2, P3, TriGfxInfo);

	//Add the triangle to the list of figures
	pManager->AddFigure(T);
}
