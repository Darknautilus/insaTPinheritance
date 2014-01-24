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
		std::list<Agregated*> agr = it->second.element->GetAgregated();
		for(std::list<Agregated*>::iterator it = agr.begin();
				it != agr.end();
				++it)
		{
			(*it)->SetDeleted(pName,false);
		}
		return true;
	}
	else
	{
		return false;
	}
}

GeoElt* Model::Delete(std::string pName, bool pHard)
{
	if(constants::DEBUG)
		std::cout << "Deleting "+pName << std::endl;
	GeoElt *element = 0;
	eltIt it = elements.find(pName);
	if(it != elements.end())
	{
		if(pHard || !it->second.deleted)
		{
			element = it->second.element;
			std::list<Agregated*> agr = element->GetAgregated();
			if(pHard)
			{
				elements.erase(it);
				for(std::list<Agregated*>::iterator it = agr.begin();
						it != agr.end();
						++it)
				{
					(*it)->Delete(pName);
				}
			}
			else
			{
				it->second.deleted = true;
				for(std::list<Agregated*>::iterator it = agr.begin();
						it != agr.end();
						++it)
				{
					(*it)->SetDeleted(pName,true);
				}
			}
		}
	}
	if(constants::DEBUG)
		std::cout << pName+" deleted" << std::endl;
	return element;
}

GeoElt* Model::Move(std::string pName, Point *pDir, int pCommandId)
{
	GeoElt *element = 0;
	eltIt it = elements.find(pName);
	if(it != elements.end() && !it->second.deleted)
	{
		if(it->second.element->Move(pDir->getX(),pDir->getY(), pCommandId))
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
