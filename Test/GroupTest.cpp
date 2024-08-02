#include "pch.h"
#include "CppUnitTest.h"
#include "Group.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(TestGroup)
	{
	public:

		TEST_METHOD(AddTeam)
		{
			Group group = Group("Football");

			TeamLeader leader = TeamLeader("Peter");
			Member member1 = Member("John");
			Member member2 = Member("Bryan");
			Member member3 = Member("Hon");

			vector<Member> MemberList = vector<Member>();
			MemberList.push_back(member1);
			MemberList.push_back(member2);
			MemberList.push_back(member3);

			Team team = Team("Simple", leader, MemberList, "Football");

			group.AddTeam(team);

			size_t expected_result = 1;

			Assert::AreEqual(group.GetTeamList().size(), expected_result);
		}
	};
}
