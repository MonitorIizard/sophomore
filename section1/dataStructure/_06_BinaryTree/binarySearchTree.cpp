#include <iostream>
using namespace std;

class Queue;
class Node;

class BTS {
private : 
  int data;
  BTS *left, *right;
  

public :
  Queue *q = new Queue();
  
  //default constructor
  BTS() {
    data = 0;
    left = NULL;
    right = NULL;
  }

  //parameterized constructor
  BTS(int data) {
    this->data = data;
    left = NULL;
    right = NULL;
  }

  //insert
  BTS* insert( BTS* root, int data ) {
    if( !root ) {
      return new BTS(data);
    }

    if( root->data < data ) {
      root->right = insert( root->right, data );

    } else if ( root->data >= data ){
      root->left = insert( root->left, data );

    }

    //return root pointer 
    return root;
  }

  void inorder( BTS *root ) {
    if( !root ) return;
    inorder( root->left );
    cout << root -> data << ",";
    inorder( root->right );
  }

  void preorder( BTS *root ) {
    if( !root ) return;
    preorder( root->right );
    cout << root -> data << ",";
    preorder( root->left );
  }

  void postorder( BTS *root ) {
    if( !root ) return;
    postorder( root->left );
    postorder( root->right );
    cout << root -> data << ",";
  }

  void breadthFirstTraversal( BTS *root ) {
    q->enqueue(root);
    for( int i = 0; i < q->length; i++ ) {
      cout<<i;
    }
    
  }

  int getData() {
    return data;
  }
};

class Node {
public :
  BTS *node;
  Node *next;

  Node( BTS *node ) : node( node ), next( NULL ) {};
};

class Queue {
private:
  Node *root;

public:
  int length;

  Queue() {
    length = 0;
    root = NULL;
  }

  void enqueue( BTS *node ) {
    if( !root ) { 
      root = new Node( node );
      return; 
    }

    Node* newNode = new Node( node );
    Node *curr = root;

    while( curr->next != NULL ) {
      curr = curr->next;
    }

    length++;
    curr->next = newNode;
  }

  int dequeue( ) {
    Node *temp = root;
    root = root->next;

    int tempData = temp->node->getData();
    delete temp;
    length--;
    return tempData;
  }

  void print( ) {
    Node *curr = root;
    while( curr != NULL ) {
      cout << curr->node->getData() << ",";
      curr = curr->next;
    }
  }
  
};


int main( ) {
  BTS* root = NULL;
  BTS binarySearchTree = NULL; 
  root = binarySearchTree.insert( root, 10 );
  binarySearchTree.insert( root, 7 );
  binarySearchTree.insert( root, 13 );
  binarySearchTree.insert( root, 2 );
  binarySearchTree.insert( root, 9 );
  binarySearchTree.insert( root, 20 );
  binarySearchTree.insert( root, 11 );
  binarySearchTree.inorder( root );
  cout << "\n";
  binarySearchTree.preorder( root );
  cout << "\n";
  binarySearchTree.postorder( root );
  cout << "\n";
  binarySearchTree.breadthFirstTraversal( root );


  return 0;
}