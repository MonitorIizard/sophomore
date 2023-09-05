package assignment4;

import java.util.Scanner;

public class _7_minTwoSet {
  public static void main( String[] args ) {

    Scanner sc = new Scanner( System.in );
    int size = sc.nextInt();

    int[] numberSet = new int[size];

    for ( int i = 0; i < size; i++ ) {
      int number = sc.nextInt();
      numberSet[i] = number;
    }

    double min = Double.MAX_VALUE;
    double product;
  
    for(int i = 0; i < numberSet.length; i++ ) {
      product = numberSet[i];

      for( int k = i; k < numberSet.length; k++ ) {

        if ( k != i ) {
          product = Math.abs(product - numberSet[k]);
        }

        for( int j = k; j < numberSet.length; j++ ) {

          if( j == k ) {
            continue;
          }

          double temp = product;
          temp = Math.abs(temp - numberSet[j]);

          System.out.printf("%.2f - %d = %.2f\n", product, numberSet[j], temp);
          System.out.printf("i = %d j = %d k = %d\n\n", i, k, j);
          if ( min > temp ) {
            min = temp;
          }
        }
         System.out.println();
      }
    }

    System.out.print(min);

  }
}
