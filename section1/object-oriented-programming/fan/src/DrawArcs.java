import javax.swing.*;
import java.awt.*;

public class DrawArcs extends JFrame {
    public DrawArcs () {
        setTitle("Hatariiiiiiii");
        ArcsPanel arcsPanel = new ArcsPanel();
        add(arcsPanel, BorderLayout.CENTER);

        FanControl fanControl = new FanControl();
        fanControl.setArcsPanel(arcsPanel);
        add( fanControl, BorderLayout.SOUTH);

        pack();
    }

    public static void main( String[] args ) {
        DrawArcs frame = new DrawArcs();
        frame.setLocationRelativeTo(null); //justify center and item center
        frame.setSize(250, 300);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setResizable(true);
        frame.setVisible(true);
    }
}
