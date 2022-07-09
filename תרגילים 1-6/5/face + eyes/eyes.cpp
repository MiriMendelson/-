#pragma warning(disable: 4996)

#include <iostream>
using namespace std;
#pragma warning(disable: 4996)

#include <string.h>
#include "eyes.h"

Eyes::Eyes(const char* color, double lashes, double eye_brows) 
	: lashesLength(lashes), eyeBrowsWidth(eye_brows)
{
	this->color = strdup(color);
	cout << "In Eyes::Eyes (color=" << this->color << ")" << endl;
}

Eyes::Eyes(const Eyes& other) 
	: lashesLength(other.lashesLength),	eyeBrowsWidth(other.eyeBrowsWidth)
{
	this->color = strdup(other.color);
	cout << "In Eyes::Eyes(copy) (color=" << this->color << ")" << endl;
}

Eyes::Eyes(Eyes&& other)
{
	color = other.color;
	other.color = nullptr;
	lashesLength = other.lashesLength;
	eyeBrowsWidth = other.eyeBrowsWidth;
	cout << "In Eyes::(move) (color=" << this->color << ")" << endl;
}

Eyes::~Eyes() 
{
	cout << "In Eyes::~Eyes ";
	if (color)
		cout << "(color = " << color << ")";
	else
		cout << " (color already deleted)";
	cout << endl;
	delete []color;
}

void Eyes::print() const
{
	cout << "color: " << color << " lashes length: " 
		<< lashesLength << " eye brows width: " << eyeBrowsWidth << endl;
}