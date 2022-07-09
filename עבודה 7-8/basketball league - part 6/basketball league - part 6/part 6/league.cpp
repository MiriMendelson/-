#include <iostream>
using namespace std;

#include "league.h"
#include "team.h"

League::League(int maxTeams) : maxTeams(maxTeams), numOfTeams(0)
{
	allTeams = new Team*[maxTeams];
}
League::~League()
{
	for (int i = 0; i < numOfTeams; i++)
		delete allTeams[i];

	delete[]allTeams;
}

bool League::addTeam(const Team& newTeam)
{
	if (numOfTeams == maxTeams)
		return false;

	// allTeams[numOfTeams] = &newTeam; // doesn't compile since newTeam is const and the pointer is not
	allTeams[numOfTeams] = new Team(newTeam);
	numOfTeams++;
	return true;
}

Team* League::getTeamByName(const char* name)
{
	for (int i = 0; i < numOfTeams; i++)
	{
		if (strcmp(name, allTeams[i]->getName()) == 0)
			return allTeams[i];
	}

	return nullptr;
}

Team* League::operator[](const char* teamName)
{
	return getTeamByName(teamName);
}

const Team* League::getTeamByName(const char* name) const
{
	for (int i = 0; i < numOfTeams; i++)
	{
		if (strcmp(name, allTeams[i]->getName()) == 0)
			return allTeams[i];
	}

	return nullptr;
}

void League::setStartDate(int arr[])
{
	for (int i = 0; i < 3; i++)
		leagueStartDate[i] = arr[i];
}

ostream& operator<<(ostream& os, const League& l)
{
	os << "The league has " << l.numOfTeams << " teams (out of " << l.maxTeams << "):\n";
	for (int i = 0; i < l.numOfTeams; i++)
	{
		os << *l.allTeams[i] << endl;
	}
	os << "The league starts at " << l.leagueStartDate[0] << "/" << l.leagueStartDate[1] << "/" << l.leagueStartDate[2] << endl;
	return os;
}