// 1659674 2008-10-07 15:42:34 Accepted  2314 C++ 160 1792 ���͵����� 

// �����½�Ļ�����
// ���Դ��ͻ�� S, T�������ڱ� (u, v)������ӱ� (S, v), (u, T)��
// ����Ϊ l��(u, v) ��������Ϊc - l��
// �� S, T ��������Ƿ�Ϊ sigma(li)��

// ����ܼ򵥣�ÿ���ߵ��½������Ƚ���Щ�½���Ԥ���ڸñ��У�
// Ȼ�����Ƕ�����������ط����ط���㣬���磺 
// ���ĳ�� v->w ���½� li����ô����� w �������;��
// �� li ������ w ���� v������Щ����;������ֻ��ռ�� c-l ���ֵ����� 

// �������Ϸ�������������� s-t ������ sigma(li) ��������� 

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
public:
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
        memset( fwd, 0, sizeof( fwd ) );
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
using namespace std;

int v[50000], w[50000], l[50000], c[50000];
int s[200], t[200], N, M, T, S;
MaxFlow<210> mf;

int main() {
    for(scanf("%d", &T); T--;) {
        scanf("%d%d", &N, &M);
        mf.init(N+2);
        memset(s, 0, sizeof(s));
        memset(t, 0, sizeof(t));
        for(int i = S = 0; i < M; ++i) {
            scanf("%d%d%d%d", v+i, w+i, l+i, c+i);
            S += l[i];
            s[w[i]-1] += l[i];
            t[v[i]-1] += l[i];
            mf.insert(v[i]-1, w[i]-1, c[i]-l[i]);
        }
        for(int i = 0; i < N; ++i) {
            mf.insert(N, i, s[i]);
            mf.insert(i ,N+1, t[i]);
        }
        if(mf.maxFlow(N, N+1) != S) puts("NO");
        else {
            puts("YES");
            for(int i = 0; i < M; ++i) {
                printf("%d\n", mf.buf[i].f+l[i]);
            }
        }
        if(T) puts("");
    }
}
