/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package topteen;

import java.util.*;
import java.util.stream.Stream;

/**
 *
 * @author Juan Ca
 */
public class SubSet_sum_problem {
    //Driver Program to test above functions 
    public static List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<List<Integer>> result = new ArrayList<>();
        List<Integer> temp = new ArrayList<>();
        helper(candidates, 0, target, 0, temp, result);
        return result;
    }
    private static void helper(int[] candidates, int start, int target, int sum,
                    List<Integer> list, List<List<Integer>> result){
        if(sum>target){
            return;
        }
        if(sum==target){
            result.add(new ArrayList<>(list));
            return;
        } 
        for(int i=start; i<candidates.length; i++){
            list.add(candidates[i]);
            helper(candidates, i, target, sum+candidates[i], list, result);
            list.remove(list.size()-1);
        }
    }
    public static void main(String args[]) {
        Scanner scan=new Scanner(System.in);
        String str = scan.nextLine();
        int[] numbers = Stream.of(str.split("\\s+")).mapToInt(Integer::parseInt).toArray();
        //System.out.println(Arrays.toString(numbers));
        int[] numbs = {numbers[1],numbers[2]};
        for(int i =0;i<numbers[0];i++){
            int suma = scan.nextInt();
            List<List<Integer>> combinations = combinationSum(numbs,suma);
            if(combinations.isEmpty() != true){
                System.out.println("SI");
            }
            else{
                System.out.println("NO");
            }
        }
//        for ( List<Integer> elem : combinationSum(numbers,sum) ) {
//           System.out.println("Element : "+elem);
//        }
    }
}
