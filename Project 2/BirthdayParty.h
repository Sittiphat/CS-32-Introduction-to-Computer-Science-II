#ifndef BIRTHDAYPARTY_H
#define BIRTHDAYPARTY_H

#include <iostream>
#include <string>

typedef std::string BirthdayType;

class BirthdayParty {

  // NAME: struct node
  // INPUT: firstName, lastName, value
  // OUTPUT: index if valid insertion, -1 if otherwise
  // DESCRIPTION: A struct class that helps create a node data type with its own
  // members as values and previous/next pointers to point to simultaneous nodes
  // in a linked list
  struct node {

    // Default Constructor for node
    node()
      : value(0), firstName(""), lastName(""), fullName(firstName + lastName), prev(nullptr), next(nullptr) {}

    // Constructor with parameter for node
    node(const std::string& firstName, const std::string& lastName, const BirthdayType& value)
      : value(value), firstName(firstName), lastName(lastName), fullName(firstName + lastName), prev(nullptr), next(nullptr) {}

    // Private member variables
    // Data Values
    std::string firstName;
    std::string lastName;
    std::string fullName;
    BirthdayType value;
    // Directional Pointers
    node* prev;
    node* next;
  };

  // Helper Functions

  // NAME: isFirstAlpha
  // INPUT: firstName, lastName, firstName2, lastName2, value
  // OUTPUT: 1 if true and 0 if false
  // DESCRIPTION: Returns 1 if true that the first full names in the parameter go before the second full name that are also in the parameter
  // otherwise it is false and returns 0.
  bool isFirstAlpha(const std::string& firstName, const std::string& lastName, const std::string& firstName2, const std::string& lastName2);

  // NAME: addToFront
  // INPUT: firstName, lastName, value
  // OUTPUT: Nothing
  // DESCRIPTION: Returns 1 if first full name in parameter is first alphabetically by ASCII
  // otherwise it is false and returns 0.
  void addToFront(const std::string& firstName, const std::string& lastName, const BirthdayType& value);

  // NAME: printValues
  // INPUT: Nothing
  // OUTPUT: Nothing
  // DESCRIPTION: Traverses through each node of a linked list and prints each and every node
  void printValues();

  // NAME: deleteNode
  // INPUT: fullName
  // OUTPUT: Nothing
  // DESCRIPTION: Finds the target value in the parameter and deletes it from the list
  void deleteNode(const std::string& fullName);

  // NAME: deleteList
  // INPUT: Nothing
  // OUTPUT: Nothing
  // DESCRIPTION: Deconstructs a whole linked list
  void deleteList();

  // NAME: copyList
  // INPUT: other
  // OUTPUT: Nothing
  // DESCRIPTION: Copies an object parameter's linked list into the current object
  void copyList(const BirthdayParty& other);

  // Private head and tail pointers
  node* head;
  node* tail;



public:

  // NAME: dump
  // INPUT: Nothing
  // OUTPUT: Nothing
  // DESCRIPTION: Prints the list with cerr
  void dump() const;


  // NAME: BirthdayParty Default Constructor
  // INPUT: Nothing
  // OUTPUT: Nothing
  // DESCRIPTION: Create an empty BirthdayParty list
  BirthdayParty();


  // NAME: BirthdayParty Copy Constructor
  // INPUT: other object
  // OUTPUT: Nothing
  // DESCRIPTION: Performs a deep copy of an object
  BirthdayParty(const BirthdayParty& other);


  // NAME: BirthdayParty Assignment Operator
  // INPUT: other object
  // OUTPUT: Nothing
  // DESCRIPTION: Performs a deep copy of an already constructed object
  BirthdayParty& operator=(const BirthdayParty& other); // Assignment Operator


  // NAME: BirthdayParty Destructor
  // INPUT: Nothing
  // OUTPUT: Nothing
  // DESCRIPTION: Deconstructs a whole linked list
  ~BirthdayParty();


  // NAME: noInvitees
  // INPUT: Nothing
  // OUTPUT: 1 if True, 0 if False
  // DESCRIPTION: Return true if the BirthdayParty list is empty, otherwise false.
  bool noInvitees() const;


  // NAME: whosOnTheGuestList
  // INPUT: Nothing
  // OUTPUT: An integer
  // DESCRIPTION: Returns the integer value of number of nodes in the linked list.
  int whosOnTheGuestList() const;


