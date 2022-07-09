#ifndef __TIMETABLE_H
#define __TIMETABLE_H

#include "game.h"

class Timetable
{
	Game** allGames;
	int maxGames, numOfGames;

public:
	Timetable() : maxGames(10), numOfGames(0)
	{
		allGames = new Game * [maxGames];
	}

	~Timetable()
	{
		delete[]allGames;
	}

	Timetable(const Timetable& other) : maxGames(other.maxGames), numOfGames(0)
	{
		allGames = new Game * [maxGames];
		for (int i = 0; i < other.numOfGames; i++)
		{
			*this += *other.allGames[i];
		}
	}

	void operator+=(Game& theGame)
	{
		if (numOfGames == maxGames)
		{ 
			maxGames *= 2;
			Game** temp = new Game * [maxGames];
			for (int i = 0; i < numOfGames; i++)
				temp[i] = allGames[i];

			delete[]allGames;
			allGames = temp;
		}

		allGames[numOfGames++] = &theGame;
	}

	Timetable operator+(const Timetable& other) const
	{
		Timetable res(*this);
		for (int i = 0; i < other.numOfGames; i++)
			res += *other.allGames[i];

		return res;
	}

	friend ostream& operator<<(ostream& os, const Timetable& t)
	{
		for (int i = 0; i < t.numOfGames; i++)
			os << (i+1) << ") " << *t.allGames[i] << endl;

		return os;
	}
};
#endif // __TIMETABLE_H