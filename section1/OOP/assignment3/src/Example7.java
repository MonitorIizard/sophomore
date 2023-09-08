import java.util.Scanner;

public class Example7 {
    public static void main( String[] args ) {
        Scanner sc = new Scanner( System.in );
        double side1 = sc.nextDouble();
        double side2 = sc.nextDouble();
        double side3 = sc.nextDouble();
        myTriangle obj = new myTriangle();
        if ( obj.isValid(side1, side2, side3) ) {
            System.out.printf("%.2f" ,obj.area(side1, side2, side3) );
        } else {
            System.out.println( "0" );
        }
    }
}

class myTriangle {
    double side1;
    double side2;
    double side3;

    public boolean isValid( double side1, double side2, double side3 ) {
        return side1 + side2 > side3;
    }

    public double area( double side1, double side2, double side3 ) {
        double s = (side1 + side2 + side3) / 2;
        return Math.sqrt( s * (s- side1) * ( s - side2 ) * (s - side3) );
    }
}
