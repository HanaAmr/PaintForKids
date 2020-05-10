#include "Copy.h"
Copy::Copy(ApplicationManager *pApp) :Action(pApp)
{


}
void Copy::ReadActionParameters()
{

	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	if (pManager->getSelected() != NULL)
	{

		pOut->PrintMessage("The selected figure is copied to clipboard");
	}
	else

		pOut->PrintMessage("Please select a figure first");
}
void Copy::Execute()
{

	Output* pOut = pManager->GetOutput();
	ReadActionParameters();

	pManager->SetIsCutOrCopy(false);  //needed in paste

	CFigure* Original = pManager->getSelected()->First();
	pManager->SetClipboard(Original);
}
Copy::~Copy()
{
}