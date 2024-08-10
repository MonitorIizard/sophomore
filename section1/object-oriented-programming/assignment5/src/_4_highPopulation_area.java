import java.util.ArrayList;
import java.util.Scanner;

public class _4_highPopulation_area {
    public static void main( String[] args ) {
        Scanner sc = new Scanner( System.in );
        int height = sc.nextInt();
        int width = sc.nextInt();
        int size = sc.nextInt();

        PopulationArea p1 = new PopulationArea(width , height, size);
        p1.initializeData();
        p1.print();
        System.out.printf("MAX is %d", p1.calculatePopulation());
//        p1.get();
    }
}

class PopulationArea {
        private final int width;
        private final int height;
        private final int size;

        ArrayList<ArrayList<Integer>> data;

        PopulationArea( int width, int height, int size ) {
            this.width = width;
            this.height = height;
            this.size = size;

            data = new ArrayList<>( height );
            for( int i = 0; i < height; i++ ) {
                data.add( new ArrayList<Integer>() );
            }


            //*
        }

        public void initializeData() {
            Scanner sc = new Scanner( System.in );
            for( int j = 0; j < height; j++ ) {
                for ( int i = 0; i < width; i++ ) {
                    int number = sc.nextInt();
                    data.get(j).add( number );
                }
            }
        }
        public int calculatePopulation( ) {
            int MAX = Integer.MIN_VALUE;
            for( int i = 0; i < width - size + 1; i++ ) {
                for( int j = 0; j < height - size + 1; j++ ) {
                    int currentValue = sumInRectangle( j, i );
                    if( MAX < currentValue) {
                        MAX = currentValue;
                    }
                    System.out.printf("current value = %d \n", currentValue );
                }
            }

            return MAX;
        }

        public int sumInRectangle( int i, int j ) {
            int sum = 0;
            int x = i;
            while( x < i + size) { // 0 < 0 + 2, 1 <=
                int y = j;
                while ( y < j + size ) {
                    System.out.printf("arr[%d][%d] = %d", x, y, data.get(x).get(y));
                    sum += data.get(x).get(y);
                    y++;
                }
                x++;
            }


            return sum;
        }

        public void print() {
            for( int i = 0; i < height; i++ ) {
                for( int j = 0; j < width; j++ ) {
                    System.out.printf( "%d_" ,data.get(i).get(j));
                }
                System.out.println();
            }
        }

}
