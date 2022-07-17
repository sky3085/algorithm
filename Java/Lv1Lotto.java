import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

//https://school.programmers.co.kr/learn/courses/30/lessons/77484/solution_groups?language=java

public class Lv1Lotto {
    public static int[] solution(int[] lottos, int[] win_nums) {
        int[] answer = {0,0};
        
        int temp = 0;
        int cnt_zero = 0;

        Arrays.sort(lottos);// 1 3 4 5 6
        Arrays.sort(win_nums);// 1 3 4 5 6
        for (int i = 0; i < 6; i++) {
            if(lottos[i]==0){
                cnt_zero++;
            }else{
                break;
            }
        }
        for(int j=0;j<6;j++){
            for(int i=0; i<6; i++){
                if(lottos[j]==win_nums[i]){
                    ++temp;
                }
            }
        }
        switch (temp) {
            case 6:
                answer[1]=1;
                answer[0]=1;    
                break;
            case 5:
                answer[1]=2;
                answer[0]=2;
                if(cnt_zero>0){
                    for (int i = 0; i < cnt_zero; i++) {
                        --answer[0];
                    }
                }
                break;
            case 4:
                answer[1]=3;
                answer[0]=3;
                if(cnt_zero>0){
                    for (int i = 0; i < cnt_zero; i++) {
                        --answer[0];
                    }
                }
                break;
            case 3:
                answer[1]=4;
                answer[0]=4;
                if(cnt_zero>0){
                    for (int i = 0; i < cnt_zero; i++) {
                        --answer[0];
                    }
                }
                break;
            case 2:
                answer[1]=5;
                answer[0]=5;
                if(cnt_zero>0){
                    for (int i = 0; i < cnt_zero; i++) {
                        --answer[0];
                    }
                }
                break;
            case 1:
                answer[1]=6;
                answer[0]=6;
                if(cnt_zero>0){
                    for (int i = 0; i < cnt_zero; i++) {
                        --answer[0];
                    }
                }
                break;
            default:
                answer[1]=6;
                answer[0]=6;
                if(cnt_zero>0){
                    for (int i = 0; i < cnt_zero; i++) {
                        if(i==0){
                            continue;
                        }
                        answer[0]-=1;
                    }
                }
                break;
        }
        return answer;
    }
    public static void main(String[] args) {
        int[] lottos = {44,1,0,0,31,25};
        int[] win_nums = {31,10,45,1,6,19};
        int[] answer = solution(lottos, win_nums);
        for (int i = 0; i < answer.length; i++) {
            System.out.println(i+" : "+answer[i]);
        }
    }
    //다른사람 풀이
    public int[] solution2(int[] lottos, int[] win_nums) {
        Map<Integer, Boolean> map = new HashMap<Integer, Boolean>();
        int zeroCount = 0;

        for(int lotto : lottos) {
            if(lotto == 0) {
                zeroCount++;
                continue;
            }
            map.put(lotto, true);
        }


        int sameCount = 0;
        for(int winNum : win_nums) {
            if(map.containsKey(winNum)) sameCount++;
        }

        int maxRank = 7 - (sameCount + zeroCount);
        int minRank = 7 - sameCount;
        if(maxRank > 6) maxRank = 6;
        if(minRank > 6) minRank = 6;

        return new int[] {maxRank, minRank};
    }
}
