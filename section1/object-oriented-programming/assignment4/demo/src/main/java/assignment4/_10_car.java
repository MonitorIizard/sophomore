package assignment4;

import java.util.Scanner;
import java.util.Stack;

public class _10_car {
  static boolean[][] visited;
  static int[][] roadStatus;

  static Stack<Integer> stack1 = new Stack<Integer>();
  static Stack<Integer> stack2 = new Stack<Integer>();

  static int count = 0;
  static int numberOfLanes;
  static int startLane;
  static int time;
  public static void main( String[] args ) {
    Scanner sc = new Scanner( System.in );
    numberOfLanes = sc.nextInt();
    startLane = sc.nextInt();

    while( startLane > numberOfLanes ) {
      System.out.print("startlane is more than number of lanes plear reenter : ");
      startLane = sc.nextInt();
    }
    time = sc.nextInt();

    visited = new boolean[ time + 1 ][ numberOfLanes ];
    initialBoolean( visited );

    roadStatus = new int[ time + 1 ][ numberOfLanes ];
    // System.out.printf( "y l = %d x l = %d", roadStatus.length, roadStatus[0].length);
    initialValue(roadStatus);
    
    dfs( 0, startLane - 1 );

    for ( int l = 0; l < 5; l++ ) {
        System.out.printf("%d\n", stack2.pop());
    }

  }

  static void dfs( int i, int j ) {
    if ( i >= roadStatus.length || 
         j >= roadStatus[i].length ) return;

    if ( visited[i][j] ) return;
    if ( roadStatus[i][j] == 1 ) { 
      stack1.pop();
      return; 
    }
    
    visited[i][j] = true;
    
    count += 1;
    
    if ( count == time + 1 ) {
      for ( int l = 0; l < count - 1; l++ ) {
        stack2.push( stack1.pop() );
        // System.out.printf("%d ", stack1.pop());
      }

    };
    // System.out.println( roadStatus[i][j] );
    // System.out.printf("j = %d, i = %d %d\n", j, i, roadStatus[i][j]);
    j = j - 1;

    for ( int k = 0; k < 3; k++ ) {
      // System.out.printf("j = %d, k = %d", j, k);
      if ( j + k < 0 ) continue;
      if ( j + k >= roadStatus[i].length ) continue;
      if ( k == 0 ) stack1.push(1);
      if ( k == 1 ) stack1.push(3);
      if ( k == 2 ) stack1.push(2);
      
      dfs( i + 1, j + k );
    }
  }

  static void initialBoolean( boolean[][] arrays ) {
    for ( int i = 0; i < arrays.length; i++ ) {
      for ( int j = 0; j < arrays[i].length; j++) {
        arrays[i][j] = false;
      }
    }
  }

  static void initialValue( int[][] arrays ) {
    Scanner sc = new Scanner( System.in );
    for ( int i = 0; i < arrays.length; i++ ) {
      for ( int j = 0; j < arrays[i].length; j++) {
        if ( i == 0 ) {
          arrays[i][j] = 0;
          continue;
        } 
        int current = sc.nextInt();
        arrays[i][j] = current;
      }
    }
  }
}
