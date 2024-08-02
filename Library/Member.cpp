#include "pch.h"
#include "Member.h"

Member::Member()
{
}

Member::Member(std::string name)
{
	_name = name;
}

Member::~Member()
{
}

std::string Member::GetName()
{
	return _name;
}

void Member::SetName(std::string value)
{
	_name = value;
}
