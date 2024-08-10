import javax.swing.*;
import java.awt.*;

public class _3_DrawGraph extends JFrame{
    public _3_DrawGraph() {
        getContentPane().setLayout(new GridLayout(3, 2, 5, 5));
        AbstractDrawFunction[] listOfFx = {new Ex1(), new Ex2(), new Ex3(), new Ex4(), new Ex5(), new Ex6()};
        for( AbstractDrawFunction function : listOfFx ) {
            getContentPane().add( function );
        }
    }
    public static void main(String args[]) {
        _3_DrawGraph frame = new _3_DrawGraph();
        frame.setSize(400, 400);
        frame.setTitle("Exercise 10.10");
        frame.setVisible(true);
    }

}


abstract class AbstractDrawFunction extends JPanel
{
    /**Polygon to hold the points*/
    private Polygon p = new Polygon();
    /**Default constructor*/
    protected AbstractDrawFunction ()
    {
        drawFunction();
        setBackground(Color.white);
    }
    /**Draw the function*/
    public abstract double f(double x);
    /**Obtain points for x coordinates 100, 101, ..., 300*/
    public void drawFunction()
    {
        for (int x = -100; x <= 100; x++)
        {
            p.addPoint(x+200, 200-(int)f(x));
        }
    }
    /**Paint the function diagram*/
    public void paintComponent(Graphics g)
    {
        super.paintComponent(g);
        // Draw x axis
        g.drawLine(10, 200, 390, 200);
        // Draw y axis
        g.drawLine(200,30, 200, 390);
        // Draw arrows on x axis
        g.drawLine(390, 200, 370, 190);
        g.drawLine(390, 200, 370, 210);
        // Draw arrows on y axis
        g.drawLine(200, 30, 190, 50);
        g.drawLine(200, 30, 210, 50);
        // Draw x, y
        g.drawString("X", 370, 170);
        g.drawString("Y", 220, 40);
        // Draw a polygon line by connecting the points in the polygon
        g.drawPolyline(p.xpoints, p.ypoints, p.npoints);
    }
}

class Ex1 extends AbstractDrawFunction{
    @Override
    public double f(double x) {
        return x*x;
    }

}

class Ex2 extends AbstractDrawFunction{
    @Override
    public double f(double x) {
        return Math.sin(x);
    }

}

class Ex3 extends AbstractDrawFunction{
    @Override
    public double f(double x) {
        return Math.cos(x);
    }

}

class Ex4 extends AbstractDrawFunction{
    @Override
    public double f(double x) {
        return Math.tan(x);
    }

}

class Ex5 extends AbstractDrawFunction{
    @Override
    public double f(double x) {
        return Math.cos(x) + 5 * Math.sin(x);
    }

}

class Ex6 extends AbstractDrawFunction{
    @Override
    public double f(double x) {
        return 5*Math.cos(x) + Math.sin(x);
    }

}

class Ex7 extends AbstractDrawFunction{
    @Override
    public double f(double x) {
        return Math.log(x) + x*x;
    }

}