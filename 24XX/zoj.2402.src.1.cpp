// 2946345 2008-06-09 23:06:33 Accepted 2402 C++ 00:00.12 1008K ���͵����� 

// ����� N * M �� DP��long long �͹������ô���
// DP[n][m]��n Ϊ�������ȣ�m Ϊĩβ����ֵ��DP ��ʾ����Ϊ n���� m ��β�����и��� 

#include <iostream>
using namespace std;

typedef long long BigNum;

int         T,  M,  N;

BigNum      DP[11][2001];

int main() {
    
    cin >> T;
    
    for( int t = 1; t <= T; ++t ) {
    
        cin >> N >> M;
        
        memset( DP, 0, sizeof( DP ) );
        
        for( int i = 1; i <= M; ++i )
            DP[1][i] = 1;
            
        for( int i = 2; i <= N; ++i )
            for( int j = 1 << (i - 1); j <= M >> ( N - i ); ++j )
                for( int k = 1; k <= j >> 1; ++k )
                    DP[i][j] += DP[i-1][k];
        
        BigNum  ans = 0;
        for( int i = 1; i <= M; ++i )
            ans += DP[N][i];
        
        cout << "Case " << t
             << ": n = " << N
             << ", m = " << M
             << ", # lists = " << ans
             << endl;
    
    }
    
}
