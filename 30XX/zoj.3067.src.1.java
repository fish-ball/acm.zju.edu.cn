// 3885896	2015-03-15 11:28:41	Accepted	3067	Java	233	2883	呆滞的慢板

import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        while(true) {
            int n = in.nextInt();
            if(n == 0) break;
            int[] a = new int[n];
            int x = 0, ans = 0;
            for(int i = 0; i < n; ++i) {
                a[i] = in.nextInt();
                x ^= a[i];
            }
            if(x > 0) {                
                for(int i = 0; i < n; ++i) {
                    if((a[i] ^ x) <= a[i]) ans += 1;
                }
            }
            System.out.println(ans);
        }
    }
};
