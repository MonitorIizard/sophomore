#include <iostream>
using namespace std;

class Queue;
class Node;

class BTS {
private : 
  int data;
  BTS *left, *right;

public :
  
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
    cout << root -> data << ",";
    preorder( root->left );
    preorder( root->right );
  }

  void postorder( BTS *root ) {
    if( !root ) return;
    postorder( root->left );
    postorder( root->right );
    cout << root -> data << ",";
  }

  void breadthFirstTraversal( BTS *root, Queue *queue );

  int getData() {
    return data;
  }

  BTS* deleteNode( BTS* root, int dataToDel ) {
    if( !root ) {
      return root;
    }

    if ( root->data > dataToDel ) {
      root->left = deleteNode( root->left, dataToDel );
      return root; //return that node to join
    }
    if ( root->data < dataToDel ) {
      root->right = deleteNode( root->right, dataToDel );
      return root;
    }

    if ( root -> left == NULL ) {
      BTS* temp = root -> right;
      delete root;
      return temp;
    
    } else if ( root -> right == NULL ) {
      BTS* temp = root -> left;
      delete root;
      return temp;

    } else {
      
      BTS* SuccParent = root;
      BTS* Succ = SuccParent->right;
      while( Succ->left != NULL ) {
        SuccParent = Succ;
        Succ = Succ->left;
      }

      if ( SuccParent != root ) {
        SuccParent->left = Succ->right;
      } else {
        SuccParent->right = Succ->right; 
      }

      root->data = Succ->data;

      delete Succ;
      return root;

    }
  }

  BTS* search( BTS *root, int valTOFind ) {
    if( !root ) {
      return NULL;
    }

    if( root->data == valTOFind ) return root;

    if( valTOFind > root->data ) {
      return search( root->right, valTOFind );
    } else {
      return search( root->left, valTOFind );
    }

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
    length++;
    if( !root ) { 
      root = new Node( node );
      return; 
    }

    Node* newNode = new Node( node );
    Node *curr = root;

    while( curr->next != NULL ) {
      curr = curr->next;
    }
    curr->next = newNode;
  }

  BTS* dequeue( ) {
    if( !root ) return 0;
    Node *temp = root;
    root = root->next;

    BTS *tempNode = temp->node;
    delete temp;
    length--;
    return tempNode;
  }

  void print( ) {
    Node *curr = root;
    while( curr != NULL ) {
      cout << curr->node->getData() << ",";
      curr = curr->next;
    }
  }
  
};

void BTS::breadthFirstTraversal( BTS *root, Queue *queue ) {
  if( !root ) return;

  queue->enqueue(root);
  int numberOfChildAtLevel = 1;
  int temp = 0;

  while( queue -> length != 0 ) {
    BTS* dequeueNode = queue->dequeue();
    cout << dequeueNode->getData() << ",";
    numberOfChildAtLevel -= 1;
    
    if(dequeueNode->left) {
      queue->enqueue(dequeueNode->left);
      temp++;
    }
    
    if (dequeueNode->right) {
      queue->enqueue(dequeueNode->right);
      temp++;
    }

    if ( numberOfChildAtLevel == 0 ) {
      cout << "|";
      numberOfChildAtLevel = temp;
      temp = 0;
    };
  }

  delete queue;
  }


int main( ) {
  BTS* root = NULL;
  BTS binarySearchTree; 

  char command;
  while (command != 'x' ) 
  {
    cin >> command;
    if( command == 'a' ) {
      int data;
      cin >> data;
      if ( !root ) {
        // cout << binarySearchTree.insert( root, data );
        root = binarySearchTree.insert( root, data );
      } else {
        binarySearchTree.insert( root, data );
      }
    }

    if( command == 'b' ) {
      Queue *q = new Queue();
      binarySearchTree.breadthFirstTraversal( root, q );
      cout << "\n";
    }

    if( command == 'i' ) {
      binarySearchTree.inorder( root );
      cout << "\n";
    }

    if( command == 'p' ) {
      binarySearchTree.preorder( root );
      cout << "\n";
    }

    if( command == 't' ) {
      binarySearchTree.postorder( root );
      cout << "\n";
    }

    if ( command == 'd' ) {
      int dataToDelete;
      cin >> dataToDelete;
      binarySearchTree.deleteNode( root , dataToDelete );
    }
  }
  return 0;
}