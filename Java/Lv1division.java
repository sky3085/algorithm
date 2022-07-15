/**
 * Lv1division
 * https://school.programmers.co.kr/learn/courses/30/lessons/87389
 */
public class Lv1division {
    public static int solution(int n) {
        int answer = 0;
        for(int i=1; i<=n; i++){
            if(n%i==1){
                answer=i;
                break;
            }
        }
        return answer;
    }
    public static void main(String[] args) {
        int answer = solution(10);
        System.out.println(answer);
    }
    
}

