// 2970607 2008-07-10 22:27:59 Accepted 2588 C++ 00:01.28 5440K ���͵����� 

// ������⣬ע��ƽ�бߵ����
// ƽ�б����������ϲ�ƽ�бߣ�Ȼ������ָñ��Ǹ�ߣ����� 

// �и� PE �����ޱȣ�����������ʽ��һ��˵����
// 1. test case ֮����У����һ�� test case �����У�
// 2. ��������֮����ո����һ�����ӿո�
// 3. ���û�и�ߣ���һ��������� 0���ڶ��б��һ�����У��������� 

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int v,  w,  k;
    Edge() {} 
    Edge( int v, int w, int k = 0 ) :
        v( v ), w( w ), k( k ) {}
};

inline bool operator < ( const Edge& e1, const Edge& e2 ) {
    if( e1.v < e2.v )   return  true;
    if( e1.v > e2.v )   return  false;
    return  e1.w < e2.w;
}

inline bool operator == ( const Edge& e1, const Edge& e2 ) {
    return  e1.v == e2.v && e1.w == e2.w; 
}

inline bool icmp( const Edge& e1, const Edge& e2 ) {
    return  e1.k < e2.k; 
}

vector<int> V[10001];
Edge        E[100000];
int         T,  N,  M;

// DFS ��¼�� 
int     dph;            // ��ǰ������� 
int     ord[10001];     // �ڵ������� 
int     pre[10001];     // �ڵ� DFS ������ 
int     low[10001];     // �ڵ�������С�ر� ord 


void DFS( int x ) {
    low[x] = ord[x] = dph++;
    for( int i = 0; i < V[x].size(); ++i ) {
        // ����������� 
        if( ord[V[x][i]] == -1 ) {
            pre[V[x][i]] = x;
            DFS( V[x][i] );
            // �������
            if( low[x] > low[V[x][i]] )
                low[x] = low[V[x][i]];
        }
        // ������Ǹ����ӣ�����������ӣ�
        else if( V[x][i] != pre[x] ) {
            if( low[x] > ord[V[x][i]] ) 
                low[x] = ord[V[x][i]];
        }
    }
}



int main() {

    for( scanf( "%d", &T ); T--; ) {

        scanf( "%d%d", &N, &M );

        for( int i = 1; i <= N; ++i )
            V[i].clear();

        for( int i = 0; i < M; ++i ) {
            scanf( "%d%d", &E[i].v, &E[i].w );
            if( E[i].v > E[i].w )
                swap( E[i].v, E[i].w ); 
            E[i].k = i + 1;
            V[E[i].v].push_back( E[i].w );
            V[E[i].w].push_back( E[i].v );
        }
        
        sort( E, E + M ); 

        memset( ord, -1, sizeof( ord ) );
        memset( pre, -1, sizeof( pre ) );
        memset( low, -1, sizeof( low ) );
        dph = 0; 
        DFS( 1 ); 
        
        vector<Edge>    ans( 0 );

        // ״̬���Ա�� 
        #ifndef ONLINE_JUDGE
        cout << "seq: ";for( int i = 1; i <= N; ++i ) printf( "%3d", i );       puts(""); 
        cout << "ord: ";for( int i = 1; i <= N; ++i ) printf( "%3d", ord[i] );  puts("");
        cout << "low: ";for( int i = 1; i <= N; ++i ) printf( "%3d", low[i] );  puts("");
        cout << "pre: ";for( int i = 1; i <= N; ++i ) printf( "%3d", pre[i] );  puts("");
        #endif 
        
        for( int i = 1; i <= N; ++i ) {
            // ���ڸ�ߵĵ� 
            if( low[i] && low[i] == ord[i] ) {
                int x = i,  y = pre[i];
                if( x > y ) swap( x, y );
                Edge*   pos = lower_bound( E, E + M, Edge( x, y ) );
                // ��ƽ�еĸ�� 
                if( !( *pos == *( pos + 1 ) ) )
                    ans.push_back( *pos );
            }
        }
        
        sort( ans.begin(), ans.end(), icmp );
        
        printf( "%d\n", ans.size() );
        if( ans.size() ) {
            printf( "%d", ans[0].k );
            for( int i = 1; i < ans.size(); ++i ) 
                printf( " %d", ans[i].k );
            puts( "" ); 
        }
        
        if( T ) puts( "" ); 

    }
    
}
