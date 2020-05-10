#include "AddEllipseAction.h"
#include "CEllipse.h"

#include "ApplicationManager.h"

#include "GUI\input.h"
#include "GUI\Output.h"


AddEllipseAction::AddEllipseAction(ApplicationManager * pApp) :Action(pApp)
{
	if (pManager->getSound() == true)
		sndPlaySound(TEXT("Sound\\Ellipse.wav"), SND_FILENAME | SND_ASYNC);
}

void AddEllipseAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Ellipse: Click at center");

	//Read 1st corner and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);
	while (P1.y <= UI.ToolBarHeight+70 || P1.y >= UI.height - UI.StatusBarHeight-70)
	{
		pOut->PrintMessage("New Elllipse : Wrong place..Reclick at center point");
		pIn->GetPointClicked(P1.x, P1.y);
	}


	EllipseGfxInfo.isFilled = pOut->getIsFilled();	//default is not filled
	//get drawing, filling colors and pen width from the interface
	EllipseGfxInfo.DrawClr = pOut->getCrntDrawColor();
	EllipseGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

//Execute the action
void AddEllipseAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();

	//Create a ellipse with the parameters read from the user
	CEllipse *E= new CEllipse(P1, EllipseGfxInfo);

	//Add the ellipse to the list of figures
	pManager->AddFigure(E);
}
