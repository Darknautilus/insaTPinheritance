#include "AO.h"
#include <sstream>
#include <iostream>
using namespace std;

AO::AO()
{
}

AO::~AO()
{
}

bool AO::Add(string aName, GeoElt *pElt)
{
	elements.insert(make_pair(aName,pElt));
}

bool AO::Move(int pX,int pY)
{
	bool moved = true;
	for(std::map<string,GeoElt*>::iterator it = elements.begin();it != elements.end();++it)
	{
		moved = (it->second)->Move(pX,pY);
	}
	return moved;
}

string AO::Display(string aName)
{
	ostringstream description;
	description << "AO " << aName ;
  for(std::map<string,GeoElt*>::iterator it = elements.begin(); it != elements.end();++it)
	{
		description << " " << it->first;
	}
	description <<endl;

	return description.str();
}
