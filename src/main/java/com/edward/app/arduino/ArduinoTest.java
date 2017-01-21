package com.edward.app.arduino;

import gnu.io.NRSerialPort;

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;


/**
 * Created by edward on 11/27/15.
 */
public class ArduinoTest {

    public static void main(String [] args) {

        String port = "/dev/ttyUSB0";
        int baudRate = 57600;

        NRSerialPort serial = new NRSerialPort(port, baudRate);

        File file = new File("/home/edward/Desktop/test.txt");

        serial.connect();

        DataInputStream ins = new DataInputStream(serial.getInputStream());
        DataOutputStream outs = new DataOutputStream(serial.getOutputStream());

        byte [] buffer = new byte[4];
        int len= -1;


        try
        {
            //Handle file
            //if file does not exist, create one
            if(!file.exists()){
                file.createNewFile();
            }
            FileWriter fw = new FileWriter(file.getAbsoluteFile());
            BufferedWriter bw = new BufferedWriter(fw);


            while( (len =ins.read( buffer)) > -1 ) {


                String st = new String(buffer, 0, len);
                System.out.println(st);

                bw.write(st);

                if(st.equalsIgnoreCase("x")){
                    break;
                }

            }

          bw.close();

        } catch (Exception e) {
            e.printStackTrace();
        }

        serial.disconnect();

    }
    }

