// =====
// INSA Lyon, Département Informatique
// TP C++ 3IF :  Héritage et polymorphisme
// Auteur : B3229
// =====

#include "AddCommand.h"

AddCommand::AddCommand(Model *pModel, std::vector<std::string>& pNames, std::vector<GeoElt*>& pElements) : Command(pModel,pNames,pElements)
{
}

AddCommand::~AddCommand()
{
	for(int i = 0; i < elements.size(); i++)
	{
		model->Delete(names.at(i),true);
		delete elements.at(i);
	}
}

bool AddCommand::Do()
{
	return model->Add(elements[0],names[0],true);
}

bool AddCommand::Undo()
{
	return model->Delete(names[0]) != 0;
}
