#include <iostream>
using namespace std;

double equation( double x ) {
    double answer = ( 43 * x - ( 1.0 ) );
    return answer;
}

double recurrtion( double xLeft, double xRight ) {

}

int main() { 

    while ( true ) {
        double parameter;
        cin >> parameter;
        printf("f(%f) : %f", parameter, equation( parameter ));
        cout << endl;
    }

    return 0;
}