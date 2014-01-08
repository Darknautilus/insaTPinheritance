#include "Model.h"

Model::Model()
{
}

Model::~Model()
{
	elements.erase(elements.begin(), elements.end());
	eltIndexes.erase(eltIndexes.begin(),eltIndexes.end());
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
			elements.erase(index);	
      eltIndexes.erase(pName);
			
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
		elements[index].Move(pDir.getX(),pDir.getY());
	
	return true;
}

bool Model::SaveInFile(std::string pFilename)
{
	ofstream save;
	save.open(pFilename, ios::out);
	string aName;
	for(itIndex it = eltIndexes.begin();  it!=eltIndexes.end();++it)
	{
		aName = it->first;
		index = it->second;

		save << elements[index].Display(aName);
	}	

	return true;
}
