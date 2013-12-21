// 3005206 2008-07-25 21:03:37 Accepted 2008 C++ 00:01.31 46020K ���͵����� 

// ���Ż� Dijsktra��ע�⻹Ҫ��ȥ�����Զ�����ͼҲҪ����һ�� 

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
#include <vector>
using namespace std;

int T,  N,  P,  Q;
int x,  y,  d,  tot;

MBH<1000001, int> hp;

vector<pair<int, int> > V[1000001], W[1000001];
int dist[1000001];

int main() {
    
    for( scanf( "%d", &T ); T--; ) {
        
        scanf( "%d%d", &P, &Q );
        
        for( int i = 1; i <= P; ++i ) {
            V[i].clear();
            W[i].clear();
        }
        
        while( Q-- ) {
            scanf( "%d%d%d", &x, &y, &d );
            V[x].push_back( make_pair( d, y ) );
            W[y].push_back( make_pair( d, x ) );
        }
                
        hp.clear();
        
        memset( dist, -1, sizeof( dist ) );
        
        dist[x = 1] = tot = 0;
        
        
        while( 1 ) {
            
            for( int i = 0; i < V[x].size(); ++i )
                if( dist[V[x][i].second] == -1 )
                    hp.push( V[x][i].second, dist[x] + V[x][i].first );
            
            if( hp.empty() )
                break;
            
            x = hp.top().first;
            dist[x] = hp.top().second;
            tot += dist[x];
            hp.pop();
            
        }
                
        hp.clear();
        
        memset( dist, -1, sizeof( dist ) );
        
        dist[x = 1] = 0;
        
        
        while( 1 ) {
            
            for( int i = 0; i < W[x].size(); ++i )
                if( dist[W[x][i].second] == -1 )
                    hp.push( W[x][i].second, dist[x] + W[x][i].first );
            
            if( hp.empty() )
                break;
            
            x = hp.top().first;
            dist[x] = hp.top().second;
            tot += dist[x];
            hp.pop();
            
        }
        
        printf( "%d\n", tot );
        
    }
    
} 
