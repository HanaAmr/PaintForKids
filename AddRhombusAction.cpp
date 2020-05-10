#include "AddRhombusAction.h"
#include "CRhombus.h"

#include "ApplicationManager.h"

#include "GUI\input.h"
#include "GUI\Output.h"



AddRhombusAction::AddRhombusAction(ApplicationManager * pApp) :Action(pApp)
{
	if (pManager->getSound() == true)
		sndPlaySound(TEXT("Sound\\Rhombus.wav"), SND_FILENAME | SND_ASYNC);
}

void AddRhombusAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Rhombus: Click at center");

	//Read center and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);
	while (P1.y <= (UI.ToolBarHeight+80) || P1.y >= (UI.height - UI.StatusBarHeight-80))
	{
		pOut->PrintMessage("New Rhombus: Wrong place..Reclick at center");
		pIn->GetPointClicked(P1.x, P1.y);
	}

	RhombusGfxInfo.isFilled = pOut->getIsFilled();	//default is not filled
	//get drawing, filling colors and pen width from the interface
	RhombusGfxInfo.DrawClr = pOut->getCrntDrawColor();
	RhombusGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

//Execute the action
void AddRhombusAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();

	//Create a rhombus with the parameters read from the user
	CRhombus *Rh = new CRhombus(P1, RhombusGfxInfo);

	//Add the rhombus to the list of figures
	pManager->AddFigure(Rh);
}

