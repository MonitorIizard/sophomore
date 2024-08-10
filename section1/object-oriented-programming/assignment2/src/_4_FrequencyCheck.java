public class _4_FrequencyCheck {
    public static void main( String[] args ) {
        double[] a = { 9, 5, 9, 5, 8 };
        double[] cleanDuplicate  = new double[a.length];
        double[] counts = new double[a.length];
        boolean[] isVisit =  new boolean[ a.length ];

        AscendSortFreq ascendArray = new AscendSortFreq( a );
        ascendArray.AscendSort( a );



        ascendArray.printAll();
    }


}

class AscendSortFreq {

    double[] A;

    AscendSortFreq( double[] A ) {
         this.A = A;
    }
    public double[] AscendSort( double[] A ) {

        double[] B = A;

        for ( int i = 0; i < B.length; i++ ) {
            for ( int j = 0; j < B.length; j++ ) {
                if ( B[i] < B[j] ) {
                    double temp = B[i];
                    B[i] = B[j];
                    B[j] = temp;
                }
            }
        }

        this.A = B;
        return B;
    }

    public double[] SortCommuFreq( double[] A ) {
        double[] C = A;
        int k = 0;
        int count = 0;
        boolean[] isVisit = new boolean[A.length];

        for( int i = 0; i < C.length; i++ ) {
            for( int j = 0; j < C.length; j++ ) {
                if( C[i] == C[j] ) {
                    isVisit[ k++ ] = true;
                    count += 0;
                }
            }


        }

        return C;
    }
    public void printAll() {
        for ( int i = 0; i < this.A.length ; i++ ) {
            System.out.print( A[i] + " ");
        }
    }
}
