package assignment4;

import java.util.Scanner;

public class _9_hiddenNumber {
    public static void main( String[] args ){

        Scanner sc = new Scanner( System.in );

        int width = sc.nextInt();
        int height = sc.nextInt();

        Grid g1 = new Grid( height, width );
        g1.initializeValue();

        System.out.println(isConsecutiveFour( g1.getGrid() ));

    }

    static boolean isConsecutiveFour( int[][] values ) {
        int[] xDirection = { 1, 1, 0, -1, -1, -1, 0, 1};
        int[] yDirection = { 0, 1, 1, 1, 0, -1, -1, -1};

        for( int row = 0; row < values.length; row++ ) {
            for( int column = 0; column < values[row].length; column++ ) {

                int currentValues = values[row][column];

                for( int dir = 0; dir < 8; dir++ ) {
                    int rd = row;
                    int cd = column;

                    for ( int i = 0; i < 4; i++ ) {

                        if( rd < 0 || cd < 0 ) break;
                        if( rd >= values.length || cd >= values[row].length ) break;

                        if( values[rd][cd] != currentValues ) break;

                        if ( i == 3 ) return true;

                        rd += yDirection[dir];
                        cd += xDirection[dir];
                    }
                }

            }
        }

        return false;
    }
 }

class Grid {
    private int[][] grid;

    private int height;

    private int width;

    Grid( int height, int width ) {
        this.height = height;
        this.width = width;

        grid = new int[height][width];
    }

    void initializeValue() {
        Scanner sc = new Scanner( System.in );

        for( int i = 0; i < height; i++ ) {
            for( int j = 0; j < width; j++) {
                int number = sc.nextInt();
                grid[i][j] = number;
            }
        }
    }

    void print() {
        for( int i = 0; i < height; i++ ) {
            for( int j = 0; j < width; j++) {
                int currentNumber = grid[i][j];
                System.out.printf("%d ", currentNumber);
            }
            System.out.println();
        }
    }

    int[][] getGrid() {
        return grid;
    }

}




