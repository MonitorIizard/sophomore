import java.util.Scanner;

public class _6_Palindome {
    public static void main( String[] args ) {
        Scanner sc = new Scanner( System.in );
        System.out.println( Palindrome.isPalindrome( sc.nextLine()) );
    }
}

class Palindrome {
    static boolean isPalindrome( String s ) {
        s = s.replaceAll( "[^A-Za-z]", "" );
        int j = s.length() - 1;
        for( int i = 0; i < s.length(); i++ ) {
            if ( s.charAt( i ) != s.charAt( j ) ) {
                return  false;
            } else {
                j--;
            }
        }
        return true;
    }
}