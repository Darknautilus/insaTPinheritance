// =====
// INSA Lyon, Département Informatique
// TP C++ 3IF :  Héritage et polymorphisme
// Auteur : B3229
// =====

#include "Agregated.h"

Agregated::Agregated()
{
}

Agregated::~Agregated()
{
}

bool Agregated::Add(std::string aName, GeoElt *pElt)
{
	elements.insert(make_pair(aName,pElt));
}

bool Agregated::Move(int pX,int pY)
{
	bool moved = true;
	for(std::map<std::string,GeoElt*>::iterator it = elements.begin();it != elements.end();++it)
	{
		moved = (it->second)->Move(pX,pY);
	}
	return moved;
}

std::string Agregated::Display(std::string aName)
{
	std::ostringstream description;
	description << "Agregated " << aName ;
  for(std::map<std::string,GeoElt*>::iterator it = elements.begin(); it != elements.end();++it)
	{
		description << " " << it->first;
	}
	description << std::endl;

	return description.str();
}
