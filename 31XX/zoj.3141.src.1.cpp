// 1867983 2009-05-14 02:00:21 Accepted  3141 C++ 430 340 ���͵����� 

// ���ɿ��������䣬�����������ܰ� M * N ���ɿ�������ȫ���������͵ġ�
// �� DP��DP[M][N] ��ʾ M * N ��Ҫ�Ĵ�����
// ��ô��ʼ�������� DP[i][i] = 0��
// ������������ DP[M][N] = min(DP[i][N] + DP[M-i][N] + 1, DP[M][j] + DP[M][N-j] + 1)��
// ���� 0<i<M��0<j<N���õݹ������ DP �ȽϷ��㡣 

#include <iostream>
#include <algorithm>
using namespace std;

int DP[201][201];

int eval(int M, int N) {
    if(DP[M][N] != INT_MAX) return DP[M][N];
    for(int i = 1; i < M; ++i)
        DP[M][N] = min(DP[M][N], eval(i, N) + eval(M - i, N) + 1);
    for(int i = 1; i < N; ++i)
        DP[M][N] = min(DP[M][N], eval(M, i) + eval(M, N - i) + 1);
    return DP[M][N];
}

int main() {
    for(int i = 0; i <= 200; ++i)
        for(int j = 0; j <= 200; ++j)
            if(i == j) DP[i][j] = 0;
            else DP[i][j] = INT_MAX;
    int T, M, N;
    for(cin >> T; T--;) {
        cin >> M >> N;
        cout << eval(M, N) << endl;
    }
}
