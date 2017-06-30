package com.edward.rest;

import com.edward.app.arduino.Relay;
import com.edward.app.arduino.TempSensor;

import javax.ws.rs.GET;
import javax.ws.rs.Path;
import javax.ws.rs.PathParam;
import javax.ws.rs.core.MediaType;
import javax.ws.rs.core.Response;


/**
 * Created by Edward Salcido on 1/30/2017.
 */

@Path("/tempsensor")
public class RestServiceTempSensor {

    //Relay rly = new Relay();
    TempSensor ts = new TempSensor();
    int result =0;

    @GET
    @Path("/{data}")
    public Response getMsg(@PathParam("data") String data){
        String output = "toggle is: "+data;

        if(data.equals("true") ) {
           // rly.toggle("1");
           result =  ts.getData("2");
        }
        else
           // rly.toggle("0");
            result = ts.getData("3");

        System.out.println("data is: "+ result);

        //return Response.status(200).entity(state).build();
        String json = "{\"state\":\""+result+"\"}";
        return Response.ok(json, MediaType.APPLICATION_JSON).build();

    }



}
