#pragma once
#include <string>
#include "User.h"
#include "Team.h"
#include "Member.h"

class Team;
class Member;

using std::string;

class Player : public User
{
private:
	string _nickname;

public:
	Player();
	Player(string username, string email, string password);
	~Player();
	string GetNickName();
	void SetNickName(string value);
	string GetName();
	void SetName(string value);
	string GetEmail();
	void SetEmail(string value);
	string GetPassword();
	void SetPassword(string value);
	Team CreateTeam(string name, string preference);
	void AddTeamMember(Team &team, Member member);
	virtual string ProfileDetails();
};

