#include "AO.h"
#include <sstream>
#include <iostream>
using namespace std;

AO::AO(string aName):name(aName)
{
}

AO::~AO()
{
}

bool AO::Add(GeoElt *pElt)
{
	elements.push_back(pElt);
}

bool AO::Move(int pX,int pY)
{
	bool moved = true;
	for(std::list<GeoElt*>::iterator it = elements.begin();
			it != elements.end();
			++it)
	{
		moved = (*it)->Move(pX,pY);
	}
	return moved;
}

string AO::Display()
{
	ostringstream description;
	description << "AO " << this.name ;
        for(std::list<GeoElt*>::iterator it = elements.begin();
                        it != elements.end();
                        ++it)
	{
		description << " " <<(*it)->getName(); //methode getName a faire pour chaque classe
	}
	description <<endl;

	return description.str();
}
