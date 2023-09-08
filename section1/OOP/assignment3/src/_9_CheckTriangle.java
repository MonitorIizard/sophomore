public class _9_CheckTriangle {
    public static  void main( String[] args ) {
        boolean isOnLine = onTheLineSegment(1, 1, 2 , 2, 1.5, 1.5);
        System.out.println( isOnLine );
        //vectorAB = { 1 - 2, 1 -2 } = { -1, -1 }
        //vectorAC = { 1 - 1.5, 1 - 1.5 } = { -0.5, -0.5 }
        //AB . AC = (-1)(-0.5) + (-0.5)(-1) = 0.5
    }

    public static boolean leftOfTheLine( double x0, double y0,
                                         double x1, double y1,
                                         double x2, double y2 ) {
        return true;
    }

    public static boolean onTheSameLine( double x0, double y0,
                                         double x1, double y1,
                                         double x2, double y2 ) {
        return true;
    }

    public static boolean onTheLineSegment( double x0, double y0,
                                            double x1, double y1,
                                            double x2, double y2 ) {
        double[] vectorAB = { x1 - x0 , y1 - y0  };
        double[] vectorAC = { x1 - x2 , y1 - y2  };

        double kAC = (vectorAC[0] * vectorAB[0]) + (vectorAC[1] * vectorAB[1]);
        double kAB = (vectorAB[0] * vectorAB[0]) + (vectorAB[1] * vectorAB[1]);

        double mAB = vectorAB[1] / vectorAB[0];
        double mAC = vectorAC[1] / vectorAC[0];

        System.out.printf( "kAB = %f  kAC = %f\n", kAB, kAC );

        return 0 < kAC && kAC < kAB && mAB == mAC ;
    }
}
