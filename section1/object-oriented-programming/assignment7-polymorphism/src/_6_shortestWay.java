import java.util.LinkedList;
import java.util.Queue;

public class _6_shortestWay {
    public static void main( String[] args ) {
        int mazeColumn = 8;
        int mazeRow = 5;
        int[][] maze = {{0, 0, 1, 1, 0, 0, 0, 0 },
                        {1, 0, 1, 1, 0, 1, 1, 1 },
                        {1, 0, 1, 1, 1, 0, 0, 1 },
                        {1, 1, 0, 0, 1, 0, 0, 1 },
                        {0, 0, 1, 1, 0, 1, 1, 1 }};
        int[] startPoint = {4, 5};
        int[] endPoint = {2, 8};
        boolean[][] isVisited = new boolean[mazeRow][mazeColumn];

        for( int i = 0; i < mazeRow; i++ ) {
            for ( int j = 0; j < mazeColumn; j++ ) {
                isVisited[i][j] = false;
            }
        }

        Queue<Integer> xq = new LinkedList<>();
        Queue<Integer> yq = new LinkedList<>();
        isVisited[startPoint[0]][startPoint[1]] = true;

        yq.add(startPoint[1]);
        xq.add(startPoint[0]);

        while(xq.size() > 0) {

        }
    }
    public static void explore_neighbors( int r, int c ) {

    }
}
