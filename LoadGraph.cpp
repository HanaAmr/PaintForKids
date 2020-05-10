#include"LoadGraph.h"

#include "ApplicationManager.h"

#include "Figures/CFigure.h"
#include "Figures/CRectangle.h"
#include "CEllipse.h"
#include "CRhombus.h"
#include "CTriangle.h "
#include "CLine.h"

#include "GUI\input.h"
#include "GUI\Output.h"

LoadGraph::LoadGraph(ApplicationManager *pApp) :Action(pApp)
{}


//Read Parameters for the load action
void LoadGraph::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces

	Output* pOut = pManager->GetOutput();

	Input* pIn = pManager->GetInput();


	pOut->PrintMessage("Enter file name: ");


	fileName = pIn->GetString(pOut) + ".txt";

	pOut->ClearStatusBar();

	InputFile.open(fileName);

	//check if the file doesn't exists
	if (InputFile.is_open())
	{
		pOut->PrintMessage("Your file has been loaded.");
	}
	else
	{
		pOut->PrintMessage("File not found.");
	}
}

void LoadGraph::Execute()
{
	ReadActionParameters();

	//check if the file is opened
	if (InputFile.is_open())
	{
		pManager->DeleteAllFigs();

		//read from the file the current draw color
		string DrawColor;
		InputFile >> DrawColor;
		if (DrawColor == "BLACK")
		{
			UI.DrawColor = BLACK;
		}
		else if (DrawColor == "RED")
		{
			UI.DrawColor = RED;
		}
		else if (DrawColor == "GREEN")
		{
			UI.DrawColor = GREEN;
		}
		else if (DrawColor == "BLUE")
		{
			UI.DrawColor = BLUE;
		}
		else if (DrawColor == "WHITE")
		{
			UI.DrawColor = WHITE;
		}

		//read from the file the current fill color
		string FillColor;
		InputFile >> FillColor;
		if (FillColor == "NO_FILL")
		{
			UI.FillColor = LIGHTGOLDENRODYELLOW;
		}
		else
		{
			//UI.isFilled = true;

			if (FillColor == "BLACK")
			{
				UI.FillColor = BLACK;
			}
			else if (FillColor == "RED")
			{
				UI.FillColor = RED;
			}
			else if (FillColor == "GREEN")
			{
				UI.FillColor = GREEN;
			}
			else if (FillColor == "BLUE")
			{
				UI.FillColor = BLUE;
			}
			else if (FillColor == "WHITE")
			{
				UI.FillColor = WHITE;
			}
		}


		//read from the file the current count of figures
		int FigCount;
		InputFile >> FigCount;


		Point P;
		P.x = 0; P.y = 0;
		GfxInfo FigGfxInfo;
		while (!InputFile.eof())
		{
			CFigure* pFig = NULL;
			string FigureType;

			InputFile >> FigureType;
			if (FigureType == "RECT")
			{
				pFig = new CRectangle(P, P, FigGfxInfo);

			}

			else if (FigureType == "RHOMBUS")
			{
				pFig = new CRhombus(P, FigGfxInfo);

			}

			else if (FigureType == "TRIANG")
			{
				pFig = new CTriangle(P, P, P, FigGfxInfo);
			}

			else if (FigureType == "ELLIPSE")
			{
				pFig = new CEllipse(P, FigGfxInfo);
			}

			else if (FigureType == "LINE")
			{
				pFig = new CLine(P, P, FigGfxInfo);
			}
			if (pFig != NULL)
			{
				pFig->Load(InputFile);
				pManager->AddFigure(pFig);
			}

			FigureType.clear();
			pFig = NULL;

		}
	}
}