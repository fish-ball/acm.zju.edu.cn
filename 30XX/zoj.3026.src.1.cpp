// 3059170 2008-09-04 11:50:39 Accepted 3026 C++ 00:00.22 900K ���͵����� 

// ���·���޸�Ȩ��Dijkstra��ע�⿪ʼ���������� 

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

int D[4*30*30], N,  M,  ans;
int G[30][30],  C[4];

const int dx[] = { -1, 0, 1, 0 };
const int dy[] = { 0, 1, 0, -1 };

MBH<4*30*30> hp;

inline int getIndex( int x, int y, int d ) {
    return  ( ( x * N ) + y ) * 4 + d;
}

int main() {
    
    while( scanf( "%d%d", &N, &M ) && N ) {

        for( int i = 0; i < M; ++i )
            for( int j = 0; j < N; ++j )
                scanf( "%d", &G[i][j] );

        scanf( "%d%d%d%d", C, C+1, C+2, C+3 );

        hp.clear();
        hp.push( 1, 0 );

        memset( D, -1, sizeof( D ) );

        int d,  x,  y,  dd, xx, yy, pos;

        while( !hp.empty() ) {

            pos = hp.top().first;
            D[pos] = hp.top().second;
            hp.pop();

            d = pos & 3,
            x = (pos >> 2) / N,
            y = (pos >> 2) % N,
            xx, yy, dd;
            if( pos >= getIndex( M-1, N-1, 0 ) ) {
                ans = D[pos];
                break;
            }
            switch( G[x][y] ) {
                case 0: dd = d;       break;
                case 1: dd = (d+1)&3; break;
                case 2: dd = (d+2)&3; break;
                case 3: dd = (d+3)&3; break;
                default:  dd = -1;
            }
            if( dd >= 0 ) {
                xx = x + dx[dd];
                yy = y + dy[dd];
                if( xx >= 0 && xx < M &&
                    yy >= 0 && yy < N &&
                    D[getIndex(xx, yy, dd)] == -1 )
                    hp.push( getIndex(xx, yy, dd), D[pos] );
            }
            for( int i = 0; i < 4; ++i ) {
                dd = (d + i) & 3;
                xx = x + dx[dd];
                yy = y + dy[dd];
                if( xx >= 0 && xx < M &&
                    yy >= 0 && yy < N &&
                    D[getIndex(xx, yy, dd)] == -1 )
                    hp.push( getIndex(xx, yy, dd), D[pos]+C[i] );
            }
        }
        printf( "%d\n", ans );
    }
    
}
