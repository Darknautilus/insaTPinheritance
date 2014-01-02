#include "AO.h"

/*
AO::AO()
{
}*/

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
	string description;
	description = "AO " << this.name ;
        for(std::list<GeoElt*>::iterator it = elements.begin();
                        it != elements.end();
                        ++it)
	{
		description << " " <<(*it)->getName(); //methode getName a faire pour chaque classe
	}
	description <<endl;

	return description;
}
