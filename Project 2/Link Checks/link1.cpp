#include "BirthdayParty.h"
#include <type_traits>

#define CHECKTYPE(f, t) { auto p = (t)(f); (void)p; }
static_assert(std::is_default_constructible<BirthdayParty>::value,
 "Map must be default-constructible.");

static_assert(std::is_copy_constructible<BirthdayParty>::value,
 "Map must be copy-constructible.");
void ThisFunctionWillNeverBeCalled()
{
 CHECKTYPE(&BirthdayParty::operator=, BirthdayParty&
 (BirthdayParty::*)(const BirthdayParty&));
 CHECKTYPE(&BirthdayParty::noInvitees, bool
 (BirthdayParty::*)() const);
 CHECKTYPE(&BirthdayParty::whosOnTheGuestList, int
 (BirthdayParty::*)() const);
 CHECKTYPE(&BirthdayParty::addInvitee, bool (BirthdayParty::*)
 (const std::string&, const std::string&, const
BirthdayType&));
 CHECKTYPE(&BirthdayParty::modifyInvitee, bool
 (BirthdayParty::*)(const std::string&, const std::string&,
 const BirthdayType&));
 CHECKTYPE(&BirthdayParty::addOrModify, bool
 (BirthdayParty::*)(const std::string&, const std::string&,
 const BirthdayType&));
 CHECKTYPE(&BirthdayParty::dropFromGuestList, bool
(BirthdayParty::*)
 (const std::string&, const std::string&));
 CHECKTYPE(&BirthdayParty::personOnGuestList, bool
 (BirthdayParty::*)(const std::string&, const std::string&)
 const);
 CHECKTYPE(&BirthdayParty::checkGuestList, bool
(BirthdayParty::*)
 (const std::string&, const std::string&, BirthdayType&)
const);

 CHECKTYPE(&BirthdayParty::selectInvitee, bool
(BirthdayParty::*)
 (int, std::string&, std::string&, BirthdayType&)
 const);
 CHECKTYPE(&BirthdayParty::changeGuestList, void
 (BirthdayParty::*)(BirthdayParty&));

 CHECKTYPE(combineGuestLists, bool (*)(const BirthdayParty&,
const
 BirthdayParty&, BirthdayParty&));
 CHECKTYPE(verifyGuestList, void (*)(const std::string&,
 const std::string&, const BirthdayParty&, BirthdayParty&));
}
int main()
{}
