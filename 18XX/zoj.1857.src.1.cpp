// 3064632 2008-09-09 14:26:38 Accepted 1857 C++ 00:00.43 1012K ���͵����� 

// ��ͨ�����·�����ݺ�������һ���������� 

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
#include <string>
#include <vector>
using namespace std;

struct Edge {
    int v,  w,  l;
    Edge() {}
    Edge( int v, int w, int l ) :
        v(v), w(w), l(l) {}
} E[10000];

MBH<501>    hp;
int D[501], T[501];
int N,  M,  K;

vector<pair<int, int> > V[501];

string  input;

int main() {
    
//    freopen( "A.10.dat", "r", stdin );
//    freopen( "test10.txt", "w", stdout );
    
    while( cin >> M >> N ) {
        hp.clear();
        memset( D, -1, sizeof( D ) );
        for( int i = 1; i <= N; ++i ) V[i].clear();
        for( int i = 0, x; i < M; ++i ) {
            cin >> x;
            hp.push( x, 0 );
        }
        getline( cin, input );
        while( true ) {
            int v, w, l;
            if( !getline( cin, input ) ) break;
            if( input == "" ) break;
            sscanf( input.c_str(), "%d%d%d", &v, &w, &l );
            V[v].push_back( make_pair( w, l ) );
            V[w].push_back( make_pair( v, l ) );
        }
        while( !hp.empty() ) {
            int x = hp.top().first;
            int y = hp.top().second;
            hp.pop();
            D[x] = y;
            for( int i = 0; i < V[x].size(); ++i )
                if( D[V[x][i].first] == -1 )
                    hp.push( V[x][i].first, y + V[x][i].second );
        }
        int val = INT_MAX, pos;
        for( int s = 1; s <= N; ++s ) {
            hp.clear();
            memset( T, -1, sizeof( T ) );
            int mx = 0;
            hp.push( s, 0 );
            while( !hp.empty() ) {
                int x = hp.top().first;
                int y = hp.top().second;
                hp.pop();
                T[x] = min( D[x], y );
                mx >?= T[x];
                for( int i = 0; i < V[x].size(); ++i )
                    if( T[V[x][i].first] == -1 )
                        hp.push( V[x][i].first, y + V[x][i].second );
            }
            if( mx < val ) {
                val = mx;
                pos = s;
            }
        }
        cout << pos << endl;
    }
    
}
