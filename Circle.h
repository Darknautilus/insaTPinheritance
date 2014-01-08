#ifndef CIRCLE_H
#define CIRCLE_H

#include "GeoElt.h"
#include "Point.h"
#include <string>
using namespace std;

class Circle : public GeoElt
{
	public:
		Circle(int,int,int);
		virtual ~Circle();

		bool Move(int,int);
		string Display(string);
		string GetName()const;

	protected:
		int radius;
		Point center;
};

#endif
