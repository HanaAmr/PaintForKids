#include "Select.h"
#include "ApplicationManager.h"

#include "GUI\input.h"
#include "GUI\Output.h"



Select::Select(ApplicationManager * pApp) :Action(pApp)
{
}

void Select::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Click on the figure you want to select");
	pIn->GetPointClicked(P1.x, P1.y);
}
void Select::Execute()
{
	Output* pOut = pManager->GetOutput();
	ReadActionParameters();
	CFigure* fig = NULL;
	fig= pManager->GetFigure(P1.x, P1.y);
	if (fig != NULL)                                  // if user clicked on a drawn figure
	{
		if (pManager->getSelected() != NULL)          // if there was a figure selected before
		{
			if (pManager->getSelected() == fig)       // if the figure selected before was the same one as the one chosen here it should be unselected
			{
				UnSelect();
			}
			else
			{
				UnSelect();                           // if there was another figure selected.. unselect it first then select the new figure
				fig->SetSelected(true);
				pManager->setSelectedfig(fig);
				fig->PrintInfo(pOut);
			}
		}
		else                                         // if there was no figure selected before just select the new figure
		{
			fig->SetSelected(true);
			pManager->setSelectedfig(fig);
			fig->PrintInfo(pOut);
		}

	}
	else
		UnSelect();                                // if the user clicked on any empty area unselect any previously selected figure
} 

void Select::UnSelect()
{
	if (pManager->getSelected()!= NULL)
	{
		(pManager->getSelected())->SetSelected(false);
		pManager->setSelectedfig(NULL);
	}
}

Select::~Select()
{
}
