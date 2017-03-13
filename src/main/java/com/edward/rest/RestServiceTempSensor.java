package com.edward.rest;

import com.edward.app.arduino.Relay;

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

    Relay rly = new Relay();

    @GET
    @Path("/{state}")
    public Response getMsg(@PathParam("state") String state){
        String output = "toggle is: "+state;

        if(state.equals("true") ) {
            rly.toggle("1");
        }
        else
            rly.toggle("0");

        System.out.println("state is: "+ state);

        //return Response.status(200).entity(state).build();
        String json = "{\"state\":\""+state+"\"}";
        return Response.ok(json, MediaType.APPLICATION_JSON).build();

    }



}
