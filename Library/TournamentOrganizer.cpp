#include "pch.h"
#include "TournamentOrganizer.h"

TournamentOrganizer::TournamentOrganizer()
{
	_username = "organizer";
	_email = "organizer@gmail.com";
	_password = "password";
}

TournamentOrganizer::~TournamentOrganizer()
{
}

void TournamentOrganizer::CreateTournament(string name, string date, string location)
{
	_tournaments.push_back(Tournament(name, date, location));
}

void TournamentOrganizer::UpdateTournament(Tournament tournament, string name, string date, string location)
{
	for (Tournament t : _tournaments)
	{
		if (t.GetTournamentName() == tournament.GetTournamentName())
		{
			t.SetTournamentName(name);
			t.SetDate(date);
			t.SetLocation(location);
		}
	}
}

void TournamentOrganizer::CreateGroup(string preference)
{
	_groups.push_back(Group(preference));
}

void TournamentOrganizer::AddTeamToGroup(string preference, Team team)
{
	for (Group &g : _groups)
	{
		if (g.GetPreference() == preference)
		{
			if (team.GetPreference() == g.GetPreference())
			{
				g.AddTeam(team);
			}
		}
	}
}


void TournamentOrganizer::ApproveRequest(Team &team)
{
	for (Tournament &tournament : _tournaments)
	{
		if (tournament.GetTournamentName() == team.GetJoinTournamentRequest())
		{
			team.SetRequestStatus(true);
			tournament.AddTeam(team);
		}
	}
}

void TournamentOrganizer::DeclineRequest(Team team)
{
	team.SetRequestStatus(false);
}

vector<Tournament> TournamentOrganizer::GetTournamentList()
{
	return _tournaments;
}

vector<Group> TournamentOrganizer::GetGroupList()
{
	return _groups;
}

string TournamentOrganizer::ProfileDetails()
{
	return "Username: " + _username + "  Email: " + _email + "\n";
}

