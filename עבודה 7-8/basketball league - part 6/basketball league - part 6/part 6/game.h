#ifndef __GAME_H
#define __GAME_H

#include <string>

class Team;

class Game
{
	Team& team1;
	Team& team2;
	char date[11];
	int team1Score, team2Score;

public:
	Game(Team& team1, Team& team2, const char* date) : team1(team1), team2(team2),
		team1Score(0), team2Score(0)
	{
		strcpy(this->date, date);
	}

	void setTeam1Score(int score) { team1Score = score; }
	void setTeam2Score(int score) { team2Score = score; }

	friend ostream& operator<<(ostream& os, const Game& t)
	{
		os << "Team1: " << t.team1.getName() << ", Team2: " << t.team2.getName() << " game at " << t.date;
		return os;
	}
};
#endif // __GAME_H