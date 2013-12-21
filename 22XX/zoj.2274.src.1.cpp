// 1661472 2008-10-09 10:44:03 Accepted  2274 C++ 980 2384 ���͵����� 

// �ñ�̬��һֱ�������Ż�һ����������
// ����һ��ͼ�ڽӾ��� X[1..N][1..N]��X[i][j] ��ʾ A[i] A[j] �Ƿ��� 
// ͬʱ����һ���ڽӱ�� X[i][j]==true �Ĳ��� �� X[i][j]==false �Ĳ��� 
// Ȼ��ö�ٶ��� i�����ڽӱ���ö���������� j,k�����ڽӾ��� j,k �Ƿ����� 
 

#include <iostream>
using namespace std;

bool X[500][500];

int N, A[500];

int P[500][500], Q[500][500];

int gcd(int m, int n) {
    if(n == 0) return m;
    return gcd(n, m%n);
}

int main() {
    while(scanf("%d", &N) != EOF) {
        memset(P, 0, sizeof(P));
        memset(Q, 0, sizeof(Q));
        for(int i = 0; i < N; ++i) {
            scanf("%d", A+i);
            for(int j = 0; j < i; ++j) {
                X[i][j] = X[j][i] = 
                    gcd(A[i], A[j]) == 1;
                if(X[i][j]) P[j][++P[j][0]] = i;
                else        Q[j][++Q[j][0]] = i;
            }
        }
        int ans = 0;
        int SZ, *bg;
        for(int i = 0; i < N; ++i) {
            SZ = (bg=P[i])[0];
            for(int j = 1; j <= SZ; ++j)
                for(int k = j + 1; k <= SZ; ++k)
                    if(X[bg[j]][bg[k]]) ++ans;
            SZ = (bg=Q[i])[0];
            for(int j = 1; j <= SZ; ++j)
                for(int k = j + 1; k <= SZ; ++k)
                    if(!X[bg[j]][bg[k]]) ++ans;
        }
        printf("%d\n", ans);
    }
}
