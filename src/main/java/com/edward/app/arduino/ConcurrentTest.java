package com.edward.app.arduino;

import java.util.concurrent.Executor;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class ConcurrentTest {

    public static void main(String [] args){
        Runnable hellos = () -> {
            for(int i=1;i<10;i++){
                System.out.println("Hello "+i);
            }
        };

        Runnable goodbyes = ()->{
            for(int i=1;i<10;i++)
                System.out.println("Goodbye "+ i);
        };

        Executor executor = Executors.newCachedThreadPool();
        ((ExecutorService) executor).execute(hellos);
        ((ExecutorService) executor).execute(goodbyes);
    }
}
