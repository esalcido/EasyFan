package com.edward.app.arduino;

import gnu.io.NRSerialPort;

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;


/**
 * Created by edward on 11/27/15.
 */
public class Relay {

    private static DataInputStream ins;
    private static DataOutputStream outs;
    private static  NRSerialPort serial;
    private static String port;
    private static int baudRate;

    public static void main(String [] args) {

        //String port = "/dev/ttyUSB0";
        port = "COM4";

        baudRate = 9600;

        String input;

        serial = new NRSerialPort(port, baudRate);

        Scanner sc = new Scanner(System.in);

        do{
            System.out.println(" Enter option ");
            input = sc.next();

        try {
            toggle(input);


        }catch(Exception e){}
            //turn off
        }while(! input.equalsIgnoreCase("x"));

        //turn off when exiting
        toggle("0");


    }

    public Relay(){
        port = "COM4";
        baudRate = 9600;
        serial = new NRSerialPort(port, baudRate);

        toggle("0");

    }

    public static  void toggle(String state) {
        serial.connect();

        ins = new DataInputStream(serial.getInputStream());
        outs = new DataOutputStream(serial.getOutputStream());
        try {
            byte [] buffer = new byte[4];
//            int len= -1;
//            while ((len = ins.read(buffer)) > -1) {

               // String st = new String(buffer, 0, len);
               // System.out.println(st);

                outs.write(state.getBytes());
                Thread.sleep(2000);

           // }

        } catch (Exception e) {
            e.printStackTrace();
        }

        serial.disconnect();
    }

    //get state
    public static  int getState() {
        serial.connect();
        int result=0;
        ins = new DataInputStream(serial.getInputStream());
        outs = new DataOutputStream(serial.getOutputStream());
        try {
            byte [] buffer = new byte[4];
            outs.write("2".getBytes());

           result = ins.read(buffer);

            System.out.println(result);


            //Thread.sleep(2000);


        } catch (Exception e) {
            e.printStackTrace();
        }

        serial.disconnect();
        return result;
    }

    }

