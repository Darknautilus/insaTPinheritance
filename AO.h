#ifndef AO_H
#define AO_H

#include "GeoElt.h"

class AO : public GeoElt
{
	public:
		AO();
		virtual ~AO();

		bool Add(GeoElt*);
		bool Move(int,int);

	protected:
		std::list<GeoElt*> elements;

};

#endif
