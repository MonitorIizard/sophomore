#include <iostream>
using namespace std;

class BST {
private :
  int data;
  BST *left, *right;

public :
  BST() {
    data = 0;
    left = NULL;
    right = NULL;
  }

  BST( int data ) {
    this->data = data;
    left = NULL;
    right = NULL;
  }

  BST* insert( BST* root, int data ) {
    if(!root) return new BST( data ); 
  }

};


int main () {
  BST* root = NULL;

  // cout << root;

  int x = 5;
  int*p;

  return 0;
}