#pragma once
#include <string>
#include <vector>
#include "Team.h"

using std::string;
using std::vector;

class Team;

class Group
{
private:
	vector<Team> _teams;
	string _preference;

public:
	Group();
	Group(string preference);
	~Group();
	void AddTeam(Team team);
	vector<Team> GetTeamList();
	string GetPreference();
	void SetPreference(string value);
};

