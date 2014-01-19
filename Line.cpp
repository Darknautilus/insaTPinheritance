// =====
// INSA Lyon, Département Informatique
// TP C++ 3IF :  Héritage et polymorphisme
// Auteur : B3229
// =====

#include "Line.h"
#include <iostream>
#include <sstream>
using namespace std;

Line::Line(Point* pFirst, Point* pSecond)
{
	ends.push_back(pFirst);
	ends.push_back(pSecond);
}

Line::~Line()
{
}

bool Line::Move(int pX, int pY)
{
	bool moved = true;
	for(std::list<Point*>::iterator it = ends.begin();
			moved && it != ends.end();
			++it)
	{
		moved = (*it)->Move(pX,pY);
	}
	return moved;
}

string Line::Display(string aName)
{
	ostringstream description;
  description << "L " << aName<<" " ;
	for(std::list<Point*>::iterator it = ends.begin(); it != ends.end(); ++it)
  {
		description << (*it)->getX() << " " << (*it)->getY() << " " ;
	}
	
	description << endl;
	return description.str();
}

