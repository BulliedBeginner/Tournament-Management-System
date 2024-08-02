#pragma once
#include "Member.h"
#include <vector>

using std::vector;

class Member;
class Team;
class Tournament;

class TeamLeader : public Member
{
	public:
		TeamLeader();
		TeamLeader(std::string name);
		~TeamLeader();
		void UpdateTeam(Team team, string name, vector<Member> members);
		void SendJoinRequest(Team &team, Tournament tournament);
};

