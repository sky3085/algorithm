package Lv1Java;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
 * https://school.programmers.co.kr/learn/courses/30/lessons/12910
 */
public class Lv1ArrayDiv {

    public static int[] solution(int[] arr, int divisor) {
        List<Integer> a = new ArrayList<Integer>();
        for (int i : arr) {
            if(i%divisor==0){
                a.add(i);
            }
        }
        if(a.size() == 0){
            a.add(-1);
        }
        int[] answer = a.stream().mapToInt(i->i).toArray();
        Arrays.sort(answer);
        return answer;
    }

    public static void main(String[] args) {
        
    }
//다른 사람 풀이 단, 길이가 0일때 조건이 없습니다.
    public int[] divisible(int[] array, int divisor) {
        //ret에 array에 포함된 정수중, divisor로 나누어 떨어지는 숫자를 순서대로 넣으세요.
        return Arrays.stream(array).filter(factor -> factor % divisor == 0).toArray();
    }
}