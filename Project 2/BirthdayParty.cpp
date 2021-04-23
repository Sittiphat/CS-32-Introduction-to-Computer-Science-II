#include "BirthdayParty.h"

using namespace std;

void BirthdayParty::dump() const {
  // Different Input Variables for Linked List Objects
  /*int age = 21;
  string firstName = "Jesse";
  string lastName = "Narkmanee";

  string firstName2 = "James";
  string lastName2 = "Moseley";
  int age2 = 30;

  string firstName3 = "Jonathan";
  string lastName3 = "Chu";
  int age3 = 21;

  string firstName4 = "Yin-Yeung";
  string lastName4 = "Cheung";
  int age4 = 21;

  string firstName5 = "Yanni";
  string lastName5 = "Backster";
  int age5 = 25;

  string firstName6 = "Zachary";
  string lastName6 = "Bentley";
  int age6 = 37;

  cerr << endl << "///////////////////////////////////////////////////////////////////////////////////" << endl;

  // Shows if my full name ordering function works since Moseley is before Narkmanee
  cerr << isFirstAlpha(firstName, lastName, firstName2, lastName2) << endl; // Works
  cerr << endl << "///////////////////////////////////////////////////////////////////////////////////" << endl;
  // Testing Front Appendage of Linked List Algorithm
  // addToFront(firstName, lastName, age); // Works
  // addToFront(firstName2, lastName2, age2); // Works
  // printValues(); // Works

  cerr << endl << "///////////////////////////////////////////////////////////////////////////////////" << endl;
  // Shows if Invitee will be added if already there (it should't) and if it is in order
  addInvitee(firstName, lastName, age); // Works
  addInvitee(firstName3, lastName3, age3); // Works
  addInvitee(firstName4, lastName4, age4); // Works
  addInvitee(firstName2, lastName2, age2); // Works
  printValues(); // Works

  cerr << endl << "///////////////////////////////////////////////////////////////////////////////////" << endl;

  // Shows number of Invitees and if how many are on the guest list is correct
  cerr << noInvitees() << endl; // Works
  cerr << whosOnTheGuestList() << endl; // Works

  cerr << endl << "///////////////////////////////////////////////////////////////////////////////////" << endl;
  // Shows if I can modify the value of Jesse Narkmanee
  cerr << modifyInvitee(firstName, lastName, age2) << endl; // Works
  printValues();

  cerr << endl << "///////////////////////////////////////////////////////////////////////////////////" << endl;
  // Shows if I can sucessfully delete Jesse Narkmanee from list
  cerr << dropFromGuestList(firstName, lastName) << endl; // works
  printValues();

  cerr << endl << "///////////////////////////////////////////////////////////////////////////////////" << endl;
  // Shows if I am able to add or modify under certain conditions
  cerr << "addOrModify();" << endl;
  cerr << addOrModify(firstName3, lastName3, age2) << endl; // error
  printValues();

  cerr << endl << "///////////////////////////////////////////////////////////////////////////////////" << endl;
  // Shows if I do select the first index of i
  int i = 1;
  cout << selectInvitee(i, firstName, lastName, age) << endl; // Works
  printValues();

  cerr << endl << "///////////////////////////////////////////////////////////////////////////////////" << endl;
  // To prepare for the next tests
  BirthdayParty other;
  other.addToFront(firstName4, lastName4, age4);
  other.addToFront(firstName3, lastName3, age3);
  other.addToFront(firstName5, lastName5, age5);
  other.addToFront(firstName6, lastName6, age6);
  other.printValues();

  cerr << endl << "///////////////////////////////////////////////////////////////////////////////////" << endl;
  // See if I am able to swap guest lists
  changeGuestList(other);
  printValues();
  cout << endl << "Other:" << '\n';
  other.printValues();

  cerr << endl << "///////////////////////////////////////////////////////////////////////////////////" << endl;
  // Continuation of Previous
  BirthdayType value;
  cerr << checkGuestList(firstName3, lastName3, value) << endl;
  cout << endl << "Original:" << '\n';
  printValues();
  cerr << "Passed by reference is now: " << value << endl;
  cerr << endl << "///////////////////////////////////////////////////////////////////////////////////" << endl;
  // Continuation of Previous
  BirthdayParty bpOne;
  bpOne.addToFront(firstName, lastName, age); // Works
  bpOne.addToFront(firstName2, lastName2, age2); // Works
  bpOne.addToFront(firstName3, lastName3, age3); // Works
  bpOne.addToFront(firstName4, lastName4, age4); // Works

  other.addToFront(firstName3, lastName3, age3);
  other.addToFront(firstName5, lastName5, age5);
  other.addToFront(firstName6, lastName6, age6);

  cout << endl << "bpOne:" << '\n';
  bpOne.printValues();

  cout << endl << "Other:" << '\n';
  other.printValues();


  BirthdayParty bpJoined;
  combineGuestLists(bpOne, other, bpJoined);
  cout << endl << "bpJoined:" << '\n';
  bpJoined.printValues();

  cerr << endl << "///////////////////////////////////////////////////////////////////////////////////" << endl;
  // Checks to see if I can search if we have one or both wildcards (should be just a copy in latter case)
  BirthdayParty bpResult;
  verifyGuestList ("*", "*", bpOne, bpResult);

  cout << endl << "bpResult:" << '\n';
  bpResult.printValues();

  cerr << endl << "///////////////////////////////////////////////////////////////////////////////////" << endl;*/

}

