// DP, O(N*K),�� iostream �ᳬʱ 
// �������ȫ���� K ���࣬Ȼ�� 
// ��һ�� K λ�� bool �� A�������ڵ� n ����֮����û���ܵ��������λ��
// ����һ�� K λ�� bool �� B��ÿ����һ���������࣬Ȼ����� A
// ��� A ��ĳλ�Ѿ�ռ�У�����λ ��/�� ������������ܵ����״̬�� B ���
// Ȼ�� B ���Ƶ� A
// ������ A �� 0 ��Ϊ true���� Divisible
// 2845273 2008-04-15 15:57:30 Accepted 2042 C++ 00:00.40 396K ���͵�����  

#include <cstring>
#include <cstdio>

int main() {
    int     T,  N,  K,  temp;
    bool    A[100], B[100];
    scanf( "%d", &T ); 
    while( T-- ) {
        scanf( "%d%d", &N, &K );
        memset( A, 0, sizeof( A ) );
        A[0] = true;
        for( int i = 0; i < N; i++ ) {
            memset( B, 0, sizeof( B ) );
            scanf( "%d", &temp ); 
            if( temp > 0 )  temp %= K;
            else    temp = -temp % K;
            for( int i = 0; i < K; i++ ) {
                if( A[i] ) {
                    B[(i+temp)%K] = true;
                    B[(i+K-temp)%K] = true;
                }
            }
            memcpy( A, B, sizeof( B ) );
        }
        if( A[0] )  puts( "Divisible" );
        else        puts( "Not divisible" );
        if( T ) puts( "" );
    }
}
