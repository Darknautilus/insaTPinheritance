// =====
// INSA Lyon, Département Informatique
// TP C++ 3IF :  Héritage et polymorphisme
// Auteur : B3229
// =====

#include "DeleteCommand.h"

DeleteCommand::DeleteCommand(Model *pModel, std::vector<std::string>& pNames) : Command(pModel,pNames)
{
}

DeleteCommand::~DeleteCommand()
{
	if(DEBUG)
		std::cout << "\tDeleteCommand destroyed" << std::endl;
}

bool DeleteCommand::Do()
{
	bool error = false;
	int i;
	GeoElt *element;
	for(i = 0; i < names.size(); i++)
	{
		element = model->Delete(names[i]);
		if(element != 0)
		{
			elements.push_back(element);
		}
		else
		{
			error = true;
			break;
		}
		
	}
	i--;
	if(error)
	{
		while(i >= 0)
		{
			model->Add(elements[i],names[i]);
			elements.pop_back();
			i--;
		}
	}
	return !error;
}

bool DeleteCommand::Undo()
{
	bool error = false;
	int i;
	for(i = 0; i < elements.size(); i++)
	{
		if(!model->Add(elements[i],names[i]))
			error = true;
	}
	return !error;
}
