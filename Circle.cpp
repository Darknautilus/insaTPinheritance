#include "Circle.h"
#include <iostream>
#include <iostream>
using namespace std;

Circle::Circle(int pX, int pY, int pR)center(Point(pX,pY)), radius(pR)
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
	ostringstream description;
	description << "C " << aName <<" " << center.getX() << " " << center.getY() << " " << radius << endl;
	return description.str();
}
