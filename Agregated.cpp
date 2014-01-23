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

bool Agregated::Add(std::string pName, GeoElt *pElt)
{
	AgregatedElement elt;
	elt.element = pElt;
	elt.index = pElt->AddAgregated(this);
	elements.insert(std::make_pair(pName,elt));
	return true;
}

bool Agregated::Delete(std::string pName)
{
	std::map<std::string,AgregatedElement>::iterator it = elements.find(pName);
	if(it != elements.end())
	{
		it->second.element->DeleteAgregated(it->second.index);
		elements.erase(it);
	}
	return true;
}

bool Agregated::Move(int pX,int pY)
{
	bool moved = true;
	for(std::map<std::string,AgregatedElement>::iterator it = elements.begin();it != elements.end();++it)
	{
		moved = it->second.element->Move(pX,pY);
	}
	return moved;
}

std::string Agregated::Display(std::string aName)
{
	std::ostringstream description;
	description << "OA " << aName ;
  for(std::map<std::string,AgregatedElement>::iterator it = elements.begin(); it != elements.end();++it)
	{
		description << " " << it->first;
	}
	description << std::endl;

	return description.str();
}
