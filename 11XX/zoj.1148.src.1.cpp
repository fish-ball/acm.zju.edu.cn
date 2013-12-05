// 3061824 2008-09-06 21:41:50 Accepted 1148 C++ 00:00.04 1236K ���͵����� 

// ���·���� Dijkstra �� 

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


int M,  N,  T = 1;

inline int toIndex( int x, int y, int d ) {
    return  (x*N + y)*4 + d;
}

inline void fromIndex( int& x, int& y, int& d, int idx ) {
    d = idx % 4;
    idx /= 4;
    y = idx % N;
    x = idx / N;
}

char G[77][77];
int DP[77*77*4];

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

MBH<25000> hp;

int main() {
    
    while( scanf( "%d%d", &N, &M ) && M ) {
        while( getchar() != '\n' );
        memset( G, 0, sizeof( G ) );
        for( int i = 1; i <= M; ++i )
            gets( G[i] + 1 );
        N += 2;
        M += 2;
        printf( "Board #%d:\n", T++ );
        int x1, y1, x2, y2, k = 0;
        while( scanf( "%d%d%d%d", &y1, &x1, &y2, &x2 ) && x1 ) {
            G[x1][y1] = G[x2][y2] = ' ';
            printf( "Pair %d: ", ++k );
            hp.clear();
            memset( DP, -1, sizeof( DP ) );
            for( int i = 0; i < 4; ++i ) {
                int idx = toIndex(x1, y1, i);
                hp.push( idx, 1 );
            }
            bool found = false;
            while( !hp.empty() ) {
                int idx, x, y, d, dis;
                idx = hp.top().first;
                DP[idx] = dis = hp.top().second;
                hp.pop();
                fromIndex( x, y, d, idx );
                if( x == x2 && y == y2 ) {
                    printf( "%d segments.\n", dis );
                    found = true;
                    break;
                }
                for( int i = 1; ; i++ ) {
                    int xx = x+i*dx[d], yy = y+i*dy[d];
                    if( xx < 0 || xx >= M || yy < 0 || yy >= N ||
                        G[xx][yy] == 'X' ) break;
                    if( DP[toIndex(xx, yy, d)] == -1 )
                        hp.push( toIndex(xx, yy, d), dis );
                    if( DP[toIndex(xx, yy, (d+1)%4)] == -1 )
                        hp.push( toIndex(xx, yy, (d+1)%4), dis+1 );
                    if( DP[toIndex(xx, yy, (d+3)%4)] == -1 )
                        hp.push( toIndex(xx, yy, (d+3)%4), dis+1 );
                }
            }
            if( !found ) puts( "impossible." );
            G[x1][y1] = G[x2][y2] = 'X';
        }
        puts( "" );
    }
    
}
