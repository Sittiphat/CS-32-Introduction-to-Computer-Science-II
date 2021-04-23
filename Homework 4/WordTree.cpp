#include "WordTree.h"

/*// assignment operator
const WordTree& WordTree::operator=(const WordTree& rhs) {

}*/


// Inserts v into the WordTree
void WordTree::add(WordType v) {
  if (root == nullptr) {
    root = new node(v);
    return;
  }

  node* curr = root;

  for (;;) {
    if (v == curr->m_data) {
      return;
    } else if (v < curr->m_data){
      if (curr->m_left != nullptr) {
        curr = curr->m_left;
      } else {
        curr->m_left = new WordNode(v);
        return;
      }
    } else if (v > curr->m_data) {
      if (curr->m_right != nullptr) {
        curr = curr->m_right;
      } else {
        curr->m_right = new WordNode(v);
        return;
      }
    }
  }
}

/*// Returns the number of distinct words / nodes
int WordTree::distinctWords() const {

}
// Returns the total number of words inserted, including
// duplicate values
int WordTree::totalWords() const {

}

// 1. Process the nodes in the left sub-tree.
// 2. Process the current node.
// 3. Process the nodes in the right sub-tree.

// Inorder Traversal
void inorderTransversal(node* curr) {
  if (curr == nullptr) {
    return;
  }

  inorderTransversal(curr->left);
  cout << curr->data << endl;
  inorderTransversal(curr->right);
}

void inorderTransversalWrapper() {
  inorderTransversal(root);
}

// Prints the LinkedList
friend WordTree::ostream& operator<<(std::ostream &out, const
WordTree& rhs) {
  inorderTransversalWrapper();
}

// Uses post-order traversal to delete tree
void freeTreeRec(node* curr) {
  if (curr == nullptr) {
    return;
  }

  freeTreeRec(curr->left);
  freeTreeRec(curr->right);
  delete curr;

}

void freeTreeRecWrapper() {
  freeTreeRec(root);
}
// Destroys all the dynamically allocated memory in the
// tree
WordTree::~WordTree() {
  freeTreeRecWrapper();
}*/
