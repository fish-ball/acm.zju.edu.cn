// 3783995	2014-09-30 19:04:33	Accepted	3778	C++	130	168	呆滞的慢板
// 注意没有说一道菜要连续做好。可以做一分钟歇一分钟再做一分钟。 

#include <cstdio>
#include <set>
#include <algorithm>
using namespace std;

int main() {
    
    int T;
    for(scanf("%d", &T); T--;) {
        int N, M;
        scanf("%d%d", &N, &M);
        int A[40000], S = 0;
        for(int i = 0; i < N; ++i) {
            scanf("%d", A + i);
            S += A[i];
        }
        sort(A, A + N);
        printf("%d\n", max((S-1)/M+1, A[N-1]));
    }
    
}
