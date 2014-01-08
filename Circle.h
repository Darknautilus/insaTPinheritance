#ifndef CIRCLE_H
#define CIRCLE_H

#include <string>
#include <sstream>

#include "GeoElt.h"
#include "Point.h"

using std::string;

class Circle : public GeoElt
{
	public:
		Circle(string,int,int,int);
		virtual ~Circle();

		bool Move(int,int);
		string Display();
		string GetName()const;

	protected:
		int radius;
		Point center;
		string name;
};

#endif
