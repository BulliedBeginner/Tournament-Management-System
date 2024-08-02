#include <iostream>
#include "PlayerAccount.h"
#include "OrganizerAccount.h"

int main()
{
	cout << "=====You are=====\n";
	cout << "1. Player\n";
	cout << "2. TournamentOrganizer\n";
	cout << "=================\n\n";

	cout << "Enter the number: ";
	string choice;
	cin >> choice;

	if (choice == "1") {
		Player player = Player_Registration_process();
		Player_Login_process(player);
		Player_Features(&player);
	}

	if (choice == "2") {
		TournamentOrganizer organizer = Organizer_Login_process();
		Organizer_Features(&organizer);
	}


	
}