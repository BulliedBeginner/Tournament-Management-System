#include "pch.h"
#include "Player.h"


Player::Player()
{
}

Player::Player(string username, string email, string password)
{
	_nickname = "none";
	_username = username;
	_email = email;
	_password = password;
}

Player::~Player()
{
}

string Player::GetNickName()
{
	return _nickname;
}

void Player::SetNickName(string value)
{
	_nickname = value;
}

string Player::GetName()
{
	return _username;
}

void Player::SetName(string value)
{
	_username = value;
}

string Player::GetEmail()
{
	return _email;
}

void Player::SetEmail(string value)
{
	_email = value;
}

string Player::GetPassword()
{
	return _password;
}

void Player::SetPassword(string value)
{
	_password = value;
}

Team Player::CreateTeam(string name, string preference)
{
	TeamLeader leader = TeamLeader(_username);
	Team team = Team(name, leader, std::vector<Member>{leader}, preference);
	return team;
}

void Player::AddTeamMember(Team &team, Member member)
{
	team.AddMember(member);
}

string Player::ProfileDetails()
{
	return "Nickname: " + _nickname + "\nUsername: " + _username + "\nEmail: " + _email + "\n\n";
}
