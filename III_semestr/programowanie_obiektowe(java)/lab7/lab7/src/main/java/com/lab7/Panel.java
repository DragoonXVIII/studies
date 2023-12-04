package com.lab7;

import java.awt.Color;
import java.awt.Graphics;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
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