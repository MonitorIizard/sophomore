import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class _4_Car extends JFrame {
    JLabel c1=new JLabel("Car 1:");
    JLabel c2=new JLabel("Car 2:");
    JLabel c3=new JLabel("Car 3:");
    JLabel c4=new JLabel("Car 4:");
    JTextField ca1=new JTextField(10);
    JTextField ca2=new JTextField(10);
    JTextField ca3=new JTextField(10);
    JTextField ca4=new JTextField(10);
    RaceCar rc1=new RaceCar();
    RaceCar rc2=new RaceCar();
    RaceCar rc3=new RaceCar();
    RaceCar rc4=new RaceCar();
    listener list1=new listener();
    _4_Car(){
        ca1.addActionListener(list1);
        ca2.addActionListener(list1);
        ca3.addActionListener(list1);
        ca4.addActionListener(list1);
        JPanel p1=new JPanel();
        p1.add(c1);
        p1.add(ca1);
        p1.add(c2);
        p1.add(ca2);
        p1.add(c3);
        p1.add(ca3);
        p1.add(c4);
        p1.add(ca4);
        JPanel p2=new JPanel(new GridLayout(4,1) );

        p2.add(rc1);

        p2.add(rc2);

        p2.add(rc3);

        p2.add(rc4);


        add(p1,BorderLayout.NORTH);
        add(p2,BorderLayout.CENTER);

    }

    class listener implements ActionListener{

        @Override
        public void actionPerformed(ActionEvent e) {
            if (e.getSource()==ca1){
                int v1=Integer.parseInt(ca1.getText());
                rc1.speed=v1;
            }if(e.getSource()==ca2){
                int v2=Integer.parseInt(ca2.getText());
                rc2.speed=v2;
            }
            if(e.getSource()==ca3){
                int v3=Integer.parseInt(ca3.getText());
                rc3.speed=v3;
            }
            if(e.getSource()==ca4){
                int v4=Integer.parseInt(ca4.getText());
                rc4.speed=v4;
            }
        }

    }
    public static void main(String[] args) {
        _4_Car frame=new _4_Car();
        frame.setTitle("Exercise");
        frame.setLocationRelativeTo(null); // Center the frame
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(800, 500);
        frame.setVisible(true);
    }

    class RepaintThread extends Thread
    {
        public void run() {
            while(true) {
                try {
                    Thread.sleep(1000);
                    repaint();
                } catch (InterruptedException e) {
                    System.out.println(e.getMessage());
                }
            }
        }
    }

    class RaceCar extends JPanel{
        int xBase=0;
        int speed=0;
        //        @Overrid
        RaceCar(){
            this.setFocusable(true);
            this.addKeyListener(new KeyAdapter() {
                public void keyPressed(KeyEvent e) {
                    if (e.isControlDown() && e.getKeyCode() == 61) {
                        speed++;
                    }
                    else if (e.isControlDown() && e.getKeyCode() == 45)
                        speed--;
                }
            });
            Thread t = new RepaintThread();
            t.start();
        }
        public void paintComponent(Graphics g){
            super.paintComponent(g);

            int yBase=getHeight();
            if(xBase>getWidth()){
                xBase=-20;
            }else{
                xBase+=speed;
            }

            g.setColor(Color.BLACK);
            g.fillOval(xBase+10, yBase-10, 10, 10);
            g.fillOval(xBase+30, yBase-10, 10, 10);
            g.setColor(Color.GREEN);
            g.fillRect(xBase, yBase-20, 50, 10);

            g.setColor(Color.RED);
            Polygon polygon=new Polygon();
            polygon.addPoint(xBase+10, yBase-20);
            polygon.addPoint(xBase+20, yBase-30);
            polygon.addPoint(xBase+30, yBase-30);
            polygon.addPoint(xBase+40, yBase-20);
            g.fillPolygon(polygon);
        }
    }

}