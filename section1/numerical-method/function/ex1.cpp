#include<iostream>
#include<math.h>

using namespace std;

int equation( int x ) { 
    int answer = exp( (-x) / 4 );
    return answer;
}

int main () {
    cout << equation(1);
    return 0;
}