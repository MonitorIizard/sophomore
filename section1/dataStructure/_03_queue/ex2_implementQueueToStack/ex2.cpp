#include <iostream>
#include <queue>
using namespace std;

class Data {
public:    
    int number;
    Data( int number ): number( number ) {};
};

class MyStack {
private:
    queue<Data*> stack;
public:
    MyStack() {
       
    }
    
    void push(int x) {
        Data* newData = new Data( x );
        if ( stack.empty() ) {
            stack.push( newData );
            return;
        }

        stack.push( newData );
        while ( stack.front() != newData ) {
            Data* temp = stack.front() ;
            stack.pop();

            stack.push( temp );
        }
    }
    
    int pop() {
        Data* temp = stack.front();
        int tmp_val = temp -> number;
        stack.pop();
        delete temp;
        return tmp_val;
    }
    
    int top() {
        return stack.front() -> number;
    }
    
    bool empty() {
        if ( stack.empty() ) return true;
        return false;
    }

    void printAll() {
      queue<Data*> a = stack;

      while( !stack.empty() ) {
        cout << stack.front() -> number << "<-";
        stack.pop();
      }

      cout << endl;
    }
};

int main() {

  MyStack x;
  x.push( 1 );
  x.push( 2 );
  x.push( 3 );
  x.push( 4 );
  x.push( 5 );
  x.push( 2 );

  x.printAll();

  return 0;
}