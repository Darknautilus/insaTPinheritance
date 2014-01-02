#include "Command.h"

Command::Command(Model *pModel, std::string pName, GeoElt *pElt) : model(pModel), element(pElt), eltName(pName)
{}


Command::~Command()
{
}
