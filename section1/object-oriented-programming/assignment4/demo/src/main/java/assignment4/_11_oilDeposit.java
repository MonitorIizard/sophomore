package assignment4;

import java.util.Scanner;

public class _11_oilDeposit {
  static int[] xDirection = { 1, 1, 0, -1, -1, -1, 0, 1};
  static int[] yDirection = { 0, 1, 1, 1, 0, -1, -1, -1};
  static int count = 0;
  static char[][] oilField;

  public static void main ( String args[] ) {
    Scanner sc = new Scanner( System.in );
    int row = sc.nextInt();
    int column = sc.nextInt();
    int k;
    String temp = sc.nextLine();

    oilField = new char[row][column];

    for ( int i = 0; i < oilField.length; i++ ) {
      String current = sc.nextLine();

      for ( k = 0; k < current.length(); k++ ) {
        oilField[i][k] = current.charAt(k);
      }
    }

    for ( int i = 0; i < row; i++ ) {
      for ( int j = 0; j < column; j++ ) {
        if ( oilField[i][j] == '@' ) {
          count += 1;
          removeDuplicatePocket(i, j);
        }
      }
    }

    System.out.println(count);
    
  }

  public static void removeDuplicatePocket( int i, int j ) {

    if ( i < 0 ||
         i >= oilField.length ||
         j < 0 || 
         j >= oilField[i].length ) {return;}
    if ( oilField[i][j] != '@' ) {return;}
    if ( oilField[i][j] == '@' ) { oilField[i][j] = '.'; }
    
    for( int k = 0; k < 8; k++ ) {
      int rd = yDirection[k];
      int cl = xDirection[k];

      removeDuplicatePocket(i + rd, j + cl);
    }

  }
}
