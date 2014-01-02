#ifndef MODEL_H
#define MODEL_H

#include <string>
#include <map>
#include <vector>
#include "GeoElt.h"

class Model
{
	using namespace std;

	typedef vector<GeoElt*>::iterator itElt;
	typedef map<string,int>::iterator itIndex;
	
	public:
		Model();
		virtual ~Model();

		bool Add(GeoElt*, string);
		bool Delete(string);
		bool Move(string, Point&);
		bool SaveInFile(string);

	protected:
		vector<GeoElt*> elements;
		map<string,int> eltIndexes;
};

#endif
