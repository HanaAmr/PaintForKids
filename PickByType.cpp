#include"PickByType.h"
#include"ApplicationManager.h"
#include"GUI/Input.h"
#include"GUI/Output.h"
#include"Figures/CRectangle.h"
#include "CTriangle.h"
#include "CLine.h"
#include"Figures/CFigure.h"
#include "CRhombus.h"
#include"CEllipse.h"
#include"string.h"
PickByType::PickByType(ApplicationManager*pApp) :Action(pApp)
{
	
	CorrectCount = 0;
	FalseCount = 0;
	FiguresCount = pApp->GetFigCount();
	EllipseCount = pApp->GetEllipseCount();
	RhombusCount = pApp->GetRhombusCount();
	RectangleCount = pApp->GetRectangleCount();
	LineCount = pApp->GetLineCount();
	TriangleCount = pApp->GetTriangleCount();
	PickedType = 0;
	Output*pOut = pApp->GetOutput();


}

PickByType::~PickByType()
{

}

void PickByType::ReadActionParameters()
{
	pManager->UpdateInterface();
	//Get a Pointer Output Interface
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	random = rand() % 5;
	do
	{
		switch (random)
		{
			//Ellipse
		case 0:
		{
			if (EllipseCount != 0)
			{
				pOut->PrintMessage("You have clicked on Pick by type, You will play on Ellipse shape");
				PickedType = EllipseCount;

				//break;
				break;
			}
			else
			{
				random = rand() % (5);
				break;
			}

		}
		//Line
		case 1:
		{
			if (LineCount != 0)
			{
				pOut->PrintMessage("You have clicked on Pick by type, You will play on Line shape");
				PickedType = LineCount;
				break;


			}
			else
			{
				random = rand() % (5);
				break;
			}

		}

		//Rectangle
	case 2:
	{
		if (RectangleCount != 0)
		{
			pOut->PrintMessage("You have clicked on Pick by type, You will play on Rectangle shape");


			PickedType = RectangleCount;
				break;


		}
		else
		{
			random = rand() %( 5);
			break;
		}

	}
		//Rhombus
	case 3:
		{
			if (RhombusCount != 0)
			{
				pOut->PrintMessage("You have clicked on Pick by type, You will play on Rhombus shape");

				PickedType = RhombusCount;
				break;
			}
			else
			{
				random = rand() % (5);
				break;
			}

		}
		//Triangle
	case 4:
	{
		if (TriangleCount != 0)
		{
			pOut->PrintMessage("You have clicked on Pick by type, You will play on Triangle shape");


			PickedType = TriangleCount;
			break;

		}

		else
		{
			random = rand() % (5);
		}
	}
		}
	} while (PickedType == 0);

	switch (random)
	{
		//Ellipse
	case 0:

	{
		CFigure*PickFigure = pManager->GetPickedFigure();


		if (PickFigure != NULL)
		{
			CEllipse*PickedEllipse = dynamic_cast<CEllipse*>(PickFigure);
			if (PickedEllipse != NULL)
			{
				CorrectCount++;
			}
			else
			{
				FalseCount++;
			}
		}
		pManager->GetDelPickedFigure();

		break;
	}



	//Line
	case 1:
	{


		CFigure*PickFigure = pManager->GetPickedFigure();
		if (PickFigure != NULL)
		{
			CLine*PickedLine = dynamic_cast<CLine*>(PickFigure);
			if (PickedLine != NULL)
			{
				CorrectCount++;
			}
			else
			{
				FalseCount++;
			}
		}
		pManager->GetDelPickedFigure();


		break;


	}

	//Rectangle
case 2:
{

	CFigure*PickFigure = pManager->GetPickedFigure();

	if (PickFigure != NULL)
	{
		CRectangle*PickedRectangle = dynamic_cast<CRectangle*>(PickFigure);
		if (PickedRectangle != NULL)
		{
			CorrectCount++;
		}
		else
		{
			FalseCount++;
		}
	}
	pManager->GetDelPickedFigure();


	break; }



	//Rhombus
   case 3:
	{


		CFigure*PickFigure = pManager->GetPickedFigure();

		if (PickFigure != NULL)
		{
			CRhombus*PickedRhombus = dynamic_cast<CRhombus*>(PickFigure);
			if (PickedRhombus != NULL)
			{
				CorrectCount++;
			}
			else
			{
				FalseCount++;
			}
		}
		pManager->GetDelPickedFigure();

		break;



	}
	//Triangle
case 4:
{


	CFigure*PickFigure = pManager->GetPickedFigure();

	if (PickFigure != NULL)
	{
		CTriangle*PickedTriangle = dynamic_cast<CTriangle*>(PickFigure);
		if (PickedTriangle != NULL)
		{
			CorrectCount++;
		}
		else
		{
			FalseCount++;
		}
	}
	pManager->GetDelPickedFigure();

	break;
}

	}
}



void PickByType::Execute()
{
	do
	{
		pManager->UpdateArray();

		ReadActionParameters();


	} while (CorrectCount != PickedType);

	Output* pOut = pManager->GetOutput();
	Message = "Correct Counter = " + to_string(CorrectCount) + " False Counter = " + to_string(FalseCount);

	pOut->PrintMessage(Message);

}
