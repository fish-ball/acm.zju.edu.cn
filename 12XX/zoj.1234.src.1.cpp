// 3022794 2008-08-05 14:53:37 Accepted 1234 C++ 00:00.77 20580K ���͵����� 

// DP��DP[K][N]��Ҫ��� K ����ӣ�һ���� N �� 
// L[N] �ǿ��ӵĳ��� 
// DP[i][j] �����õ� j ���Ժ�Ŀ������ i ����ӵ���С���� 
// DP[0][?] = 0
// DP[i][j] = min(DP[i][j+1], (L[j+1]-L[j])^2 + DP[i-1][j+2]); 
// ע������ (0 <= j <= N-3*i)

// ���ս��Ϊ DP[K][0];

#include <iostream>
#include <algorithm>
using namespace std;

#define clr(x) memset(x, 0, sizeof(x))

int T, N, K, A[5000];

int DP[1009][5000], V[5000];

int getVal(int index) {
    return (A[index + 1] - A[index])*
            (A[index + 1] - A[index]);
}

int main() {

    for (cin >> T; T--;) {

        cin >> K >> N;
        K += 8;

        for(int i = 0; i < N; ++i )
            cin >> A[i];

        for (int i = 0; i < N - 1; ++i)
            V[i] = (A[i + 1] - A[i])*(A[i + 1] - A[i]);

        clr(DP[0]);
        
        for (int i = 1; i <= K; ++i) {
            DP[i][N - 3 * i + 1] = INT_MAX;
            for (int j = N - 3 * i; j >= 0; --j) {
                DP[i][j] = DP[i][j + 1];
                DP[i][j] <?= DP[i - 1][j + 2] + V[j];
            }
        }

        cout << DP[K][0] << endl;

    }

}
