// 3854608	2015-01-23 20:22:10	Accepted	3647	C++	50	11940	呆滞的慢板

#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long i64;
const int MAXN = 1002;

// 计算 C(k, 3) k 个点中取三个的组合数 
inline i64 ck3(i64 k) {
    return (k * (k-1) >> 1) * (k-2) / 3;
}

int gcd(int m, int n) {
    int r = 0;
    while(n) {
        r = m % n;
        m = n;
        n = r;
    }
    return m;
}

int A[MAXN][MAXN] = {};
i64 B[MAXN][MAXN] = {};
int CK3[MAXN] = {};

void init() {
    
    // 预处理计算组合数 
    for(int i = 0; i < MAXN; ++i) {
        CK3[i] = int(ck3(i));
    }
    // 计算 A 函数 DP 矩阵
    for(int i = 3; i < MAXN; ++i) {
        A[i][1] = i - 2;
    }
    for(int i = 1; i < MAXN; ++i) {
        for(int j = 2; j < MAXN; ++j) {
            A[i][j] = (A[i][j-1] << 1) - A[i][j-2] 
                    + (gcd(i-1, j-1)-1 << 1);
        }
    }
    // 计算 B 函数 DP 矩阵
    for(int i = 1; i < MAXN; ++i) {
        B[i][1] = B[1][i] = CK3[i];
    }
    for(int i = 2; i < MAXN; ++i) {
        for(int j = 2; j <= i; ++j) {
            B[i][j] = B[j][i] = B[i-1][j] * 2LL - B[i-2][j] + A[i][j];
        }
    }
    
}

int main() {
    
    init();

    int n, m;

    while(scanf("%d%d", &n, &m) != EOF) {
        
        n += 1;
        m += 1;
        
        printf("%lld\n", ck3(n*m) -B[m][n]);
        
    }

    return 0;

} 
