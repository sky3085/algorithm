package Lv1Java;


//https://programmers.co.kr/learn/courses/30/lessons/68644

import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.List;

public class Lv1AddArray2 {
    public static int[] solution(int[] numbers) {
        int[] answer = {};
        List list = new ArrayList<>();

        for(int i=0; i<numbers.length; i++){
            for(int a=i+1; a<numbers.length; a++ ){
                int temp = numbers[i]+numbers[a];
                list.add(temp);
            }
        }
        
        HashSet<Integer> arr = new HashSet<Integer>(list);
        List<Integer> arr2 = new ArrayList<Integer>(arr);

        answer = new int[arr2.size()];
        
        for(int i =0; i<answer.length; i++) {
        	answer[i] = (int) arr2.get(i);
        }
        Arrays.sort(answer);


        return answer;
    }

    public static void main(String[] args) {
        int[] numbers = {2,1,3,4,1};
        int[] answer = solution(numbers);
        for (int i = 0; i < answer.length; i++) {
            System.out.print(answer[i]+" ");
        }
    }
}


//다른사람풀이

// import java.util.HashSet;
// import java.util.Set;

// class Solution {
//      public int[] solution(int[] numbers) {
//         Set<Integer> set = new HashSet<>();

//         for(int i=0; i<numbers.length; i++) {
//             for(int j=i+1; j<numbers.length; j++) {
//                 set.add(numbers[i] + numbers[j]);
//             }
//         }

//         return set.stream().sorted().mapToInt(Integer::intValue).toArray();
//     }
// }