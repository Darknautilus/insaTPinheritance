#include "Polyline.h"

Polyline::Polyline()
{
}

Polyline::~Polyline()
{
	for(std::list<Point*>::iterator it = points.begin();
			it != points.end();
			++it)
	{
		delete *it;
	}
}

bool Polyline::Add(Point *pPt)
{
	points.push_back(pPt);
	return true;
}

bool Polyline::Move(int pX, int pY)
{
	bool moved = true;
	for(std::list<Point*>::iterator it = points.begin();
			moved && it != points.end();
			++ it)
	{
		moved = (*it)->Move(pX,pY);
	}
	return moved;
}
