#include "BringtoBack_Front.h"
#include "ApplicationManager.h"

#include "GUI\input.h"
#include "GUI\Output.h"


BringtoBack_Front::BringtoBack_Front(ApplicationManager * pApp) :Action(pApp)
{
}

void BringtoBack_Front::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	if (pManager->getSelected() == NULL)
		pOut->PrintMessage("Please choose a figure first");
	else
	{
		pOut->PrintMessage("Bring figure to front/back");
	}
}
void BringtoBack_Front::Execute()
{
	Output* pOut = pManager->GetOutput();
	ReadActionParameters();
	if (pManager->getSelected() != NULL )   
	{
		int i = pManager->getSelectedFigIndex();
		if (i != 0)
		{
			pManager->swaplist(i, 2);
			pOut->PrintMessage("Figure brought to the back");
		}
		else
		{
			pManager->swaplist(i, 1);
			pOut->PrintMessage("Figure brought to the front");
		}
		
	}
}


BringtoBack_Front::~BringtoBack_Front()
{
}
