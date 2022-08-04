package Lv1Java;

/*
두개의 정수를 입력받아 그 사이의 모든 정수의 합을 구하시오.
https://programmers.co.kr/learn/courses/30/lessons/12912?language=java
*/

public class Lv1AddMethod {
    public static void main(String[] args) {
        int a = 5;
        int b = 10;
        long answer = solution(a,b);
        System.out.println(answer);
    }

    static long solution(int a, int b) {
        long answer = 0;
        if(a<=b){
            for(int i =a;i<=b;i++){
                answer+=i;
            }
        }else{
            for(int i =b;i<=a;i++){
                answer+=i;
            }
        }
        return answer;
    }
}
