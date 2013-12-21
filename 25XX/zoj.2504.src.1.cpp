// 3064791 2008-09-09 17:02:17 Accepted 2504 C++ 00:00.04 952K ���͵����� 

// �����·��Dijktra 

//////////////////////////////////////////////////////////
//       ӳ����ֶ�(Mapped_Binary_Heap)��ģ�� v1.3      //
//////////////////////////////////////////////////////////
//                                                      //
//                   ģ�����                           //
// 1. SZ:     ӳ����ֶѵ����������;                   //
// 2. T:      ӳ����ֶ��̺�ֵ���ͣ�ȱʡΪ int;         //
// 3. Op:     �Ƚ�׼�� functor��ȱʡΪС��;             // 
//                                                      //
//                     �ӿ�                             //
// 1. clear:  ��ն�;                                   //
// 2. empty:  �п�;                                     // 
// 3. size:   ���ضѴ�С(Ԫ�ظ���);                     //
// 4. top:    ���ضѶ�Ԫ��(������ֵ���);               //
// 5. push:   ����������Ԫ�أ��Զ�ʶ�����Ϊ��Сֵ;     //
// 6. pop:    ɾ����Сֵ;                               //
//                                                      //
//////////////////////////////////////////////////////////
//               2008 CopyRight(c) by elf               //
//////////////////////////////////////////////////////////

#include <functional>
#include <algorithm>
using namespace std;

template <int SZ, class T = int, class Op = less<T> >
class MBH {

    pair<int, T> heap[SZ + 1];
    int key[SZ + 1], sz;

public:

    void clear() { sz = 0; memset( key, 0, sizeof( key ) ); }
    
    int size() const { return sz; }
    
    bool empty() const { return sz == 0; } 
    
    pair<int, T> top() const { return heap[1]; }
    
    void push( int idx, T val ) {
        if( !key[idx] ) {
            key[idx] = ++sz;
            heap[sz] = make_pair( idx, val );
        }
        else if( Op()( val, heap[key[idx]].second ) )
            heap[key[idx]].second = val;
        for( int pos = key[idx], c;
            ( c = pos >> 1 ) && Op()( val, heap[c].second ); pos = c ) {
            swap( heap[pos], heap[c] );
            key[idx] = c;
            key[heap[pos].first] = pos;
        }
    }
    
    void pop() {
        key[heap[1].first] = 0;
        heap[1] = heap[sz--];
        if( sz == 0 )   return;
        key[heap[1].first] = 1;
        for( int pos = 1, c; ( c = pos<<1 ) <= sz; pos = c ) {
            if( c < sz && Op()( heap[c+1].second, heap[c].second ) ) ++c;
            if( Op()( heap[c].second, heap[pos].second ) ) {
                swap( heap[c], heap[pos] );
                key[heap[c].first] = c;
                key[heap[pos].first] = pos;
            }
            else break;
        }
    }

};

//////////////////////////////////////////////////////////
//               2008 CopyRight(c) by elf               //
//////////////////////////////////////////////////////////


#include <iostream>
#include <map>
#include <vector>
using namespace std;

map<int, int>   G[1001];
map<int, int>::iterator iter;

vector<int> P;

int T,  N,  M,  K,  C = 0;

MBH<1001>   hp;
int D[1001];

int main() {
    
    for( scanf( "%d", &T ); T--; ) {
        
        scanf( "%d%d", &N, &M );
        
        for( int i = 1; i <= N; ++i  )
            G[i].clear();
        
        for( int i = 0; i < M; ++i ) {
            int x,  y,  d;
            scanf( "%d%d%d", &x, &y, &d );
            G[x][y] = G[y][x] = d;
        }
        
        scanf( "%d", &K );
        P.resize( K );
        
        for( int i = 0; i < K; ++i )
            scanf( "%d", &P[i] );
        
        printf( "TEST %d ", ++C );
            
        int len = 0;
        for( int i = 1; i < K; ++i ) {
            iter = G[P[i-1]].find( P[i] );
            if( iter == G[P[i-1]].end() ) {
                len = -1;
                break;
            }
            len += iter->second;
        }
        
        if( len == -1 ) {
            puts( "N" );
            continue;
        }
        
        if( N == 1 ) {
            puts( "Y 0" );
            continue;
        }
        
        memset( D, -1, sizeof( D ) );
        hp.clear();
        D[1] = 0;
        hp.push( P[1], G[P[0]][P[1]] );
        while( !hp.empty() ) {
            int v = hp.top().first;
            int d = hp.top().second;
            hp.pop();
            D[v] = d;
            if( v == N ) break;
            for( iter = G[v].begin(); iter != G[v].end(); ++iter )
                if( D[iter->first] == -1 )
                    hp.push( iter->first, d + iter->second );
        }
        
        printf( "Y %d\n", len - D[N] );
        
    }
    
}
