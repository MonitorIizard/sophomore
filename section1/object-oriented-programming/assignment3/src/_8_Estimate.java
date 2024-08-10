import java.util.Scanner;

public class _8_Estimate {

    public static void main( String[] args ) {
        Scanner sc = new Scanner( System.in );
        int i = sc.nextInt();

        System.out.printf("%.4f", m(i));
    }
    public static double m( int i ) {
        double sum = 0;
        for( int j = 1; j <= i; j++ ) {
            sum += 4 * ( Math.pow( -1, j + 1) / ((2 * j) - 1 ));
        }

        return sum;
    }
}
