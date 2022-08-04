package Lv1Java;
import java.util.Arrays;

class Lv1IDcard {
    public static int solution(int[][] sizes) {
        int answer = 0;
        int maxW = 0;
        int maxH = 0;

        for (int i = 0; i < sizes.length; i++) {
            if(sizes[i][0] <= sizes[i][1]){
                if(maxW <=sizes[i][1]){
                    maxW = sizes[i][1];
                }
                if(maxH <= sizes[i][0]){
                    maxH = sizes[i][0];
                }
            }else{
                if(maxW <=sizes[i][0]){
                    maxW = sizes[i][0];
                }
                if(maxH <= sizes[i][1]){
                    maxH = sizes[i][1];
                }
            }
        }
        answer = maxH * maxW;
        return answer;
    }

    public static void main(String[] args) {
        int[][] sizes = {{1,2},{3,4},{4,4}};
        solution(sizes);
    }

    //다른 사람 풀이
    public int solution1(int[][] sizes) {
        return Arrays.stream(sizes).reduce((a, b) -> new int[]{
                Math.max(Math.max(a[0], a[1]), Math.max(b[0], b[1])), Math.max(Math.min(a[0], a[1]), Math.min(b[0], b[1]))
        }).map(it -> it[0] * it[1]).get();
    }

    //다른 사람 풀이2
    public int solution2(int[][] sizes) {
        int max = 0;
        int min = 0;
        for (int[] size : sizes) {
            int paramMax = Math.max(size[0], size[1]);
            int paramMin = Math.min(size[0], size[1]);

            if (paramMax > max) {
                max = paramMax;
            }

            if (paramMin > min) {
                min = paramMin;
            }
        }
        return max * min;
    }
}