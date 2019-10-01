/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package topteen;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

/**
 *
 * @author Juan Ca
 */
public class Topteen {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws IOException {
        // *-*-*-*-*-*-*-*-*-*-**-*-*-*-*-*-*-*-*-*-*-*-*-*-*
         Scanner keyboard = new Scanner(System.in);
         Scanner keyboard2 = new Scanner(System.in);
         Vector words = new Vector();
         Integer cases = keyboard.nextInt();
         //Get Words the number needs to be times two since they are by pairs
         for(int i =0;i<cases*2;i++){
             String wordinput = keyboard2.nextLine();
             words.addElement(wordinput);
         }
         //System.out.println(words);
         for(int i =1;i<words.size();i+=2){
             System.out.println();
             if(isScreawled((String) words.get(i-1), (String) words.get(i))){
                 System.out.println("YES");
             }
             else{
                 System.out.println("NO");
             }
         }
         // *-*-*-*-*-*-*-*-*-*-**-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
//        int number = Integer.parseInt(reader.readLine());
//        int[] array = Arrays.stream(reader.readLine().split("\\s")).mapToInt(Integer::parseInt).toArray();
//        System.out.println(Subset(array).size());
// *-*-*-*-*-*-*-*-*-*-*
    
    }
    public static boolean isScreawled(String w1, String w2) {
        if (w1.length() > w2.length())return false;
        int[] w1map = new int[26];
        int[] w2map = new int[26];
        for (int i = 0; i < w1.length(); i++) {
            w1map[w1.charAt(i) - 'a']++;
            w2map[w2.charAt(i) - 'a']++;
        }
        for (int i = 0; i <w2.length() - w1.length(); i++) {
            if (match(w1map, w2map))
                return true;
            w2map[w2.charAt(i + w1.length()) - 'a']++;
            w2map[w2.charAt(i) - 'a']--;
        }
        return match(w1map, w2map);
    }
    public static boolean match(int[] w1map, int[] w2map) {
        for (int i = 0; i < 26; i++) {
            if (w1map[i] != w2map[i])
                return false;
        }
        return true;
    }
    
    public static String isScreawled2(String word1, String word2){
        int[] arry = new int[26];
        for(int i = 0 ; i < word2.length();++i){
            arry[word2.charAt(i) - 'a']++;
        }
        for(int j=0; j < word1.length();++j){
            if(--arry[word1.charAt(j)-'a']<0){
                return "NO";
            }
        }
        return "YES";
    }
    
    public static List<Integer> Subset(int[] nums) {
        List<Integer> result = new ArrayList<Integer>();
        if(nums==null||nums.length==0)
            return result;

        Arrays.sort(nums);

        int[] t = new int[nums.length];
        int[] index = new int[nums.length];
        Arrays.fill(t, 1);
        Arrays.fill(index, -1);

        int max=0;
        int maxIndex=-1;

        for(int i=0; i<t.length; i++){
            for(int j=i-1; j>=0; j--){
                if(nums[i]%nums[j]==0 && t[j]+1>t[i]){
                    t[i]=t[j]+1;
                    index[i]=j;
                }
            }
            if(max<t[i]){
                max=t[i];
                maxIndex=i;
            }
        }

        int i=maxIndex;
        while(i>=0){
            result.add(nums[i]);
            i=index[i];
        }

        return result;
    }
    
}
