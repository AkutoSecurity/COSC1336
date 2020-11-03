//This program displays the number of times a user-entered team has won the World Series.
//NOTE FOR GITHUB: There are two files referenced in this program, so this program alone WILL NOT work.
#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>
#include <fstream>
using namespace std;

//Prototypes
void displayMenu();
void processMenu();
void getTeams(vector<string> &);
void getWinners(vector<string> &);
void displayWins(const vector<string>, const vector<string>);

int main()
{ //Call menu functions
	displayMenu();
	processMenu();

	return 0;
}

void displayMenu() //Shows user the teams and lets them choose to quit
{
	cout << "                  MLB - WORLD SERIES WINNER DATABASE\n\n"
		<< "1. TEAMS\n"
		<< "2. QUIT\n\n"
		<< "Please enter the name of a team: ";
}

void processMenu() 
{
	const int ROSTER = 1,
		QUIT = 2;
	int choice = 0;

	vector<string> teams = { " " };
	vector<string> winners = { " " };

	do
	{ //Quit or display selection
		cin >> (choice);

		switch (choice)
		{
		case 1:

			winners.clear();
			teams.clear();

			getTeams(teams);
			getWinners(winners);
			displayWins(winners, teams);

			displayMenu();
			break;

		case 2:
			if (choice == QUIT)
			{
				cout << "Goodbye!\n";
			}
			break;
		}
	} while (choice != QUIT);
}


void getTeams(vector<string> &teams)
{
	teams.clear();

	ifstream teamsFile;

	string teamRoster = " ";

	//Open Teams.txt
	teamsFile.open("Teams.txt");

	if (teamsFile)
	{
		while (getline(teamsFile, TeamRoster) && !teamsFile.eof())
		{
			teams.push_back(teamRoster);
		}
	}
	else
	{ //Error message
		cout << "\nFile opening error: The file 'Teams.txt' could not be opened or processed."
     << endl << "Program is now terminating...";
	}

	teamsFile.close();
}

void getWinners(vector<string> &winners)
{
	ifstream winnersFile;

	string winningRoster = " ";

	//Open WorldSeriesWinners.txt
	winnersFile.open("WorldSeriesWinners.txt");

	if (winnersFile)
	{
		while (getline(winnersFile, winningRoster) && !winnersFile.eof())
		{
			winners.push_back(winningRoster);
		}
	}
	else
	{ //Error message
		cout << "\nFile open error: The file 'WorldSeriesWinners.txt' could not be opened or processed."
      << endl << "Program is now terminating...";
	}

	winnersFile.close();
}

void displayNumWins(const vector<string> winners, const vector<string> teams)
{
	string teamName = " ";
	int cnt = 0;

	//Displays teams
	cout << "\nTeam Roster:\n\n";
	for (string v : teams)
	{
		cout << v << "\n";
	}

	//Asks user for team
	cout << "\nEnter a team name: ";
	cin.get();
	getline(cin, teamName);

	//Counts number of wins a team has had
	for (size_t n = 0; n < winners.size(); n++)
	{
		if (teamName == winners[n])
		{
			cnt++;
		}
	}

	//Display results
	cout << "\nThe " << teamName << " have won the Major League Baseball World Series a total of " << cnt << " times!\n\n";
}
