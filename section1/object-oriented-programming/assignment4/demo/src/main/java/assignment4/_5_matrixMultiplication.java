package assignment4;

import java.util.Scanner;

public class _5_matrixMultiplication {

  public static void main( String[] args ) {

    Scanner sc = new Scanner( System.in );

    int width = sc.nextInt();
    int height = sc.nextInt();

    int[][] matrixA = new int[width][height];

    MatrixMultiplication.intializeMatrix(matrixA);

    width = sc.nextInt();
    height = sc.nextInt();

    int[][] matrixB = new int[width][height];

    MatrixMultiplication.intializeMatrix(matrixB);

    int[][] product = MatrixMultiplication.multiplication(matrixA, matrixB);
    MatrixMultiplication.printMatrix( product );

  }

}

class MatrixMultiplication {
  
  static int[][] multiplication( int[][] matrixA, int[][] matrixB ) {

    int matrixARowNumber = matrixA.length;
    int matrixBColumnNumber = matrixB[0].length;

    if(matrixARowNumber != matrixBColumnNumber) return null;

    int[][] product = new int[matrixARowNumber][matrixBColumnNumber];

    for (int i = 0; i < matrixARowNumber; i++ ) {
      for (int j = 0; j < matrixBColumnNumber; j++ ) {

        int sum = 0;

        for ( int k = 0; k < matrixA[i].length; k++ ) {
          sum += matrixA[i][k] * matrixB[k][j];
          //System.out.printf("matrixA[%d][%d] = %d, matrixB[%d][%d] = %d\n", i,k, matrixA[i][k],  i,j, matrixB[k][j]);
        }

        product[i][j] = sum;
        // System.out.printf("sum = %d\n", sum);

      }
      // System.out.printf("\n");
    }

    return product;
  }

  static void printMatrix( int[][] product ) {
    for( int i = 0; i < product.length; i++ ) {
      System.out.print("[ ");
      for( int j = 0; j < product[i].length; j++ ) {
        System.out.print( product[i][j] + " ");
      } 
      System.out.print("]\n");
    }
  }

  static void intializeMatrix( int[][] matrix ) {
    Scanner input = new Scanner( System.in );
    for( int i = 0; i < matrix.length; i++ ) {
      for( int j = 0; j < matrix[i].length; j++ ) {
        int currentNumber = input.nextInt();
        matrix[i][j] = currentNumber;
      }
    }

  }
}
