import java.util.ArrayList;
import java.util.Scanner;

public class ex6_multriTable {
    public static void main ( String[] args ) {

        Scanner scan = new Scanner(System.in);
        int col = scan.nextInt();
        int row = scan.nextInt();

        for ( int i = 1; i <= row; i++) {
            for ( int j = 1; j <= col; j++ ) {

                if (j == 1 && i == 1) {
                    System.out.format( "    " );
                    continue;
                }

                if ( j == 1 ) {
                    System.out.format("%4d", i );
                    continue;
                }

                if ( i == 1 ) {
                    System.out.format("%4d", j );
                }

                if ( i != 1 ) {
                    System.out.format("%4d", j * i );
                }
            }
            System.out.println();
        }


    }
}
