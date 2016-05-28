/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Phoneword;

import java.lang.System;
import java.util.ArrayList;
import java.util.List;

/**
 *
 * @author Matt
 */
public class Main {
    
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        
        int intArg;
        Phoneword p;
        ArrayList<String> wordList;
        for ( String arg : args ){
            try {
                intArg = Integer.parseInt( arg );
                p = new Phoneword( intArg );
                wordList = p.get();
                for ( String word : wordList )
                    System.out.println( word );
            }
            catch (NumberFormatException err) {
                System.err.println("Argument " + args[0] + " must be an integer.");
                usage();
                System.exit(1);
            }
            System.out.println();
        }
        
    }
    
    public static void usage(){
        return;
    }
    
}
