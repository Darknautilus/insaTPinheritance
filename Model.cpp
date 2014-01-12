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

bool Model::Add(GeoElt *pElt, std::string pName)
{
	elements.push_back(pElt);	
	itElt itDebut = elements.begin();
	itElt itFin = elements.end();

	int index = itFin - itDebut;

	eltIndexes.insert(make_pair(pName,index));		

	return true;
}

bool Model::Delete(std::string pName)
{
	for(itIndex it = eltIndexes.begin();it!=eltIndexes.end();++it) //on cherche l'index de l'eltGeo dans le vecteur  grâce a pName
	{
		if(it->first == pName)
		{
			int index = it->second;
			elements.erase(elements.begin()+index);	
      eltIndexes.erase(it);
			
			return true;	
		}
	}
 
	return false;
}

bool Model::Move(std::string pName, Point *pDir)
{
	int index;
	bool trouve =false;
	for(itIndex it = eltIndexes.begin();it!=eltIndexes.end();++it)
	{
		if(it->first == pName)
		{
			index = it->second;
			trouve = true;	
		}
	}
	if(trouve)
		elements[index]->Move(pDir->getX(),pDir->getY());
	
	return true;
}

bool Model::SaveInFile(std::string pFilename)
{
	int index;
	std::ofstream save;
	save.open(pFilename.c_str());
	for(itIndex it = eltIndexes.begin();  it!=eltIndexes.end();++it)
	{
		index = it->second;

		save << elements[index]->Display(it->first);
	}	

	return true;
}

void Model::List()
{
	for(itIndex it = eltIndexes.begin(); it != eltIndexes.end(); ++it)
	{
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
	eltIndexes.clear();
}
