import java.util.Scanner;

public class _10_Light {
    static int[][]  shipCoordinate;

    static int[] light;

    static int count = 0;

    public static void main( String[] args ) {

        Scanner sc = new Scanner( System.in );

        int numberOfShip = sc.nextInt();
        int numberOfLight = sc.nextInt();

        shipCoordinate = new int[numberOfShip][2];

        for( int i = 0; i < numberOfShip; i++ ) {
            for( int j = 0; j < 2; j++ ) {
                shipCoordinate[i][j] = sc.nextInt();
            }
        }

        light = new int[numberOfLight];

        for( int i = 0; i < numberOfLight; i++ ) {
            light[i] = sc.nextInt();
        }

        findIntersect();

        System.out.println( count );

    }

    static public void findIntersect() {
        for (int[] ints : shipCoordinate) {
            for (int k : light) {
                if (k > ints[0] && k < ints[1]) {
                    count++;
                }
            }
        }
    }
}
