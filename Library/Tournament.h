#pragma once
#include "Team.h"

class Team;

class Tournament
{
private:
	string _tournamentName;
	string _date;
	string _location;
	vector<Team> _teams;
	string _currentStanding;
	string _result;

public:
	Tournament();
	Tournament(string name, string date, string location);
	~Tournament();
	string GetTournamentName();
	void SetTournamentName(string value);
	string GetDate();
	void SetDate(string value);
	string GetLocation();
	void SetLocation(string value);
	vector<Team> GetTeams();
	void SetTeams(vector<Team> value);
	string GetCurrentStandings();
	void SetCurrentStandings(string value);
	string GetResult();
	void SetResult(string value);
	void AddTeam(Team team);
};


