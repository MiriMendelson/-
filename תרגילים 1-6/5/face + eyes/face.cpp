#include <iostream>
using namespace std;

#include "face.h"

Face::Face(double hair, int teeth) : hairLength(hair), numOfTeeth(teeth)
{
	cout << "In Face::Face ver #1" << endl;
}

Face::Face(Eyes&& eyes, double hair, int teeth) : eyes(std::move(eyes)), hairLength(hair), numOfTeeth(teeth)
//Face::Face(Eyes&& eyes, double hair, int teeth) : eyes(eyes), hairLength(hair), numOfTeeth(teeth)
{
	cout << "In Face::Face ver move" << endl;
}


// NOTE THE DIFFERENCE WHEN NOT PASSING eyes AS CONST& !!!!
Face::Face(const Eyes& eyes, double hair, int teeth) 
	: eyes(eyes), hairLength(hair), numOfTeeth(teeth)
{
	cout << "In Face::Face ver #2" << endl;
}

Face::~Face()
{
	cout << "In ~Face\n";
}

void Face::print() const
{
	cout << "Person-- Hair length: " << hairLength 
		 << "Num of teeth: " << numOfTeeth << endl;
	cout << "Eyes: ";
	eyes.print();
	cout << endl;
}