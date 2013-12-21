// 3069105 2008-09-14 01:55:21 Accepted 2067 C++ 00:00.37 888K ���͵����� 

// ����ÿ������ͬ�����������İ׸���������������
// Ȼ���� O(n^3) ��ö�� 

#include <iostream>
using namespace std;

char    C[100][101];
int     DP[100][101],   N;

int main() {
    
    while(cin >> N) {
        memset(DP, 0, sizeof(DP));
        for(int i = 0; i < N; ++i) {
            cin >> C[i];
            for(int j = N - 1; j >= 0; --j) {
                if(C[i][j] == '.')
                    DP[i][j] = 1 + DP[i][j+1];
            }
        }
        int cnt = 0;
        for(int i = 0; i < N; ++i) {
            for(int j = 0; j < N; ++j) {
                int mn = DP[i][j];
                for(int k = i; k < N && DP[k][j] > 0; ++k) {
                    mn <?= DP[k][j];
                    cnt += mn;
                }
            }
        }
        cout << cnt << endl;
    }
    
}
