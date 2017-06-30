package com.edward.app.arduino;

import gnu.io.CommPortIdentifier;
import gnu.io.NRSerialPort;

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.util.Enumeration;

/**
 * Created by Soughloff on 2/25/2017.
 */
public class TempSensor {

    private static DataInputStream ins;
    private static DataOutputStream outs;
    private static NRSerialPort serial;
    private static String port;
    private static int baudRate;

    private static SerialConnection serialCon;

    private static final String PORT_NAMES[]={
            "/dev/tty.usbserial-A9007UX1",
            "/dev/ttyACM0",
            "/dev/ttyUSB0",
            "COM5",
            "COM4",
            "COM3",
            "COM8",
    };

    public TempSensor(){

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

    public  int getData(String st){
        //TODO work on this to get data from the arduino
        return 1;
    }



}
