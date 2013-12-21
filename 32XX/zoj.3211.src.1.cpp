// 1882468 2009-05-24 01:32:15 Accepted  3211 C++ 50 184 ���͵����� 

// DP���������������Ŀ������б��� b[i] <= b[j]���� i < j��
// ��ˣ��ȶ� b[1..N] ����Ȼ������ DP ��������Ӷ� O(N*K)�� 

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    
    int T, N, K;

    vector<pair<int, int> > V;
    
    // DP[i][j] ��ʾȡ���� i ����ʱ��¼ȡ j �õ����ֵ�� 
    int DP[251][251];

    for(cin >> T; T--;) {
        cin >> N >> K;
        V.resize(N);
        for(int i = 0; i < N; ++i)
            scanf("%d", &V[i].second);
        for(int i = 0; i < N; ++i)
            scanf("%d", &V[i].first);
        sort(V.begin(), V.end());
        memset(DP, -1, sizeof(DP));
        DP[0][0] = 0;
        for(int i = 0; i < N; ++i) {
            for(int j = 0; j < K; ++j) {
                if(DP[i][j] != -1) {
                    DP[i+1][j] = max(DP[i+1][j], DP[i][j]);
                    DP[i+1][j+1] = max(DP[i+1][j+1], DP[i][j] + V[i].second + j * V[i].first);
                }
            }
        }
        printf("%d\n", DP[N][K]);
    }
}
