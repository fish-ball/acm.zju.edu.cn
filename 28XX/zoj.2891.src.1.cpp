// 2963126 2008-07-05 23:47:35 Accepted 2891 C++ 00:06.26 844K ���͵����� 

// bt++ ������
// ������ DFS��Ȼ����ö�ٳ��ȣ��Ӵ�С��
// Ȼ���б𣬱���������У�n!���ԣ���ǽ�ֹ�ĳ��� 
 
// ע�����⣺1. ��������������ƴ��
//           2. �������п�����ͬ�ĵط� 
 
#include <cstdio>
#include <bitset> 
#include <map> 
using namespace std; 

int     N,  tot_len,    len;
bool    C[250]; // ��ǽ�ֹ���� 
bitset<250> B;
map<int, int>   M; 

typedef map<int, int>::iterator Iter; 

// ǰ���ж����õ��Ǳ��� DP
// �ܹ����� 3 �����ӵģ����벿�ֺ��ܴﵽ 
//      B[len]��B[2*len]��B[3*len] 
bool pred() {
    return  B[len] && B[len * 2] && B[len * 3];
} 

// ��׼������x ����ʣ���������y ����ǰ���ӳ��� 
bool DFS( int x, int y ) {

    if( x == 0 )    return  true;
    
    for( Iter it = M.begin(); it != M.end(); ++it ) {
        // ����´�λ�ã���ջ�� 
        int tick = y + it -> first;
        if( !it -> second ) continue; 
        if( C[tick] )       continue;
        if( tick > len )    continue;
        if( y == 0 && tick == len ) continue;
        if( tick == len ) {
            --it -> second;
            if( DFS( x - 1, 0 ) ) {
                ++it -> second;
                return  true;
            }
            ++it -> second;
            continue;
        }
        C[tick] = true;
        --it -> second;
        if( DFS( x, tick ) ) {
            ++it -> second;
            C[tick] = false;
            return  true;
        }
        ++it -> second;
        C[tick] = false;
    }
    
    return  false;

} 

int main() {
    
    int T = 0; 
    
    while( scanf( "%d", &N ) && N ) {
        
        tot_len = 0; 
        M.clear();
        B.reset();
        B.set( 0 );
        
        for( int i = 0; i < N; ++i ) {
            int temp; 
            scanf( "%d", &temp );
            tot_len += temp;
            ++M[temp];
            B |= ( B << temp );
        }
        
        printf( "Case %d: ", ++T ); 
        
        bool    found = false; 
        
        for( len = tot_len / 3; len > M.begin() -> first; --len ) {
            
            // ǰ�ü�֦ 
            if( !pred() )  continue;
            
            memset( C, 0, sizeof( C ) );
            
            if( DFS( 3, 0 ) ) {
                found = true;
                printf( "%d\n", len );
                break; 
            }
        
        } 
        
        if( !found )    puts( "0" );
        
    }
    
} 

