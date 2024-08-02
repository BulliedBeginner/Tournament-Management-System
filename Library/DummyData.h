#pragma once
#include "TournamentOrganizer.h"


TeamLeader leader1 = TeamLeader("John");
Member member1 = Member("Bryan");
Team team1 = Team("Football_Team", leader1, vector<Member>{leader1, member1}, "Football");

TeamLeader leader2 = TeamLeader("Peter");
Member member2 = Member("Jason");
Team team2 = Team("Basketball_Team", leader1, vector<Member>{leader2, member2}, "Basketball");


Tournament tournament1 = Tournament("Football_Rush", "1 / 1 / 2022", "Stadium");
Tournament tournament2 = Tournament("Basketball_Rush", "2 / 2 / 2022", "Hall");

User user1 = User("John", "john@gmail.com", "");
User user2 = User("Peter", "peter@gmail.com", "");
User user3 = User("Bryan", "bryan@gmail.com", "");