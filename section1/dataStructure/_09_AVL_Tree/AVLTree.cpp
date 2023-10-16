#include <iostream>
using namespace std;

class Node {
public :
  int data;
  int height;
  Node *left;
  Node *right;

  Node( int data ) {
    this->data = data;
    height = 1;
    left = NULL;
    right = NULL;
  }

   Node( ) {
    this->data = 0;
    height = 1;
    left = NULL;
    right = NULL;
  }
};

class AVLTree {
private :
  Node* root;
public : 
  AVLTree() {
    root = NULL;
  }

  int max(int a, int b) {
    if ( a > b ) {
      return a;
    } else {
      return b;
    }
  }

  Node* rotateLeft( Node* root ) {
    Node* succPar = root->right;
    Node* succ = succPar->left;

    succPar -> left = root;
    root -> right = succ;

    root -> height = 1 + max( getHeight(root -> left), getHeight(root -> right));
    succPar -> height = 1 + max( getHeight(succPar->left), getHeight(succPar->right) );

    return succPar;
  }

  Node* rotateRight( Node* root ) {
    Node* predesuccPar = root->left;
    Node* predesucc = predesuccPar->right;

    predesuccPar -> right = root;
    root -> left = predesucc;

    root -> height = 1 + max( getHeight(root -> left), getHeight(root -> right));
    predesuccPar -> height = 1 + max( getHeight(root -> left), getHeight(root -> right));
    return predesuccPar;
  }

  int getHeight(Node* root) {
    if ( root == NULL ) {
      return 0;
    }

    return root->height;
  }
  
  Node* insert( int data, Node* root ) {
    if( root == NULL ) {
      // cout << "case 1 of insert";
      return new Node( data );
    }

    if ( root -> data > data ) {
      root -> left = insert( data, root -> left );
    } else if (root -> data < data) {
      root -> right = insert( data, root -> right) ;
    } else {
      return root;
    }

    root -> height = 1 + max(getHeight(root->left), getHeight(root->right));

    int diffOfFactor = getBalance( root );
    // cout << diffOfFactor;

    if ( diffOfFactor > 1 && data < root -> left -> data ) {
      return rotateRight(root);
    }

    if ( diffOfFactor < -1 && data > root -> right -> data ) {
      return rotateLeft(root);
    }

    // 
    if ( diffOfFactor > 1 && data > root -> left -> data ) {
      root -> left = rotateLeft(root->left);
      return rotateRight(root);
    }

    //right left rotate
    if ( diffOfFactor < -1 && data < root -> right -> data ) {
      root -> right = rotateRight(root->right);
      return rotateLeft(root);
    }

    return root;
  }

  Node* deleteNode( int data , Node* root ) {
    if ( root == NULL ) {
      return root;
    }
    //search target
    if ( root -> data  > data ) {
      root -> left = deleteNode( data, root -> left );
    } else if ( root -> data < data ) {
      root -> right = deleteNode( data, root -> right );
    } 

    //case 1, 2
    if ( root -> left == NULL ) {
      Node* temp = root -> right;
      delete root;
    }

    if ( root -> right == NULL ) {
      Node* temp = root -> left;
      delete root;
    }

    //case 3
    Node* succPar = root;
    Node* succ = succPar -> right;

    while ( succ -> left != NULL ) {
      succPar = succ;
      succ = succ -> left;
    }

    if ( succPar != root ) {
      succPar -> left = succ -> right;
    }

    if ( succPar == root ) {
      succPar -> right = succ -> right;
    }

    root -> data = succ -> data;
    delete succ;

    if ( root == NULL ) {
      return root;
    }

    root -> height = 1 + max( getHeight(root -> left), getHeight(root -> right));

    int balance = getBalance(root);
    // cout << "balance at " << root->data << " = " << getBalance(root) << "\n";

    if ( balance > 1 && getBalance(root->left) >= 0 ) {
      // cout << "case1\n";
      return rotateRight(root);
    }

    if ( balance < -1 && getBalance(root->right) <= 0 ) {
      return rotateRight(root);
    }

    if ( balance > 1 && getBalance(root->left) < 0 ) {
      root -> right = rotateRight(root -> right);
      return rotateLeft(root);
    }

    if ( balance < -1 && getBalance(root->left) > 0 ) {
      root -> left = rotateLeft(root -> left);
      return rotateRight(root);
    }

    return root;
  }

  void preorder( Node *root ) {
    if( !root ) return;
    cout << root -> data << " ";
    preorder( root->left );
    preorder( root->right );
  }

  Node* getNode() {
    return root;
  }

  void setNode( Node* node ) {
    root = node;
  }

  int getBalance( Node* root ) {
    if ( root == NULL ) {
      return 0;
    } 

    return getHeight(root->left) - getHeight(root->right);
  }
};

int main() {
  AVLTree* root = new AVLTree();
  char command;

  while ( command != 'x' ) {
    cin >> command;

    if ( command == 'a' ) {
      int data;
      cin >> data;
      root->setNode(root->insert(data, root->getNode()));      
    }
    

    if ( command == 'd' ) {
      int dataToDelete;
      cin >> dataToDelete;
      root->setNode(root->deleteNode( dataToDelete ,root->getNode()));
    }

    if ( command == 'p' ) {
      root->preorder(root->getNode());
      cout << "\n";
    }

    if ( command == 'x' ) {
      break;
    }
  }

  return 0;
}