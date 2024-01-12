package com.lab10;

class kucharz implements Runnable 
{
    private automatNalesnikowy pancakeMachine;

    public kucharz(automatNalesnikowy pancakeMachine) 
    {
        this.pancakeMachine = pancakeMachine;
    }

    @Override
    public void run() 
    {
        try 
        {
            while(true) 
            {
                String pancake = pancakeMachine.getPancakeQueue().take();

                pancakeMachine.fryPancake(pancake);
                pancakeMachine.spreadJam(pancake);
                pancakeMachine.rollPancake(pancake);

                System.out.println("Naleśnik gotowy: " + pancake);
            }
        } 
        catch(InterruptedException e) 
        {
            e.printStackTrace();
        }
    }
}

