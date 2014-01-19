// =====
// INSA Lyon, Département Informatique
// TP C++ 3IF :  Héritage et polymorphisme
// Auteur : B3229
// =====

#include "Line.h"

Line::Line(Point* pFirst, Point* pSecond)
{
	ends.push_back(pFirst);
	ends.push_back(pSecond);
}

Line::~Line()
{
	for(std::list<Point*>::iterator it = ends.begin();
			it != ends.end();
			++it)
	{
		delete *it;
	}
}

bool Line::Move(int pX, int pY)
{
	bool moved = true;
	for(std::list<Point*>::iterator it = ends.begin();
			it != ends.end();
			++it)
	{
		moved = (*it)->Move(pX,pY);
		if(!moved)
			break;
	}
	return moved;
}

std::string Line::Display(std::string aName)
{
	std::ostringstream description;
  description << "L " << aName<<" " ;
	for(std::list<Point*>::iterator it = ends.begin(); it != ends.end(); ++it)
  {
		description << (*it)->getX() << " " << (*it)->getY() << " " ;
	}
	
	description << std::endl;
	return description.str();
}

