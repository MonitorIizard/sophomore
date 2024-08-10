import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class ShowBorderLayout extends JFrame {
    TextField enterText = new TextField(8);
    TextField freeSpace = new TextField(8);
    JButton setTextBT = new JButton("set text");


    public ShowBorderLayout() {
        setLayout(new BorderLayout());
        JPanel p1 = new JPanel();
        p1.add(new JLabel("Please Enter Text"));
        p1.add(enterText);

        add(p1, BorderLayout.NORTH );
        add(freeSpace, BorderLayout.CENTER);
        add(setTextBT, BorderLayout.SOUTH);

        setTextBT.addActionListener(new ButtonListener());
    }

    private class ButtonListener implements ActionListener {

        @Override
        public void actionPerformed(ActionEvent e) {
            String textInput = enterText.getText();
            freeSpace.setText(textInput);
        }
    }
    public static void main(String[] args) {
        ShowBorderLayout frame = new ShowBorderLayout();
        frame.setSize(400, 400);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setVisible(true);
    }
}
