#include "Circle.h"
#include <iostream>
using namespace std;

Circle::Circle(string aName, int pX, int pY, int pR) : name(aName) ,center(Point(pX,pY)), radius(pR)
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
	string description;
	description = "C " << this.name <<" " << center.getX() << " " << center.getY() << " " << radius << endl;
	return description
}
