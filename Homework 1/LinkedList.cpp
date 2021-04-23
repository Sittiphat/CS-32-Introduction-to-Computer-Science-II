#include "LinkedList.h"

using namespace std;

// Assign head and tail in initializer list.
LinkedList::LinkedList()
  : head(nullptr), tail(nullptr) {}

// If the we copy two objects and the second object is yet created.
LinkedList::LinkedList(const LinkedList& rhs) {
  head = rhs.head;
  tail = rhs.tail;
  
}

// We create two pointers so that when we delete one node, there is another
// carried over
LinkedList::~LinkedList() {
  Node* temp = head;
  Node* temp2 = head;
  while (temp2 != nullptr) {
    temp2 = temp2->next;
    delete temp;
    temp = temp2;
  }
}

// When both objects to be copied are already created
// To account for assigning to oneself.
const LinkedList& LinkedList::operator=(const LinkedList& rhs) {
  if (&rhs == this) {
    return *this;
  }

  Node* temp = head;
  Node* temp2 = head;
  while (temp2 != nullptr) {
    temp2 = temp2->next;
    delete temp;
    temp = temp2;
  }


}

// We create a pointer to a new node on the heap
// with its value and next pointer.
// If there is no linked list yet, then then head is
// a nullptr and so both head and tail are to be the same
// since only one node.
void LinkedList::insertToFront(const ItemType &val) {
  Node* temp = new Node;
  temp->value = val;
  temp->next = head;
  if (head == nullptr) {
    head = temp;
    tail = temp;
  } else {
    head = temp;
  }
}


// A simple traversal that stops until we reach the end
// of the linked list which would be met with a nullptr
void LinkedList::printList() const {
  Node* temp = head;
  while (temp != nullptr) {
    cout << temp->value << " ";
    temp = temp->next;
  }
}

// We create an int counter and traverse the List
// just like the last function but stop and return true
// if we hit a match with i, ending the program.
bool LinkedList::get(int i, ItemType& item) const {
  Node* temp = head;
  int count = 0;
  while (temp != nullptr) {
    if (count == i) {
      temp->value = item;
      return true;
    }
    count++;
    temp = temp->next;
  }
  return false;
}

// We store the linked list like the regular print
// function in an array also using a node count
// algorithm featured in the last size() function.
// We need to store the array in the heap since it
// does not have a constant size. Then we print reverse using
// a deincremented for loop and then delete what is left on the heap.
void LinkedList::printReverse() const {
  Node* temp = head;
  int count = 0;
  while (temp != nullptr) {
    count++;
    temp = temp->next;
  }

  string *arr = new string[count];
  temp = head;
  int i = 0;
  while (temp != nullptr) {
    arr[i] = temp->value;
    temp = temp->next;
    i++;
  }

  for (int j = count - 1; j >= 0; j--) {
    cout << arr[j] << " ";
  }

  delete [] arr;
}

// If the list to be appended was never created, it becomes other,
// else the tail end pointer of the linked list is appended by
// becoming head of other
void LinkedList::append(const LinkedList &other) {
  if (head == nullptr) {
    head = other.head;
    tail = other.tail;
  } else {
    tail = other.head;
  }
}

// We traverse both linked lists simultaneously
// so that when we arrive at each node, we switch them.
void LinkedList::swap(LinkedList &other) {
  Node* temp = head;
  Node* temp2 = other.head;
  while (temp != nullptr) {
    string hold = temp->value;
    temp->value = temp2->value;
    temp2->value = hold;

    temp = temp->next;
    temp2 = temp2->next;
  }
}

// A counter is initialized at zero where
// every node traversed will +1, where the
// the counter only ends at the end of a linked list
// indicated by nullptr.
int LinkedList::size() const {
  Node* temp = head;
  int count = 0;
  while (temp != nullptr) {
    count++;
    temp = temp->next;
  }
  return count;
}
