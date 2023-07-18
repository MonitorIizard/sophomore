#include <iostream>
#include <iomanip>
using namespace std;

float equation( float parameter ) {
    return 43 * ( parameter ) - 1;
}

int main () {

    int i = 0;

    double xl;
    float xr;
    cout << "input xl : ";
    cin >> xl;
    cout << "input xr : ";
    cin >> xr;
    float epsilon = 0.000001;
    double xm = ( xl + xr ) / 2;
    double temp = 0;

    int round = 0;

    while ( true ) {
        xm = ( xl + xr ) / 2.0;

        //printf( "%.6f %.6f\n",  equation( xm ) / 0.000001 , temp / 0.000001 );
        if ( fabs( equation( xm ) - temp ) < epsilon ) break;

        printf( "value of xm is %.6f\n", xm);

        printf( "value of f(%.3f) is %.6f\n", xm, equation( xm ) );
        printf( "value of f(%.3f) is %.6f\n", xl, equation( xl ) );
        printf( "value of f(%.3f) is %.6f\n", xr, equation( xr ) );

        if ( equation( xm ) * equation( xr ) > 0 ) {
            cout << " xr = xm ";
            xr = xm;
            

        } else {
            cout << " xl = xm";
            xl = xm;
        }
        temp = equation( xm );
        cout << "_____________________\n";
        round++;
    }

    cout << "value is : " << xm << setw(7) << " , number of round is " << round << endl;
    return 0;
}