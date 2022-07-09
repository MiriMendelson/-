#pragma warning(disable: 4996)

#include <iostream>
using namespace std;

#include "team.h"

Team::Team(const char* name)
{
	strcpy(this->name, name);
	numOfPlayers = 0;
}

Team::Team(const Team& other)
{
	strcpy(this->name, other.name);
	numOfPlayers = 0;
}

Team::~Team()
{
	for (int i = 0; i < numOfPlayers; i++)
	{
		delete allPlayers[i];
	}
}

ostream& operator<<(ostream& os, const Team& t)
{
	os << "The team " << t.name << " has " << t.numOfPlayers << " players:" << endl;
	for (int i = 0; i < t.numOfPlayers ; i++)
	{
		os << "\t" << (i + 1) << ") ";
		os << *t.allPlayers[i] << endl;
	}

	return os;
 }

Team::eAddPlayerStatus Team::addPlayer(const char* name, int birthYear, TShirt::eSize theSize, const char* nickname)
{
	TShirt shirt(nickname, theSize);

	return addPlayer(shirt, name, birthYear);
}

Team::eAddPlayerStatus Team::addPlayer(const TShirt& shirt, const char* name, int birthYear)
{
	if (numOfPlayers == MAX_PLAYERS)
		return Team::eAddPlayerStatus::FAILED_FULL_TEAM;

	allPlayers[numOfPlayers] = new Player(name, birthYear, shirt);
	allPlayers[numOfPlayers]->setTeam(this);

	numOfPlayers++;
	return Team::eAddPlayerStatus::SUCCEED;
}

bool Team::canAddMorePlayers() const
{
	return numOfPlayers < MAX_PLAYERS;
}

Player* Team::getPlayerByName(const char* name)
{
	for (int i = 0; i < numOfPlayers; i++)
	{
		if (strcmp(name, allPlayers[i]->getName()) == 0)
			return allPlayers[i];
	}

	return nullptr;
}
