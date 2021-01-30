package programmers;

import java.util.Arrays;

public class Songgyubin_greedy {
    public static void main(String[] args) {


        int[] a = {70, 80, 50, 50};
//        int[] a = {70, 80, 50};
        int limit = 100;

        System.out.println(solution(a, limit));
    }

    public static int solution(int[] people, int limit) {
        int answer = 0;
        Arrays.sort(people);
        int lastIndex = people.length - 1;
        int tmp = 0;

        for (int max = lastIndex; tmp <= max; max--) {
            if (people[tmp] + people[max] <= limit) tmp++;
            answer++;
        }

        return answer;
    }
}
