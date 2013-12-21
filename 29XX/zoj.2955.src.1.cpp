// 2955074 2008-06-23 01:10:37 Accepted 2955 C++ 00:00.08 876K ���͵����� 

// �ܺõ������⣬���ȣ��� 10000 ���ڵĽ�� DP ����
// ���������ԣ���� DP[i] Ϊ����������������Ϊ -1 
// ö�� i = 1~10000
// ���п���ѡ�����Ϊ SC[j]
// ��� DP[i-SC[j]] ���� -1����ôˢ�����ֵΪ��С�� DP[i-SC[j]] + 1
// �����Ҫ������Ҫ 10000 * 100 ������

// Ȼ�� N > 10000 ��ʱ��ö�� x = 1~10000
// �� N ��ʾ�� N = k * x + y (k = N / x, y = N % x)
// ��ʱ�򣬹���Ҫ k * DP[x] + DP[y] ��
// Ȼ��ö�� x = 1~10000��ȡ����ֵ����

// ����Ϊʲô 10000 ���ھͱ�֤�㷨��ȷ...���û֤��...�����ǿ���֤����... 

#include <iostream>
#include <algorithm>
using namespace std;

int     DP[10001];
int     SC[100],    M,  N,  T;

int main() {
    
    for( cin >> T; T--; ) {
        
        memset( DP, -1, sizeof( DP ) );
        DP[0] = 0;
        
        cin >> M >> N;
        int top = min( N, 10000 );
        
        for( int i = 0; i < M; ++i )
            cin >> SC[i];
        
        sort( SC, SC + M );
        
        for( int i = 1; i <= top; ++i ) {
            for( int j = 0; j < M; ++j ) {
                if( i < SC[j] )    break;
                if( DP[i-SC[j]] != -1 ) {
                    if( DP[i] == -1 || DP[i] > DP[i-SC[j]] + 1 )
                        DP[i] = DP[i-SC[j]] + 1;
                }
            }
        }
        
        if( N <= 10000 ) {
            cout << DP[N] << endl;
            continue;
        }
        
        int ans = -1;
        for( int i = 1; i <= 10000; ++i ) {
            if( DP[i] != -1 && DP[N % i] != -1 ) {
                if( ans == -1 || ans > ( N / i ) * DP[i] + DP[N % i] ) 
                    ans = ( N / i ) * DP[i] + DP[N % i];
            }
        }
        
        cout << ans << endl;
        
    }
    
}
