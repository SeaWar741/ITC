/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package topteen;

import java.util.Scanner;

/**
 *
 * @author Juan Ca
 */
public class Topteen {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
         Scanner keyboard = new Scanner(System.in);
         Scanner keyboard2 = new Scanner(System.in);
         int years = keyboard.nextInt();
         for(int i =0; i<years;i++){
             int yeari = keyboard2.nextInt();
             if(yeari%4 ==0 && yeari%100 != 0 || yeari%100 == 0 && yeari%400 == 0){
                 System.out.println("S");
             }
             else{
                 System.out.println("N");
             }
         }
    }
    
}
