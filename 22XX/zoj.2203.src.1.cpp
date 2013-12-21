// ���� + ��֦���Ҿ��ÿ���������Բ���ɾ���Ż�������û��Ҳ����
// �м����һ����ϵ�ǿ��֦��������ȷ��δ��֤��Ч���൱�ڿ�ʱ���������ˡ�
// 2884759 2008-05-02 19:31:17 Accepted 2203 C++ 00:00.78 500K ���͵�����  

#include <cstdio>
#include <algorithm>
using namespace std;

bool    isPrime[10000];
int     n,  m,  d;

bool    flag[1001];
int     S[1000];

bool  DFS( const int& pos ) {
    /*   ע�ͱ��п��Թۿ��������� 
        for( int i = 0; i < pos; ++i )
            printf("%d_",S[i]);
        putchar('\n');
        for( int i = m; i <= n; ++i )
            if( flag[i] )
                printf("%d_",i);
        putchar('\n');
        system("pause");
    //*/
    if( pos == n + 1 - m )
        return  true;

    // ����һ��δ����֤��ǿ��֦����
    // ���ǰ d ������ͷ��û�г��Գɹ������о�ʧ��    
    if( S[0] - m > d )  return  true;

    for( int i = m; i <= n; ++i ) {
        if( !flag[i] )
            continue;
        bool  next = false;
        int   pSum = i;
        for( int j = pos - 1; j > pos - d && j >= 0; --j ) {
            pSum += S[j];
            if( isPrime[pSum] ) {
                next = true;
                break;
            }
        }
        if( next )  continue;
        S[pos] = i;
        flag[i] = false;
        if( DFS( pos + 1 ) )
            return  true;
        flag[i] = true;
    }


    return  false;

}

int main() {

    fill( isPrime, isPrime + 10000, true );
    for( int i = 2; i < 100; ++i )
        if( isPrime[i] )
            for( int j = i + i; j < 10000; j += i )
                isPrime[j] = false;

    while( scanf( "%d%d%d", &m, &n, &d ) && m ) {

        fill( flag + m, flag + n + 1, true );

        S[0] = m;

        // ��Ӧǿ��֦�������ʹ�� 
        if( DFS( 0 ) && S[0] - m <= d ) {
            printf( "%d", S[0] );
            for( int i = 1; i < n - m + 1; ++i )
                printf( ",%d", S[i] );
            putchar( '\n' );
        }
        else  puts( "No anti-prime sequence exists." );

    }

}
