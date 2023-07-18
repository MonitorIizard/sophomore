#include <iostream>
#include <iomanip>
using namespace std;

double equation( double constant , double parameter, int root ) {
    return parameter -  pow( constant, 1.0/root );
}

int main () {

    int i = 0;

    double xl = 0;
    float xr = 10000000;

    float constant;
    cin >> constant;

    int root;
    cin >> root;

    float epsilon = 0.000001;
    double xm = ( xl + xr ) / 2;
    double temp = 0;

    int round = 0;

    while ( true ) {
        xm = ( xl + xr ) / 2.0;

        //printf( "%.6f %.6f\n",  equation( xm ) / 0.000001 , temp / 0.000001 );
        if ( fabs( equation( constant, xm, root ) - temp ) * 1.0 < epsilon ) break;

        printf( "value of xm is %.6f\n", xm);

        printf( "value of f(%.3f) is %.6f\n", xm, equation( constant, xm,root ) );
        printf( "value of f(%.3f) is %.6f\n", xl, equation( constant, xl, root ) );
        printf( "value of f(%.3f) is %.6f\n", xr, equation( constant, xr, root ) );

        if ( equation( constant, xm, root ) * equation( constant, xr, root ) > 0 ) {
            cout << " xr = xm " << endl;
            xr = xm;
            

        } else {
            cout << " xl = xm" << endl;
            xl = xm;
        }
        temp = equation( constant, xm, root );
        cout << "_____________________\n";
        round++;
    }

    cout << "value is : " << xm << setw(7) << " , number of round is " << round << endl;
    return 0;
}