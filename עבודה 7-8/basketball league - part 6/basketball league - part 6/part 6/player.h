#ifndef __PLAYER_H
#define __PLAYER_H

#pragma warning(disable: 4996)

#include "tshirt.h"
//#include "team.h"
class Team;

class Player
{
private:
	static int snGenerator;
	int serialNumber;
	char* name;
	int birthYear;
	TShirt theTShirt;
	const Team* theTeam;
	int numOfPoints;

	Player(const Player& other) :theTShirt(other.theTShirt), name(nullptr)
	{
		serialNumber = other.serialNumber;
		setName(other.name);
		birthYear = other.birthYear;
		theTeam = other.theTeam;
		numOfPoints = other.numOfPoints;
	}
	const Player& operator=(const Player& other);
public:
	Player(const char* name, int birthYear, const TShirt& shirt);
	Player(const char* name, int birthYear, /*const*/ TShirt&& shirt);
	//Player(const Player& other) = delete;
	
	~Player();
	void setName(const char* name);
	bool setBirthYear(int birthYear);
	void setTeam(Team* theTeam) { this->theTeam = theTeam; }

	void addPoints(int more) { numOfPoints += more; }
	const Player& operator+=(int more) { numOfPoints += more; return *this; }

	// prefix
	const Player& operator++() { numOfPoints++; return *this; }
	// postfix
	Player operator++(int) 
	{
		Player temp(*this);
		numOfPoints++;
		return temp;
	}

	bool operator<(const Player& other) const;
	bool operator>(const Player& other) const;
	bool operator==(const Player& other) const;

	inline const char* getName() const;//  { return name; }
	int getBirthYear() const { return birthYear; }

	void print() const;

	static int getNumOfPlayers() { return snGenerator; }

	friend ostream& operator<<(ostream& os, const Player& p);
};

const char* Player::getName() const
{ 
	return name; 
}
#endif  // __PLAYER_H

