import java.util.Scanner;

public class ex1_cal {

    public static void main ( String args[] ) {
        Scanner fahrenheit = new Scanner( System.in );
        double celsius= ( ( float )5/9 ) * ( fahrenheit.nextDouble() - 32 );
        System.out.println( String.format( "celsius is %.3f" , celsius ) );
    }
}
