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

    // double min = Double.MAX_VALUE;
    // double product;
  
    for(int i = 0; i < numberSet.length; i++ ) {
      for( int k = 0; k < numberSet.length; k++ ) {
        if( numberSet[i] < numberSet[k] ) {
          int temp = numberSet[i];
          numberSet[i] = numberSet[k];
          numberSet[k] = temp;
        }
      }

    }

    double product = 0;
    for ( int i = 0; i < numberSet.length / 2; i++ ) {
      // product -= numberSet[i] - numberSet[ numberSet.length - 1 - i ];
      System.out.printf("%f %d %d\n",product , numberSet[i] , numberSet[ numberSet.length - 1 - i]);
      // product = Math.abs( product );
    }

    System.out.println(product);
  }
}
