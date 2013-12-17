// 3009389 2008-07-27 20:56:53 Accepted 1319 C++ 00:01.41 672K ���͵����� 

//     ��box�����ݰ��������˳���ŵ�array�С����ǿ���u(N)����GET������
// �൱����array��ǰu(N) ��Ԫ������i-minimumԪ�ء����array��ǰu(N)��Ԫ
// �ذ�����������ˣ���ôֻҪȡarray[i]�����ˡ�
//     ���ڵĹؼ������������ٶȡ�����u(k)��ʱ��array[0] .... array[u(k)-1]
// �Ѿ��ź�����ôֻҪ�ȶ�array[u(k)] ... array[u(k+1)-1]�����ٰѶ�
// �ߺϲ����������ˡ�C++ STL�ṩ�����еĹ��ܣ�sort��merge��������ֱ�������á�

// �ܵ�Ч���ű���͹������� 

#include <cstdio>
#include <algorithm>
using namespace std;

int A[60002],   *V = A, *W = A + 30001;

int T,  N,  Q,  P,  X,  Y;

int main() {
    
    for( scanf( "%d", &T ); T--; ) {

        scanf( "%d%d", &N, &Q );

        for( int i = 0; i < N; ++i )
            scanf( "%d", V + i );
        copy( V, V + N, W );
        
        for( int q = X = P = 0; q < Q; ++q ) {
            scanf( "%d", &Y );
            if( Y > X ) {
                sort( V + X, V + Y );
                merge( V, V + X, V + X, V + Y, W );
                swap( V, W );
                X = Y;
            }
            printf( "%d\n", V[P++] );
        }

        if( T ) puts( "" );

    }

}
