package com.edward.app.arduino;

import gnu.io.NRSerialPort;

import java.io.DataInputStream;
import java.io.DataOutputStream;

/**
 * Created by Soughloff on 2/25/2017.
 */
public class SerialConnection {


    private static DataInputStream ins;
    private static DataOutputStream outs;
    private static NRSerialPort serial;
    private static String port;
    private static int baudRate;


    public SerialConnection(DataInputStream ins,DataOutputStream outs,NRSerialPort  serial,String port,int baudRate){
        this.ins = ins;
        this.outs = outs;
        this.serial= serial;
        this.port=port;
        this.baudRate = baudRate;

    }

    public static boolean write(String state){

        serial.connect();

        ins = new DataInputStream(serial.getInputStream());
        outs = new DataOutputStream(serial.getOutputStream());
        try {
            byte [] buffer = new byte[4];

            outs.write(state.getBytes());
            Thread.sleep(2000);

        } catch (Exception e) {
            e.printStackTrace();
            return false;
        }

        serial.disconnect();
    return true;

    }


    public static int read(byte [] buffer){

        serial.connect();
        int result=0;
        ins = new DataInputStream(serial.getInputStream());
        outs = new DataOutputStream(serial.getOutputStream());
        try {
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
