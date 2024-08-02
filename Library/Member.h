#pragma once
#include <string>
using std::string;

class Member
{
protected:
	std::string _name;

public:
	Member();
	Member(std::string name);
	~Member();
	std::string GetName();
	void SetName(std::string value);
};

