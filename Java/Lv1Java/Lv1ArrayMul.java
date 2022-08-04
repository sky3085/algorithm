package Lv1Java;

/*
https://programmers.co.kr/learn/courses/30/lessons/70128
두 배열을 받아 같은 인덱스 번호끼리 곱하여 나온 값을 더하는 문제입니다.
*/

public class Lv1ArrayMul {
    public static void main(String[] args) {
        int[] a = {1,3,9,-1};
        int[] b = {3,1,0,-1};
        int result = solution(a, b);
        System.out.println(result);
    }

    public static int solution(int[] a, int[] b) {
        int answer = 0;
        
        for(int i=0; i<a.length; i++){
            int temp = a[i]*b[i];
            answer += temp;
        }
        
        return answer;
    }
}
