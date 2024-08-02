#include "pch.h"
#include "CppUnitTest.h"
#include "TournamentOrganizer.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(TestOrganizer)
	{
	public:

		TEST_METHOD(CreateGroup)
		{
			TournamentOrganizer organizer;
			organizer.CreateGroup("Football");
			organizer.CreateGroup("Basketball");
			organizer.CreateGroup("Badmintonball");

			Assert::AreEqual(organizer.GetGroupList().size(), size_t(3));

		}

		TEST_METHOD(CreateTournament)
		{
			TournamentOrganizer organizer;
			organizer.CreateTournament("Football", " 12/12/2022", "Stadium");
			organizer.CreateTournament("Basketball", " 12/12/2022", "Stadium");
			organizer.CreateTournament("Badminton", " 12/12/2022", "Stadium");
			organizer.CreateTournament("CS:GO", " 12/12/2022", "Stadium");

			Assert::AreEqual(organizer.GetTournamentList().size(), size_t(4));
		}

		TEST_METHOD(AddTeamToGroup)
		{
			TournamentOrganizer organizer;
			organizer.CreateGroup("Basketball");

			TeamLeader leader = TeamLeader("John");
			Team t1 = Team("Football team", leader, vector<Member>{leader}, "Football");
			Team t2 = Team("Basketball team", leader, vector<Member>{leader}, "Basketball");

			organizer.AddTeamToGroup("Basketball", t1);
			organizer.AddTeamToGroup("Basketball", t2);

			// The size is only 1 although 2 team is added because team1 has different preference (football) with the created group (basketball) 
			// Therefore, team1 is not added. 
			Assert::AreEqual(organizer.GetGroupList()[0].GetTeamList().size(), size_t(1));
		}

		TEST_METHOD(ApproveRequest)
		{
			TournamentOrganizer organizer;
			organizer.CreateTournament("Candy Football", " 12/12/2022", "Stadium");

			TeamLeader leader = TeamLeader("John");
			Team t1 = Team("Football team", leader, vector<Member>{leader}, "Football");

			leader.SendJoinRequest(t1, organizer.GetTournamentList()[0]);
			organizer.ApproveRequest(t1);

			Assert::AreEqual(organizer.GetTournamentList()[0].GetTeams().size(), size_t(1));
			Assert::AreEqual(t1.GetRequestStatus(), true);
		}

		TEST_METHOD(DeclineRequest)
		{
			TournamentOrganizer organizer;
			organizer.CreateTournament("Candy Football", " 12/12/2022", "Stadium");

			TeamLeader leader = TeamLeader("John");
			Team t1 = Team("Football team", leader, vector<Member>{leader}, "Football");

			leader.SendJoinRequest(t1, organizer.GetTournamentList()[0]);
			organizer.DeclineRequest(t1);

			Assert::AreEqual(t1.GetRequestStatus(), false);
		}

	};
}
