package com.edward.app.arduino;

import gnu.io.NRSerialPort;

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.util.Arrays;

/**
 * Created by Soughloff on 12/11/2017.
 */
public class TestRelay {

    public static void main(String [] args){

       // Relay rly = new Relay();

       // rly.toggle("1");
        System.out.println("Starting test ");
        System.setProperty("gnu.io.rxtx.SerialPorts", "COM6");

        String port = "COM6";
        int baudRate = 9600;
        NRSerialPort serial = new NRSerialPort(port,baudRate);
        serial.connect();
            try {
        String valS = "1";
        DataInputStream ins = new DataInputStream(serial.getInputStream());
        DataOutputStream outs = new DataOutputStream(serial.getOutputStream());


            for(String s:NRSerialPort.getAvailableSerialPorts()){
                System.out.println("Availible port: "+s);
            }
            int val = Integer.parseInt(valS);

           int b = ins.read();
            //outs.write("1".getBytes());
            outs.write(49);
            System.out.println("ins b = "+b);
                Thread.sleep(2000);
            //outs.flush();
            //outs.close();
           // System.out.println(Arrays.toString("1".getBytes()));

        }catch(Exception e){
e.printStackTrace();
        }
        serial.disconnect();
    }


}
