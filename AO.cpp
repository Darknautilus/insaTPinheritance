#include "AO.h"

AO::AO()
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
