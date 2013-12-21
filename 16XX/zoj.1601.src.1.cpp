// 2953132 2008-06-20 13:10:14 Accepted 1601 C++ 00:00.01 836K ���͵����� 

// ��һ��С���������ʽ���ƣ���ö�پͺã�O(n)
// ע�����㣺1-���ӷ�ĸ������ȡ�㣻 2-ҪԼ�ֵ���� 

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    
    double  x,  y,  eps;
    int     D,  N,  M,  T;
    
    while( cin >> x >> M ) {
        
        eps = 1e99;
        
        y = 1.0 / double ( M );
        if( eps > fabs( y - x ) ) {
            eps = fabs( y - x );
            N = 1;
            D = M; 
        }
        
        y = double( M );
        if( eps > fabs( y - x ) ) {
            eps = fabs( y - x );
            N = M;
            D = 1; 
        }
        
        for( int i = 1; i <= M; ++i ) {
            
            T = int( floor( double( i ) * x ) );
            
            if( T > M )
                break;
            
            if( T ) { 
                y = double( T ) / double ( i );
                if( eps > x - y ) {
                    N = T;
                    D = i;
                    eps = x - y;
                }
            }
            
            if( T + 1 <= M ) {
                y = double( T + 1 ) / double ( i );
                if( eps > y - x ) {
                    N = T + 1;
                    D = i;
                    eps = y - x;
                }
            }
            
        }
        
        cout << N << ' ' << D << endl;
        
    }
    
}
