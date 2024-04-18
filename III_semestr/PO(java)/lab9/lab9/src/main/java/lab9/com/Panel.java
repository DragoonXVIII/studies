package lab9.com;

import java.awt.Color;
import java.awt.Graphics;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import javax.swing.JPanel;
import javax.swing.Timer;

public class Panel extends JPanel 
{
    private ArrayList<Kula> listaKul;
    private int size = 20;
    private Timer timer;
    private final int DELAY = 33;
    //dla 30fps -> 1s/30 = 0,033s 
    public int collisions = 0;
    /*
        Stwórz okno analogiczne do zadania 7.1 ale bez animacji. Użyj odczytanych danych do 
        zaznaczenia miejsc kolizji (użyj metody rysującej drawOval()).
    */
    
    public Panel() 
    {
        listaKul = new ArrayList<>();
        setBackground(Color.BLACK);
        addMouseListener(new Event());
        timer = new Timer(DELAY, new Event());
        timer.start();
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
        g.drawString(Integer.toString(listaKul.size()),40,40);
    }
    
    private class Event implements MouseListener, 
    ActionListener 
    {
        @Override
        public void mouseClicked(MouseEvent e) 
        {
        }
        @Override
        public void mousePressed(MouseEvent e) 
        {
            listaKul.add(new Kula(e.getX(), e.getY(), size));
            repaint();
        }
        @Override
        public void mouseReleased(MouseEvent e) 
        {
        }
        @Override
        public void mouseEntered(MouseEvent e) 
        {
        }
        @Override
        public void mouseExited(MouseEvent e) 
        {
        }
        @Override
        public void actionPerformed(ActionEvent e) 
        {
            for (Kula k : listaKul) 
            {
                k.update();
            }
            repaint();
            
            for (int c = 0; c < listaKul.size(); c++)
            {
                for(int cs = c+1; cs<listaKul.size(); cs++)
                {
                    if(listaKul.get(c).x == listaKul.get(cs).x && listaKul.get(c).y == listaKul.get(cs).y)
                    {
                        collisions++;
                        try (FileWriter writer = new FileWriter("collisions.txt", true)) 
                        {
                            writer.write("Kolizja: " + collisions + " " + "Wspolrzedne kul: " + listaKul.get(c).x + " " + listaKul.get(c).y + " " + "Rozmiar kul: " + listaKul.get(c).size + "\n");
                            writer.flush();
                        } 
                        catch (IOException ex) 
                        {
                            ex.printStackTrace();
                        }
                    }
                }
            }
        }
    }

    private class Kula 
    {
        public int x, y, size, xspeed, yspeed;
        public Color color;
        private final int MAX_SPEED = 5;
        public Kula(int x, int y, int size) 
        {
            this.x = x;
            this.y = y;
            this.size = size;
            color = new Color((float) Math.random(), (float) 
            Math.random(), (float) Math.random());
            xspeed = (int) (Math.random() * MAX_SPEED * 2 -
            MAX_SPEED);
            yspeed = (int) (Math.random() * MAX_SPEED * 2 -
            MAX_SPEED);
        }

        public void update()
        {
            x += xspeed;
            y += yspeed;
            if (x <= 0 || x >= getWidth()) 
            {
                xspeed = -xspeed;
            }
            if (y <= 0 || y >= getHeight())
            {
                yspeed = -yspeed;
            }
        }
    }
}