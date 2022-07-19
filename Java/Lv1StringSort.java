import java.util.Arrays;
//https://school.programmers.co.kr/learn/courses/30/lessons/12917
public class Lv1StringSort {
    public static void main(String[] args) {
        String a = solution("abcksdjfaaas");
        System.out.println(a);
    }
    public static String solution(String s) {
        char[] stringChar = s.toCharArray();
        Arrays.sort(stringChar);
        StringBuilder answer = new StringBuilder(new String(stringChar,0,stringChar.length)).reverse();
        
        return answer.toString();
    }
}
