#include "BirthdayParty.h"
#include <string>
#include <iostream>
#include <cassert>
using namespace std;
void test()
{
 BirthdayParty aListCommissioners;

 assert(aListCommissioners.addInvitee("Adam", "Silver",
 "asilver@nba.com"));
 assert(aListCommissioners.addInvitee("Roger", "Goodell",
 "rgoodell@nfl.com"));
 assert(aListCommissioners.whosOnTheGuestList() == 2);
 string first, last, e;
 assert(aListCommissioners.selectInvitee(0, first, last, e)
 && e == "rgoodell@nfl.com");
 assert(aListCommissioners.selectInvitee(1, first, last, e)
 && (first == "Adam" && e == "asilver@nba.com"));
 return;

}
int main()
{
 test();
 cout << "Passed all tests" << endl;
 return 0;
}
