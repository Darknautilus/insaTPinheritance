// =====
// INSA Lyon, Département Informatique
// TP C++ 3IF :  Héritage et polymorphisme
// Auteur : B3229
// =====

#include "Polyline.h"
#include <sstream>
#include <iostream>
using namespace std;

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

bool Polyline::Move(int pX, int pY)
{
	bool moved = true;
	for(std::list<Point*>::iterator it = points.begin();
			moved && it != points.end();
			++ it)
	{
		moved = (*it)->Move(pX,pY);
	}
	return moved;
}

string Polyline::Display(string aName)
{
	ostringstream description;
	description << "PL " << aName << " " ;
  for(std::list<Point*>::iterator it = points.begin(); it != points.end(); ++ it)
  {
		description << (*it)->getX() << " " << (*it)->getY() << " " ;
	}
	description << std::endl;

	return description.str();
}
