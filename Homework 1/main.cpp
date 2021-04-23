#include "LinkedList.h"

#include <assert.h>

using namespace std;

// Testing different fuctions and how they interact together
int main() {
cout << "Main Function Starts: " << endl << endl;

LinkedList linked;
string name1 = "Jesse";
string name2 = "James";


linked.insertToFront(name1);
linked.insertToFront(name1);
linked.insertToFront(name1);
linked.insertToFront(name1);
linked.insertToFront(name1);


linked.printList();

cout << "Main Function Starts: " << endl << endl;
cout << linked.get(4, name2);

linked.printList();

// cout << "Main Function Starts: " << endl << endl;
// linked.printReverse();

cout << "Main Function Starts: " << endl << endl;
cout << linked.size();


cout << "Main Function Starts: " << endl << endl;
linked.printReverse();

cout << "Main Function Starts: " << endl << endl;

LinkedList linked2;


linked2.insertToFront(name2);
linked2.insertToFront(name2);
linked2.insertToFront(name2);
linked2.insertToFront(name2);
linked2.insertToFront(name2);

linked2.printList();

cout << "Main Function Starts: " << endl << endl;
linked.append(linked2);

linked2.printList();

cout << "Main Function Starts: " << endl << endl;
linked.swap(linked2);

linked2.printList();

cout << "Main Function Starts: " << endl << endl;
linked.printList();

  return 0;
}
