// 1664598 2008-10-12 18:56:03 Accepted  1883 C++ 0 200 ���͵����� 

// �� DP�����Գ���Ϊ n����������� k �Ĵ��� (k+1)^n ���� 
// ��ôֻ����� tight ���ж��ٸ����У������Ļ��Ϳ��� DP �ˡ� 

#include <iostream>
using namespace std;

double DP[10][100], ANS[10][100];

int main() {
    for(int k = 0; k < 10; ++k) {
        memset(DP, 0, sizeof(DP));
        for(int i = 0; i <= k; ++i)
            DP[i][0] = 1.0;
        for(int i = 0; i < 99; ++i) {
            for(int j = 0; j <= k; ++j) {
                if(j > 0) DP[j-1][i+1] += DP[j][i];
                if(j < k) DP[j+1][i+1] += DP[j][i];
                DP[j][i+1] += DP[j][i];
            }
        }
        for(int i = 0; i < 100; ++i) {
            ANS[k][i] = 0;
            for(int j = 0; j <= k; ++j)
                ANS[k][i] += DP[j][i];
            for(int j = 0; j <= i; ++j)
                ANS[k][i] /= double(k+1);
        }
    }
    int n, k;
    while(cin >> k >> n)
        printf("%.5lf\n", ANS[k][n-1] * 100.0);
}
