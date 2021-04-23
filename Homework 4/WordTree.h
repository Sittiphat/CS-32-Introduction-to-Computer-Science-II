#ifndef WORDTREE_H
#define WORDTREE_H

#include <iostream>
#include <string>

typedef std::string WordType;

struct WordNode {
 WordType m_data;
 WordNode *m_left;
 WordNode *m_right;
 // You may add additional data members and member functions
 // in WordNode

 // Default Constructor
 WordNode()
   : m_data(0), m_left(nullptr), m_right(nullptr) {}

 // Constructor with parameter
 WordNode(const int& data)
   : m_data(data), m_left(nullptr), m_right(nullptr) {}

};

class WordTree {
 private:
 WordNode *root;
 int node_counter;

 public:
 // default constructor
 WordTree() : root(nullptr) { };

 // copy constructor
 WordTree(const WordTree& rhs);

 // assignment operator
 const WordTree& operator=(const WordTree& rhs);
 // Inserts v into the WordTree
 void add(WordType v);
 // Returns the number of distinct words / nodes
 int distinctWords() const;
 // Returns the total number of words inserted, including
 // duplicate values
 int totalWords() const;

 // Prints the LinkedList
 friend ostream& operator<<(std::ostream &out, const
WordTree& rhs);
 // Destroys all the dynamically allocated memory in the
 // tree
 ~WordTree();
};


#endif
