// 2903488 2008-05-10 12:52:56 Accepted 2150 C++ 00:00.14 440K ���͵����� 

// ֱ�Ӹ�����ˣ������� pow Ҫд�� O(logn)��

#include <cstdio>

int     M;

int Pow( const int& x, const int& y ) {
    if( y == 0 )    return  1;
    if( y == 1 )    return  x;
    int     p2 = Pow( x, y / 2 );
    if( y % 2 )     return  ( x * ( ( p2 * p2 ) % M ) ) % M;
    else            return  ( p2 * p2 ) % M;
}


int main() {

    int Z,  N,  x,  y,  ans;
    
    for( scanf( "%d", &Z ); Z--; ) {
        
        ans = 0;
        for( scanf( "%d%d", &M, &N ); N--; ) {
            scanf( "%d%d", &x, &y );
            ans += Pow( x % M, y );
            ans %= M;
        }
        
        printf( "%d\n", ans );
        
    } 
    
}
