// 2164775 2010-04-16 11:53:09 Accepted  3310 C++ 300 11904 ���͵����� 

// �������ڻ���0-1�������⣬ֻ��ֵ�һ���Ƿ�ѡ����DP���ɡ� 

#include <iostream>
#include <algorithm>
using namespace std;

int A[1000000], DP[2][1000000], N;

int main() {
    while(cin >> N) {
        for(int i = 0; i < N; ++i) scanf("%d", A + i);
        int ans = 0;
        // ��һ�飬ǿ�Ƶ�һ��ѡ��
        memset(DP, 0, sizeof(DP));
        DP[1][0] = A[0];
        for(int i = 1; i < N; ++i) {
            DP[0][i] = max(DP[0][i-1], DP[1][i-1]);
            DP[1][i] = max(DP[1][i-1], DP[0][i-1]+A[i]);
        }
        ans = DP[0][N-1];
        // �ڶ��飬ǿ�Ƶ�һ����ѡ
        memset(DP, 0, sizeof(DP));
        for(int i = 1; i < N; ++i) {
            DP[0][i] = max(DP[0][i-1], DP[1][i-1]);
            DP[1][i] = max(DP[1][i-1], DP[0][i-1]+A[i]);
        }
        ans = max(ans, max(DP[0][N-1], DP[1][N-1]));
        cout << ans << endl; 
    }
}
