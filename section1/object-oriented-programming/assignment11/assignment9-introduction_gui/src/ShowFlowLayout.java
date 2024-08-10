import javax.swing.*;
import java.awt.*;

public class ShowFlowLayout extends JFrame {
    public ShowFlowLayout () {
        setLayout(new FlowLayout(FlowLayout.LEFT, 10, 20));
        add( new JLabel("First Name"));
        add( new JTextField(8) );
        add( new JLabel("MI"));
        add( new JTextField(1) );
        add( new JLabel("Last Name"));
        add( new JTextField(8) );
    }

    public static void main(String[] args ) {
        ShowFlowLayout frame = new ShowFlowLayout();
        frame.setTitle("test flow layout");
        frame.setSize(200, 200);
        frame.setLocationRelativeTo(null);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setVisible(true);
    }
}