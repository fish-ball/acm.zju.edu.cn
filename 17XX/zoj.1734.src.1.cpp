// 3018063 2008-08-02 14:46:29 Accepted 1734 C++ 00:03.40 1296K ���͵����� 

// �ҵĵ�һ������������˵��㷨��FIFO ·������������㷨 

#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
using namespace std;

struct Edge {
    int v,  w,  f,  c;
    int next( int vv ) { return vv == v ? w : v; }
    int remain( int vv ) { return vv == v ? c-f : f; }
    void increase( int vv, int val ) { vv == v ? f += val : f -= val; }
};

int N,  S,  T,  M;

// new single-source & single-sink vertex added.
int s,  t,  total;

Edge    E[20000];

vector<Edge*>   V[102];

Edge* fwd[102];

deque<int> Q;

void build() {
    
    s = N;  t = N + 1;
    
    char    c;
    
    for( int i = 0; i < N + 2; ++i )
        V[i].clear();
        
    for( int i = 0; i < M; ++i ) {
        cin >> c >> E[i].v >> c >> E[i].w >> c >> E[i].c;
        E[i].f = 0;
        V[E[i].v].push_back( E + i );
        V[E[i].w].push_back( E + i );
    }
        
    for( int i = M; i < M + S; ++i ) {
        cin >> c >> E[i].w >> c >> E[i].c;
        E[i].v = s;
        E[i].f = 0;
        V[E[i].v].push_back( E + i );
        V[E[i].w].push_back( E + i );
    }
        
    for( int i = M + S; i < M + S + T; ++i ) {
        cin >> c >> E[i].v >> c >> E[i].c;
        E[i].w = t;
        E[i].f = 0;
        V[E[i].v].push_back( E + i );
        V[E[i].w].push_back( E + i );
    }
        
    M += ( S + T );
}

int addFlow( int v, int flow ) {
    if( fwd[v] < E )    return  flow;
    flow = min( flow, fwd[v] -> remain( fwd[v] -> next( v ) ) );
    flow = min( flow, addFlow( fwd[v] -> next(v), flow ) );
    fwd[v] -> increase( fwd[v] -> next(v), flow );
    return  flow;
}

int main() {
    
    while( cin >> N >> S >> T >> M ) {

        build();

        total = 0;
        
        while( true ) {
            
            memset( fwd, 0, sizeof( fwd ) );
            Q.clear();
            fwd[s] = E - 1;
            Q.push_back( s );
            
            while( !Q.empty() && !fwd[t] ) {
                int v = Q.front();
                Q.pop_front();
                for( int i = 0; i < V[v].size(); ++i ) {
                    if( !fwd[V[v][i] -> next( v )] &&
                             V[v][i] -> remain( v ) ) {
                        fwd[V[v][i] -> next( v )] = V[v][i];
                        Q.push_back( V[v][i] -> next( v ) );
                    }
                }
            }
            
            if( !fwd[t] )   break;
            
            total += addFlow( t, 0x7FFFFFF );

        }
        
        cout << total << endl;
  
    }
    
}

