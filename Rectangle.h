#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Polyline.h"
#include <string>
using namespace std;

class Rectangle : public GeoElt
{
	public:
		Rectangle(string,Point*,Point*);
		virtual ~Rectangle();

		bool Move(int,int);
		string Display();
		string GetName() const;

	protected:
		Polyline edge;
		string name;
};

#endif
