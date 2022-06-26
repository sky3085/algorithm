import java.util.ArrayList;
import java.util.List;

//https://programmers.co.kr/learn/courses/30/lessons/42840?language=java
//수포자 3명의 모의고사 채점

public class Lv1score {
    public static void main(String[] args) {
        int[] answers = {1,2,3,4,5};
        int[] answer = solution(answers);
        
        System.out.println(answer);
    }

    public static int[] solution(int[] answers) {
        int[] answer = {};
        int[] person1 = {1,2,3,4,5};
        int[] person2 = {2,1,2,3,2,4,2,5};
        int[] person3 = {3,3,1,1,2,2,4,4,5,5};

        int score1=0, score2 =0, score3 =0;
        
        for(int i =0; i<answers.length; i++){
            if(person1[i%person1.length] == answers[i]) score1++;
            if(person2[i%person2.length] == answers[i]) score2++;
            if(person3[i%person3.length] == answers[i]) score3++;
        }

        int max = Math.max(Math.max(score1, score2),score3);

        ArrayList<Integer> list = new ArrayList<Integer>();
        if(max==score1) list.add(1);
        if(max==score2) list.add(2);
        if(max==score3) list.add(3);

        answer = new int[list.size()];
        
        for(int i =0; i<answer.length; i++) {
        	answer[i] = list.get(i);
        }
        
        return answer;
    }

    //다른사람 풀이
    public static int[] solution2(int[] answers) {
        int[][] patterns = {
                {1, 2, 3, 4, 5},
                {2, 1, 2, 3, 2, 4, 2, 5},
                {3, 3, 1, 1, 2, 2, 4, 4, 5, 5}
        };

        int[] hit = new int[3];
        for(int i = 0; i < hit.length; i++) {
            for(int j = 0; j < answers.length; j++) {
                if(patterns[i][j % patterns[i].length] == answers[j]) hit[i]++;
            }
        }

        int max = Math.max(hit[0], Math.max(hit[1], hit[2]));
        List<Integer> list = new ArrayList<>();
        for(int i = 0; i < hit.length; i++)
            if(max == hit[i]) list.add(i + 1);

        int[] answer = new int[list.size()];
        int cnt = 0;
        for(int num : list)
            answer[cnt++] = num;
        return answer;
    }
}