// Default Constructor
BirthdayParty::BirthdayParty()
  : head(nullptr), tail(nullptr) {} // Initialize Private Member Variables

// Copy Constructor
BirthdayParty::BirthdayParty(const BirthdayParty& other) {

  if (other.head == nullptr) { // If other is empty, then this object should be empty too
    head = nullptr;
    tail = nullptr;
  } else {

    // Call function that copies values over from other object into this object
    copyList(other);
    }
}

// Assignment Operator
BirthdayParty& BirthdayParty::operator=(const BirthdayParty& other) {

  if (&other == this) { // Ensures self-assignment would work by returning itself
    return *this;
  }

  BirthdayParty temp = other; // A temporary object placeholder on the stack so other does not need to change
  changeGuestList(temp); // Calling a helper function which swaps linked lists
  return *this; // Ensures chaining assignments will work by returning a refernce to itself
}

BirthdayParty::~BirthdayParty() {
  // Call to destruct and delete whole link list function
  deleteList();
}

// We determine if the first full name parameter versus the second full name parameter is alphabetically first
// by looking at the last name, then first name if the last names are the same, returning false
bool BirthdayParty::isFirstAlpha(const std::string& firstName, const std::string& lastName, const std::string& firstName2, const std::string& lastName2) {
  if ((lastName != lastName2) && (lastName < lastName2)) {
    return true;
  } else if ((lastName != lastName2) && (lastName > lastName2)) {
    return false;
  } else if ((firstName != firstName2) && (firstName < firstName2)) {
    return true;
  }
  return false;
}

void BirthdayParty::addToFront(const std::string& firstName, const std::string& lastName, const BirthdayType& value) {
  node* temp = new node(firstName, lastName, value);

  temp->next = head; // Go to top of the list
  if (head != nullptr) { // If empty list before we don't need to connect prev
    head->prev = temp;
  }
  head = temp; // Reposition head
  tail = head; // If that is first node, then head and tail are the same

  // If node just inserted is not the only node, then we traverse until the end
  // of the list to assign where the tail pointer should point to
  if (tail->next != nullptr) {
    while (tail->next != nullptr) {
      tail = tail->next;
    }
  }

}

// Traverses through whol linked list by first pointing to head then after poining to each next node,
// we print its values
void BirthdayParty::printValues() {
  node* temp = head;

  while (temp != nullptr) {
    cout << temp->firstName << endl;
    cout << temp->lastName << endl;
    cout << temp->fullName << endl;
    cout << temp->value << endl;

    temp = temp->next;
  }
}

// Delete a target node from the parameter once
void BirthdayParty::deleteNode(const std::string& fullName) {
  // If there is nothing in the list
  if (head == nullptr) {
    return;
    // If there is only one element in the list
  } else if (head->next == nullptr) {
    delete head;
  }
  node* temp = head;
  while (temp != nullptr) {

    if (temp->fullName == fullName) {
      // If the list is filled and we delete head
      if (temp == head) {
        temp->next->prev = nullptr;
        delete temp;
      } else if (temp == tail) {
        // If temp is tail
        temp->prev->next = nullptr;
        delete temp;
      } else {
        // If we delete in middle of list
        node* temp2 = temp->prev;
        // Reconnect the nodes before deletion
        temp->prev->next = temp->next;
        temp->next->prev = temp2; // Equal to original temp->prev

        delete temp;
      }
    }
    temp = temp->next; // We keep on going until we either hit or last element w/ no hit
  }
}

// We traverse through a whole linked list where the second pointer
// always stays ahead of the first temp pointer so that after  deletion
// of a node, our place does not get lost.
void BirthdayParty::deleteList() {
  node* temp = head;

  while (temp != nullptr) {
    node* temp2 = temp->next;
    delete temp;
    temp = temp2;
  }
}


