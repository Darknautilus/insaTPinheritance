#include "DeleteCommand.h"

DeleteCommand::DeleteCommand(Model *pModel, std::string pName) : Command(pModel,pName,NULL)
{
}

DeleteCommand::~DeleteCommand()
{
}

bool DeleteCommand::Do()
{
	return model->Delete(eltName);
}

bool DeleteCommand::Undo()
{
	return model->Add(element,eltName);
}
