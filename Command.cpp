// =====
// INSA Lyon, Département Informatique
// TP C++ 3IF :  Héritage et polymorphisme
// Auteur : B3229
// =====

#include "Command.h"

Command::Command(Model *pModel) : model(pModel)
{}

Command::Command(Model *pModel, std::vector<std::string>& pNames) : model(pModel), names(pNames)
{}

Command::Command(Model *pModel, std::vector<std::string>& pNames, std::vector<GeoElt*>& pElements) : model(pModel), elements(pElements), names(pNames)
{}


Command::~Command()
{}
