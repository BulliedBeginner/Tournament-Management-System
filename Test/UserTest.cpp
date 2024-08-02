#include "pch.h"
#include "CppUnitTest.h"

// SearchUser
#include "Account.h"
#include "User.h"
class User;

// SearchTeam
#include "TournamentOrganizer.h"
#include "Group.h"


#include "Player.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(TestUser)
	{
	public:

		TEST_METHOD(SearchUser)
		{
			vector<Account> account = vector<Account>();

			account.push_back(User());
			account.push_back(User());
			account.push_back(User());

			account[0].Register("John", "john@gmail.com", "1");
			account[1].Register("Hon", "hon@gmail.com", "2");
			account[2].Register("Bryan", "bryan@gmail.com", "3");

			User user;
			bool result = user.SearchUser(account, "Hon");

			Assert::AreEqual(result, true);
		}


		TEST_METHOD(SearchTeam)
		{
			TournamentOrganizer organizer;

			TeamLeader leader1 = TeamLeader("John");
			Member member1 = Member("Peter");

			TeamLeader leader2 = TeamLeader("Bryan");
			Member member2 = Member("Hon");

			Team team1 = Team("Football_Team", leader1, vector<Member>{member1}, "Football");
			Team team2 = Team("Basketball_Team", leader2, vector<Member>{member2}, "Basketball");



			organizer.CreateGroup("Football");
			organizer.AddTeamToGroup("Football", team1);


			organizer.CreateGroup("Basketball");
			organizer.AddTeamToGroup("Basketball", team2);

			User user;
			bool result = user.SearchTeam(organizer.GetGroupList(), "Football_Team");
			Assert::AreEqual(result, true);
		}


		TEST_METHOD(SearchTournament)
		{
			TournamentOrganizer organizer;
			organizer.CreateTournament("Candy Football", "12/2/2022", "Stadium");
			organizer.CreateTournament("Candy Basketball", "12/2/2022", "Stadium");
			organizer.CreateTournament("Candy Badminton", "12/2/2022", "Stadium");

			User user;
			bool result = user.SearchTournament(organizer.GetTournamentList(), "Candy Basketball");
			Assert::AreEqual(result, true);
		}

		TEST_METHOD(PlayerAddTeamMember)
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
