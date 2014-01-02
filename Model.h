#ifndef MODEL_H
#define MODEL_H

#include <map>
#include <vector>
#include "GeoElt.h"

class Model
{
<<<<<<< HEAD
	using namespace std;

	typedef vector<GeoElt*>::iterator itElt;
	typedef map<string,int>::iterator itIndex;
	
=======
>>>>>>> 4dc019fce05dd37a2608d06742f3fcac910c5618
	public:
		Model();
		virtual ~Model();

		bool Add(GeoElt*, std::string);
		bool Delete(std::string);
		bool Move(std::string, Point*);
		bool SaveInFile(std::string);

	protected:
<<<<<<< HEAD
		vector<GeoElt*> elements;
		map<string,int> eltIndexes;
=======
		std::list<GeoElt*> elements;
		std::map<std::string,int> eltIndexes;
>>>>>>> 4dc019fce05dd37a2608d06742f3fcac910c5618
};

#endif
