#pragma once
#include <iostream>
#include "Account.h"
#include "Player.h"
#include "UserFeatures.h"

using std::cout;
using std::cin;
using std::string;

// Global (dummy data for display)
#include "DummyData.h"
vector<Team> teams =  vector<Team>{ team1, team2 };
vector<Tournament> tournaments = vector<Tournament>{ tournament1, tournament2 };
vector<Account> accounts = vector<Account>{ user1, user2, user3 };


void Player_Menu() {
	cout << "\n\n=================\n";
	cout << "1. Set a nickname\n";
	cout << "2. Create a team\n";
	cout << "3. Add team member to existing team\n";
	cout << "4. View Team Details\n";
	cout << "5. View Tournament Details\n";
	cout << "6. Search Team\n";
	cout << "7. Search Tournament\n";
	cout << "8. Search User\n";
	cout << "9. Reset Password\n";
	cout << "10. Update Profile\n";
	cout << "11. See profile details\n";
	cout << "=================\n\n";
}



Player Player_Registration_process() {
	string username;
	string email;
	string password;

	cout << "Enter your username (no space allowed): ";
	cin >> username;

	cout << "Enter your email: ";
	cin >> email;

	cout << "Enter your password: ";
	cin >> password;

	vector<Player> players = vector<Player>();
	players.push_back(Player());

	static int account_index = 0;
	players[account_index] = Player(username, email, password);
	return players[account_index];
}



void Player_Login_process(Account account) {
	string username;
	string password;

	while (true) {
		cout << "\nLogin: " << "\n";
		cout << "Enter your username: ";
		cin >> username;

		cout << "Enter your password: ";
		cin >> password;

		bool result = account.Login(username, password);

		if (result) {
			cout << "Login successful" << "\n";
			break;

		} else {
			cout << "Username or password is incorrect" << "\n";
			system("pause");
		}
	}
}



void Player_Set_Nick_Name(Player &player) {
	string nickname;
	cout << "Enter your nickname: ";
	cin >> nickname;

	player.SetNickName(nickname);
	cout << "Now you nickname is " + player.GetNickName() + "\n";
}


void Player_Create_Team(Player player) {
	string team_name;
	cout << "Enter the team name: ";
	cin >> team_name;

	string preference;
	cout << "What is your team preference? \n(eg. football, badminton etc..) : ";
	cin >> preference;

	teams.push_back(player.CreateTeam(team_name, preference));
}



void AddTeamMember(Player &player, vector<Team> &teams) {
	if (teams.size() != 0) {
		int i = 0;
		cout << "Existing team(s): \n";
		for (Team &team : teams) {
			cout << std::to_string(++i) << ". " << team.GetName() << "   Preference: " << team.GetPreference() << "\n";
		}

		cout << "\nSelect team: ";
		string choice;
		cin >> choice;

		cout << "Enter member name: ";
		string member_name;
		cin >> member_name;

		player.AddTeamMember(teams[stoi(choice) - 1], Member(member_name));
	} else {
		cout << "No existing team\n";
		system("pause");

	}
}



void ResetPassword(Player &player) {
	cout << "Enter your password: ";
	string old_password;
	cin >> old_password;

	if (old_password == player.GetPassword()) {
		cout << "Enter your new password: ";
		string new_password;
		cin >> new_password;

		cout << "Confirm password: ";
		string confirm_password;
		cin >> confirm_password;

		if (confirm_password == new_password) {
			player.SetPassword(confirm_password);
		} else {
			cout << "Password does not match. Please try again.\n";
			system("pause");
		}
	} else {
		cout << "Incorrect password. Please try again.";
		system("pause");
	}
}



void UpdateProfile(Player &player) {
	cout << "1. Nickname: " << player.GetNickName() << "\n";
	cout << "2. Username: " + player.GetName() + "\n";
	cout << "3. Email: " + player.GetEmail() + "\n";

	cout << "Which do you want to update?\n";
	cout << "Enter 1 / 2 / 3 or anything key to quite: ";
	string choice;
	cin >> choice;

	if (choice == "1") {
		cout << "New nickname: ";
		string new_nickname;
		cin >> new_nickname;
		player.SetNickName(new_nickname);
	}

	if (choice == "2") {
		cout << "New username: ";
		string new_username;
		cin >> new_username;
		player.SetName(new_username);
	}

	if (choice == "3") {
		cout << "New email: ";
		string new_email;
		cin >> new_email;
		player.SetEmail(new_email);
	}
}



void ProfileDetails(Player &player) {
	cout << player.ProfileDetails();
	system("pause");
}



void Player_Features(Player *player) {
	while (true) {
		Player_Menu();

		cout << "Enter your selection or enter 'n' to quit: ";
		string choice;
		cin >> choice;


		if (choice == "1") {
			Player_Set_Nick_Name(*player);
		}

		if (choice == "2") {
			Player_Create_Team(*player);
		}

		if (choice == "3") {
			AddTeamMember(*player , teams);
		}

		if (choice == "4") {
			ViewTeamDetails(*player, teams);
		}

		if (choice == "5") {
			ViewTournamentDetails(*player, tournaments);
		}

		if (choice == "6") {
			// for display purpose only
			TournamentOrganizer organizer;
			organizer.CreateGroup("Football");
			organizer.AddTeamToGroup("Football", team1);

			SearchTeam(*player, organizer.GetGroupList());
		}

		if (choice == "7") {
			SearchTournament(*player, tournaments);
		}

		if (choice == "8") {
			SearchUser(*player, accounts);
		}

		if (choice == "9") {
			ResetPassword(*player);
		}

		if (choice == "10") {
			UpdateProfile(*player);
		}

		if (choice == "11") {
			ProfileDetails(*player);
		}

		if (choice == "n" || choice == "N") {
			break;
		}
	}
}
