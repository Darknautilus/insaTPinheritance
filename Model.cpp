// =====
// INSA Lyon, Département Informatique
// TP C++ 3IF :  Héritage et polymorphisme
// Auteur : B3229
// =====

#include "Model.h"

Model::Model()
{
}

Model::~Model()
{
	for(eltIt it = elements.begin(); it != elements.end(); ++it)
	{
		delete it->second.element;
	}
}

bool Model::Add(GeoElt *pElt, std::string pName, bool pHard)
{
	eltIt it = elements.find(pName);
	if(it == elements.end() && pHard)
	{
		ElementMarker em;
		em.element = pElt;
		em.deleted = false;
		elements.insert(make_pair(pName,em));		
		return true;
	}
	else if(it->second.deleted && !pHard)
	{
		it->second.deleted = false;
		return true;
	}
	else
	{
		return false;
	}
}

GeoElt* Model::Delete(std::string pName, bool pHard)
{
	if(DEBUG)
		std::cout << "Deleting "+pName << std::endl;
	GeoElt *element = 0;
	eltIt it = elements.find(pName);
	if(it != elements.end())
	{
		if(pHard || !it->second.deleted)
		{
			element = it->second.element;
			if(pHard)
			{
				elements.erase(it);
			}
			else
			{
				it->second.deleted = true;
			}
		}
	}
	if(DEBUG)
		std::cout << pName+" deleted" << std::endl;
	return element;
}

GeoElt* Model::Move(std::string pName, Point *pDir)
{
	GeoElt *element = 0;
	eltIt it = elements.find(pName);
	if(it != elements.end() && !it->second.deleted)
	{
		if(it->second.element->Move(pDir->getX(),pDir->getY()))
			element = it->second.element;
	}
	return element;
}

bool Model::SaveInFile(std::string pFilename)
{
	int index;
	std::ofstream save(pFilename);
	if(save.good())
	{
		for(eltIt it = elements.begin();  it != elements.end();++it)
		{
			if(!it->second.deleted)
				save << it->second.element->Display(it->first);
		}
		return true;
	}
	else
	{
		return false;
	}
}

void Model::List()
{
	for(eltIt it = elements.begin(); it != elements.end(); ++it)
	{
		if(!it->second.deleted)
			std::cout << it->second.element->Display(it->first);
	}
}

void Model::Clear()
{
	for(eltIt it = elements.begin(); it != elements.end(); ++it)
	{
		delete it->second.element;
	}
	elements.clear();
}

GeoElt *Model::Exists(std::string pName)
{
	eltIt it = elements.find(pName);
	if(it == elements.end() || it->second.deleted)
	{
		return 0;
	}
	else
	{
		return it->second.element;
	}
}
