#include <iostream>
using namespace std;

double f( double parameter, double constant, int root )  {
    return parameter - pow( constant, 1.0 / root );
}

int main() {

    double xm = 0;
    double xl = 0;
    double xr = 1000000;
    double temp = 0;

    double constant;
    int root;
    cin >> constant;
    cin >> root;

    while( true ) {

        xm = ( xr + xl ) / 2.0;
        
        if (  fabs ( xm - temp ) / xm * 100 < 0.00001 ) {
            cout << "f(xm) is" << f( xm, constant, root) << endl;
            cout << "temp is" << temp << endl;
            printf( "answer is %.4f", xm);
            break;    
        }

        cout << "f(xm) is" << f( xm, constant, root) << endl;
        cout << "f(xl) is" << f( xl, constant, root) << endl;
        cout << "f(xr) is" << f( xr, constant, root) << endl;

        if ( f( xm, constant, root ) * f( xr, constant, root ) < 0 ) {
            cout << "case 1" << endl;
            xl = xm;
        } else if ( f( xm, constant, root ) * f( xl, constant, root ) < 0 ) {
            cout << "case 2" << endl;
            xr = xm;
        }

        temp = xm;
        
        cout << endl;

    }

    return 0;
}