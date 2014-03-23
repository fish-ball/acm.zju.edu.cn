// 3566763 2014-03-24 01:42:18 Accepted 3702 C++ 20 31420 ´ôÖÍµÄÂý°å

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int SZ[1000000] = {};
int buf[5000000] = {};
int* cur = buf;
int* L[1000000];

int main() {

    for(int t = 1; t < 1000000; ++t) {
        int len = 0;
        L[t] = cur;
        cur[len++] = 1;
        cur[len++] = t;
        for(int i = 2; i <= 20; ++i) {
            int p = cur[i-1] + cur[i-2];
            if(p >= 1000000) break;
            cur[len++] = p;
        }
        SZ[t] = len;
        cur += len;
    }
    
    int T;

    for(scanf("%d", &T); T--;) {
        
        int i, g, j;
        scanf("%d%d%d", &i, &g, &j);
        
        int l = 0, r = 1000000, m;
        
        while(l + 1 < r) {
            m = l + r >> 1;
            if(SZ[m] <= i || L[m][i] > g) r = m;
            else l = m;
        }
        
        if(SZ[l] > i && L[l][i] == g) {
            long long p[21] = {1, l};
            for(int jj = 2; jj <= j; ++jj) {
                p[jj] = p[jj-1] + p[jj-2];
            }
            printf("%lld\n", p[j]);
        }
        else puts("-1");
        
    }

}
