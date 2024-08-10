import javax.swing.*; //1 import
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

// Press Shift twice to open the Search Everywhere dialog and type `show whitespaces`,
// then press Enter. You can now see whitespace characters in your code.
public class Main extends JFrame  { //2 extendJframe

    JLabel jlbName = new JLabel("name"); //5 create attribute
    JLabel jlbSurname = new JLabel("surname");
    JLabel jlbAge = new JLabel("age");

    JTextField jtfName = new JTextField(10);
    JTextField jtfSurname = new JTextField(10);
    JTextField jtfAge = new JTextField(2);

    JButton jbtOk = new JButton("OK");
    JButton jbtCancel = new JButton("Cancel");

    JLabel jlbInfo = new JLabel("info");
    JLabel jlbInfoFromText = new JLabel("");

    JPanel p = new JPanel();

    //5 inner class, listener
    class Listener implements ActionListener {
        @Override
        public void actionPerformed(ActionEvent e) {
            if( e.getActionCommand().equals("OK") ) {
                jlbInfoFromText.setText(jtfName.getText() + " " + jtfSurname.getText() + " " + jtfAge.getText());
            } else {
                jtfName.setText("");
                jtfSurname.setText("");
                jtfAge.setText("");
                jlbInfoFromText.setText("");
            }
        }
    }
    Main() {
        //ใน j frame จะมี add เรียบร้อยเเล้ว
        p.setLayout(new GridLayout( 5, 2, 5, 5));
        p.add(jlbName);
        p.add(jtfName);

        p.add(jlbSurname);
        p.add(jtfSurname);

        p.add(jlbAge);
        p.add(jtfAge);

        p.add(jlbInfo);
        p.add(jlbInfoFromText);

        p.add(jbtOk);
        p.add(jbtCancel);
        add(p);

        Listener spyObj = new Listener();
        jbtCancel.addActionListener( spyObj );
        jbtOk.addActionListener( spyObj );
    }

    public static void main(String[] args) {
        Main frame = new Main(); //3 new frame
        frame.setTitle("Example");
        frame.setSize(300, 300);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE); // 4 เมื่อ exit object จะคืนกลับไปที่ memory
        frame.setVisible( true );
    }
}