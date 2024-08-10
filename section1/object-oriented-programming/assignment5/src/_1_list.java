import java.util.ArrayList;
import java.util.Scanner;

public class _1_list {
    public static void main( String[] args ) {
        ArrayList<Float> list = new ArrayList<Float>();
        Scanner sc = new Scanner( System.in );

        float i = 0;
        float max = Float.MIN_VALUE;
        float min = Float.MAX_VALUE;
        float sum = 0;

        while ( i < 5 ) {
            int j = 0;

            while ( j < 10 ) {
                float number = sc.nextFloat();
                if ( max < number ) {
                    max = number;
                }

                if ( min > number ) {
                    min = number;
                }

                sum += number;

                if ( number % 2 != 0 ) {
                    list.add( number );
                }

                j++;
            }
            i++;
        }

        System.out.println( sum / 50.0 );
        System.out.println( max );
        System.out.println( min );

        for ( Float g : list ) {
            System.out.print( g + " " );
        }

    }
}
