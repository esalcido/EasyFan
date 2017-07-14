package com.edward.app.arduino;

import gnu.io.CommPortIdentifier;
import gnu.io.NRSerialPort;

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Enumeration;
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

    private static SerialConnection serialCon;

    private static final String PORT_NAMES[]={
            "/dev/tty.usbserial-A9007UX1",
            "/dev/ttyACM0",
            "/dev/ttyACM1",
            "/dev/ttyUSB0",
            "/dev/ttyUSB1",
            "COM5",
            "COM4",
            "COM3",
            "COM8",
    };

    public Relay(){

        //get port from system
        CommPortIdentifier portId=null;
        Enumeration portEnum =CommPortIdentifier.getPortIdentifiers();
        CommPortIdentifier currPortId=null;
        while(portEnum.hasMoreElements()){
             currPortId = (CommPortIdentifier)portEnum.nextElement();
            for(String portName: PORT_NAMES){
                if(currPortId.getName().equals(portName)){
                    portId = currPortId;
                    break;
                }
            }
        if(portId==null){
            System.out.println("Unable to find COM port");

        }
        }


       // port = "COM5";

        port = currPortId.getName();
        System.out.println("port");
        baudRate = 9600;
        serial = new NRSerialPort(port, baudRate);


        serialCon = new SerialConnection(ins,outs,serial, port,baudRate);

    }

    public static  void toggle(String state) {


        serialCon.write(state);

    }

    //get state
    public static  int getState() {


        serialCon.write("2");
        byte [] buffer = new byte[4];
        int result = serialCon.read(buffer);
        return result;
    }

    }

