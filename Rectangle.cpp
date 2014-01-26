// =====
// INSA Lyon, Département Informatique
// TP C++ 3IF :  Héritage et polymorphisme
// Auteur : B3229
// =====

#include "Rectangle.h"

Rectangle::Rectangle(Point *pSupG, Point *pInfD): PtSupG(pSupG) , PtInfD(pInfD)
{
}

Rectangle::~Rectangle()
{
	delete PtSupG;
	delete PtInfD;
}

bool Rectangle::Move(int pX, int pY, int pCommandId)
{
	if(GeoElt::Move(pX,pY,pCommandId))
		return (PtSupG->Move(pX,pY) && PtInfD->Move(pX,pY));
	else
		return true;
}

std::string Rectangle::Display(std::string aName)
{
	std::ostringstream description;
	description << "R " << aName << " " << PtSupG->getX() << " " << PtSupG->getY() << " " << PtInfD->getX() << " " << PtInfD->getY(); 
	return description.str();
}
