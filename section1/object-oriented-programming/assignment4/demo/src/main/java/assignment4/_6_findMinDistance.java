package assignment4;

import java.util.Scanner;

public class _6_findMinDistance {
  public static void main( String[] args ) {
    Scanner sc = new Scanner( System.in );

    int numberOfCoordinate = sc.nextInt();

    // System.out.printf("%f", numberOfCoordinate);

    double[][] arrays = new double[numberOfCoordinate][2];
    
    initializeArray(arrays);

    // double[][] arrays = {{3, 3},{3, -1},{2, 4},{0.5, 2},{-1, -1},{0.5, -4},{2, -1},{1,1}};
    System.out.printf("%.2f\n", findMinDistance(arrays));

    
  }  

  static void initializeArray( double[][] arrays ) {
    Scanner input = new Scanner( System.in );
    for ( int i = 0; i < arrays.length; i++ ) {
      for( int j = 0; j < 2; j++ ) {
        double currentNumber = input.nextDouble();
        arrays[i][j] = currentNumber;
      } 
    }
  }

  static double findMinDistance( double[][] arrays ) {
    double min = Double.MAX_VALUE;
    double distance;
    double deltaX;
    double deltaY;
    
    for( int i = 0; i < arrays.length; i++ ) {
      for( int j = i + 1; j < arrays.length; j++ ) {
        deltaX = arrays[i][0] - arrays[j][0];
        deltaY = arrays[i][1] - arrays[j][1];

        // System.out.printf("x1 = %.2f, x2 = %.2f\n", arrays[i][0], arrays[j][0]);
        // System.out.printf("deletaX = %.2f\n", deltaX);

        // System.out.printf("y1 = %.2f, y2 = %.2f\n", arrays[i][1], arrays[j][1]);
        // System.out.printf("deletaY = %.2f\n", deltaY);
        
        distance = Math.sqrt( Math.pow(deltaX, 2) + Math.pow(deltaY, 2) );
        
        // System.out.printf("distance = %.2f\n", distance);
        // System.out.printf("\n");

        if( min > distance ) {
          min = distance;
        }
      }
    }

    return min;
  }
}


