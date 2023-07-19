import java.util.Scanner;

public class ex9_findMax {
    public static void main ( String[] args ) {

        int max = -100000;
        int count = 0;

        while ( true ) {
            Scanner scan = new Scanner( System.in );
            int value = scan.nextInt();

            if ( value == 0 ) {
                break;
            }

            if ( max < value ) {
                count = 0;
                max = value;
            }

            if ( max == value ) {
                count += 1;
            }
        }

        System.out.format( "%2d %2d", max, count );
    }
}
