// 4387438	2018-11-16 14:11:34	Accepted	4025	C++	180	184	呆滞的慢板

/**
 * 简单题
 * 只需要做两个数列的差分，找出出现最多的数字次数即可。
 * 注意时间要求比较高，计数用 map 会超时。
 */

#include <cstring>
#include <cstdio>
#include <map>
using namespace std;

int main() {
    int t, n, a[100010], b, m[400050];
    for (scanf("%d", &t); t--;) {
        scanf("%d", &n);
        memset(m, 0, sizeof(m));
        int mx = 0;
        for (int i = 0; i < n; ++i) scanf("%d", a+i);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &b);
            int x = a[i] - b + 200010;
            m[x] += 1;
            if (m[x] > mx) mx = m[x];
        }
        printf("%d\n", mx);
    }
    return 0;
}