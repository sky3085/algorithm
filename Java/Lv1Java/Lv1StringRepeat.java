package Lv1Java;
/**
 * https://school.programmers.co.kr/learn/courses/30/lessons/12922
 */
public class Lv1StringRepeat {
    public static String solution(int n) {
        String answer = "";

        for (int i = 0; i < n; i++) {
            if(i%2==0){
                answer = answer.concat("수");
            }else{
                answer = answer.concat("박");
            }
        }

        return answer;
    }

    public static void main(String[] args) {
        String answer = solution(3);
        System.out.println(answer);
    }
    
}