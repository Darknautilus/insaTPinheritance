#include "Line.h"

Line::Line(Point* pFirst, Point* pSecond)
{
	ends.push_back(pFirst);
	ends.push_back(pSecond);
}

Line::~Line()
{
}

bool Line::Move(int pX, int pY)
{
	bool moved = true;
	for(std::list<Point*>::iterator it = ends.begin();
			moved && it != ends.end();
			++it)
	{
		moved = (*it)->Move(pX,pY);
	}
	return moved;
}
