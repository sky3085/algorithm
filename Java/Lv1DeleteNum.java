import java.util.stream.IntStream;

//https://school.programmers.co.kr/learn/courses/30/lessons/12935

public class Lv1DeleteNum {
    public static int[] solution(int[] arr) {
        
	    if(arr.length==1){
            return new int[] {-1};
        }else{
            int min = IntStream.of(arr).min().getAsInt();
            return IntStream.of(arr).filter(i -> i != min).toArray();
        }
    }
    public static void main(String[] args) {
        int[] arr = {2,2,3,4,6};
        arr = solution(arr);
        for (int i = 0; i < arr.length; i++) {
            System.out.println(arr[i]);
        }
    }
    //다른 사람 풀이
    public int[] solution2(int[] arr) {
        if(arr.length == 1){
            int[] answer = {-1};
            return answer;
        }
  
        int[] answer = new int[arr.length-1];
        int minIndex=0;
  
        for(int i=0;i<arr.length;i++){
            if(arr[minIndex]>arr[i]){
                minIndex = i;
            }
        }
        for(int i=minIndex+1;i<arr.length;i++){
            arr[i-1] = arr[i];
        }
        for(int i=0;i<answer.length;i++){
            answer[i] = arr[i];
        }
        return answer;
    }
}
