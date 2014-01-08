#include "Circle.h"

Circle::Circle(std::string aName, int pX, int pY, int pR) : name(aName) ,center(Point(pX,pY)), radius(pR)
{
}

Circle::~Circle()
{
}

bool Circle::Move(int pX, int pY)
{
	return center.Move(pX, pY);
}

string Circle::Display()
{
	std::ostringstream description;
	description << "C " << this->name <<" " << center.getX() << " " << center.getY() << " " << radius << std::endl;
	return description.str();
}
