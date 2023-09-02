import java.util.ArrayList;
import java.util.Scanner;

public class _3_sortedMergeArray {

    public static void main ( String args[] ) {

        ArrayList<Integer> integers1 = new ArrayList<Integer>();
        ArrayList<Integer> integers2 = new ArrayList<Integer>();

        Scanner sc = new Scanner( System.in );

        String k = sc.nextLine();
        String[] l = k.split(" ");
        int size = l.length;

        int i = 0;
        while ( i < size ) {
            int number = Integer.parseInt(l[i]);
            integers1.add( number );
            i++;
        }

        k = sc.nextLine();
        l = k.split(" ");
        size = l.length;

        i = 0;
        while ( i < size ) {
            int number = Integer.parseInt(l[i]);
            integers2.add( number );
            i++;
        }

        System.out.println(sortedMergeList.intersect( integers1, integers2 ));
    }
}

class sortedMergeList {

    public static ArrayList<Integer> intersect ( ArrayList<Integer> integers1, ArrayList<Integer> integers2 ) {
        int size1 = integers1.size();
        int size2 = integers2.size();
        int sizeMin = Math.min( size2, size1 ) ;
        int sizeMax = Math.max( size1, size2 );

        ArrayList<Integer> integersMin = integers1;
        ArrayList<Integer> integersMax = integers2;
        ArrayList<Integer> result = new ArrayList<Integer>();

        if ( sizeMin == size2 ) {
            integersMin = integers2;
            integersMax = integers1;
        }

        int i = 0;

        while ( i < sizeMin ) {

            int j = i;
            while ( j < sizeMax ) {

                if( integersMin.get(i).equals( integersMax.get(j) )) {
//                    System.out.println( integersMin.get(i) );
                    result.add( integersMin.get(i) );
                }

                j++;
            }
            System.out.println();
            i++;
        }
        return result;
    }
}