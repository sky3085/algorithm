package Lv1Java;
//https://school.programmers.co.kr/learn/courses/30/lessons/12903

public class Lv1StringIndex {
    public static String solution(String s) {
        String answer = "";
        int indexSize = s.length();
        if(indexSize%2==0){
            answer = s.substring(indexSize/2-1, indexSize/2+1);
        }else{
            answer = s.substring(indexSize/2, indexSize/2+1);
        }
        
        return answer;
    }
    public static void main(String[] args) {
        String a = solution("abcdef");
        String b = solution("abcde");
        System.out.println(a);
        System.out.println(b);
    }
    //다른 사람 풀이

    String getMiddle(String word){

        return word != null ? word.substring((word.length()-1)/2,(word.length()+2)/2) : "";
      }
}
