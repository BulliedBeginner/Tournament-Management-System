#include "pch.h"
#include "Team.h"
#include "TeamLeader.h"
#include <vector>
#include "Member.h"

Team::Team()
{
	_request_status = false;
}

Team::Team(std::string name, TeamLeader leader, std::vector<Member> members, std::string preference)
{
	_name = name;
	_leader = leader;
	_members = members;
	_preference = preference;
}

Team::~Team()
{
}

string Team::GetName()
{
	return _name;
}

void Team::SetName(string value)
{
	_name = value;
}

TeamLeader Team::GetTeamLeader()
{
	return _leader;
}

void Team::SetTeamLeader(TeamLeader leader)
{
	_leader = leader;
}

std::vector<Member> Team::GetMemberList()
{
	return _members;
}

void Team::SetMemberList(vector<Member> members)
{
	_members = members;
}

string Team::GetPreference()
{
	return _preference;
}

void Team::SetPreference(string value)
{
	_preference = value;
}

void Team::AddMember(Member member)
{
	_members.push_back(member);
}

string Team::GetJoinTournamentRequest()
{
	return _join_tournament_request;
}

void Team::SetJoinTournamentRequest(string value)
{
	_join_tournament_request = value;
}

bool Team::GetRequestStatus()
{
	return _request_status;
}

void Team::SetRequestStatus(bool value)
{
	_request_status = value;
}
