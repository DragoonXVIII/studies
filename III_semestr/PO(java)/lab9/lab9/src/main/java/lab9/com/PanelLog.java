package lab9.com;

import java.awt.Color;
import java.awt.Graphics;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import javax.swing.JFrame;
import javax.swing.JPanel;

public class PanelLog extends JPanel
{
    private ArrayList<Kula> listaKul;

    public PanelLog() 
    {
        listaKul = new ArrayList<>();
        setBackground(Color.BLACK);

        try (BufferedReader br = new BufferedReader(new FileReader("collisions.txt"))) 
        {
            String line;
            while ((line = br.readLine()) != null) 
            {
                String[] collisionInfo = line.split(" ");
                int x = Integer.parseInt(collisionInfo[4]);
                int y = Integer.parseInt(collisionInfo[5]);
                int size = Integer.parseInt(collisionInfo[8]);
                listaKul.add(new Kula(x, y, size));
            }
        } 
        catch (IOException e) 
        {
            e.printStackTrace();
        }
    }

    @Override
    protected void paintComponent(Graphics g) 
    {
        super.paintComponent(g);
        for (Kula k : listaKul) 
        {
            g.setColor(k.color);
            g.drawOval(k.x, k.y, k.size, k.size);
        }
        g.setColor(Color.YELLOW);
        g.drawString(Integer.toString(listaKul.size()), 40, 40);
    }

    private class Kula 
    {
        public int x, y, size;
        public Color color;

        public Kula(int x, int y, int size) 
        {
            this.x = x;
            this.y = y;
            this.size = size;
            this.color = Color.GREEN; 
        }
    }

    public static void main(String[] args) 
    {
        JFrame frame = new JFrame("LogPanel");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.getContentPane().add(new PanelLog());
        frame.setPreferredSize(new java.awt.Dimension(800, 600));
        frame.pack();
        frame.setVisible(true);
    }
}