void BirthdayParty::copyList(const BirthdayParty& other) {

  // First we create this node then assign the values head nodes of the other object
  // to this object then move temp one step up in preparation of assigning it over in the loop
	head = new node;
  tail = head;

	head->value = other.head->value;
  head->firstName = other.head->firstName;
  head->lastName = other.head->lastName;
  head->fullName = other.head->fullName;

	node* temp = head;
	node* temp2 = other.head->next;

	while (temp2 != nullptr) {
    // Every iteration creates a new node on the heap for us to copy over from other
		temp->next = new node;

    // Tail is the last node which we just added
    tail = temp->next;
    // Link our newly created node back to temp, our previous node
    temp->next->prev = temp;

    // Copy the values over from other
		temp->next->value = temp2->value;
    temp->next->firstName = temp2->firstName;
    temp->next->lastName = temp2->lastName;
    temp->next->fullName = temp2->fullName;

    // Traverse on where tail node points to nullptr
    // and both linked list objects move one node up until passed the last node
		temp->next->next = nullptr;
		temp = temp->next;
    temp2 = temp2->next;
  }
}

// Head being a nullptr indicates that there indeed was no invitees currently in the list
bool BirthdayParty::noInvitees() const {
  if (head == nullptr) return true;
  return false;
}

// We have an integer counter variable that increments after each traversal.
// After all nodes have been traversed we return the count
int BirthdayParty::whosOnTheGuestList() const {
  node* temp = head;
  int count = 0;

  while (temp != nullptr) {
  count++;
  temp = temp->next;
  }
  return count;
}

bool BirthdayParty::addInvitee(const std::string& firstName, const std::string& lastName, const BirthdayType& value) {
  string fullName = firstName + lastName;

  // If the person's full name is already on the guess list, return false.
  if (personOnGuestList(firstName, lastName)) {
    return false;
  } else if (head == nullptr) {
    addToFront(firstName, lastName, value); // Add to front if list is empty
    return true;
  } else if (isFirstAlpha(firstName, lastName, head->firstName, head->lastName)) { // Add to front if alphabetically before values of first node
    addToFront(firstName, lastName, value);
    return true;
  } else { // In all other cases we need to find the above our targeted insertion place
    node* temp = head;
    while (temp->next != nullptr) {
      if (isFirstAlpha(firstName, lastName, temp->next->firstName, temp->next->lastName)) {
        break;
      }
      temp = temp->next; // Checks until reaches node before insertion
    }

    node* temp2 = new node(firstName, lastName, value); // Now above insertion point create node

    if (temp->next == nullptr) { // If last of the list do this
      temp2->prev = temp;
      temp2->next = nullptr;
      temp->next = temp2;
    } else {
      node* temp3 = temp->next; // The node positioned after the one to be inserted

      temp->next = temp2; // In all other cases we make 4 way conneection
      temp2->prev = temp;
      temp2->next = temp3;
      temp3->prev = temp2;
    }

    tail = head; // If that is first node, then head and tail are the same

    // If node just inserted is not the only node, then we traverse until the end
    // of the list to assign where the tail pointer should point to
    if (tail->next != nullptr) {
      while (tail->next != nullptr) {
        tail = tail->next;
      }
    }
  }
  return true;
}

// If the person is on the guest list, iterate until we find which node the full name is on.
bool BirthdayParty::modifyInvitee(const std::string& firstName, const std::string& lastName, const BirthdayType& value) {
  string fullName = firstName + lastName;

  if (personOnGuestList(firstName, lastName)) {
    node* temp = head;

    while (temp->fullName != fullName) { // After finding the target node after looping, we assign the node's value to the parameter's
      temp = temp->next;
    }
    temp->value = value;
    return true; // and return true after we assign the new value to the node
    }

  return false; // If person is not on the guest list, we return false
}


bool BirthdayParty::addOrModify(const std::string& firstName, const std::string& lastName, const BirthdayType& value) {
  string fullName = firstName + lastName;

  if (personOnGuestList(firstName, lastName)) { // If full name matches, proceed
    return modifyInvitee(firstName, lastName, value); // to check guest list and replace value
  } else {
    return addInvitee(firstName, lastName, value); // Else add invitee to rightful place
  }
}

