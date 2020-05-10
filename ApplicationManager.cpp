#include "ApplicationManager.h"
#include "Actions\AddRectAction.h"
#include "AddLineAction.h"
#include "AddTriAction.h"
#include "AddRhombusAction.h"
#include "AddEllipseAction.h"
#include "Select.h"
#include "ChngDrawClrAction.h"
#include "ChngFillClrAction.h"
#include "BringtoBack_Front.h"
#include "Resize.h"
#include "Delete.h"
#include "SaveGraph.h"
#include "SaveByType.h"
#include "LoadGraph.h"
#include "CEllipse.h"
#include "CLine.h"
#include"CRhombus.h"
#include "CTriangle.h"
#include "Figures/CRectangle.h"
#include"Copy.h"
#include "Paste.h"
#include "Cut.h"
#include"SwitchToDrawMode.h"
#include"SwitchToPlayMode.h"
#include"PickByType.h"
#include"Exit.h"
#include"PickByColor.h"



//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();
	
	FigCount = 0;
		
	//Create an array of figure pointers and set them to NULL		
	for(int i=0; i<MaxFigCount; i++)
		FigList[i] = NULL;
	SelectedFig = NULL;
	SOUND = false;
}

//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//
ActionType ApplicationManager::GetUserAction() const
{
	//Ask the input to get the action from the user.
	return pIn->GetUserAction();		
}
////////////////////////////////////////////////////////////////////////////////////
//Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType) 
{
	Action* pAct = NULL;
	
	//According to Action Type, create the corresponding action object
	switch (ActType)
	{
		case DRAW_RECT:
			pAct = new AddRectAction(this);
			break;

		case DRAW_LINE:
			pAct = new AddLineAction(this);     ///create AddLineAction here
			break;

		case DRAW_TRI:
			pAct = new AddTriAction(this);   ///create AddTriAction here
			break;
		case DRAW_ELLIPSE:
			pAct = new AddEllipseAction(this);   ///create AddEllipseAction here
			break;
		case DRAW_RHOMBUS:
			pAct = new AddRhombusAction(this);   ///create AddRhombusAction here
			break;
		case SELECT:
			pAct = new Select(this);
			break;
		case CHNG_DRAW_CLR:
			pAct = new ChngDrawClrAction(this);
			break;
		case CHNG_FILL_CLR:
			pAct = new ChngFillClrAction(this);
			break;
		case DEL:
			pAct = new Delete(this);
			break;
		case COPY:
			pAct = new Copy(this);
			break;
		case CUT:
			pAct = new Cut(this);
			break;
		case PASTE:
			pAct = new Paste(this);
			break;
		case SAVE:
			pAct = new SaveGraph(this);
			break;
		case SAVE_BY_TYPE:
			pAct = new SaveByType(this);
			break;
		case LOAD:
			pAct = new LoadGraph(this);
			break;
		case BringToBack_Front:
			pAct = new BringtoBack_Front(this);
			break;
		case Sound:
			SetSound();
			break;
		case EXIT:
			pAct = new Exit(this);
			///create ExitAction here
			break;

		case TO_DRAW:
			pAct = new SwitchToDrawMode(this);
			break;

		case FIGURE_TYPE:
			pAct = new PickByType(this);
			break;

		case FIGURE_COLOR:
			pAct = new PickByColor(this);
			break;

		case TO_PLAY:
			pAct = new SwitchToPlayMode(this);
			break;

		
		case STATUS:	//a click on the status bar ==> no action
			return;
	}
	
	//Execute the created action
	if(pAct != NULL)
	{
		pAct->Execute();//Execute
		delete pAct;	//Action is not needed any more ==> delete it
		pAct = NULL;
	}
}
//==================================================================================//
//						Figures Management Functions								//
//==================================================================================//

//Add a figure to the list of figures
void ApplicationManager::AddFigure(CFigure* pFig)
{
	if(FigCount < MaxFigCount )
		FigList[FigCount++] = pFig;	
}
////////////////////////////////////////////////////////////////////////////////////
CFigure *ApplicationManager::GetFigure(int x, int y) const
{
	Point p;
	p.x = x;
	p.y = y;
	for (int i = FigCount-1; i >=0; i--)
	{
		if (FigList[i]->IsInside(p))
			return FigList[i];
	}
	//If a figure is found return a pointer to it.
	//if this point (x,y) does not belong to any figure return NULL


	//Add your code here to search for a figure given a point x,y	
	//Remember that ApplicationManager only calls functions do NOT implement it.

	return NULL;
}
void ApplicationManager::SetClipboard(CFigure * c)
{
	Clipboard = c;
}
CFigure*  ApplicationManager::GetClipboard()
{

	return Clipboard;
}
bool ApplicationManager::IsCutOrCopy()
{
	return CutOrCopy;
}
void ApplicationManager::SetIsCutOrCopy(bool x)
{
	CutOrCopy = x;
}
void ApplicationManager::DeleteSelectedFigure()
{
	int j = getSelectedFigIndex();
	if (j != -1) {
		SelectedFig = NULL;
		//delete FigList[j];
		for (int i = j; i < FigCount - 1; i++)
			FigList[i] = FigList[i + 1];

		FigList[FigCount - 1] = NULL;
		--FigCount;
	}
}
int ApplicationManager::getFigCount() const

