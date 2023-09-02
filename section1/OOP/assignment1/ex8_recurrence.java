import java.util.Scanner;

public class ex8_recurrence {
//    public static double recurrence( int a0, int a1, int n ) {
//
//        return double value = ( Math.pow( n, 2 ) * a1 ) - ( a0 ) + Math.pow( 3, n )  ;
//    }
    public static void main ( String[] args ) {
        System.out.print( "Please input n, a0 and a1: " );

        Scanner scan = new Scanner( System.in );
        double n = scan.nextDouble();
        double a0 = scan.nextDouble();
        double a1 = scan.nextDouble();
        System.out.print( "Output is : " );

        for ( double i = 0; i <= n; i++ ) {

            if ( i == 0 ) {
                System.out.format( "%.0f ", a0 );
                continue;
            }

            if ( i == 1 ) {
                System.out.format( "%.0f ", a1 );
                continue;
            }

            if ( i % 2 == 0 ) {
                a0 = ( Math.pow( i, 2 ) * a1 ) - ( a0 ) + Math.pow( 3, i );
                System.out.format( "%.0f ", a0 );
            }

            if ( i % 2 != 0 ) {
                a1 = ( Math.pow( i, 2 ) * a0 ) - ( a1 ) + Math.pow( 3, i );
                System.out.format( "%.0f ", a1 );
            }

//            System.out.format( "%4d",  );

        }
    }
}
