package com.kol1;

import java.awt.Color;

public class Truck implements Auto 
{
    public String nazwa;

    public int ileMiejsc()
    {
        return 2;
    }

    public Color jakiKolor()
    {
        return Color.RED;
    }   
}
