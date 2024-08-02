#include "pch.h"
#include "TeamLeader.h"
#include "Team.h"
#include "Tournament.h"

TeamLeader::TeamLeader()
{
}

TeamLeader::TeamLeader(std::string name) : Member(name)
{
	_name = name;
}

TeamLeader::~TeamLeader()
{
}

void TeamLeader::UpdateTeam(Team team, string name, vector<Member> members)
{
	team.SetName(name);
	team.SetMemberList(members);

}

void TeamLeader::SendJoinRequest(Team &team, Tournament tournament)
{
	string tournamentName = tournament.GetTournamentName();
	team.SetJoinTournamentRequest(tournamentName);
}

