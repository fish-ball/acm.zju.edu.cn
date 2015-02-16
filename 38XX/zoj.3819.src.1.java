// 3869377	2015-02-16 23:23:47	Accepted	3819	Java	224	5050	呆滞的慢板
import java.util.*;

public class Main {

    public static void main(String[] args) {

        Scanner in = new Scanner(System.in);

        for(int t = in.nextInt(); t > 0; t--) {

            int m = in.nextInt();
            int n = in.nextInt();

            int sum1 = 0;
            for(int i = 1; i < m; ++i) {
                int x = in.nextInt();
                sum1 += x;
            }
            int answerMax = (sum1 - 1) / (m - 1);

            int sum2 = 0;
            for(int i = 0; i < n; ++i) {
                int x = in.nextInt();
                sum2 += x;
            }
            int answerMin = sum2 / n + 1;

            System.out.println(answerMin + " " + answerMax);

        }
    }

}
