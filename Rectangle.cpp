// =====
// INSA Lyon, Département Informatique
// TP C++ 3IF :  Héritage et polymorphisme
// Auteur : B3229
// =====

#include "Rectangle.h"
#include <sstream>
#include <iostream>

Rectangle::Rectangle(Point *pSupG, Point *pInfD): PtSupG(pSupG) , PtInfD(pInfD)
{
}

Rectangle::~Rectangle()
{
	delete PtSupG;
	delete PtInfD;
}

bool Rectangle::Move(int pX, int pY)
{
	return (PtSupG->Move(pX,pY) && PtInfD->Move(pX,pY));
}

std::string Rectangle::Display(std::string aName)
{
	std::ostringstream description;
	description << "R " << aName << " " << PtSupG->getX() << " " << PtSupG->getY() << " " << PtInfD->getX() << " " << PtInfD->getY() << std::endl; 
	return description.str();
}
