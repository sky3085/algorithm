package Lv1Java;
// https://school.programmers.co.kr/learn/courses/30/lessons/12919

public class Lv1stringKim {
    public static String solution(String[] seoul) {
        String answer = "";
        for(int i=0; i<seoul.length; i++){
            if(seoul[i].equals("Kim")){
                answer = "김서방은 "+i+"에 있다";
            }
        }
        return answer;
    }
    public static void main(String[] args) {
        String[] seoul = {"java", "Kim"};
        String answer = solution(seoul);
        System.out.println(answer);
    }
}
