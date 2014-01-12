#include "Controller.h"

Controller::Controller()
{
	currAction = actions.rbegin();
}

Controller::~Controller()
{
	for(std::list<Command*>::iterator it = actions.begin();
			it != actions.end();
			++it)
	{
		delete *it;
	}
}

bool Controller::Add(std::string pName, GeoElt *pElement)
{
	if(currAction != actions.rbegin())
	{
		--currAction;
		actions.erase(--(currAction.base()),actions.end());
	}
	actions.push_back(new AddCommand(&model, pName, pElement));
	currAction = actions.rbegin();
	return (*currAction)->Do();
}

bool Controller::Delete(std::string pName)
{
	if(currAction != actions.rbegin())
	{
		--currAction;
		actions.erase(--(currAction.base()),actions.end());
	}
	actions.push_back(new DeleteCommand(&model, pName));
	currAction = actions.rbegin();
	return (*currAction)->Do();
}

bool Controller::Move(std::string pName, Point *pDirection)
{
	if(currAction != actions.rbegin())
	{
		--currAction;
		actions.erase(--(currAction.base()),actions.end());
	}
	actions.push_back(new MoveCommand(&model, pName, pDirection));
	currAction = actions.rbegin();
	return (*currAction)->Do();
}

bool Controller::SaveInFile(std::string pFilename)
{
	return model.SaveInFile(pFilename);
}

bool Controller::Undo()
{
	if(currAction == actions.rend())
	{
		return false;
	}
	else
	{
		bool ret = (*currAction)->Undo();
		++currAction;
		return ret;
	}
}

bool Controller::Redo()
{
	if(currAction == actions.rbegin())
	{
		return false;
	}
	else
	{
		--currAction;
		return (*currAction)->Do();
	}
}

void Controller::List()
{
	model.List();
}

void Controller::Clear()
{
	for(std::list<Command*>::iterator it = actions.begin();
			it != actions.end();
			++it)
	{
		delete *it;
	}
	actions.clear();
	currAction = actions.rbegin();
	model.Clear();
}
