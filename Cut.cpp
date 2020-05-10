#include "Cut.h"
Cut::Cut(ApplicationManager *pApp) :Action(pApp)
{


}
void Cut::ReadActionParameters()
{

	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	if (pManager->getSelected() != NULL)
	{

		pOut->PrintMessage("The selected figure is cut to clipboard");

	}
	else

		pOut->PrintMessage("Please select a figure first");
}
void Cut::Execute()
{

	Output* pOut = pManager->GetOutput();
	ReadActionParameters();
	pManager->SetClipboard(pManager->getSelected());
	pManager->SetIsCutOrCopy(true);  //neeeded in paste
	if (pManager->getSelected() != NULL)
	{
		pManager->SetIsCutOrCopy(true);
		CFigure* Original = pManager->getSelected()->First();
		pManager->SetClipboard(Original);
		(pManager->getSelected())->ChngDrawClr(GREY);
		(pManager->getSelected())->ChngFillClr(GREY);

	}
}
Cut::~Cut()
{
}