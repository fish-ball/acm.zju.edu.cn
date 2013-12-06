#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

bool B[201];

inline int f(int x) {
    return !x || B[x] ? 0 : (B[x] = true);
}

int cal(int x, int y, int z) {
    memset(B, 0, sizeof(B));
    return f(x) + f(y) + f(z) +
        f(abs(x-y)) + f(abs(x-z)) + f(abs(y-z)) +
        f(abs(x+y)) + f(abs(x+z)) + f(abs(y+z)) +
        f(abs(x+y+z)) + f(abs(x-y+z)) + f(abs(x+y-z)) +
        f(abs(x-y-z));
}

int main() {
    
    int T, x, y;

    for(scanf("%d", &T); T--;) {
        
        scanf("%d%d", &x, &y);
        
        int ans = 0;
        for(int i = 1; i < x; ++i) ans = max(ans, cal(i, x-i, y));
        for(int i = 1; i < y; ++i) ans = max(ans, cal(i, y-i, x));
        
        printf("%d\n", ans);
        
    }

}
