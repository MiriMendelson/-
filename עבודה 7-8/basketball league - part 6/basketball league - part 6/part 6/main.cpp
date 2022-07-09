#include <iostream>
using namespace std;

#include "team.h"
#include "tshirt.h"
#include "league.h"
#include "timetable.h"
#include "game.h"

Team* readTeam();

void foo(const char* s)
{
	cout << "*** " << s << " ***\n";
}

void goo(char ch)
{
	cout << "### " << ch << " ###\n";
}
int main()
{
	/*{
		TShirt t1("p1", TShirt::eSize::L);

		int x = t1("p1p1p", 4);


		foo(t1);
		//goo(t1);

		cout << (const char*)t1 << endl;
		cout << (int)(TShirt::eSize)t1 << endl;
		cout << t1 << endl;
		
		//t1.print();
		//cout << t1 << endl;

		cout << "Enter the nickname and the size [ ";
		int numOfSizes = sizeof(TShirt::sizeStr) / sizeof(TShirt::sizeStr[0]);
		for (int i = 0; i < numOfSizes; i++)
		{
			cout << i << " (" << TShirt::sizeStr[i] << ") ";
		}
		cout << "] ";
		cin >> t1;
		cout << t1;
		
		cout << "\n";
	}*/
	/*{
		Player p1("p1", 1996, TShirt("p1p1", TShirt::eSize::L));
		Player p2("p2", 1996, TShirt("p1p1", TShirt::eSize::L));

		///p1 = p2;
	}*/
	std::cout << "Total there are " << Player::getNumOfPlayers() << std::endl;

	int numOfTeams;
	cout << "How many teams in your league? ";
	cin >> numOfTeams;
	League myLeague(numOfTeams);

	myLeague.addTeam(Team("maccabi"));
	myLeague.addTeam(Team("hapoel Jerusalem"));
	myLeague.addTeam(Team("hapoel Holon"));
	//allTeams[0] = new Team(");
	Team* temp = myLeague.getTeamByName("maccabi");
	if (temp != nullptr)
	{
		temp->addPlayer("gogo", 1999, TShirt::eSize::XL, "The Gogomat");
		temp->addPlayer("momo", 1998, TShirt::eSize::XXL, "Giant Momo");
		temp->getPlayerByName("gogo")->addPoints(3);
		temp->getPlayerByName("gogo")->addPoints(2);
		/*Player* p = temp->getPlayerByName("gogo");
		Player* p2 = temp->getPlayerByName("momo");
		cout << (*p > *p2) << endl;
		cout << (*p < *p2) << endl;
		*p += 4;
		(*p)++;
		++(*p);

		int x = 2, y;
		y = x++; // y=2, x=3
		y = ++x; // x=3, y=3
		*/
		TShirt s("Yoyo", TShirt::eSize::L);
		temp->addPlayer("yoyo-nickname", "yoyo");
		Team::eAddPlayerStatus res = temp->addPlayer();
		if (res == Team::eAddPlayerStatus::INVALID_BIRTH_YEAR)
		{
			cout << "Player's birth year is invalid\n";
		}
	}

	myLeague.getTeamByName("maccabi")->getPlayerByName("momo")->addPoints(21);
	myLeague["maccabi"]->getPlayerByName("momo")->addPoints(21);

	Timetable time1, time2;
	Game g1(*myLeague.getTeamByName("maccabi"), *myLeague.getTeamByName("hapoel Jerusalem"), "03/08/2020");
	Game g2(*myLeague.getTeamByName("maccabi"), *myLeague.getTeamByName("hapoel Holon"), "13/08/2020");
	time1 += g1;
	time2 += g2;

	cout << "\n*** Timetable tests ***\n";
	cout << "Time1:\n";
	cout << time1 << endl;
	cout << "Time2:\n";
	cout << time2 << endl;

	Timetable time3 = time1 + time2;
	cout << "Time3:\n"; 
	cout << time3 << endl;

	/*for (int i = 1; i < numOfTeams; i++)
	{
		Team* newTeam = readTeam();
		myLeague.addTeam(*newTeam);
		delete newTeam;
	}*/

	int arr[] = { 21, 10, 2020 };
	myLeague.setStartDate(arr);
	
	cout << "All league's data:" << endl;
	cout << myLeague << endl;

	cout << "Total there are " << Player::getNumOfPlayers() << endl;

	cout << "Goodbye\n";
}

Team* readTeam()
{
	char name[20];
	cout << "Enter team's name: ";
	cin >> name;

	Team* t = new Team(name);

	while (t->canAddMorePlayers())
	{
		cout << "Would you like to add another player to the team? ";
		char answer;
		cin >> answer;

		if (answer == 'n' || answer == 'N')
		{
			break;
		}
		else // answer == 'y'
		{
			char name[20];
			cout << "Enter player's name: ";
			cin >> name;

			int birthYear;
			cout << "Enter player's birth-year: ";
			cin >> birthYear;
			Team::eAddPlayerStatus res = t->addPlayer(name, birthYear, TShirt::eSize::XL, name);
			while (res == Team::eAddPlayerStatus::INVALID_BIRTH_YEAR)
			{
				cout << "Invalid birth-year, try again: ";
				cin >> birthYear;
				res = t->addPlayer(name, birthYear);
			}
		}
	}
	cout << endl;

	return t;
}
