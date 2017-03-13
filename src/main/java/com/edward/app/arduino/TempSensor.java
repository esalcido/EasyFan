package com.edward.app.arduino;

import gnu.io.NRSerialPort;

import java.io.DataInputStream;
import java.io.DataOutputStream;

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

    public TempSensor(){



    }



}
