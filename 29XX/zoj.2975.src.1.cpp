// 2922839 2008-05-19 15:59:21 Accepted 2975 C++ 00:00.08 916K ���͵����� 

// Brute Force, TLE
// �����ĳ��� bitset λ���㣬���˰��ף���

#include <iostream>
#include <bitset>
using namespace std;

char    A[250][251];
const char Figure[5] = { 'B', 'J', 'H', 'Y', 'N' };
bitset<250> B[250];
int         T,  M,  N;
long long   cnt,    temp;


int main() {
    
    for( cin >> T; T--; ) {
    
        cin >> M >> N >> ws;
        
        for( int i = 0; i < M; ++i )
            gets( A[i] );
        
        cnt = 0;
        
        for( int fig = 0; fig < 5; ++fig ) {
            
            for( int i = 0; i < M; ++i ) {
                B[i].reset();
                for( int j = 0; j < N; ++j ) {
                    if( A[i][j] == Figure[fig] )
                        B[i].set( j );
                }
            }
            
            for( int i = 1; i < M; ++i ) {
                for( int j = 0; j < i; ++j ) {
                    temp = ( B[i] & B[j] ).count();
                    cnt += temp * ( temp - 1 ) / 2;
                }
            }
            
        }
        
        cout << cnt << endl;
    
    }
    
}
