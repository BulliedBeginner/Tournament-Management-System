#include "pch.h"
#include "User.h"
#include "TournamentOrganizer.h"
#include "Tournament.h"
#include <iostream>
#include "Group.h"

class Group;
class TournamentOrganizer;

User::User()
{
}

User::User(string name, string email, string password) :Account(name, email, password)
{
	_username = name;
	_email = email;
	_password = password;
}

User::~User()
{
}

void User::UpdateUserProfile(string name, string email)
{
	_username = name;
	_email = email;
}

void User::ViewTournamentDetails(Tournament tournament)
{
	std::cout << "Tournament Details" << "\n";
	std::cout << "  Name: " << tournament.GetTournamentName() << "\n";
	std::cout << "  Date: " << tournament.GetDate() << "\n";
	std::cout << "  Location: " << tournament.GetLocation() << "\n";
	std::cout << "  Current Standing: " << tournament.GetCurrentStandings() << "\n";
	std::cout << "  Result: " << tournament.GetResult() << "\n";

	std::cout << "\n";
	system("pause");

}



void User::ViewTournamentDetails(vector<Tournament> tournaments, string name)
{
	for (Tournament t : tournaments)
	{
		if (t.GetTournamentName() == name)
		{
			std::cout << "Tournament Details" << "\n";
			std::cout << "  Name: " << t.GetTournamentName() << "\n";
			std::cout << "  Date: " << t.GetDate() << "\n";
			std::cout << "  Location: " << t.GetLocation() << "\n";
			std::cout << "  Current Standing: " << t.GetCurrentStandings() << "\n";
			std::cout << "  Result: " << t.GetResult() << "\n";

			std::cout << "\n";
			system("pause");
		}
	}
}

void User::ViewTeamDetails(vector<Group> groups, string name)
{
	for (Group g : groups)
	{
		for (Team t : g.GetTeamList())
		{
			if (t.GetName() == name)
			{
				std::cout << "Team Name: " << t.GetName() << "\n";
				std::cout << "Team Leader: " << t.GetTeamLeader().GetName() << "\n";
				std::cout << "Team Member(s): ";
				for (Member m : t.GetMemberList()) std::cout << m.GetName() << " ";
				std::cout << "\nTeam Preference: " << t.GetPreference() << "\n";

				std::cout << "\n";
				system("pause");
			}
		}
	}
}

void User::ViewTeamDetails(Team t)
{
	std::cout << "Team Details: \n";
	std::cout << " Name: " << t.GetName() << "\n";
	std::cout << " Leader: " << t.GetTeamLeader().GetName() << "\n";
	std::cout << " Member(s): ";
	for (Member m : t.GetMemberList())std::cout << m.GetName() << " ";
	std::cout << "\n Preference: " << t.GetPreference() << "\n";

	std::cout << "\n";
	system("pause");
}

bool User::SearchTournament(vector<Tournament> tournaments, string name)
{
	for (Tournament t : tournaments)
		if (t.GetTournamentName() == name) return true;

	return false;
}

bool User::SearchTeam(vector<Group> groups, string teamName)
{
	for (Group g : groups)
		for (Team t : g.GetTeamList())
			if (t.GetName() == teamName) return true;
			
	return false;
}

bool User::SearchUser(vector<Account> accounts, string username)
{
	for (Account a : accounts)
		if (a.GetName() == username)
			return true;

	return false;
}

string User::GetName()
{
	return _username;
}

string User::ProfileDetails()
{
	return string();
}

