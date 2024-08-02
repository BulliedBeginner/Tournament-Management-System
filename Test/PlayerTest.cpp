#include "pch.h"
#include "CppUnitTest.h"

#include "Player.h"
#include <string>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(TestPlayer)
	{
	public:

		TEST_METHOD(CreateTeam)
		{
			Player player = Player("John", "john@gmail.com", "password");
			Team team = player.CreateTeam("Dance Team", "dancing");

			TeamLeader leader = TeamLeader("John");
			Team compare = Team("Dance Team", leader, vector<Member>{leader}, "dancing");

			Assert::AreEqual(team.GetName(), compare.GetName());
		}

		TEST_METHOD(AddTeamMember)
		{
			Player player = Player("John", "john@gmail.com", "password");
			Member m1 = Member("Hon");
			Member m2 = Member("Bryan");


			Team t1 = player.CreateTeam("Dance Team", "dancing");
			Team t2 = player.CreateTeam("Ball Team", "ball");

			player.AddTeamMember(t1, m1);
			player.AddTeamMember(t1, m2);

			size_t result = t1.GetMemberList().size();

			// player himself + 2 member = 3
			Assert::AreEqual(result, size_t(3));
		}

	};
}
