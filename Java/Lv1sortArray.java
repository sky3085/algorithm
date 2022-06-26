

import java.util.Arrays;
/*
https://programmers.co.kr/learn/courses/30/lessons/42748?language=java
배열을 요구한 인덱스부터 인덱스까지 자른 후
정렬한 뒤 K번째 수를 구하는 알고리즘입니다.
*/
public class Lv1sortArray {
    public static int[] solution(int[] array, int[][] commands) {
        int[] answer = new int[commands.length];
        for(int a = 0; a<commands.length; a++){
            int size = commands[a][1] - commands[a][0] + 1;
            int[] temp = new int[size];
            
            for(int i=0; i < size; i++){
                temp[i] = array[commands[a][0]+i-1];    
            }
            
            Arrays.sort(temp);
            
            answer[a]=temp[commands[a][2]-1];
        }
        
        return answer;
    }
    public static void main(String[] args) {
        int[] array={1, 5, 2, 6, 3, 7, 4};
        // 1 2 3 4 5 6 7
        int[][] commands={{2, 5, 3}, {4, 4, 1}, {1, 7, 3}};
        //System.out.println("command len"+commands.length);
        int[] answer = solution(array, commands);
        for(int i=0; i<answer.length; i++){
            System.out.print(answer[i]+" ");
        }
    }
}
