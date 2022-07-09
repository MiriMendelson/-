#ifndef __EYES_H
#define __EYES_H

#include <iostream>
using namespace std;

class Eyes
{
	char*  color;
	double lashesLength;
	double eyeBrowsWidth;

public:
	Eyes(const char* color="blue", double lashes=1, double eyeBrows=0.5);
	Eyes(const Eyes& other);
	Eyes(Eyes&& other);
	~Eyes();

	void print() const;

};

#endif // __EYES_H