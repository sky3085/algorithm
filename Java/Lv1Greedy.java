import java.util.Arrays;

//https://school.programmers.co.kr/learn/courses/30/lessons/42862
public class Lv1Greedy {
    public static int solution(int n, int[] lost, int[] reserve) {
        int answer = n-lost.length;

        Arrays.sort(lost);
        Arrays.sort(reserve);

        for (int i = 0; i < reserve.length; i++) {
            for (int j = 0; j < lost.length; j++) {
                if(reserve[i] == lost[j]){
                    answer++;
                    lost[i] = -1;
                    reserve[j] = -1; 
                    break; 
                }
            }    
        }
        
        for (int i = 0; i < lost.length; i++) {
            for(int j=0; j<reserve.length; j++){
                if(lost[i] == (reserve[j]-1)){
                    answer += 1;
                    reserve[j]=-1;
                    break;
                } else if(lost[i]== (reserve[j]+1)){
                    answer += 1;
                    reserve[j]=-1;
                    break;
                }
            }
        }

        return answer;
    }

    public static void main(String[] args) {
        int[] lost = {2, 4};
        int[] reserve = {1,3,5};
        System.out.println(solution(5, lost, reserve));  
    }
    //다른 사람 풀이
    public int solution2(int n, int[] lost, int[] reserve) {
        int[] people = new int[n];
        int answer = n;

        for (int l : lost) 
            people[l-1]--;
        for (int r : reserve) 
            people[r-1]++;

        for (int i = 0; i < people.length; i++) {
            if(people[i] == -1) {
                if(i-1>=0 && people[i-1] == 1) {
                    people[i]++;
                    people[i-1]--;
                }else if(i+1< people.length && people[i+1] == 1) {
                    people[i]++;
                    people[i+1]--;
                }else 
                    answer--;
            }
        }
        return answer;
    }
}
