import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class Panel extends JPanel {

    int x = 0;
    int y = 20;

    Timer timer = new Timer( 100, new TimerListener() );
    Panel() {
        setBackground( Color.gray );
        setLayout(null);
        timer.start();
    }

    public void paintComponent( Graphics g ) {
        super.paintComponent(g);

        int widthScreen = getWidth();
        int heightScreen = getHeight();

        int width = 100;
        int height = 50;

        g.setColor( new Color(155, 118, 83) );
        g.fillRect( 0, heightScreen - height, widthScreen, height );

        //draw umbrella
        g.setColor( Color.red );
        g.fillArc(x, y, 200, 80, 0, 180);
        g.drawLine(x + 100, y + 40, x + 100, y + 40 + 50 );

        //draw head
        g.drawOval(x + 10, y + 50, 40, 40);

        //draw body
        g.drawLine(x + 20 + 10, y  + 25 +70, x + 20 + 10, y + 25 + 70 + 50 );

        //draw hand
        g.drawLine(x + 20 + 10, y  + 25 + 60 + 50, x + 100, y + 40 + 50);
        g.drawLine(x + 20 + 10, y  + 15 + 60 + 50, x + 100, y + 40 + 50);

        //draw leg
        if (x % 3 == 0) {
            g.drawLine(x + 20 + 10, y + 25 + 70 + 50, x -15, heightScreen - height);
        } else {
            g.drawLine(x + 20 + 10, y + 25 + 70 + 50, x + 45, heightScreen - height);
        }
    }



    private class TimerListener implements ActionListener {

        @Override
        public void actionPerformed(ActionEvent e) {
            x += 20;
            repaint();
        }
    }
}
