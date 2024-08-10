#include <iostream>
using namespace std;

double f( double parameter ) {
    return ( parameter ) * 43 - 180;
}

int main () {
    int upperLimit = 10;
    double i = 0;
    double temp = 0;
    double epsilon = 0.000001;
    double iterative = 1;

    while ( i <= upperLimit ) {
    
        if ( f(i) * temp  < 0 ) {
            if ( iterative == 0.000001) {
                printf( "answer is %.6f", i);
                break;
            }
            int upperLimit = i--;
            iterative = 0.000001;
        }

        temp = f(i);
        i += iterative;
    }

    return 0;
}