// =====
// INSA Lyon, Département Informatique
// TP C++ 3IF :  Héritage et polymorphisme
// Auteur : B3229
// =====

#include "AddCommand.h"

AddCommand::AddCommand(Model *pModel, std::vector<std::string>& pNames, std::vector<GeoElt*>& pElements) : Command(pModel,pNames,pElements), done(false)
{
}

AddCommand::~AddCommand()
{
	if(DEBUG)
		std::cout << "\tDestroying AddCommand" << std::endl;
	for(int i = 0; i < elements.size(); i++)
	{
		if(DEBUG)
			std::cout << "\t\t";
		model->Delete(names.at(i),true);
		delete elements.at(i);
	}
	if(DEBUG)
		std::cout << "\tdestroyed" << std::endl;
}

bool AddCommand::Do()
{
	bool ret;
	if(!done)
	{
		ret = model->Add(elements[0],names[0],true);
		done = true;
	}
	else
	{
		ret = model->Add(elements[0],names[0]);
	}
	return ret;
}

bool AddCommand::Undo()
{
	return model->Delete(names[0]) != 0;
}
