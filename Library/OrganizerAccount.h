#pragma once
#include <iostream>
#include "TournamentOrganizer.h"
#include "UserFeatures.h"

using std::cout;
using std::cin;
using std::string;

// Global (dummy data for display)
#include "DummyData.h"
vector<Account> account_s = vector<Account>{ user1, user2, user3 };
vector<Team> team_s =  vector<Team>{ team1, team2 };



TournamentOrganizer Organizer_Login_process()
{
	string username;
	string password;
	TournamentOrganizer organizer;

	while (true)
	{
		std::cout << "\nLogin: " << "\n";
		std::cout << "Enter your username (organizer): ";
		cin >> username;

		std::cout << "Enter your password (password): ";
		cin >> password;

		bool result = organizer.Login(username, password);

		if (result) {
			cout << "Login successful" << "\n";
			break;

		}
		else {
			cout << "Username or password is incorrect" << "\n";
		}
	}

	return organizer;
}



void Organizer_Menu() {
	cout << "\n\n=================\n";
	cout << "1. Create New Tournament\n";
	cout << "2. Update Existing Tournament\n";
	cout << "3. Create Group\n";
	cout << "4. Add Team to Group\n";
	cout << "5. Approve Join Request from Team\n";
	cout << "6. Decline Join Request from Team\n";
	cout << "7. View Team Details\n";
	cout << "8. View Tournament Details\n";
	cout << "9. Search Team\n";
	cout << "10. Search Tournament\n";
	cout << "11. Search User\n";
	cout << "12. See profile details\n";
	cout << "=================\n";
}



void CreateTournament(TournamentOrganizer &organizer) {
	cout << "Enter tournament name: ";
	string tournamentName;
	getline(cin , tournamentName);

	cout << "Enter tournament date: ";
	string tournamentDate;
	cin >> tournamentDate;

	cout << "Enter tournament location";
	string tournamentLocation;
	cin >> tournamentLocation;

	organizer.CreateTournament(tournamentName, tournamentDate, tournamentLocation);
	cout << "Tournament created successfully\n\n";
	system("pause");
}

void UpdateTournament(TournamentOrganizer &organizer, vector<Tournament> tournaments) {
	if (tournaments.size() != 0) {
		int i = 0;
		for (Tournament tournament : tournaments) cout << std::to_string(++i) << ". " << tournament.GetTournamentName() << "\n";

		cout << "\nSelect tournament: ";
		string choice;
		cin >> choice;

		cout << "Enter tournament name: ";
		string tournamentName;
		cin >> tournamentName;

		cout << "Enter tournament date: ";
		string tournamentDate;
		cin >> tournamentDate;

		cout << "Enter tournament location";
		string tournamentLocation;
		cin >> tournamentLocation;

		organizer.UpdateTournament(tournaments[stoi(choice) - 1], tournamentName, tournamentDate, tournamentLocation);
		cout << "Tournament updated successfully";
		system("pause");
	} else {
		cout << "No existing tournament. Please create the tournament first.\n";
		system("pause");
	}

}

void CreateGroup(TournamentOrganizer &organizer) {
	cout << "Enter group preferences: ";
	string preference;
	cin >> preference;

	organizer.CreateGroup(preference);
	cout << "Group created successfully";
	system("pause");
}

void AddTeamToGroup(TournamentOrganizer &organizer) {
	int i = 0;
	if (organizer.GetGroupList().size() != size_t(0)) {
		for (Group g : organizer.GetGroupList()) cout << std::to_string(++i) << ". " << g.GetPreference() << "\n";
	
		cout << "Select group: ";
		string index;
		cin >> index;

		cout << "\n";

		i = 0;
		for (Team team : team_s)
		{
			if (team.GetPreference() == organizer.GetGroupList()[stoi(index) - 1].GetPreference())  {
				cout << std::to_string(++i) << ". " << team.GetName() << "\n";
			}
		}

		cout << "Select team: ";
		string team_index;
		cin >> team_index;

		organizer.AddTeamToGroup(organizer.GetGroupList()[stoi(index) - 1].GetPreference(), team_s[stoi(team_index) - 1]);
		cout << team_s[stoi(team_index) - 1].GetName() << " has successfully added to " << organizer.GetGroupList()[stoi(index) - 1].GetPreference() << " group.";
		system("pause");
		
	} else {
		cout << "No existing group. Please create the group first.\n";
		system("pause");
	}

}

