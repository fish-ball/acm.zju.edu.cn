// 3037112 2008-08-15 20:59:03 Accepted 2316 C++ 00:01.15 880K ���͵����� 

// ��ϸ����һ�¾��У��Ǹ�������⣬�ø�������Ķȿ���ѹ��

// ����Ǹ�����ȵ�ƽ���� 

#include <iostream>
using namespace std;

int A[10001],   T,  N,  M,  x,  y,  tot;

int main() {
    
    for( cin >> T; T--; ) {
        
        memset( A, 0, sizeof( A ) );

        for( cin >> M >> N; N--; ) {
            scanf( "%d%d", &x, &y );
            ++A[x];
            ++A[y];
        }
        
        for( int i = tot = 0; i <= M; ++i )
            tot += A[i] * A[i];
            
        cout << tot << endl;
        
        if( T ) puts( "" );
        
    }
    
}
