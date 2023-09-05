package assignment4;

import java.util.Scanner;

public class _8_findPokemon {
  public static void main( String[] args ) {

    double frequencyMax =  Double.MIN_VALUE;
    int[][] coordinateMax = new int[1][2];

    // int[][] frequency = {{5, 1, 2, 10, 4},
    //                      {4,30, 3,0 ,100},
    //                      {3, 25, 10, 4, 10},
    //                      {3,20,4,8,5}};
    Scanner sc = new Scanner( System.in );

    int width = sc.nextInt();
    int height = sc.nextInt();
    int[][] frequency = new int[width][height];

    innitializeValue(frequency);

    for( int row = 0; row < frequency.length; row++ ) {
      for ( int column = 0; column < frequency[row].length; column++ ) {
        double sum1 = 0;
        double difference1 = 0;
        int[][] coordinate = {{row, column}};

        for ( int k = column; k <= column + 1; k++ ) {
          if ( column  == frequency[row].length - 1 ) {
            // System.out.println("break case 1");  
            break;
          }

          // System.out.printf("f[%d][%d] = %d\n", row, k, frequency[row][k]);
          sum1 += frequency[row][k];
          difference1 = Math.abs( difference1 - frequency[row][k]);
          // System.out.printf("difference =  %f\n", difference1);
        }

        double sum2 = 0;
        double difference2 = 0;

        for ( int j = row; j <= row + 1; j++ ) {
          if ( row == frequency.length - 1 ) {
            // System.out.println("break case 2");  
            break;
          }

          sum2 += frequency[j][column];
          difference2 = Math.abs( difference2 - frequency[j][column]);
          // System.out.printf("f[%d][%d] = %d\n", j, column, frequency[j][column]);
          // System.out.printf("difference = %f\n", difference2);
        }
        // System.out.printf("sum1 = %f sum2 = %f \n\n", sum1, sum2);

        if ( difference1 < 10  ) {
          if ( sum1 > frequencyMax ) {
            frequencyMax = sum1;
            coordinateMax[0][0] = coordinate[0][0];
            coordinateMax[0][1] = coordinate[0][1];
          };
        }

        if ( difference2 < 10 ) {
          if ( sum2 > frequencyMax ) {
            frequencyMax = sum2;
            coordinateMax[0][0] = coordinate[0][0];
            coordinateMax[0][1] = coordinate[0][1];
          }
        }
      }

    }
    // System.out.printf("%f, %d, %d", frequencyMax , coordinateMax[0][0] + 1 , coordinateMax[0][1] + 1 );
  } 

  static void innitializeValue( int[][] frequency ) {
    Scanner sc = new Scanner( System.in );
    for( int i = 0 ; i < frequency.length; i++ ) {
      for( int j = 0; j < frequency[i].length; j++ ) {
        int number = sc.nextInt();
        frequency[i][j] = number;
      }
    }
  }

}
