#ifndef __FACE_H
#define __FACE_H

#include "eyes.h"

class Face
{
	Eyes   eyes;
	double hairLength;
	int    numOfTeeth;

public:
	Face(double hair=30, int teeth=32);
	Face(const Eyes& eyes, double hair=30, int teeth=32);
	Face(Eyes&& eyes, double hair = 30, int teeth = 32);
	~Face();

	void print() const;
};

#endif // __FACE_H