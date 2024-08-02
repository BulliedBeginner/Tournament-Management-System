#pragma once
#include <iostream>
#include <string>
#include "TournamentOrganizer.h"

using std::cout;
using std::cin;
using std::string;

void ViewTeamDetails(User &user, vector<Team> teams) {
	int i = 0;
	for (Team team : teams) {
		cout << std::to_string(++i) << ". " << team.GetName() << "\n";
	}

	cout << "Which team detail do you want to view?: ";
	string index;
	cin >> index;
	user.ViewTeamDetails(teams[stoi(index) - 1]);
}



void ViewTournamentDetails(User &user, vector<Tournament> tournaments) {
	int i = 0;
	for (Tournament tournament : tournaments) {
		cout << std::to_string(++i) << ". " << tournament.GetTournamentName() << "\n";
	}

	cout << "Which tournament detail do you want to view?: ";
	string index;
	cin >> index;
	user.ViewTournamentDetails(tournaments[stoi(index) - 1]);
}



void SearchTeam(User user, vector<Group> groups) {
	cout << "Search (Team Name) ";
	cout << "eg. Football_Team , Basketball_Team: ";
	string teamName;
	cin >> teamName;

	if (user.SearchTeam(groups, teamName)) {
		cout << "\n\n";
		user.ViewTeamDetails(groups, teamName);


	} else {
		cout << "No result. Please try again.\n";
		system("pause");
	}
}



void SearchTournament(User user, vector<Tournament> tournaments) {
	cout << "Search (Tournament Name) ";
	cout << "eg. Football_Rush , Basketball_Rush: ";

	string tournamentName;
	cin >> tournamentName;

	if (user.SearchTournament(tournaments, tournamentName)) {
		cout << "\n\n";
		user.ViewTournamentDetails(tournaments, tournamentName);


	} else {
		cout << "No result. Please try again.\n";
		system("pause");
	}
	
}



void SearchUser(User user, vector<Account> accounts) {
	cout << "Search (Username) ";
	cout << "eg. John , Peter, Bryan: ";

	string username;
	cin >> username;


	if (user.SearchUser(accounts, username)) {
		cout << "Found.\n\n";
		system("pause");
	} else {
		cout << "No result. Please try again.\n";
		system("pause");
	}

}