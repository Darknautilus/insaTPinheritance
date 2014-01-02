#include "Rectangle.h"
#include <sstream>
#include <iostream>
using namespace std;

Rectangle::Rectangle(string aName, Point *pSupG, Point *pInfD):name(aName)
{
	edge.Add(pSupG);
	edge.Add(new Point(pSupG->getY(),pInfD->getX()));
	edge.Add(pInfD);
	edge.Add(new Point(pSupG->getX(),pInfD->getY()));
}

Rectangle::~Rectangle()
{
}

bool Rectangle::Move(int pX, int pY)
{
	return edge.Move(pX,pY);
}

string Rectangle::Display()
{
	ostringstream description;
	description << "R " << this.name << " " ; //todo 
	return " ";
}
