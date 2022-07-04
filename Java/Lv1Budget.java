import java.util.Arrays;

/**
 * Lv1Budget
 * https://programmers.co.kr/learn/courses/30/lessons/12982
 */
public class Lv1Budget {
    public static int solution(int[] d, int budget) {
        int answer = 0;
        Arrays.sort(d);
        for (int i : d ) {
            if(budget >= i){
                budget -= i;
                answer++;
            }
        }

        return answer;
    }

    public static void main(String[] args) {
        int[] d = {2,2,3,3};
        int budget = 10;
        int answer = solution(d, budget);
        System.out.println(answer);
    }
    
}