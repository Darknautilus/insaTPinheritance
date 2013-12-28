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
