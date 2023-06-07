#include <iostream>
#include <stack>
using namespace std;

void printStackElements(stack<int> stack) {
    while (!stack.empty()) {
        cout << stack.top() << endl;
        stack.pop();
    }
}

int main () 
{
    stack <int> numberStack;

    numberStack.push(1);
    numberStack.push(2);
    numberStack.push(3);
    // numberStack.pop();
    // numberStack.pop();
    // numberStack.pop();

    if (numberStack.empty()) {
        cout << "stack is empty" << endl ;
    } else {
        cout << "stack is not empty" << endl;
    }
    
    cout << "stack size is " << numberStack.size() << endl;
    
    //? how to write out the element out the stack

    cout << "print stack" << endl;
    printStackElements(numberStack);


    
    // 5 function in stack
    // isEmpty();
    // Size();
    // top();
    // push();
    // pop();
}