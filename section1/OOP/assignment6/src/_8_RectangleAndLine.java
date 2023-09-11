import org.w3c.dom.css.Rect;

public class _8_RectangleAndLine {
    public static void main( String[] args ) {
        Line a = new Line(1, 0, 2, 1);
        Rectangle b = new Rectangle( 5, 5, 50, 0 );
        Rectangle c = new Rectangle( 5, 5, 0, 0 );

        System.out.printf("line a, x0 = %f , y0 = %f\n x1 = %f, y1 = %f\n\n", a.getX1(), a.getY1(), a.getX2(), a.getY2());
        System.out.printf("line a length = %f\n", Line.getLong(a));
        System.out.printf("distance from Rectangle b to line a = %f\n", Rectangle.distance(a, b));
        System.out.printf("Is line a in rectangle b ? %b\n", Rectangle.contains(a , b));
        System.out.printf("area of Rectangle b ? %f\n", Rectangle.getArea(b));
        System.out.printf("Is line a cross rectangle b ? %b\n", Line.cross(a , b));
        System.out.printf("Is rectangle b contain rectangle c ? %b\n", Rectangle.contains(b, c));


    }
}

class Rectangle extends MyRectangle2D {

    Rectangle() {}

    Rectangle( double width, double height, double x, double y ) {
        setWidth( width );
        setHeight( height );
        setX( x );
        setY( y );
    }

    public static double getArea(Rectangle a){
        return a.getHeight() * a.getWidth();
    }

    public static boolean contains( Line a, Rectangle b ) {
        double x0_r = b.getX();
        double x1_r = b.getX() + b.getWidth();
        double y0_r = b.getY();
        double y1_r = b.getY() - b.getHeight();

        double x0_l = a.getX1();
        double x1_l = a.getX2();
        double y0_l = a.getY1();
        double y1_l = a.getY2();

        return x0_l >= x0_r &&
                x1_l <= x1_r &&
                y0_l >= y0_r &&
                y1_l <= y1_r;
    }

    public static boolean contains( Rectangle a , Rectangle b ) {
        return  a.contains(b);
    }

    public static double distance(Line a, Rectangle b ) {
        double[] centerOfRectangle = { b.getX() + b.getWidth() / 2 , b.getY() - b.getHeight() / 2 };
        double[] centerOfLine = { ( a.getX1() + a.getX2() ) / 2, ( a.getY1() + a.getY2() ) / 2 };

        double deltaX = centerOfRectangle[0] - centerOfLine[0];
        double deltaY = centerOfRectangle[1] - centerOfLine[1];

        return Math.sqrt( Math.pow( deltaX, 2 ) + Math.pow( deltaY, 2 ) ) ;
    }
}

class Line {
    private double x1;
    private double x2;
    private double y1;
    private double y2;

    Line() {}

    Line( double x1, double x2, double y1, double y2 ) {
        this.x1 = x1;
        this.x2 = x2;
        this.y1 = y1;
        this.y2 = y2;
    }

    public double getX1() {
        return x1;
    }

    public double getX2() {
        return x2;
    }

    public double getY1() {
        return y1;
    }

    public double getY2() {
        return y2;
    }

    static double getLong( Line a ) {
        double deltaX = Math.pow( a.getX1() - a.getX2(), 2 );
        double deltaY = Math.pow( a.getY1() - a.getY2(), 2 );

        return Math.sqrt(  deltaX + deltaY );
    }

    public static boolean cross( Line a, Rectangle b ) {
        double x0_r = b.getX();
        double x1_r = b.getX() + b.getWidth();
        double y0_r = b.getY();
        double y1_r = b.getY() - b.getHeight();

        return y0_r <= equationOfLineX( a, x0_r ) && y1_r >= equationOfLineX( a, x0_r) ||
                y0_r <= equationOfLineX( a, x1_r ) && y1_r >= equationOfLineX( a, x1_r) ||
                x0_r <= equationOfLineY( a, y0_r ) && x1_r >= equationOfLineY( a, y0_r) ||
                x0_r <= equationOfLineY( a, y0_r ) && x1_r >= equationOfLineY( a, y0_r);
    }

    public static double equationOfLineX( Line a,  double x ) {
        double x0_l = a.getX1();
        double x1_l = a.getX2();
        double y0_l = a.getY1();
        double y1_l = a.getY2();

        double ml = ( x0_l - x1_l ) / ( y0_l - y1_l );
        return (ml * ( x - x0_l )) + y0_l;
    }

    public static double equationOfLineY( Line a, double y ) {
        double x0_l = a.getX1();
        double x1_l = a.getX2();
        double y0_l = a.getY1();
        double y1_l = a.getY2();

        double ml = ( x0_l - x1_l ) / ( y0_l - y1_l );
        return x0_l + ( y - y0_l ) / ml;
    }

    public boolean overLaps( Rectangle a, Rectangle b ) {

        double x0_OfRectangle1 = a.getX() - a.getWidth() / 2;
        double x1_OfRectangle1 = a.getX() + a.getWidth() / 2;
        double y0_OfRectangle1 = a.getY() - a.getHeight() / 2;
        double y1_OfRectangle1 = a.getY() + a.getHeight() / 2;

        double[] c0_r1 = {x0_OfRectangle1, y1_OfRectangle1};
        double[] c1_r1 = {x1_OfRectangle1, y1_OfRectangle1};
        double[] c2_r1 = {x1_OfRectangle1, y0_OfRectangle1};
        double[] c3_r1 = {x0_OfRectangle1, y0_OfRectangle1};


        double x0_OfRectangle2 = b.getX() - b.getWidth() / 2;
        double x1_OfRectangle2 = b.getX() + b.getWidth() / 2;
        double y0_OfRectangle2 = b.getY() - b.getHeight() / 2;
        double y1_OfRectangle2 = b.getY() + b.getHeight() / 2;

        double[] c0_r2 = {x0_OfRectangle2, y1_OfRectangle2};
        double[] c1_r2 = {x1_OfRectangle2, y1_OfRectangle2};
        double[] c2_r2 = {x1_OfRectangle2, y0_OfRectangle2};
        double[] c3_r2 = {x0_OfRectangle2, y0_OfRectangle2};

        //System.out.printf("%f %f %f %f\n", x0_OfRectangle1, x1_OfRectangle1, y0_OfRectangle1, y1_OfRectangle1);
        //System.out.printf("%f %f %f %f", x0_OfRectangle2, x1_OfRectangle2, y0_OfRectangle2, y1_OfRectangle2);

        if ( b.contains( a ) ) {
            return true;
        }

        return  c0_r2[0] > c3_r1[0] && c0_r2[0] < c2_r1[0] &&
                c0_r2[1] > c2_r1[1] && c0_r2[1] < c1_r2[1] ||

                c2_r2[0] > c0_r1[0] && c2_r2[0] < c1_r1[0] &&
                        c2_r2[1] < c0_r1[1] && c2_r2[1] > c3_r1[1] ||

                c1_r2[0] > c3_r1[0] && c1_r2[0] < c2_r1[0] &&
                        c1_r2[1] > c3_r1[1] && c1_r2[1] < c1_r2[1] ||

                c3_r2[0] > c0_r1[0] && c3_r2[0] < c1_r1[0] &&
                        c3_r2[1] < c0_r1[1] && c3_r2[1] > c3_r1[1];
    }
}
