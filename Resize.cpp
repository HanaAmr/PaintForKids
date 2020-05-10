#include "Resize.h"
#include "ApplicationManager.h"

#include "GUI\input.h"
#include "GUI\Output.h"
#include "Delete.h"
#include "Select.h"


Resize::Resize(ApplicationManager * pApp) :Action(pApp)
{
	Output* pOut = pManager->GetOutput();
}

void Resize::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	if (pManager->getSelected() == NULL)
		pOut->PrintMessage("Please choose a figure first");
	else
	{
		pOut->PrintMessage("Choose the scaling factor you want");
		ScalingFactor=pManager->GetScalingFactor();
		
	}
}

void  Resize::Execute()
{
	Output* pOut = pManager->GetOutput();
	ReadActionParameters();
	if (pManager->getSelected() != NULL)
	{
		CFigure*c = pManager->getSelected();
		c->SetSelected(false);
		c->Resize(ScalingFactor);
		pManager->AddFigure(c);
		pManager->DeleteSelectedFigure();
		
	}
	
}

Resize::~Resize()
{
	Output* pOut = pManager->GetOutput();
	
}
