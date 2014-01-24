// =====
// INSA Lyon, Département Informatique
// TP C++ 3IF :  Héritage et polymorphisme
// Auteur : B3229
// =====

#include "Agregated.h"
#include "GeoElt.h"

int GeoElt::AddAgregated(Agregated* pOA)
{
	int lastInd;
	std::map<int,Agregated*>::reverse_iterator it = agregated.rbegin();
	if(it == agregated.rend())
	{
		lastInd = 0;
	}
	else
	{
		lastInd = it->first + 1;
	}
	agregated.insert(std::make_pair(lastInd,pOA));
	return lastInd;
}

bool GeoElt::DeleteAgregated(int pInd)
{
	agregated.erase(pInd);
	return true;
}

std::list<Agregated*> GeoElt::GetAgregated()
{
	std::list<Agregated*> ret;
	for(std::map<int,Agregated*>::iterator it = agregated.begin();
			it != agregated.end();
			++it)
	{
		ret.push_back(it->second);
	}
	return ret;
}

bool GeoElt::Move(int pX, int pY, int pCommandId)
{
	if(lastMoveCommandId == pCommandId)
	{
		return false;
	}
	else
	{
		lastMoveCommandId = pCommandId;
		return true;
	}
}
