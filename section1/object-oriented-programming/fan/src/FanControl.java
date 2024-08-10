import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class FanControl extends JPanel {
    private JButton fanSwitchNo1 = new JButton("1");
    private JButton fanSwitchNo2 = new JButton("2");
    private JButton fanSwitchNo3 = new JButton("3");
    private JButton fanSwitchOff = new JButton("Off");
    ArcsPanel arcsPanel;

    FanControl () {
        setLayout(new GridLayout(1, 4, 0, 5));
        fanSwitchNo1.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                arcsPanel.setStep(1);
            }
        });
        fanSwitchNo2.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                arcsPanel.setStep(5);
            }
        });
        fanSwitchNo3.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                arcsPanel.setStep(10);
            }
        });
        fanSwitchOff.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                arcsPanel.setStep(0);
            }
        });


        add( fanSwitchNo1 );
        add( fanSwitchNo2 );
        add( fanSwitchNo3 );

        fanSwitchOff.setForeground( Color.red );
        add( fanSwitchOff );
    }

    public void setArcsPanel(ArcsPanel arcsPanel) {
        this.arcsPanel = arcsPanel;
    }
}
