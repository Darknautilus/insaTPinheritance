// =====
// INSA Lyon, Département Informatique
// TP C++ 3IF :  Héritage et polymorphisme
// Auteur : B3229
// =====

#ifndef POINT_H
#define POINT_H

class Point
{
	public:
		Point(int,int);
		virtual ~Point();

		bool Move(int,int);
		Point *Inverse() const;
		int getX() const;
		int getY() const;

	protected:
		int x;
		int y;
};

#endif
