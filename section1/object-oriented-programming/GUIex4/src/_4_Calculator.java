import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

// Press Shift twice to open the Search Everywhere dialog and type `show whitespaces`,
// then press Enter. You can now see whitespace characters in your code.
public class _4_Calculator extends JFrame {

    JPanel p1 = new JPanel();

    JLabel jlbUsDollars = new JLabel("US Dollars");
    JLabel jlbCanadianDollars = new JLabel("Canadian Dollars");
    JPanel p2 = new JPanel();

    JTextField jtfUsDollars = new JTextField(10);
    JTextField jtfCanadianDollars = new JTextField(10);
    JPanel p3 = new JPanel();

    JPanel p4 = new JPanel();
    JButton convertBtn = new JButton("convert");
    _4_Calculator() {
        p4.setLayout( new BorderLayout(5 ,10) );
        p4.add(convertBtn, BorderLayout.EAST );

        ButtonListen spy = new ButtonListen();
        convertBtn.addActionListener(spy);

        p3.setLayout( new BorderLayout(5 ,10) );
        p3.add(p1, BorderLayout.WEST);
        p3.add(p2, BorderLayout.CENTER);

        p1.setLayout( new GridLayout(2, 1));
        p1.add(jlbUsDollars);
        p1.add(jlbCanadianDollars);

        p2.setLayout( new GridLayout(2, 1));
        jtfUsDollars.setHorizontalAlignment(JTextField.RIGHT);
        p2.add(jtfUsDollars);
        jtfCanadianDollars.setHorizontalAlignment(JTextField.RIGHT);
        p2.add(jtfCanadianDollars);

        // p5.setLayout( new BorderLayout());
        add( p3, BorderLayout.CENTER );
        add( p4, BorderLayout.SOUTH );

        // add(p5);
    }

    class ButtonListen implements ActionListener {

        @Override
        public void actionPerformed(ActionEvent e) {
            double CAD_RATE = 1.35;
            double usDollars = 0;
            try {
                usDollars = Double.parseDouble(jtfUsDollars.getText());
                jtfCanadianDollars.setText( "" + (usDollars * CAD_RATE) );
            } catch ( Exception err ){
                jtfCanadianDollars.setText( "Please input text" );
            }


        }
    }

    public static void main( String[] args ) {
        _4_Calculator frame = new _4_Calculator();
        frame.setSize( 500, 200 );
        frame.setTitle( "Convert US Dollars to Canadian Dollars" );
        frame.setDefaultCloseOperation( JFrame.EXIT_ON_CLOSE );
        frame.setVisible(true);
    }
}