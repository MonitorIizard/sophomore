import java.awt.Color;
        import java.awt.Graphics;

        import javax.swing.JFrame;
        import javax.swing.JPanel;

public class _3_Car extends JPanel {
    int speed = 0;
    int UPDATE_RATE = 60;
    Thread thread = new Thread() {
        public void run() {
            System.out.println("Start thread");
            while (true) {
                speed += 2;
                repaint();
                try {
                    Thread.sleep(1000 / UPDATE_RATE);
                } catch (InterruptedException ex) { }
            }
        }
    };

    _3_Car() {
        System.out.println("Race Car Question 4 Start");
        thread.start();
    }

    @Override
    protected void paintComponent(Graphics g) {
        super.paintComponent(g);
        g.drawLine(0, 400, getWidth(), 400);
        g.fillArc(50 + speed, 380, 20, 20, 0, 360);
        g.fillArc(100 + speed, 380, 20, 20, 0, 360);
        g.setColor(Color.GREEN);
        g.fillRect(40 + speed, 360, 90, 20);
        g.setColor(Color.red);
        g.fillRect(60 + speed, 340, 50, 20);
    }

    public static void main(String[] args) {

        JFrame frame = new JFrame("Race Car Question 4");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(1000, 500);
        frame.setContentPane(new _3_Car());
        frame.setVisible(true);

    }
}
