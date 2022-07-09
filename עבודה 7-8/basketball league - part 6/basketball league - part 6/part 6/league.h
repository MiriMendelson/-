#ifndef __LEAGUE_H
#define __LEAGUE_H

class Team;

class League
{
	Team** allTeams;
	int maxTeams;
	int numOfTeams;
	int leagueStartDate[3]; // day, month, year;

	League(const League& other);
	
public:
	League(int maxTeams);
	~League();

	const League operator=(const League& other) = delete;

	bool addTeam(const Team& newTeam);

	//void print() const;

	Team* getTeamByName(const char* name);
	const Team* getTeamByName(const char* name) const;

	void setStartDate(int arr[]);

	Team* operator[](const char* teamName);

	friend ostream& operator<<(ostream& os, const League& l);
};
#endif // __LEAGUE_H