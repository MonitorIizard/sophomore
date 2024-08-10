import java.util.Scanner;

public class _9_CheckTriangle {
    public static  void main( String[] args ) {

        Scanner sc = new Scanner( System.in );
        double[] coordinate1 = { sc.nextDouble(), sc.nextDouble() };
        double[] coordinate2 = { sc.nextDouble(), sc.nextDouble() };
        double[] coordinate3 = { sc.nextDouble(), sc.nextDouble() };

        if( onTheLineSegment(coordinate1[0], coordinate1[1], coordinate2[0], coordinate2[1], coordinate3[0], coordinate3[1]) ) System.out.println("0");
        if( checkLeftOfTheLine(coordinate1[0], coordinate1[1], coordinate2[0], coordinate2[1], coordinate3[0], coordinate3[1]) ) System.out.println("1");
        if( checkRightOfTheLine(coordinate1[0], coordinate1[1], coordinate2[0], coordinate2[1], coordinate3[0], coordinate3[1]) ) System.out.println("2");

    }

    public static boolean checkLeftOfTheLine( double x0, double y0,
                                              double x1, double y1,
                                              double x2, double y2 ) {
        double[] vectorAB = { x1 - x0 , y1 - y0  };
//        double[] vectorAC = { x2 - x0 , y2 - y0  };
//
        double mVectorAB = vectorAB[1] / vectorAB[0] ;
//        double mVectorAC = vectorAC[1] / vectorAC[0] ;
//        return mVectorAC > mVectorAB ;
        double x = y2 / mVectorAB;

        return x > x2;
    }

    public static boolean checkRightOfTheLine( double x0, double y0,
                                               double x1, double y1,
                                               double x2, double y2 ) {
        double[] vectorAB = { x1 - x0 , y1 - y0  };
        double[] vectorAC = { x2 - x0 , y2 - y0  };

        double mVectorAB = vectorAB[1] / vectorAB[0] ;
        double x = y2 / mVectorAB;

        return x < x2;

    }

    public static boolean onTheLineSegment( double x0, double y0,
                                            double x1, double y1,
                                            double x2, double y2 ) {
        double[] vectorAB = { x1 - x0 , y1 - y0  };
        double[] vectorAC = { x2 - x0, y2 - y0  };

        double kAC = (vectorAC[0] * vectorAB[0]) + (vectorAC[1] * vectorAB[1]);
        double kAB = (vectorAB[0] * vectorAB[0]) + (vectorAB[1] * vectorAB[1]);

        double mAB = vectorAB[1] / vectorAB[0];
        double mAC = vectorAC[1] / vectorAC[0];

        return 0 < kAC && kAC < kAB && mAB == mAC ;
    }
}
