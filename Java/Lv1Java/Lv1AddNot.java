package Lv1Java;

public class Lv1AddNot {
    public static void main(String[] args) {
        int[] numbers={1,2,3,4,5};
        System.out.println(solution(numbers));

    }
    public static int solution(int[] numbers) {
        int answer = 45;
        int sum=0;
        for(int i=0; i< numbers.length; i++){
            sum+=numbers[i];
        }
        answer-=sum;
        return answer;
    }
}
