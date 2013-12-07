// 3020628 2008-08-04 11:54:38 Accepted 1298 C++ 00:00.01 1828K ���͵����� 

// ���㵽���ʱ��һ�������·���ﵽ�ģ������ϵ�ʱ������������˵���ʱ��ȷ��
// ��ˣ�����һ�� Dijkstra��Ȼ��������㼰���ߵ�ʱ�� 

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
using namespace std;

int G[501][501],    N,  M,  T = 1;

int tt[501];

MBH<501>    hp;

int main() {
    
    while( cin >> N >> M && N ) {
        
        for( int i = 1; i <= N; ++i )
            for( int j = 1; j <= N; ++j )
                G[i][j] = -1;
                
        for( int i = 0, x, y, z; i < M; ++i ) {
            cin >> x >> y >> z;
            G[y][x] = G[x][y] = z;
        }
        
        printf( "System #%d\n", T++ );
     
        if( N == 1 ) {
            puts( "The last domino falls after 0.0 seconds, at key domino 1.\n" );
            continue;
        }
        
        hp.clear();
        
        hp.push( 1, 0 );
        
        memset( tt, -1, sizeof( tt ) );
        
        while( 1 ) {
            int now = hp.top().first;
            tt[now] = hp.top().second;
            hp.pop();
            for( int i = 1; i <= N; ++i )
                if( G[now][i] != -1 && tt[i] == -1 )
                    hp.push( i, G[now][i] + tt[now] );
            if( hp.empty() )    break;
        }
        
        int mx = 0, x,  y;
        
        for( int i = 1; i <= N; ++i ) {
            if( 2 * tt[i] > mx ) {
                mx = 2 * tt[i];
                x = i;
                y = 0;
            }
            for( int j = i + 1; j <= N; ++j ) {
                if( G[i][j] == -1 )  continue;
                int u = tt[i],  v = tt[j];
                if( u > v ) swap( u, v );
                if( v - u >= G[i][j] )  continue;
                else if( G[i][j] + u + v > mx )
                    mx = G[x=i][y=j] + u + v;
            }
        }
        
        printf( "The last domino falls after %d.%d seconds, ", mx / 2, mx % 2 * 5 );
        if( y == 0 )
            printf( "at key domino %d.\n\n", x );
        else
            printf( "between key dominoes %d and %d.\n\n", x, y );
        
    }
    
}
