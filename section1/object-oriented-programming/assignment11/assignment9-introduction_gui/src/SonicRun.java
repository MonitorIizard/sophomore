import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.net.URL;

public class SonicRun extends JFrame {
    public SonicRun() {
        URL imageURL = this.getClass().getResource("s.jpeg");
        Image image = new ImageIcon(imageURL).getImage();
        add( new SonicRunPanel(image) );
    }

    public static class SonicRunPanel extends JPanel {
        private Image image;
        private Timer timer = new Timer( 400, new Listener() );
        int x = 0;
        int y = 0;

        public SonicRunPanel( Image image ) {
            this.image = image;
            timer.start();
        }

        @Override
        public void paintComponent( Graphics g ) {
            super.paintComponents(g);

            if ( y < this.getHeight() ) {
                y += 10;
            }

            if ( x < this.getWidth() ) {
                x += 10;
            }

            g.drawImage(image, x, y, 60, 40, this);
        }

        class Listener implements ActionListener {
            @Override
            public void actionPerformed(ActionEvent e) {
                repaint();
            }
        }
    }




    public static void main( String[] args ) {
        SonicRun frame = new SonicRun();
        frame.setSize(300, 200);
        frame.setVisible(true);
    }
}
