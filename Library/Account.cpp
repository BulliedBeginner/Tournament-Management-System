#include "pch.h"
#include "Account.h"

Account::Account()
{
}

Account::Account(string username, string email, string password)
{
	_username = username;
	_email = email;
	_password = password;
}

Account::~Account()
{
}

void Account::Register(string username, string email, string password)
{
	_username = username;
	_email = email;
	_password = password;
}

string Account::GetName()
{
	return _username;
}

bool Account::Login(string username, string password)
{
	return (_username == username && _password == password) ? true : false;
}

