#ifndef MODEL_H
#define MODEL_H

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

		bool Add(GeoElt*, std::string);
		bool Delete(std::string);
		bool Move(std::string, Point*);
		bool SaveInFile(std::string);

	protected:
		vector<GeoElt*> elements;
		map<string,int> eltIndexes;
};

#endif
