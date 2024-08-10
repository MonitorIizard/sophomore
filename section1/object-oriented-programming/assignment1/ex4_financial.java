import java.util.Scanner;

public class ex4_financial {
    public static void main ( String[] args) {

        Scanner input = new Scanner( System.in );

        float i = input.nextFloat() * ( input.nextFloat() / 1200 );

        System.out.println( i );
    }
}
