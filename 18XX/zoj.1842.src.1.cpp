// 2916444 2008-05-15 18:54:14 Accepted 1842 C++ 00:00.09 3416K ���͵����� 

// �����⣬��ǿ��ɸ������������ɸ��
// ֻҪɸ��������Ŀ�����ʣ�µľ�������
// ���������һ�� sqrt(2^31) ��Լ 65536 ��������Ȼ��
// ����ÿ�� L~U �����䣬ɸ�� sqrt(U) ֮�ڵ������ı������� 

#include <cstdio>
#include <cstring>

bool    isPrime[65540];
int     Prime[6544];
bool    diff[1000001];
int     top = 0,    N,  k;

int     segPrime[500000],   segTop;

int main() {
    
    memset( isPrime, 1, sizeof( isPrime ) );
    
    for( int i = 2; i < 258; ++i ) 
        if( isPrime[i] )
            for( int j = i + i; j < 65540; j += i )
                isPrime[j] = false;
    
    for( int i = 2; i < 65540; ++i )
        if( isPrime[i] )
            Prime[top++] = i;

    int     L,  U,  D;
    while( scanf( "%d%d", &L, &U ) != EOF ) {
        
        if( L == 1 )    ++L;
        D = U - L + 1;
        memset( diff, 1, D );
        
        segTop = 0;
        for( int j = 0; j < top && ( Prime[j] * Prime[j] ) <= U; ++j ) {
            k = Prime[j] - L % Prime[j];
            if( k == Prime[j] ) k = 0;
            if( k + L == Prime[j] )
                k += Prime[j];
            for( ; k <= D; k += Prime[j] )
                diff[k] = false;
        }
            
        for( int i = 0; i < D; ++i )
            if( diff[i] )   segPrime[segTop++] = L + i;

        if( segTop < 2 ) {
            puts( "There are no adjacent primes." );
            continue;
        }

        int minPos = 1, maxPos = 1, val;

        for( int i = 2; i < segTop; ++i ) {
            val = segPrime[i] - segPrime[i - 1];
            if( val < segPrime[minPos] - segPrime[minPos - 1] )
                minPos = i;
            if( val > segPrime[maxPos] - segPrime[maxPos - 1] )
                maxPos = i;
        }
        
        printf( "%d,%d are closest, %d,%d are most distant.\n",
            segPrime[minPos - 1], segPrime[minPos],
            segPrime[maxPos - 1], segPrime[maxPos] );

    }
    
}
