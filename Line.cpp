#include "Line.h"
#include <iostream>
using namespace std;

Line::Line(string aName,Point* pFirst, Point* pSecond):name(aName)
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

string Line::Display()
{
        string description;
        description = "L " << this.name<<" " ;
	for(std::list<Point*>::iterator it = ends.begin();
                        it != ends.end();
                        ++it)
        {
		description << (*it)->GetX() << " " << (*it)->GetY() << " " ;
	}
	
	description << endl;
	return description;
}