void ApproveRequest(TournamentOrganizer &organizer) {
	// this function need some dummy data to work with
	// As this function need player and team leader to interact with organizer, I will use some declared data to show how this working
	// There is also a unit testing for this function

	organizer.CreateTournament("Football_Rush", " 12/12/2022", "Stadium");
	organizer.CreateTournament("Basketball_Rush", " 12/12/2022", "Stadium");


	cout << "Pending request: \n";
	cout << "1. Football_Team	Request to join: Football_Rush\n";
	cout << "2. Basketball_Team		Request to join: Basketball_Rush\n\n";

	cout << "Select request to approve: ";
	string choice;
	cin >> choice;

	leader1.SendJoinRequest(team1, organizer.GetTournamentList()[0]);
	leader2.SendJoinRequest(team2, organizer.GetTournamentList()[1]);
	if (choice == "1") organizer.ApproveRequest(team1);
	if (choice == "2") organizer.ApproveRequest(team2);

	cout << "Now " << organizer.GetTournamentList()[stoi(choice) - 1].GetTeams()[stoi(choice) - 1].GetName() << " has join " <<organizer.GetTournamentList()[stoi(choice) - 1].GetTournamentName() << ".\n";
	system("pause");
}

void DeclineRequest(TournamentOrganizer &organizer) {
	// this function need some dummy data to work with
	// As I cant demonstrate how player interact with organizer, I will use some declared data to show how this working
	// There is also a unit testing for this function

	organizer.CreateTournament("Football_Rush", " 12/12/2022", "Stadium");
	organizer.CreateTournament("Basketball_Rush", " 12/12/2022", "Stadium");
	leader1.SendJoinRequest(team1, organizer.GetTournamentList()[0]);
	leader2.SendJoinRequest(team2, organizer.GetTournamentList()[1]);

	cout << "Pending request: \n";
	cout << "1. Football_Team	Request to join: Football_Rush\n";
	cout << "2. Basketball_Team		Request to join: Basketball_Rush\n\n";

	cout << "Select request to reject: ";
	string choice;
	cin >> choice;

	if (choice == "1") {
		organizer.DeclineRequest(team1);
		cout << "You have rejected Football_team to join " << organizer.GetTournamentList()[stoi(choice) - 1].GetTournamentName() << ".\n";
		system("pause");

	}
	if (choice == "2")  {
		organizer.DeclineRequest(team2);
		cout << "You have rejected Basketball_team to join " << organizer.GetTournamentList()[stoi(choice) - 1].GetTournamentName() << ".\n";
		system("pause");
	}
}


void ProfileDetails(TournamentOrganizer &organizer) {
	cout << organizer.ProfileDetails();
	system("pause");
}




void Organizer_Features(TournamentOrganizer *organizer) {
	while (true) {
		Organizer_Menu();

		cout << "Enter your selection or enter 'n' to quit: ";
		string choice;
		cin >> choice;


		if (choice == "1") {
			CreateTournament(*organizer);
		}

		if (choice == "2") {
			UpdateTournament(*organizer , organizer->GetTournamentList());
		}

		if (choice == "3") {
			CreateGroup(*organizer);
		}

		if (choice == "4") {
			AddTeamToGroup(*organizer);
		}

		if (choice == "5") {
			ApproveRequest(*organizer);
		}

		if (choice == "6") {
			DeclineRequest(*organizer);
		}

		if (choice == "7") {
			vector<Team> teams = {team1, team2};
			for (Group group : organizer->GetGroupList())
				for (Team team : group.GetTeamList())
					teams.push_back(team);

			ViewTeamDetails(*organizer, teams);
		}

		if (choice == "8") {
			ViewTournamentDetails(*organizer , organizer->GetTournamentList());
		}

		if (choice == "9") {
			// For display purpose only
			organizer->CreateGroup("Football");
			organizer->AddTeamToGroup("Football", team1);

			SearchTeam(*organizer , organizer->GetGroupList());
		}

		if (choice == "10") {
			SearchTournament(*organizer , organizer->GetTournamentList());
		}

		if (choice == "11") {
			SearchUser(*organizer , account_s);
		}

		if (choice == "12") {
			ProfileDetails(*organizer);
		}

		if (choice == "n" || choice == "N") {
			break;
		}
	}
}