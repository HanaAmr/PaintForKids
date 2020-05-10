#include "Paste.h"
Paste::Paste(ApplicationManager *pApp) :Action(pApp)
{

}
void Paste::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();


	pOut->PrintMessage("Click on the place where you want to place the figure");
	pIn->GetPointClicked(P1.x, P1.y);
	while (P1.y <= UI.ToolBarHeight || P1.y >= UI.height - UI.StatusBarHeight)
	{
		pOut->PrintMessage("New Line: Wrong place..Reclick at first point");
		pIn->GetPointClicked(P1.x, P1.y);
	}
}
void Paste::Execute()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	if (pManager->getSelected() != NULL)
	{
		ReadActionParameters();
		Point shift;
		shift = (pManager->GetClipboard())->GetShift(P1);
	
		//for copied shapes==>
		CFigure * PastedShape = (pManager->GetClipboard())->DrawPaste(shift,P1);
		if (PastedShape != NULL)
		{
			pManager->AddFigure(PastedShape);
			if ((pManager->IsCutOrCopy() == true))
			{

				pManager->DeleteSelectedFigure();
			}

		}
		else
			pOut->PrintMessage("Figure will be drawn in a forbidden area please try redoing the operation");

		//	if(pManager->IsCutOrCopy()==1)
			   // delete original figure
	}
	else
		pOut->PrintMessage("Please Cut or Copy a figure first");

}
Paste::~Paste()
{

}