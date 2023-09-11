public class _7_Rectangle {

    public static void main( String[] args ) {
        MyRectangle2D r1 = new MyRectangle2D( 0, 0, 1, 1 );
        MyRectangle2D r2 = new MyRectangle2D( 0, 0, 5, 5 );
        MyRectangle2D r3 = new MyRectangle2D( 0, 0, 0.5, 0.5 );

        System.out.printf("r1, x0 = %f x1 = %f y0 = %f y1 = %f\n", r1.getX() - r1.getWidth() / 2, r1.getX() + r1.getWidth() / 2, r1.getY() - r1.getHeight() / 2, r1.getY() - r1.getHeight() / 2);
        System.out.printf("r1, x0 = %f x1 = %f y0 = %f y1 = %f\n", r2.getX() - r2.getWidth() / 2, r2.getX() + r2.getWidth() / 2, r2.getY() - r2.getHeight() / 2, r2.getY() - r2.getHeight() / 2);
        System.out.printf("r1, x0 = %f x1 = %f y0 = %f y1 = %f\n\n", r3.getX() - r3.getWidth() / 2, r3.getX() + r3.getWidth() / 2, r3.getY() - r3.getHeight() / 2, r3.getY() - r3.getHeight() / 2);

        System.out.printf("r1.contains(0, 0) is %b\n", r1.contains( 0, 0 ));
        System.out.printf("r1.contains(400, 400) is %b\n", r1.contains( 400, 400 ));
        System.out.printf("r1.contains(r2) is %b\n", r1.contains( r2 ));
        System.out.printf("r1.contains(r3) is %b\n", r1.contains( r3 ));
        System.out.printf("r1.overLaps(r2) is %b\n", r1.overLaps( r2 ));
        System.out.printf("r1.overLaps(r3) is %b\n", r1.overLaps( r3 ));

    }
}

class MyRectangle2D {
    private double x;
    private double y;
    private double width;
    private double height;

    MyRectangle2D() {
        this.x = 0;
        this.y = 0;
        this.width = 1;
        this.height = 1;
    }

    MyRectangle2D( double x,
                   double y,
                   double width,
                   double height ) {
        this.x = x;
        this.y = y;
        this.width = width;
        this.height = height;
    }

    public double getX() { return this.x;}
    public double getY() { return this.y;}
    public double getWidth() { return this.width; }
    public double getHeight() { return this.height; }
    public double getArea() { return width * height; }
    public double getPerimeter() { return width * 2 + height * 2; }

    public boolean contains( double x, double y ) {
        double[] coordinateToCheck = {x, y};
        double x0_OfRectangle = this.x - width / 2;
        double x1_OfRectangle = this.x + width / 2;
        double y0_OfRectangle = this.y - height / 2;
        double y1_OfRectangle = this.y + height / 2;

        //System.out.printf("%f %f %f %f\n", x0_OfRectangle, x1_OfRectangle, y0_OfRectangle, y1_OfRectangle);

        return coordinateToCheck[0] >= x0_OfRectangle &&
                coordinateToCheck[0] <= x1_OfRectangle &&
                coordinateToCheck[1] >= y0_OfRectangle &&
                coordinateToCheck[1] <= y1_OfRectangle;
    }

    public boolean contains( MyRectangle2D r ) {
        double x0_OfRectangle1 = r.getX() - width / 2;
        double x1_OfRectangle1 = r.getX() + width / 2;
        double y0_OfRectangle1 = r.getY() - height / 2;
        double y1_OfRectangle1 = r.getY() + height / 2;

        return  contains( x0_OfRectangle1, y0_OfRectangle1 ) &&
                contains( x0_OfRectangle1, y1_OfRectangle1 ) &&
                contains( x1_OfRectangle1, y0_OfRectangle1 ) &&
                contains( x1_OfRectangle1, y1_OfRectangle1 );
    }

    public boolean overLaps( MyRectangle2D r ) {

        double x0_OfRectangle1 = this.x - width / 2;
        double x1_OfRectangle1 = this.x + width / 2;
        double y0_OfRectangle1 = this.y - height / 2;
        double y1_OfRectangle1 = this.y + height / 2;

        double[] c0_r1 = {x0_OfRectangle1, y1_OfRectangle1};
        double[] c1_r1 = {x1_OfRectangle1, y1_OfRectangle1};
        double[] c2_r1 = {x1_OfRectangle1, y0_OfRectangle1};
        double[] c3_r1 = {x0_OfRectangle1, y0_OfRectangle1};


        double x0_OfRectangle2 = r.getX() - r.getWidth() / 2;
        double x1_OfRectangle2 = r.getX() + r.getWidth() / 2;
        double y0_OfRectangle2 = r.getY() - r.getHeight() / 2;
        double y1_OfRectangle2 = r.getY() + r.getHeight() / 2;

        double[] c0_r2 = {x0_OfRectangle2, y1_OfRectangle2};
        double[] c1_r2 = {x1_OfRectangle2, y1_OfRectangle2};
        double[] c2_r2 = {x1_OfRectangle2, y0_OfRectangle2};
        double[] c3_r2 = {x0_OfRectangle2, y0_OfRectangle2};

        //System.out.printf("%f %f %f %f\n", x0_OfRectangle1, x1_OfRectangle1, y0_OfRectangle1, y1_OfRectangle1);
        //System.out.printf("%f %f %f %f", x0_OfRectangle2, x1_OfRectangle2, y0_OfRectangle2, y1_OfRectangle2);

        if ( r.contains( this ) ) {
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

    public void setX( double x ) { this.x = x; }
    public void setY( double y ) { this.y = y; }
    public void setWidth( double width ) { this.width = width; }
    public void setHeight( double height ) { this.height = height; }


}