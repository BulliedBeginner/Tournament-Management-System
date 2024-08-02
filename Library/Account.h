#pragma once
#include <string>
#include <vector>

using std::string;
using std::vector;

class Account
{
	protected:
		string _username;
		string _email;
		string _password;

	public:
		Account();
		Account(string username, string email, string password);
		~Account();
		bool Login(string username, string password);
		void Register(string username, string email, string password);
		string GetName();
};