{

	return FigCount;

}

void ApplicationManager::SaveAll(ofstream & out)
{
	for (int i = 0; i < FigCount; i++)
	{
		FigList[i]->Save(out);
	}
}


void ApplicationManager::DeleteAllFigs()
{
	for (int i = 0; i < FigCount; i++)
	{
		delete FigList[i];
		FigList[i] = NULL;
	}
	FigCount = 0;
}


void ApplicationManager::Save_By_Type(ActionType A, ofstream &out)
{
	int FigNewCount = 0;
	switch (A)
	{
	case DRAW_RECT:
		for (int i = 0; i < FigCount; ++i)
			if (dynamic_cast <CRectangle*> (FigList[i]) != NULL)
				FigNewCount++;
		break;

	case DRAW_TRI:
		for (int i = 0; i < FigCount; ++i)
			if (dynamic_cast <CTriangle*> (FigList[i]) != NULL)
				FigNewCount++;
		break;

	case DRAW_LINE:
		for (int i = 0; i < FigCount; ++i)
			if (dynamic_cast <CLine*> (FigList[i]) != NULL)
				FigNewCount++;
		break;

	case DRAW_ELLIPSE:
		for (int i = 0; i < FigCount; ++i)
			if (dynamic_cast<CEllipse*> (FigList[i]) != NULL)
				FigNewCount++;
		break;


	case DRAW_RHOMBUS:
		for (int i = 0; i < FigCount; ++i)
			if (dynamic_cast<CRhombus*> (FigList[i]) != NULL)
				FigNewCount++;
		break;

	default:
		break;
	}
	out << FigNewCount << endl; // Save the new count in the file
	switch (A)
	{
	case DRAW_RECT:
		for (int i = 0; i < FigCount; ++i)
			if (dynamic_cast <CRectangle*> (FigList[i]) != NULL)
				FigList[i]->Save(out);
		break;

	case DRAW_TRI:
		for (int i = 0; i < FigCount; ++i)
			if (dynamic_cast <CTriangle*> (FigList[i]) != NULL)
				FigList[i]->Save(out);
		break;

	case DRAW_LINE:
		for (int i = 0; i < FigCount; ++i)
			if (dynamic_cast <CLine*> (FigList[i]) != NULL)
				FigList[i]->Save(out);
		break;

	case DRAW_ELLIPSE:
		for (int i = 0; i < FigCount; ++i)
			if (dynamic_cast<CEllipse*> (FigList[i]) != NULL)
				FigList[i]->Save(out);
		break;


	case DRAW_RHOMBUS:
		for (int i = 0; i < FigCount; ++i)
			if (dynamic_cast<CRhombus*> (FigList[i]) != NULL)
				FigList[i]->Save(out);
		break;

	default:
		break;
	}
}


void ApplicationManager::setSelectedfig(CFigure* c)
{
	SelectedFig = c;
}
CFigure * ApplicationManager::getSelected()
{
	return SelectedFig;
}
void ApplicationManager::GetInfo(CFigure* c)
{
	//c->PrintInfo();
}

color ApplicationManager::GetColor(int &test)
{
	ActionType a = pIn->GetUserAction();
	switch (a)
	{
      case COLORBLACK:
	   {
		 pOut->PrintMessage("You chose the color BLACK");
		 return BLACK;
	   }
      case COLORBLUE:
	   {
		  pOut->PrintMessage("You chose the color BLUE");
		 return BLUE;
	   }
	   case COLORWHITE:
	   {
		 pOut->PrintMessage("You chose the color WHITE");
		 return WHITE;
	   } 
	   case COLORRED:
	   {
		 pOut->PrintMessage("You chose the color RED");
		 return RED;
	   }
	   case COLORGREEN:
	   {
	     pOut->PrintMessage("You chose the color GREEN");
		 return GREEN;
	   }
	}
	test = 0;
	return UI.BkGrndColor;
}

float ApplicationManager::GetScalingFactor()
{
	pOut->PrintMessage("Please enter the scaling factor: 1 for Quarter , 2 for Half , 3 for Double , 4 for Four Times");
	while (1)
	{
		string s = pIn->GetString(pOut);
		if (s == "1")
		{
			return 0.25;
			break;
		}
		else if (s == "2")
		{
			return 0.5;
			break;
		}
		else if (s == "3")
		{
			return 2;
			break;
		}
		else if (s == "4")
		{
			return 4;
			break;
		}
	} 

}

int ApplicationManager::getSelectedFigIndex() const
{
	for (int i = 0; i < FigCount; i++)
		if (FigList[i]->IsSelected())
			return i;
	return -1;
}

void ApplicationManager::SetSound()
{
	SOUND = !SOUND;
	if (SOUND == true)
		pOut->PrintMessage("Sound is Activated");
	else
		pOut->PrintMessage("Sound is Deactivated");
}

bool ApplicationManager::getSound()
{
	return SOUND;
}

