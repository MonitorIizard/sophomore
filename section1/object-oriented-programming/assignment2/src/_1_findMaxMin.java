public class _1_findMaxMin {
    public static void main( String[] args ) {
        int a[] = { -128, 65, -235, 99, 0, 26 };
        int minIndex = findMinIdx( a );
        int maxIndex = findMaxIdx( a );
        System.out.println( "min value is a["+minIndex+"] = " + a[ minIndex ] );
        System.out.println( "max value is a["+maxIndex+"] = " + a[ maxIndex ] );
    }
    public static int findMinIdx( int[] a ) {
        int k, minIdx = 0;
        for ( k = 0; k < a.length; k++ ) {
            if ( a[k] < a[minIdx] ) {
                minIdx = k;
            }
        }
        return minIdx;
    }

    public static int findMaxIdx( int[] a ) {
        int k, maxIdx = 0;
        for (k = 0; k < a.length; k++) {
            if (a[k] > a[maxIdx]) {
                maxIdx = k;
            }
        }
        return maxIdx;
    }
}
