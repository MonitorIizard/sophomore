public class _2_errorCheck {
    public static void main( String[] args ) {
        _2dot6_.code();
    }
}

class _2dot2_ {
    public static void code() {
        int list[] = { 1, 2, 3, 4, 5 };
        for ( int i = 1; i < list.length; i++ ) {
            list[ i ] = list[ i - 1 ];
        }

        for ( int i = 0; i < list.length ; i++ ) {
            System.out.println( list[i] + " ");
        }
    }
}
class _2dot3_ {
    public static void code() {
        int number = 0;
        int[] numbers = new int[1];
        m(number, numbers);
        System.out.println("number is " + number + " numbers[0] is " + numbers[ 0 ]);
    }
    public static void m( int x, int[] y) {
        x = 3;
        y[0] = 3;
    }
}

class _2dot4_ {
    public static void code() {
        int number = 0;
        int[] numbers = new int[1];
        m(number, numbers);
        System.out.println("number is " + number + " numbers[0] is " + numbers[ 0 ]);
    }
    public static void m( int x, int[] y) {
        x = 3;
        y[0] = 3;
    }
}

class _2dot5_ {
    public static void code() {
        int[] list = { 1, 2 ,3 ,4, 5 };
        reverse( list );
        for ( int i = 0 ; i < list.length; i++) {
            System.out.print( list[i] + " ");
        }

    }

    public static void reverse( int[] list ) {
        int[] newList = new int[ list.length ];
        for ( int i = 0; i < list.length; i++ ) {
            newList[ i ] =  list[list.length - 1 -i];
            list = newList;
        }
    }
}

class _2dot6_ {
    public static void code() {
        int[][] array= {{1, 2}, {3, 4}, {5, 6 } , {7 ,8}};

        for( int i = array.length - 1; i >= 0; i-- ) {
            for( int j = array[i].length - 1; j >= 0; j-- ) {
                System.out.print( array[i][j] + " ");
            }
            System.out.println( );
        }
    }
    public static int[] m1( int[][] m ) {
        int[] result = new int[2];
        result[0] = m.length;
        result[1] = m[0].length;
        return result;
    }
}
class _2dot7_ {
    public static void code() {
        int[][] array= {{1, 2, 3, 4}, {5, 6 ,7 ,8}};
        System.out.println(m1(array)[0]);
        System.out.println(m1(array)[1]);
    }
    public static int[] m1( int[][] m ) {
        int[] result = new int[2];
        result[0] = m.length;
        result[1] = m[0].length;
        return result;
    }
}
