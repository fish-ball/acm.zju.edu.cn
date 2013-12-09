/* 3488118 2013-12-09 22:26:50 Accepted 3633 C++ 720 48020 呆滞的慢板

这题实际上是一道 RMQ，不过归约不是十分的明显：
1. 先预处理出一个数组，表示前一个与其相同的位置；
2. 然后对这个数组预处理 RMQ，用于查询区间最大值；
3. 每给定一个区间，查询的 RMQ 最大值即从右往左最先出现重复的位置；
4. 如果这个位置在 l 之后，说明有重复，输出该位置的数字；
5. 否则，说明在这个区间没用重复，输出 OK。
*/

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
using namespace std;

int n, m, a[500000];
int rmq[19][500000];

int bit_length(int b) {
    int ans = 0;
    while(b) {
        ++ans;
        b >>= 1;
    }
    return ans;
}

void rmq_build() {
    for(int i = 1; (1<<i) < n; ++i)
        for(int j = 0; j + (1<<i) <= n; ++j)
            rmq[i][j] = max(rmq[i-1][j], rmq[i-1][j+(1<<(i-1))]);
}

int rmq_query(int l, int r) {
    if(l == r) return -1;
    int len = bit_length(r - l) - 1;
    return max(rmq[len][l], rmq_query(l+(1<<len), r));
}

int main() {
    
    while(scanf("%d", &n) != EOF) {
        
        map<int, int> pre;
        memset(rmq, -1, sizeof(rmq));
        
        for(int i = 0, s = 0; i < n; ++i) {
            scanf("%d", a+i);
            map<int, int>::iterator it = pre.find(a[i]);
            if(it != pre.end()) rmq[0][i] = it->second;
            pre[a[i]] = i;
        }
        
        rmq_build();
        
        for(scanf("%d", &m); m--;) {
            int l, r, p;
            scanf("%d%d", &l, &r);
            p = rmq_query(l-1, r);
            if(p < l-1) puts("OK");
            else printf("%d\n", a[p]);
        }
        
        puts("");
        
    }
    
}
