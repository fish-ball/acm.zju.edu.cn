// 3009376 2008-07-27 20:50:09 Accepted 1319 C++ 00:00.26 1668K ���͵����� 

// �ø� set ���ģ�������ȥ����������ʼ�Ҹ�
// ���һ�������������ĳ����Ȼ AC��ʵ��û����
// û���κβο���ֵ��Ȩ�����ڲ���ݹ��Ͱ��� 

#include <set>
#include <cstdio>
using namespace std;

set<pair<int, int> >    S;
set<pair<int, int> >::iterator  it;

pair<int, int>  p;

int V[30001];

int T,  N,  Q,  X,  P;

int main() {
    
    for( scanf( "%d", &T ); T--; ) {

        scanf( "%d%d", &N, &Q );

        for( int i = 0; i < N; ++i )
            scanf( "%d", V + i );

        S.clear();
        S.insert( make_pair( V[0], P = 1 ) );
        it = S.begin();

        while( Q-- ) {
            scanf( "%d", &X );
            while( P < X ) {
                p = *it;
                S.insert( make_pair( V[P], P + 1 ) );
                it = S.find( p );
                if( V[P++] < it -> first ) --it;
            }
            printf( "%d\n", it++->first );
            if( it == S.end() ) {
                S.insert( make_pair( V[P], ++P ) );
                it = S.end();
                --it;
            }
        }

        if( T ) puts( "" );

    }

}

