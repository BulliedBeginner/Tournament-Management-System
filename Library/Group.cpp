#include "pch.h"
#include "Group.h"

Group::Group()
{
}

Group::Group(string preference)
{
	_preference = preference;
}

Group::~Group()
{
}

void Group::AddTeam(Team team)
{
	_teams.push_back(team);
}

vector<Team> Group::GetTeamList()
{
	return _teams;
}

string Group::GetPreference()
{
	return _preference;
}

void Group::SetPreference(string value)
{
	_preference = value;
}
