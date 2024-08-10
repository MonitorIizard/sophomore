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

    if ( data > root->data ) {
      root->right = insert( root->right, data );
    }

    if ( data < root->data ) {
      root->left = insert( root->left, data );
    }

    return root;
  }

  BST* del( BST* root, int data ) {
    if( !root ) return;

    if ( data > root->data ) {
      root->right = del(root->right, data);
      return root;
    }

    if ( data < root->data ) {
      root->left = del(root->left, data);
      return root;
    }

    if ( !root -> left ) {
      BST* temp = root->right;
      delete root;
      return temp;
    } else if ( !root -> right ) {
      BST* temp = root->left;
      delete root;
      return temp;
    } else {

      BST* succP = root;
      BST* succ = root->right;

      while( succ->left != NULL ) {
        succP = succ;
        succ = succ->left;
      }

      if ( succP != root ) {
        succP->left = succ->right;
      } else {
        succP->right = succ->right;
      }

      succP->data = succ->data;
      delete succ;

      return succP;

    }
  }
};


int main () {
  BST* root = NULL;

  // cout << root;

  int x = 5;
  int*p;

  return 0;
}