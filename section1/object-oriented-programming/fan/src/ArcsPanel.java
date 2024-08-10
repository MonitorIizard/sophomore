import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class ArcsPanel extends JPanel {
    private int ang = 0;
    private int step = 1;
    Timer timer = new Timer(10, new TimerListener());

    ArcsPanel() {
        timer.start();
    }
    @Override
    protected void paintComponent( Graphics g ) {
        super.paintComponent(g);

        int xCenter = getWidth() / 2;
        int yCenter = getHeight() / 2;
        int radius = (int)(Math.min(getHeight(), getHeight()) * 0.4);

        int x = xCenter - radius;
        int y = yCenter - radius;

        g.fillArc(x, y, 2 * radius, 2 * radius, ang, 30);
        g.fillArc(x, y, 2 * radius, 2 * radius, 90 + ang, 30);
        g.fillArc(x, y, 2 * radius, 2 * radius, 180 + ang, 30);
        g.fillArc(x, y, 2 * radius, 2 * radius, 270 + ang, 30);
    }

    private class TimerListener implements ActionListener {
        @Override
        public void actionPerformed(ActionEvent e) {
            ang += step;
            repaint();
        }
    }

    public void setStep(int step) {
        this.step = step;
    }
}
