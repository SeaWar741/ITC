/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package topteen;

import java.util.Random;
import java.util.Scanner;
import java.util.stream.Stream;

/**
 *
 * @author Juan Ca
 */
public class pinball {

    /**
     * @param args the command line arguments
     */
    public static int[][] valor = new int[1002][1002];
    public static char[][] dir =new char[1002][1002];
    public static int[][] visitado = new int[1002][1002];
    
    public static void main(String[] args) {
        Random ran = new Random();
        // Assumes max and min are non-negative.
        int randomInt = 0 + ran.nextInt(3 - 0 + 1);
        
        // TODO code application logic here
        Scanner scan=new Scanner(System.in);
        String str = scan.nextLine();
        int[] numbers = Stream.of(str.split("\\s+")).mapToInt(Integer::parseInt).toArray();
        int n = numbers[0];
        int m = numbers[1];
        
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                int number = scan.nextInt();
                valor[i][j] = number;
            }
        }
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                char word = scan.next().charAt(0);
                dir[i][j] = word;
            }
        }
        
        int ganancia = 0;
        int pf = 1;
        int pc = 1;
        while(pf >= 1 && pf <= n && pc >= 1 && pc <= m){
            if(visitado[pf][pc] == 1){
                pf = pc = 0;
                ganancia += 100;
            }else{
                visitado[pf][pc] = 1;
                ganancia += valor[pf][pc];
                switch(dir[pf][pc]){
                case 'A':
                    pf--;
                    break;
                case 'D':
                    pc++;
                    break;
                case 'B':
                    pf++;
                    break;
                case 'I':
                    pc--;
                    break;
                }
            }
        }
        System.out.println(ganancia);
    }
    
    
}
