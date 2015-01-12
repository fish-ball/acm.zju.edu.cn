// 3848884	2015-01-12 23:42:51	Accepted	1464	C++	10	168	呆滞的慢板

// 二分结果，暴力判断，10000*log(10000) 

#include <cstdio>
#include <cstring>

int main() {
    
    int T, L[10000];
    
    for(scanf("%d", &T); T--;) {
        int N, K;
        scanf("%d%d", &N, &K);
        
        int l = 0, r = 0;
        for(int i = 0; i < N; ++i) {
            int a, b;
            scanf("%d.%d", &a, &b);
            L[i] = a*100 + b;
            if(L[i] > r) r = L[i];
        }
        
        while(l < r - 1) {
            int m = l + r >> 1;
            int k = 0;
            for(int i = 0; i < N && k < K; ++i) {
                k += L[i] / m;
            }
            if(k < K) r = m;
            else l = m;
        }
        
        printf("%0d.%02d\n", l / 100, l % 100);
    }
}
