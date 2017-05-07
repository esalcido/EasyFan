package com.edward.rest;

import com.edward.app.arduino.Relay;
import org.codehaus.jackson.map.ObjectMapper;

import javax.ws.rs.GET;
import javax.ws.rs.Path;
import javax.ws.rs.PathParam;
import javax.ws.rs.core.MediaType;
import javax.ws.rs.core.Response;


/**
 * Created by Edward Salcido on 1/30/2017.
 */

@Path("/toggle")
public class RestService {

    Relay rly = new Relay();

    @GET
    @Path("/{state}")
    public Response getMsg(@PathParam("state") String state){
        String output = "toggle is: "+state;
        String json="";
        try {
            if (state.equals("true")) {
                rly.toggle("1");
            } else
                rly.toggle("0");

            System.out.println("state is: " + state);

            //return Response.status(200).entity(state).build();
            json = "{\"state\":\"" + state + "\"}";
        }catch(Exception e){
            System.out.println("error in restService");
        }

        return Response.ok(json, MediaType.APPLICATION_JSON).build();

    }

   @GET
    @Path("/state")
    public Response getState(@PathParam("getState") String getState){
        String output = "toggle is: "+getState;

        int result = rly.getState();

        System.out.println("result state is: "+ result);

        //return Response.status(200).entity(state).build();
        String json = "{\"state\":\""+result+"\"}";
        return Response.ok(json, MediaType.APPLICATION_JSON).build();

    }

}
