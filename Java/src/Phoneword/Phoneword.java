/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package Phoneword;

import java.util.Arrays;
import java.util.ArrayList;
import java.util.List;
import java.util.Stack;

/**
 *
 * @author Matt
 */
public class Phoneword {
    
    private Computation comp;
    
    public Phoneword( int phoneNumber ){
        comp = new Computation<String>(phoneNumber);
    }
    
    /**
     * Returns Array List of all possible phoneword combinations
     * @return 
     */
    public ArrayList<String> get(){
        return comp.getWords();
    }
    
    private class Computation<T> {

        private Stack<Integer> phoneDigits;
        private ArrayList<List<T>> phoneWords;
        private List<T> wordList;

        private String join( List<T> l ){
            String retVal = "";
            for ( T s : l ){
                retVal += s;
            }
            return retVal;
        }

        public Computation( int phoneNumber ){
            phoneDigits = new Stack<Integer>();
            phoneWords = new ArrayList<List<T>>();
            wordList = new ArrayList<T>();
            digits( phoneNumber );  // Digit split
        }

        public ArrayList<T> getWords(){
            compileList();
            List<List<T>> cart = cartesian( phoneWords );
            ArrayList words = new ArrayList<T>();
            for ( List<T> word : cart ){
                words.add( join(word) );
            }
            return words;
        }

        private void compileList(){
            while ( !phoneDigits.isEmpty() ){
                phoneWords.add( phoneletter( phoneDigits.pop().intValue() ) );
            }
        }

        // http://stackoverflow.com/a/9496234
        private <T> List<List<T>> cartesian(List<List<T>> lists) {
            List<List<T>> resultLists = new ArrayList<List<T>>();
            if (lists.size() == 0) {
                resultLists.add(new ArrayList<T>());
                return resultLists;
            }
            List<T> firstList = lists.get(0);
            List<List<T>> remainingLists = cartesian(lists.subList(1, lists.size()));
            for (T condition : firstList) {
                for (List<T> remainingList : remainingLists) {
                    ArrayList<T> resultList = new ArrayList<T>();
                    resultList.add(condition);
                    resultList.addAll(remainingList);
                    resultLists.add(resultList);
                }
            }
            return resultLists;
        }

        private void digits( int n ){
            while ( n != 0 ){
                phoneDigits.push( new Integer( phoneMod(n, 10) ) );
                n = n/10;
            }
        }

        private int phoneMod( int n, int div ){
            return n < 0 
                    ? -n % div 
                    : n % div ;
        }

        private List<T> phoneletter(int index){
            List<String> retVal = new ArrayList<String>();
            switch ( phoneMod( index, 10 ) ){
                case 0:
                case 1:
                    retVal = Arrays.asList( " " );
                    break;
                case 2:
                    retVal = Arrays.asList( "A", "B", "C" );
                    break;
                case 3:
                    retVal = Arrays.asList( "D", "E", "F" );
                    break;
                case 4:
                    retVal = Arrays.asList( "G", "H", "I" );
                    break;
                case 5:
                    retVal = Arrays.asList( "J", "K", "L" );
                    break;
                case 6:
                    retVal = Arrays.asList( "M", "N", "O" );
                    break;
                case 7:
                    retVal = Arrays.asList( "P", "Q", "R", "S" );
                    break;
                case 8:
                    retVal = Arrays.asList( "T", "U", "V" );
                    break;
                case 9:
                    retVal = Arrays.asList( "W", "X", "Y", "Z" );
            }
            return (List<T>)retVal;
        }

    }

}