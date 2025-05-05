package org.example;

import javax.xml.ws.Endpoint;
//Endpoint publisher
public class MyFirstSOAPPublisher{
    public static void main(String[] args) {
        Endpoint.publish("http://localhost:7779/ws/first",
                new MyFirstWS());
    }
}