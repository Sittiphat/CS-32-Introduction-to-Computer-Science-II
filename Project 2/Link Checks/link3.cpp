#include "BirthdayParty.h"
#include <string>
#include <iostream>
#include <cassert>
using namespace std;
void test()
{
 BirthdayParty terribleCommissioners;
 assert(terribleCommissioners.addInvitee("Gary", "Bettman",
68));
 assert(terribleCommissioners.addInvitee("Robert", "Manfred",
61));
 assert(terribleCommissioners.whosOnTheGuestList() == 2);
 string first, last;
 int a;
 assert(terribleCommissioners.selectInvitee(0, first, last, a)
&& a == 68);
 assert(terribleCommissioners.selectInvitee(1, first, last, a)
&& (first == "Robert" && a == 61));
 return;
}
int main()

{
 test();
 cout << "Passed all tests" << endl;
 return 0;
}
