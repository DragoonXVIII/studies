/*package com.lab7;

import java.awt.Color;

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
 }*/
 