  // NAME: addInvitee
  // INPUT: First and last names and its value
  // OUTPUT: 1 if True, 0 if False
  // DESCRIPTION:   // If the full name (both the first and last name) is not equal
  // to any full name currently in the list then add it and return
  // true. Elements should be added according to their last name.
  // Elements with the same last name should be added according to
  // their first names. Otherwise, make no change to the list and
  // return false (indicating that the name is already in the list).
  bool addInvitee(const std::string& firstName, const std::string&
  lastName, const BirthdayType& value);


  // NAME: modifyInvitee
  // INPUT: First and last names and its value
  // OUTPUT: 1 if True, 0 if False
  // DESCRIPTION: If the full name is equal to a full name currently in the
  // list, then make that full name no longer map to the value it
  // currently maps to, but instead map to the value of the third
  // parameter; return true in this case. Otherwise, make no
  // change to the list and return false.
  bool modifyInvitee(const std::string& firstName, const
  std::string& lastName, const BirthdayType& value);


  // NAME: addOrModify
  // INPUT: First and last names and its value
  // OUTPUT: 1 if True, 0 if False
  // DESCRIPTION: If full name is equal to a name currently in the list, then
  // make that full name no longer map to the value it currently
  // maps to, but instead map to the value of the third parameter;
  // return true in this case. If the full name is not equal to
  // any full name currently in the list then add it and return
  // true. In fact, this function always returns true.
  bool addOrModify(const std::string& firstName, const std::string&
  lastName, const BirthdayType& value);


  // NAME: dropFromGuestList
  // INPUT: First and last names
  // OUTPUT: 1 if True, 0 if False
  // DESCRIPTION: If the full name is equal to a full name currently in the
  // list, remove the full name and value from the list and return
  // true. Otherwise, make no change to the list and return
  // false.
  bool dropFromGuestList(const std::string& firstName, const
  std::string& lastName);


  // NAME: personOnGuestList
  // INPUT: First and last names
  // OUTPUT: 1 if True, 0 if False
  // DESCRIPTION: Return true if the full name is equal to a full name
  // currently in the list, otherwise false.
  bool personOnGuestList(const std::string& firstName, const
  std::string& lastName) const;


  // NAME: checkGuestList
  // INPUT: First and last names
  // OUTPUT: 1 if True, 0 if False
  // DESCRIPTION: If the full name is equal to a full name currently in the
  // list, set value to the value in the list that that full name
  // maps to, and return true. Otherwise, make no change to the
  // value parameter of this function and return false.
  bool checkGuestList(const std::string& firstName, const
  std::string& lastName, BirthdayType& value) const;


  // NAME: selectInvitee
  // INPUT: i which is an index of the linked list
  // OUTPUT: Pass by reference full names and value
  // DESCRIPTION: If 0 <= i < size(), copy into firstName, lastName and value
  // parameters the corresponding information of the element at
  // position i in the list and return true. Otherwise, leave the
  // parameters unchanged and return false. (See below for details
  // about this function.)
  bool selectInvitee(int i, std::string& firstName, std::string&
  lastName, BirthdayType& value) const;


  // NAME: changeGuestList
  // INPUT: other
  // OUTPUT: Nothing
  // DESCRIPTION: // Exchange the contents of this list with the other one.
  void changeGuestList(BirthdayParty& other);


};

// NAME: combineGuestLists
// INPUT: Two object that are to be joined plus a thrid object that is joined
// OUTPUT: If there is a match of a fullName with same value then return false, otherwise true
// DESCRIPTION: If a full name appears in exactly one of bpOne and bpTwo, then bpJoined must
// contain an element consisting of that full name and its corresponding value.
// If a full name appears in both bpOne and bpTwo, with the same corresponding value in
// both, then bpJoined must contain an element with that full name and value.
bool combineGuestLists(const BirthdayParty & bpOne, const BirthdayParty & bpTwo, BirthdayParty & bpJoined);

// NAME: verifyGuestList
// INPUT: Two searches for lastName, firstName or netiher with the object you are searching and its search results
// OUTPUT: Nothing
// DESCRIPTION: When this function returns, bpResult contains a copy of all the elements in bpOne
// that match the search terms; does not contain any other elements. You can wildcard
// the first name, last name or both by supplying "*".
void verifyGuestList(const std::string& fsearch, const std::string& lsearch, const BirthdayParty& bpOne, BirthdayParty& bpResult);


#endif
