#include "pch.h"
#include "Tournament.h"

Tournament::Tournament()
{
}

Tournament::Tournament(string name, string date, string location)
{
	_tournamentName = name;
	_date = date;
	_location = location;
	_teams = vector<Team>();
	_currentStanding = "Unknown";
	_result = "Unknown";
}

Tournament::~Tournament()
{
}

std::string Tournament::GetTournamentName()
{
	return _tournamentName;
}

void Tournament::SetTournamentName(std::string value)
{
	_tournamentName = value;
}

std::string Tournament::GetDate()
{
	return _date;
}

void Tournament::SetDate(std::string value)
{
	_tournamentName = value;
}

string Tournament::GetLocation()
{
	return _location;
}

void Tournament::SetLocation(string value)
{
	_location = value;
}

vector<Team> Tournament::GetTeams()
{
	return _teams;
}

void Tournament::SetTeams(vector<Team> value)
{
	_teams = value;
}

string Tournament::GetCurrentStandings()
{
	return _currentStanding;
}

void Tournament::SetCurrentStandings(string value)
{
	_currentStanding = value;
}

string Tournament::GetResult()
{
	return _result;
}

void Tournament::SetResult(string value)
{
	_result = value;
}

void Tournament::AddTeam(Team team)
{
	_teams.push_back(team);
}

