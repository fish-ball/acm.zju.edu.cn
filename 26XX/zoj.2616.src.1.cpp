// 3048891 2008-08-24 14:55:53 Accepted 2616 C++ 00:02.81 21792K ���͵����� 

// ʵ������һ�����ֵ����⣬����ת��Ϊ����С�� 

// ���� A ���� N �����꣬B ���� M ������

// ����������£����Ӧ�������о��궼���յ����ܼ�ֵ�ﵽ S

// Ȼ������ N �� M ����������ĳЩ���ܹ���

// ���Ҫ���ĳЩ�ߣ��Է������Լ��

// ����һ��ͼ��S -> N ����һ���ߣ�����Ϊ�ø�����ļ۸�

// M -> T ����һ���ߣ�����Ϊ�ø�����ļ۸�

// ���⣬���� M��N ֮�䣬���ĳ��������֮�䲻�ܹ���

// ������֮������һ�����������ı�

// Ȼ�����ͼ��С�Ҳ����������������������ʧ

// ������� S - MaxFlow

// ����������⣬�����С���Ȼ��������м����Щ��

// Ҳ���ǲ���ͬʱȡì�ܵ�˫��

// ���⹹ͼ����ҪһЩ�ɾ� 

//////////////////////////////////////////////////////
//              �����(·������) v1.0               //
///////////////////Documentation//////////////////////
//                                                  //
// 1. SZ:       ģ�������ȷ������ͼ��ģ;         //
// 2. init:     ����һ����Сһ���Ŀյ�������;       //
// 3. insert:   �����������һ����;                 //
// 4. maxFlow:  ���ָ��Դ-��������ֵ;            // 
//                                                  //
//////////////////////////////////////////////////////
//             2008 CopyRight(c) by elf             //
//////////////////////////////////////////////////////

#include <algorithm>
#include <vector>
using namespace std;

struct Edge {
    int     v,  w,  f,  c;
    Edge() {}
    Edge( int v, int w, int c, int f = 0 ) : v(v), w(w), c(c), f(f) {}
    int     next( int vv ) { return vv == v ? w : v; }
    int     remain( int vv ) { return vv == v ? c-f : f; }
    void    increase( int vv, int val ) { vv == v ? f += val : f -= val; }
};

template<int SZ, int BUF_SZ = SZ*SZ> 
class MaxFlow {
    
    int     size,   edges;
    vector<Edge*>   V[SZ+1];
    Edge    buf[BUF_SZ];
    Edge*   fwd[SZ+1];
    int     Q[SZ + 1],  top;
    
    int addFlow( int v, int flow ) {
        if( fwd[v] == buf - 1 ) return  flow;
        flow = min( flow, fwd[v] -> remain( fwd[v] -> next( v ) ) );
        flow = min( flow, addFlow( fwd[v] -> next(v), flow ) );
        fwd[v] -> increase( fwd[v] -> next(v), flow );
        return  flow;
    }
    
    bool findPath( int s, int t ) {
        memset( fwd, 0, sizeof( fwd ) );
        Q[0] = s;
        top = 1;
        fwd[s] = buf - 1;   // Sentinel
        while( top && !fwd[t] ) {
            int pos = rand() % top;
            int v = Q[pos];
            swap( Q[pos], Q[--top] );
            for( int i = 0; i < V[v].size(); ++i ) {
                if( !fwd[V[v][i] -> next( v )] &&
                         V[v][i] -> remain( v ) ) {
                    fwd[V[v][i] -> next( v )] = V[v][i];
                    Q[top++] = V[v][i] -> next( v );
                }
            }
        }
        return  fwd[t] ? true : false;
    }
    
public:
    
    void init( int sz ) {
        for( int i = 0; i <= size; ++i )
            V[i].clear();
        size = sz;
        edges = 0;
    }
    
    void insert( int v, int w, int c ) {
        buf[edges++] = Edge( v, w, c );
        V[v].push_back( buf + edges - 1 );
        V[w].push_back( buf + edges - 1 );
    } 
    
    int maxFlow( int s, int t ) {
        for( int i = 0; i <= size; ++i )
            for( int j = 0; j < V[i].size(); ++j )
                V[i][j] -> f = 0;
        int total = 0;
        while( findPath( s, t ) )
            total += addFlow( t, INT_MAX );
        return  total;
    }
    
};

//////////////////////////////////////////////////////
//             2008 CopyRight(c) by elf             //
//////////////////////////////////////////////////////

#include <iostream>
#include <set>
using namespace std;

MaxFlow<6002, 1000000>   mf;

int     T,  N,  M,  S,  X;

vector<int> H[300001];

set<int>    P;
set<int>::iterator  it;

int main() {

    scanf( "%d", &T );

    for( int t = 0; t < T; ++t ) {

        if( t ) puts( "" );

        for( int i = 1; i < 300001; ++i )
            H[i].clear();
            
        S = 0;

        mf.init( 6002 );
        
        scanf( "%d", &N );
        for( int i = 1; i <= N; ++i ) {
            scanf( "%d", &X );
            S += X;
            mf.insert( 0, i, X );
            while( getchar() != '\n' ) {
                scanf( "%d", &X );
                H[X].push_back( i );
            }
        }
        
        scanf( "%d", &M );
        for( int i = N+1; i <= N+M; ++i ) {
            scanf( "%d", &X );
            S += X;
            mf.insert( i, N+M+1, X );
            P.clear();
            while( getchar() != '\n' ) {
                scanf( "%d", &X );
                for( int j = 0; j < H[X].size(); ++j )
                    P.insert( H[X][j] );
            }
            for( it = P.begin(); it != P.end(); ++it )
                mf.insert( *it, i, 1000 );
        }
        
        printf( "Case %d:\n", t + 1 );
        printf( "%d\n", S - mf.maxFlow( 0, N+M+1 ) );

    }

}
