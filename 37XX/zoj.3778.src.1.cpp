// 3783995	2014-09-30 19:04:33	Accepted	3778	C++	130	168	���͵�����
// ע��û��˵һ����Ҫ�������á�������һ����Ъһ��������һ���ӡ� 

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
