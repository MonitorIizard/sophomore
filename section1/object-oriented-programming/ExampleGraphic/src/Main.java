import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.net.URL;

// Press Shift twice to open the Search Everywhere dialog and type `show whitespaces`,
// then press Enter. You can now see whitespace characters in your code.
public class Main extends JFrame {

    Main() {
        add( new DrawArea() );
    }

    //1 create innerclass for drawing
    class DrawArea extends JPanel {
        URL imageURL = this.getClass().getResource("download.jpeg");
        Image image = new ImageIcon( imageURL ).getImage();
        URL imageURL2 = this.getClass().getResource("download.jpeg");
        Image image2 = new ImageIcon( imageURL2 ).getImage();

        Timer timer = new Timer( 10, new Listener());
        int x = 0;
        int y = 400;

        DrawArea() {
            timer.start();
        }
        @Override
        public void paintComponent( Graphics g ) {
            super.paintComponent(g);
            if ( x < getWidth() - 100 ) {
                x++;
            }
            g.drawImage( image, 0, 0, 1200, 1500, this);
            g.drawImage( image2, x, y, 100, 100, this);
        }
    }

    class Listener implements ActionListener {
        @Override
        public void actionPerformed(ActionEvent e) {
            repaint();
        }
    }

    public static void main(String[] args) {
        Main frame = new Main();
        frame.setSize(500, 600);
        frame.setDefaultCloseOperation( JFrame.EXIT_ON_CLOSE );
        frame.setVisible( true );
    }
}