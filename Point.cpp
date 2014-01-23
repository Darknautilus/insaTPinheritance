// =====
// INSA Lyon, Département Informatique
// TP C++ 3IF :  Héritage et polymorphisme
// Auteur : B3229
// =====

#include "Point.h"

std::ostream& operator <<(std::ostream &stream,Point& p)
{
	stream << "(" << p.getX() << ";" << p.getY() << ")";
}

Point::Point(int pX, int pY) : x(pX), y(pY)
{
}

Point::~Point()
{
}

bool Point::Move(int pX, int pY)
{
	x += pX;
	y += pY;
	return true;
}

Point* Point::Inverse() const
{
	return new Point((-x),(-y));
}

int Point::getX() const
{
	return x;
}

int Point::getY() const
{
	return y;
}
