// =====
// INSA Lyon, Département Informatique
// TP C++ 3IF :  Héritage et polymorphisme
// Auteur : B3229
// =====

#include "Circle.h"

Circle::Circle(int pX, int pY, int pR):center(Point(pX,pY)), radius(pR)
{
}

Circle::~Circle()
{
}

bool Circle::Move(int pX, int pY, int pCommandId)
{
	if(GeoElt::Move(pX,pY,pCommandId))
		return center.Move(pX, pY);
	else
		return true;
}

std::string Circle::Display(std::string aName)
{
	std::ostringstream description;
	description << "C " << aName <<" " << center.getX() << " " << center.getY() << " " << radius;
	return description.str();
}
