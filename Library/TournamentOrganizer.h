#pragma once
#include "User.h"
#include "Tournament.h"
#include "Group.h"

class Team;
class Group;
class Tournament;

class TournamentOrganizer : public User
{
private:
	vector<Group> _groups;
	vector<Tournament> _tournaments;

public:
	TournamentOrganizer();
	~TournamentOrganizer();
	void CreateTournament(string name, string date, string location);
	void UpdateTournament(Tournament tournament, string name, string date, string location);
	void CreateGroup(string preference);
	void AddTeamToGroup(string preference, Team team);
	void ApproveRequest(Team &team);
	void DeclineRequest(Team team);
	vector<Tournament> GetTournamentList();
	vector<Group> GetGroupList();
	virtual string ProfileDetails();


};

