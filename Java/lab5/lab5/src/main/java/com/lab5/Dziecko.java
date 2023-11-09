package com.lab5;

public abstract class Dziecko extends Czlowiek 
{
    
        public abstract void zabawa();
        
        public void drzemka()
        {
            System.out.println("Dziecko drzemie");
        }

        @Override
        public void jedz()
        {
            System.out.println("Dziecko je");   
        }

        @Override
        public void pij() 
        {
            System.out.println("Dziecko pije");
        }
        
}


/*
 * zabawa(),
 obowiązki().
 dodaj 2 autorskie metody z implementacją
 */