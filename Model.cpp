// =====
// INSA Lyon, Département Informatique
// TP C++ 3IF :  Héritage et polymorphisme
// Auteur : B3229
// =====

#include "Model.h"
#include <iostream>

Model::Model()
{
}

Model::~Model()
{
	for(itElt it = elements.begin(); it != elements.end(); ++it)
	{
		delete *it;
	}
}

bool Model::Add(GeoElt *pElt, std::string pName, bool pHard)
{
	itIndex it = eltIndexes.find(pName);
	if(it == eltIndexes.end() && pHard)
	{
		elements.push_back(pElt);
		deleted.push_back(false);
		eltIndexes.insert(make_pair(pName,elements.size()-1));		
		return true;
	}
	else if(deleted.at(it->second) && !pHard)
	{
		deleted.at(it->second) = false;
		return true;
	}
	else
	{
		return false;
	}
}

GeoElt* Model::Delete(std::string pName, bool pHard)
{
	GeoElt *element = 0;
	itIndex it = eltIndexes.find(pName);
	if(it != eltIndexes.end())
	{
		int index = it->second;
		if(pHard || !deleted.at(index))
		{
			element = elements.at(index);
			if(pHard)
			{
				elements.erase(elements.begin()+index);
				deleted.erase(deleted.begin()+index);
				eltIndexes.erase(it);
			}
			else
			{
				deleted.at(index) = true;
			}
		}
	}
	return element;
}

GeoElt* Model::Move(std::string pName, Point *pDir)
{
	GeoElt *element = 0;
	itIndex it = eltIndexes.find(pName);
	if(it != eltIndexes.end() && !deleted.at(it->second))
	{
		if(elements.at(it->second)->Move(pDir->getX(),pDir->getY()))
			element = elements.at(it->second);
	}
	return element;
}

bool Model::SaveInFile(std::string pFilename)
{
	int index;
	std::ofstream save(pFilename);
	if(save.good())
	{
		for(itIndex it = eltIndexes.begin();  it!=eltIndexes.end();++it)
		{
			if(!deleted.at(it->second))
				save << elements.at(it->second)->Display(it->first);
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
	for(itIndex it = eltIndexes.begin(); it != eltIndexes.end(); ++it)
	{
		if(!deleted.at(it->second))
			std::cout << elements.at(it->second)->Display(it->first) << std::endl;
	}
}

void Model::Clear()
{
	for(itElt it = elements.begin(); it != elements.end(); ++it)
	{
		delete *it;
	}
	elements.clear();
	deleted.clear();
	eltIndexes.clear();
}
