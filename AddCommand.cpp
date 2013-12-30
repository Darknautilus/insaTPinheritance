#include "AddCommand.h"

AddCommand::AddCommand(Model *pModel, std::string pName, GeoElt *pElt) : Command(pModel,pName,pElt)
{
}

AddCommand::~AddCommand()
{
}

bool AddCommand::Do()
{
	return model->Add(element,eltName);
}

bool AddCommand::Undo()
{
	return model->Delete(eltName);
}
