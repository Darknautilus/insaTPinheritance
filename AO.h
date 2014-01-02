#ifndef AO_H
#define AO_H

#include "GeoElt.h"
#include <string>
using namespace std;

class AO : public GeoElt
{
	public:
		AO(string );
		virtual ~AO();

		bool Add(GeoElt*);
		bool Move(int,int);

	protected:
		std::list<GeoElt*> elements;
		string name;
};

#endif
