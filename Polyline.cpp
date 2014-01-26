// =====
// INSA Lyon, Département Informatique
// TP C++ 3IF :  Héritage et polymorphisme
// Auteur : B3229
// =====

#include "Polyline.h"

Polyline::Polyline()
{
}

Polyline::~Polyline()
{
	for(std::list<Point*>::iterator it = points.begin();
			it != points.end();
			++it)
	{
		delete *it;
	}
}

bool Polyline::Add(Point *pPt)
{
	points.push_back(pPt);
	return true;
}

bool Polyline::Move(int pX, int pY, int pCommandId)
{
	bool moved = !GeoElt::Move(pX,pY,pCommandId);
	if(moved)
	{
		return true;
	}
	else
	{
		moved = true;
		for(std::list<Point*>::iterator it = points.begin();
				it != points.end();
				++ it)
		{
			moved = (*it)->Move(pX,pY);
			if(!moved)
				break;
		}
		return moved;
	}
}

std::string Polyline::Display(std::string aName)
{
	std::ostringstream description;
	description << "PL " << aName;
  for(std::list<Point*>::iterator it = points.begin(); it != points.end(); ++ it)
  {
		description << " " << (*it)->getX() << " " << (*it)->getY();
	}
	return description.str();
}
