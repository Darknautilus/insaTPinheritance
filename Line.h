#ifndef LINE_H
#define LINE_H

#include "GeoElt.h"
#include "Point.h"
#include <string>
using namespace std;

class Line : public GeoElt
{
	public:
		Line(Point*,Point*);
		virtual ~Line();

		bool Move(int,int);
		string Display(string);
		string GetName() const;

	protected:
		list<Point*> ends;
};

#endif
