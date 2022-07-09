#ifndef __TEAM_H
#define __TEAM_H

#include "player.h"

#include <iostream>
using namespace std;


const int MAX_PLAYERS = 11;

class Team
{
public:
	enum class eAddPlayerStatus { SUCCEED, FAILED_FULL_TEAM, INVALID_BIRTH_YEAR };

private:
	char name[20];
	Player* allPlayers[MAX_PLAYERS];
	int numOfPlayers;

	Team(const Team& other);
	const Team& operator=(const Team& other);
public:
	friend class League;

	Team(const char* name);
	
	~Team();
	friend ostream& operator<<(ostream& os, const Team& t);
	eAddPlayerStatus addPlayer(const char* name = "player1", int birthYear = 1999, TShirt::eSize theSize=TShirt::eSize::XXL, const char* nickname="kuki");
	eAddPlayerStatus addPlayer(const TShirt& shirt, const char* name = "player1", int birthYear = 1999);

	bool canAddMorePlayers() const;

	const char* getName() const { return name; }

	Player* getPlayerByName(const char* name);
};

#endif // __TEAM_H

