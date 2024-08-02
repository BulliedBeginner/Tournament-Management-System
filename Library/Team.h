#pragma once
#include <vector>
#include "Member.h"
#include "TeamLeader.h"

class Member;
class TeamLeader;


class Team
{
private:
	string _name;
	TeamLeader _leader;
	vector<Member> _members;
	string _preference;
	string _join_tournament_request;
	bool _request_status;

public:
	Team();
	Team(string name, TeamLeader leader, vector<Member> members, string preference);
	~Team();
	string GetName();
	void SetName(string value);
	TeamLeader GetTeamLeader();
	void SetTeamLeader(TeamLeader leader);
	vector<Member> GetMemberList();
	void SetMemberList(vector<Member> value);
	string GetPreference();
	void SetPreference(string value);
	void AddMember(Member member);
	string GetJoinTournamentRequest();
	void SetJoinTournamentRequest(string value);
	bool GetRequestStatus();
	void SetRequestStatus(bool value);
};

