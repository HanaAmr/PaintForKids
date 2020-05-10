#include "Delete.h"
#include "ApplicationManager.h"

#include "GUI\input.h"
#include "GUI\Output.h"


Delete::Delete(ApplicationManager *pApp) :Action(pApp)
{}

void Delete::ReadActionParameters()
{

}


void Delete::Execute()
{
	Output* pOut = pManager->GetOutput();
	ReadActionParameters();
	if (pManager->getSelected() != NULL)
	{
		pManager->DeleteSelectedFigure();
		pOut->PrintMessage("The figure is deleted");
	}
	else
		pOut->PrintMessage("Please select a figure first to delete");
}

Delete::~Delete()
{}