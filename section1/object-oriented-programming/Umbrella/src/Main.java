import javax.swing.*;

// Press Shift twice to open the Search Everywhere dialog and type `show whitespaces`,
// then press Enter. You can now see whitespace characters in your code.
public class Main extends JFrame {

    Main() {
        add( new Panel() );
    }

    public static void main(String[] args) {
        Main frame = new Main();
        frame.setTitle("What R You Doing In The Rain?");
        frame.setSize(400, 300);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setVisible(true);
    }
}