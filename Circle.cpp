#include "Circle.h"

Circle::Circle(int pX, int pY, int pR):center(Point(pX,pY)), radius(pR)
{
}

Circle::~Circle()
{
}

bool Circle::Move(int pX, int pY)
{
	return center.Move(pX, pY);
}

string Circle::Display(string aName)
{
	std::ostringstream description;
	description << "C " << aName <<" " << center.getX() << " " << center.getY() << " " << radius << std::endl;
	return description.str();
}
