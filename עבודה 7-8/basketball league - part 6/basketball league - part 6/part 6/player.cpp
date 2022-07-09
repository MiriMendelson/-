#include <iostream>
using namespace std;

#include "player.h"
#include "team.h"

int Player::snGenerator = 0;

Player::Player(const char* name, int birthYear, const TShirt& shirt) 
	: name(nullptr), theTShirt(shirt), serialNumber(++snGenerator), numOfPoints(0)
{
	setName(name);
	//setTShirt(shirt);
	setBirthYear(birthYear);
	numOfPoints = 0;
}

Player::Player(const char* name, int birthYear, /*const*/ TShirt&& shirt) 
	: name(nullptr), theTShirt(std::move(shirt)), serialNumber(++snGenerator), numOfPoints(0)
{
	setName(name);
	//setTShirt(shirt);
	setBirthYear(birthYear);
	numOfPoints = 0;
}

Player::~Player()
{
	delete []name;
}
void Player::setName(const char* name) 
{ 
	delete[]this->name;
	this->name = new char[strlen(name)+1];
	strcpy(this->name, name); 
}

bool Player::setBirthYear(int birthYear)
{
	if (birthYear >= 2002 || birthYear <= 1980)
	{
		return false;
	}
	else
	{
		this->birthYear = birthYear;
		return true;
	}
}

/*void Player::setTShirt(const TShirt& shirt)
{
	theTShirt = shirt;
}*/

void Player::print() const
{
	cout << "Name: " << name << " (" << serialNumber << "), birthYear: " << birthYear 
		<< ", numOfPoints: " << numOfPoints << "\t";
	theTShirt.print();
}

bool Player::operator<(const Player& other) const
{
	return (numOfPoints < other.numOfPoints);
}

bool Player::operator>(const Player& other) const
{
	return (numOfPoints > other.numOfPoints);
}

bool Player::operator==(const Player& other) const
{
	return (numOfPoints == other.numOfPoints);
}

ostream& operator<<(ostream& os, const Player& p)
{
	os << "Name: " << p.name << " (" << p.serialNumber << "), birthYear: " << p.birthYear
		<< ", numOfPoints: " << p.numOfPoints << ", tshirt: " << p.theTShirt;

	return os;
}