#include "Rectangle.h"

Rectangle::Rectangle(Point *pSupG, Point *pInfD)
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
