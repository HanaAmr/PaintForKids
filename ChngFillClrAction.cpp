#include "ChngFillClrAction.h"
#include "ApplicationManager.h"

#include "GUI\input.h"
#include "GUI\Output.h"


ChngFillClrAction::ChngFillClrAction(ApplicationManager * pApp) :Action(pApp)
{
	C = UI.FillColor;
}

void ChngFillClrAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	if (pManager->getSelected() == NULL)
		pOut->PrintMessage("Please choose a figure first");
	else
	{
		pOut->PrintMessage("Choose the colour you want to fill with");
		test = 1;
		C = pManager->GetColor(test);
		if (test==0)    // same as draw color ...test is just a flag
		{
			pOut->PrintMessage("Please make sure you selected a color");
		}
	}

}

void ChngFillClrAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	ReadActionParameters();

	if (pManager->getSelected()!= NULL)
	{
		(pManager->getSelected())->ChngFillClr(C);
		pOut->setFillColor(C);

	}
	else
		pOut->PrintMessage("Please select the figure you want to change its color");
}
ChngFillClrAction::~ChngFillClrAction()
{
}
