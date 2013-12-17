// 3064003 2008-09-08 21:33:34 Accepted 1430 C++ 00:00.01 1016K ���͵����� 

// ���·���� BFS ������������ð��ֵ��Ȼ�� Dijkstra��ע���б���������֮���Ƿ���ͨ�� 

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

#include <queue>
#include <iostream>
using namespace std;

char    G[81][81];
int     D[81][81],  R[81][81];

MBH<10000>  hp;

int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };
int cx1[] = { 0, 0, 0, -1 };
int cy1[] = { 0, 0, -1, 0 };
int cx2[] = { -1, 0, -1, -1 };
int cy2[] = { 0, -1, -1, -1 };

int T,  M,  N,  sx, sy, tx, ty;

int main() {
    
    for( cin >> T; T--; ) {
        cin >> M >> N >> sx >> sy >> tx >> ty;
        for( int i = 0; i < M; ++i )
            cin >> G[i];
        hp.clear();
        memset( D, -1, sizeof( D ) );
        memset( R, -1, sizeof( R ) );
        for( int i = 0; i < M; ++i ) {
            for( int j = 0; j < N; ++j ) {
                if( G[i][j] == '1' ) {
                    hp.push( (i+1)*(N+1)+j+1, 0 );
                    hp.push( i*(N+1)+j, 0 );
                    hp.push( (i+1)*(N+1)+j, 0 );
                    hp.push( i*(N+1)+j+1, 0 );
                }
            }
        }
        while( !hp.empty() ) {
            int x = hp.top().first / (N+1);
            int y = hp.top().first % (N+1);
            int d = hp.top().second;
            R[x][y] = M + N - d;
            hp.pop();
            for( int i = 0; i < 4; ++i ) {
                x += dx[i];
                y += dy[i];
                if( x >= 0 && x <= M &&
                    y >= 0 && y <= N && R[x][y] == -1 )
                    hp.push( x*(N+1)+y, d+1 );
                x -= dx[i];
                y -= dy[i];
            }
        }
        hp.clear();
        hp.push( sx*(N+1)+sy, 0 );
        while( !hp.empty() ) {
            int x = hp.top().first / (N+1);
            int y = hp.top().first % (N+1);
            int d = hp.top().second + R[x][y];
            int cx, cy;
            D[x][y] = d;
            hp.pop();
            for( int i = 0; i < 4; ++i ) {
                x += dx[i];
                y += dy[i];
                if( x >= 0 && x <= M &&
                    y >= 0 && y <= N && D[x][y] == -1 ) {
                    cx = x - dx[i] + cx1[i];
                    cy = y - dy[i] + cy1[i];
                    if( cx < 0 || cx >= M || cy < 0 || cy >= N || G[cx][cy] == '0' )
                        hp.push( x*(N+1)+y, d );
                    else {
                        cx = x - dx[i] + cx2[i];
                        cy = y - dy[i] + cy2[i];
                        if( cx < 0 || cx >= M || cy < 0 || cy >= N || G[cx][cy] == '0' )
                            hp.push( x*(N+1)+y, d );
                    }
                }
                x -= dx[i];
                y -= dy[i];
            }
        }
            
        if( D[tx][ty] == -1 )
                puts( "no solution" );
        else    cout << D[tx][ty] << endl;
        
    }
    
}
