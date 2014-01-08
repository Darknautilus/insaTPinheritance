#include "Rectangle.h"
#include <sstream>
#include <iostream>
using namespace std;

Rectangle::Rectangle(Point *pSupG, Point *pInfD): PtSupG(pSupG) , PtInfD(pInfD)
{
	/*
	edge.Add(pSupG);
	edge.Add(new Point(pSupG->getY(),pInfD->getX()));
	edge.Add(pInfD);
	edge.Add(new Point(pSupG->getX(),pInfD->getY()));
	*/
}

Rectangle::~Rectangle()
{
}

bool Rectangle::Move(int pX, int pY)
{
	//return edge.Move(pX,pY);
	PtSupG->Move(pX,pY);
	PtInfD->Move(pX,pY);

	return true;
}

string Rectangle::Display(string aName)
{
	ostringstream description;
	description << "R " << aName << " " << PtSupG->getX() << " " << PtSupG->getY() << " " << PtInfD->getX() << " " << PtInfD->getY()<<endl; 
	return description.str();
}
