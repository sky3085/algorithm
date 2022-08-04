package Lv1Java;
/**
 * https://school.programmers.co.kr/learn/courses/30/lessons/82612
 */
public class Lv1Calc {
    public static long solution(int price, int money, int count) {

        long total = 0;
        for(int i=1; i<=count; i++){
            total += (price*i);
        }
        if(total>money){
            return total-money;
        }else{
            return 0;
        }
        
    }
    public static void main(String[] args) {
        long a = solution(3, 20, 4);
        System.out.println(a);
    }
    
}