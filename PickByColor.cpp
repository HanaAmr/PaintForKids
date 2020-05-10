#include"PickByColor.h"
#include"ApplicationManager.h"
#include"GUI/Input.h"
#include"GUI/Output.h"

#include"Figures/CRectangle.h"
#include "CTriangle.h"
#include "CLine.h"
#include"Figures/CFigure.h"
#include"CRhombus.h"
#include"CEllipse.h"

PickByColor::PickByColor(ApplicationManager*pApp) :Action(pApp)
{
	
	CorrectCount = 0;
	FalseCount = 0;
	FiguresCount = pApp->GetFigCount();
	BlackCount = pApp->GetBlackCount();
	WhiteCount = pApp->GetWhiteCount();
	RedCount = pApp->GetRedCount();
	GreenCount = pApp->GetGreenCount();
	BlueCount = pApp->GetBlueCount();
}

PickByColor::~PickByColor()
{

}


void PickByColor::ReadActionParameters()
{
	pManager->UpdateInterface();
	//Get a Pointer Output Interface
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	random = rand() % (5);
	do
	{
		switch (random)
		{
			//Black
		case 0:
		{
			if (BlackCount != 0)
			{
				pOut->PrintMessage("You have clicked on Pick by type, You will play on Black Color");
				PickedType = BlackCount;

				break;

			}
			else
			{
				random = rand() % (5);
				break;
			}

		}
		//White
		case 1:
		{
			if (WhiteCount != 0)
			{
				pOut->PrintMessage("You have clicked on Pick by type, You will play on White color");
				PickedType = WhiteCount;
				break;


			}
			else
			{
				random = rand() % (5);
				break;
			}

		}

		//Green
		case 2:
		{
			if (GreenCount != 0)
			{
				pOut->PrintMessage("You have clicked on Pick by type, You will play on Green color");


				PickedType = GreenCount;
				break;


			}
			else
			{
				random = rand() % (5);
				break;
			}

		}
		//Red
		case 3:
		{
			if (RedCount != 0)
			{
				pOut->PrintMessage("You have clicked on Pick by type, You will play on Red color");

				PickedType = RedCount;
				break;
			}
			else
			{
				random = rand() % (5);
				break;
			}

		}
		//Blue
		case 4:
		{
			if (BlueCount != 0)
			{
				pOut->PrintMessage("You have clicked on Pick by type, You will play on Blue color");


				PickedType = BlueCount;
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
		//Black
	case 0:

	{
		CFigure*PickFigure = pManager->GetPickedFigure();
		if (PickFigure != NULL)
		{

			if (PickFigure->GetFillColor() == BLACK)
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



	//White
	case 1:
	{

		CFigure*PickFigure = pManager->GetPickedFigure();

		if (PickFigure != NULL)
		{

			if (PickFigure->GetFillColor() == WHITE)
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
	//Green
	case 2:
	{

		CFigure*PickFigure = pManager->GetPickedFigure();

		if (PickFigure != NULL)
		{

			if (PickFigure->GetFillColor() == GREEN)
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


	//Red
	case 3:
	{


		CFigure*PickFigure = pManager->GetPickedFigure();

		if (PickFigure != NULL)
		{
			if (PickFigure->GetFillColor() == RED)
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
	//BLUE
	case 4:
	{


		CFigure*PickFigure = pManager->GetPickedFigure();

		if (PickFigure != NULL)
		{

			if (PickFigure->GetFillColor() == BLUE)
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


void PickByColor::Execute()
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


