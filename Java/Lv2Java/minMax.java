import java.util.*;
//https://school.programmers.co.kr/learn/courses/30/lessons/12939
public class minMax {
    public String solution(String s) {
        StringBuilder answer = new StringBuilder();
        //문자열 나누기
        String[] a = s.split(" ");
        //나눈 문자열 정수형 리스트에 저장
        int[] b = new int[a.length];
        for(int i=0; i<a.length; i++){
            b[i]=Integer.parseInt(a[i]);
        }
        //정렬
        Arrays.sort(b);
        //맨앞 인덱스 맨뒤인덱스 문자열 합치기
        answer.append(Integer.toString(b[0]));
        answer.append(" ");
        answer.append(Integer.toString(b[b.length-1]));
        return answer.toString();
    }

}
