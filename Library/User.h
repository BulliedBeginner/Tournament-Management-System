#pragma once
#include "Account.h"
#include "Tournament.h"
#include "Group.h"

using std::string;

class User : public Account
{
public:
	User();
	User(string name, string email, string password);
	~User();
	void UpdateUserProfile(string name, string email);
	void ViewTournamentDetails(Tournament tournament);
	void ViewTournamentDetails(vector<Tournament> tournaments, string name);
	void ViewTeamDetails(Team team);
	void ViewTeamDetails(vector<Group> groups, string teamName);
	bool SearchTournament(vector<Tournament> tournaments, string tournamentName);
	bool SearchTeam(vector<Group> groups, string teamName);
	bool SearchUser(vector<Account> accounts, string username);
	string GetName();
	virtual string ProfileDetails();

};

