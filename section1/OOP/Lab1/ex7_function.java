import java.util.Scanner;

public class ex7_function {
    public static void main ( String[] args ) {
        System.out.print("Please input x and n : ");
        Scanner scan = new Scanner( System.in );
        double x = scan.nextDouble();
        double n = scan.nextDouble();

        int answer = 0;
        for ( double i = 0; i <= n; i++ ) {
            double value = Math.pow( x, i );
            answer += value;
        }

        System.out.format( "Output is : %d", answer );
    }
}
