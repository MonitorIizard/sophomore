import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class _6_Hangman extends JFrame {
    HangMe panel = new HangMe();
    Timer timer = new Timer((int) (1.0 / 60 * 1000), panel);

    _6_Hangman() {
        timer.start();
        add(panel);
    }

    class HangMe extends JPanel implements ActionListener {
        int timerTick = 0;
        boolean left = false;
        double posX;

        @Override
        public void paintComponent(Graphics g) {
            super.paintComponent(g);

            g.drawArc(20, 220, 80, 40, 0, 180);
            g.drawLine(20 + 40, 220, 20 + 40, 20);
            g.drawLine(20 + 40, 20, 20 + 40 + 100, 20);

            int x = (int) (50 * (posX - 0.5));

            g.drawLine(20 + 40 + 100, 20, 20 + 40 + 100 + x, 40);

            int radius = 20;
            g.setColor(Color.BLACK);
            // head
            g.fillOval(20 + 40 + 100 - radius + x, 40, 2 * radius, 2 * radius);
            // left arm
            g.drawLine(x + 20 + 40 + 100 - (int) (radius *
                            Math.cos(Math.toRadians(45))),
                    40 + radius + (int) (radius * Math.sin(Math.toRadians(45))),
                    20 + 40 + 100 - 60 + (int) (x * 2.5), 40 + radius + 60);
            // right arm
            g.drawLine(x + 20 + 40 + 100 + (int) (radius *
                            Math.cos(Math.toRadians(45))),
                    40 + radius + (int) (radius * Math.sin(Math.toRadians(45))),
                    20 + 40 + 100 + 60 + (int) (x * 2.5), 40 + radius + 60);
            // body
            g.drawLine(20 + 40 + 100 + x, 40 + 2 * radius,
                    20 + 40 + 100 + (x * 2), 40 + radius + 80);
            // left ขา
            g.drawLine(20 + 40 + 100 + (x * 2), 40 + radius + 80, 20 + 40 + 100 - 40 + (x * 3),
                    40 + radius + 80 + 40);
            // right ขา
            g.drawLine(20 + 40 + 100 + (x * 2), 40 + radius + 80, 20 + 40 + 100 + 40 + (x * 3),
                    40 + radius + 80 + 40);
        }

        @Override
        public void actionPerformed(ActionEvent e) {
            timerTick += 1;

            if (timerTick % 60 == 0) left = !left;

            posX = posX + (left ? -1.0 / 60 : 1.0 / 60);

            repaint();
        }
    }

    public static void main(String args[]) {
        _6_Hangman frame = new _6_Hangman();
        frame.setVisible(true);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(500, 500);
    }
}