void ApplicationManager::swaplist(int i, int type)  // swaps the list of figures
{
	if (type == 1)                                  // used to bring FigList[i] to the front
	{
		for (int j = i; j < FigCount - 1; j++)
		{
			CFigure* c = FigList[j];
			FigList[j] = FigList[j + 1];
			FigList[j + 1] = c;
		}
	}
	else if (type == 2)                            // used to bring FigList[i] to the back
	{
		for (int j = i; j > 0; j--)
		{
			CFigure* c = FigList[j];
			FigList[j] = FigList[j - 1];
			FigList[j - 1] = c;
		}
	}
}

int ApplicationManager::GetFigCount()const
{
	return FigCount;
}


int ApplicationManager::GetEllipseCount()const
{
	int count = 0;
	for (int i = 0; i < FigCount; i++)
	{
		CEllipse* EllipseFig = dynamic_cast<CEllipse*>(FigList[i]);
		if (EllipseFig != NULL)

			count++;
	}
	return count;
}

int ApplicationManager::GetLineCount()const
{
	int count = 0;
	for (int i = 0; i < FigCount; i++)
	{
		CLine * LineFig = dynamic_cast<CLine*>(FigList[i]);
		if (LineFig != NULL)
			count++;
	}
	return count;
}

int ApplicationManager::GetRhombusCount()const
{
	int count = 0;
	for (int i = 0; i < FigCount; i++)
	{
		CRhombus* RhombusFig = dynamic_cast<CRhombus*>(FigList[i]);
		if (RhombusFig != NULL)
			count++;
	}
	return count;
}

int ApplicationManager::GetTriangleCount()const
{
	int count = 0;
	for (int i = 0; i < FigCount; i++)
	{
		CTriangle* TriangleFig = dynamic_cast<CTriangle*>(FigList[i]);
		if (TriangleFig != NULL)
			count++;
	}
	return count;
}

int ApplicationManager::GetRectangleCount()const
{
	int count = 0;
	for (int i = 0; i < FigCount; i++)
	{
		CRectangle* RectangleFig = dynamic_cast<CRectangle*>(FigList[i]);
		if (RectangleFig != NULL)
			count++;
	}
	return count;
}
//Draw all figures in the array user pass to
void ApplicationManager::DrawNewInterface(CFigure**Array1, int size1) const
{
	for (int i = 0; i < size1; i++)
	{
		if (Array1[i] != NULL)
			Array1[i]->Draw(pOut);
	}
	//Call Draw function (virtual member fn)
}

void ApplicationManager::CopyFigList()
{
	size = FigCount;
	for (int i = 0; i < size; i++)
	{
		CopyArray[i] = FigList[i];
	}
}

void ApplicationManager::GetDelPickedFigure()
{

	Point p;
	pIn->GetPointClicked(p.x, p.y);

	CFigure* PickedFigure = GetFigure(p.x, p.y);
	PickedFigure->SetSelected(true);
	DeleteSelectedFigure();
	pOut->ClearDrawArea();
	UpdateInterface();
}

CFigure* ApplicationManager::GetPickedFigure()
{

	Point p;
	pIn->GetPointClicked(p.x, p.y);
	if (p.y >= 0 && p.y < UI.ToolBarHeight)
		return NULL;
	CFigure* PickedFigure = GetFigure(p.x, p.y);
	PickedFigure->SetSelected(true);
	return PickedFigure;
}
void ApplicationManager::UpdateArray()
{
	FigCount = size;
	for (int i = 0; i < size; i++)
	{
		FigList[i] = CopyArray[i];
	}
	UpdateInterface();
}


void ApplicationManager::DeleteCopyArray(CFigure**Array, int size)
{
	for (int i = 0; i < size; i++)
		delete Array[i];
	delete[]Array;
}

int ApplicationManager::GetBlackCount()const
{
	int count = 0;
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i]->GetFillColor() == BLACK)
			count++;
	}
	return count;
}

int ApplicationManager::GetWhiteCount()const
{
	int count = 0;
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i]->GetFillColor() == WHITE)
			count++;
	}
	return count;
}

int ApplicationManager::GetRedCount()const
{
	int count = 0;
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i]->GetFillColor() == RED)
			count++;
	}
	return count;
}

int ApplicationManager::GetGreenCount()const
{
	int count = 0;
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i]->GetFillColor() == GREEN)
			count++;
	}
	return count;
}
int ApplicationManager::GetBlueCount()const
{
	int count = 0;
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i]->GetFillColor() == BLUE)
			count++;
	}
	return count;
}





//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{	
	pOut->ClearDrawArea();
	for (int i = 0; i < FigCount; i++)
	{
			FigList[i]->Draw(pOut);		//Call Draw function (virtual member fn)
	}
		
}
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the input
Input *ApplicationManager::GetInput() const
{	return pIn; }
//Return a pointer to the output
Output *ApplicationManager::GetOutput() const
{	return pOut; }
////////////////////////////////////////////////////////////////////////////////////
//Destructor
ApplicationManager::~ApplicationManager()
{
	for(int i=0; i<FigCount; i++)
		delete FigList[i];
	delete pIn;
	delete pOut;
	
}