bool BirthdayParty::dropFromGuestList(const std::string& firstName, const std::string& lastName) {
  string fullName = firstName + lastName;

  if (personOnGuestList(firstName, lastName)) { // If person is on the guest list, we now need to begin search of the list
    node* temp = head;

    while (temp != nullptr) {
      if (temp->fullName == fullName) { // When found we delete the node then reattach other nodes with our helper function
        deleteNode(fullName);
        return true;
      } else
      temp = temp->next;
    }
  }
  return false;
}


bool BirthdayParty::personOnGuestList(const std::string& firstName, const std::string& lastName) const {
  string fullName = firstName + lastName;
  node* temp = head;

  while (temp != nullptr) {
    if (temp->fullName == fullName) { // We iterate through the whole list, and once we find our target full name, we return true
      return true;
    } else
    temp = temp->next;
  }
  return false; // If the person is not on the list then we return false
}

bool BirthdayParty::checkGuestList(const std::string& firstName, const std::string& lastName, BirthdayType& value) const {
  string fullName = firstName + lastName;
  if (personOnGuestList(firstName, lastName)) { // If the person is on the guest list, then we search for the node it is on
    node* temp = head;

    while (temp->fullName != fullName) {
      temp = temp->next;
    }
    value = temp->value; // After finding the node, we extract the value through pass by refrence then return true
    return true;
    }

  return false; // If the name is not on the list we return false
}

bool BirthdayParty::selectInvitee(int i, std::string& firstName, std::string& lastName, BirthdayType& value) const {
  string fullName = firstName + lastName;

  if ((0 <= i) && (i < whosOnTheGuestList())) { // As long as we are in the bounds of the linked list indexes, we eventually return true
    node* temp = head;
    for (size_t j = 0; j < i; j++) { // After we reach our target index i, then we assign the node's values through pass by reference
      temp = temp->next;
    }

    firstName = temp->firstName;
    lastName = temp->lastName;
    value = temp->value;
    return true;
  }
  return false; // If we chose an index that is not in the bounds of the linked list, we return false
}

void BirthdayParty::changeGuestList(BirthdayParty& other) {

  node* tempHead = head; // We switch the heads and tails of our two object linked lists
  node* tempTail = tail; // To do our switch we also use two placeholder pointers

  head = other.head;
  tail = other.tail;

  other.head = tempHead;
  other.tail = tempTail;
}

bool combineGuestLists(const BirthdayParty & bpOne, const BirthdayParty & bpTwo, BirthdayParty & bpJoined) {
  // Passed thru ref varriables
  string firstName;
  string lastName;
  BirthdayType value;
  bool trueFalse = true;

  // Iterate through the second list with the range of number of its guest list
  for (size_t i = 0; i < bpOne.whosOnTheGuestList(); i++) {

    // Each iteration (i) selects a variable to pass back by reference into addInvitee()
    bpOne.selectInvitee(i, firstName, lastName, value);

    // If this node full name is also in the other object, return false later
    if (bpTwo.personOnGuestList(firstName, lastName)) {
      trueFalse = false;
    }
    // If not yet on the list, then add it to bpJoined, if already on the list then do nothing
    bpJoined.addInvitee(firstName, lastName, value);
  }

  // Iterate through the second list with the range of number of its guest list
  for (size_t i = 0; i < bpTwo.whosOnTheGuestList(); i++) {

    // Each iteration (i) selects a variable to pass back by reference into addInvitee()
    bpTwo.selectInvitee(i, firstName, lastName, value);

    // If this node full name is also in the other object, return false later
    if (bpOne.personOnGuestList(firstName, lastName)) {
      trueFalse = false;
    }

    // If not yet on the list, then add it to bpJoined, if already on the list then do nothing
    bpJoined.addInvitee(firstName, lastName, value);
  }
  return trueFalse;
}


void verifyGuestList (const std::string& fsearch, const std::string& lsearch, const BirthdayParty& bpOne, BirthdayParty& bpResult) {

  // Passed through reference varriables
  string firstName;
  string lastName;
  BirthdayType value;

  if ((fsearch == "*") && (lsearch == "*")) {
    bpResult = bpOne; // Assignment Operator makes this possible where if both wildcarded, we simply a copy
  }

  // Iterate through the second list with the range of number of its guest list
  for (size_t i = 0; i < bpOne.whosOnTheGuestList(); i++) {

    // Each iteration (i) selects a variable to pass back by reference into addInvitee()
    bpOne.selectInvitee(i, firstName, lastName, value);

    if ((fsearch == "*") && (lastName == lsearch)) {
      bpResult.addInvitee(firstName, lastName, value);
    } else if ((lsearch == "*") && (firstName == fsearch)) {
      bpResult.addInvitee(firstName, lastName, value);
    }
  }
}
