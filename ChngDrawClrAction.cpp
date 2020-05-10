#include "ChngDrawClrAction.h"
#include "ApplicationManager.h"

#include "GUI\input.h"
#include "GUI\Output.h"


ChngDrawClrAction::ChngDrawClrAction(ApplicationManager * pApp) :Action(pApp)
{
	C = UI.DrawColor;
}
void ChngDrawClrAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	if (pManager->getSelected() == NULL)
		pOut->PrintMessage("Please choose a figure first");
	else
	{
		pOut->PrintMessage("Choose the colour you want to draw with");
		test = 1;
		C = pManager->GetColor(test);
		if (test==0)                  // test is like a flag... if the user didnt chose any color test will be returned as 0
		{
			pOut->PrintMessage("Please make sure you selected a color");
		}
	}

}

void ChngDrawClrAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	ReadActionParameters();
	if (pManager->getSelected() != NULL && test!=0)   // if there  is a selected figure and a chosen color change the color
	{
		(pManager->getSelected())->ChngDrawClr(C);
		pOut->setDrawColor(C);
	}
}


ChngDrawClrAction::~ChngDrawClrAction()
{
}
