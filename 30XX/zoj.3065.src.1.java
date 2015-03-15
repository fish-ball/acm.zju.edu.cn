// 3885880	2015-03-15 11:09:35	Accepted	3065	Java	175	3806	呆滞的慢板

import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner in  = new Scanner(System.in);
        while(true) {
            int n = in.nextInt();
            if(n == 0) break;
            String[] words = new String[n];
            for(int i = 0; i < n; ++i) {
                words[i] = in.next();
            }
            int[] cnt = new int[27];
            String tiles = in.next();
            for(int i = 0; i < tiles.length(); ++i) {
                if(tiles.charAt(i) == '_') {
                    cnt[26] += 1;
                } else {
                    cnt[tiles.charAt(i) - 'A'] += 1;
                }
            }
            int ans = 0;
            for(int i = 0; i < n; ++i) {
                int[] c = cnt.clone();
                String s = words[i];
                boolean success = true;
                for(int j = 0; j < s.length(); ++j) {
                    int idx = (int)(s.charAt(j) - 'A');
                    if(c[idx] > 0) {
                        c[idx] -= 1;
                    } else if(c[26] > 0) {
                        c[26] -= 1;
                    } else {
                        success = false;
                        break;
                    }
                }
                if(success) ans += 1;
            }
            System.out.println(ans);
        }
    }
}
