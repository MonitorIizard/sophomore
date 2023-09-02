import java.util.ArrayList;
import java.util.Scanner;

public class _2_star {
    public static void main( String args[] ) {
        ArrayList<String> strings= new ArrayList<String>();
        Scanner sc = new Scanner( System.in );

        int numberOfMessege = sc.nextInt();
        int numberOfCommand = sc.nextInt();

        String temp = sc.nextLine();

        int i = 0;
        while( i < numberOfMessege) {
            strings.add( sc.nextLine() );
            i++;
        }

        Star star1 = new Star(  );

        int j = 0;
        while ( j < numberOfCommand ) {
            String command = sc.nextLine();

            if(command.equals( "1" )) {
                strings = star1.addStars( strings );
                System.out.println(strings);
            }

            if( command.equals( "2" )) {
                strings = star1.removeStars( strings );
                System.out.println(strings);
            }

            j++;
        }


    }
}

class Star {

    ArrayList<String> strings;

    Star() {
        this.strings = new ArrayList<String>();
    }
    ArrayList<String> addStars( ArrayList<String> strings ) {
        int size = strings.size();
//        System.out.println( size );
        int i = 0;
        while ( i < strings.size() ) {
            if ( i % 2 == 0 ) {
                strings.add( i+1, "*");
            }
            i++;
        }
        return strings;
    }

    ArrayList<String> removeStars( ArrayList<String> strings ) {
        int i = 1;
        while ( i < strings.size() ) {
            strings.remove(i);
            i++;
        }
        return strings;
    }
}
