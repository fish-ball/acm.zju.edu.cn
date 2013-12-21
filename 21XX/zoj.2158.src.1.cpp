// 3004292 2008-07-25 13:18:54 Accepted 2158 C++ 00:00.53 880K ���͵����� 

// ��С������ Prim �㷨��ע���ڽӾ���ȨҪ��ʱ���� 

//////////////////////////////////////////////////////////
//       ӳ����ֶ�(Mapped_Binary_Heap)��ģ�� v1.0      //
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
#include <iostream>
#include <algorithm>
using namespace std;

template <int SZ, class T = int, class Op = less<T> >
class MBH {
public:
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

char    C[2001][7];

int     N,  x,  tot;

bool    B[2000];

MBH<2000> hp;

inline int dist( int i, int j ) {
    int ans = ( C[i][0] != C[j][0] );
    ans += ( C[i][1] != C[j][1] );
    ans += ( C[i][2] != C[j][2] );
    ans += ( C[i][3] != C[j][3] );
    ans += ( C[i][4] != C[j][4] );
    ans += ( C[i][5] != C[j][5] );
    ans += ( C[i][6] != C[j][6] );
    return  ans; 
}

int main() {

    while( scanf( "%d", &N ) && N ) {
        
        for( int i = 0; i < N; ++i )
            scanf( "%s", C[i] );
            
        hp.clear();
        
        tot = 0;
        
        memset( B, 0, sizeof( B ) );
        
        B[x = 0] = true;
        
        int cnt = N - 1;
        
        while( cnt-- ) {
            for( int i = 0; i < N; ++i )
                if( !B[i] ) hp.push( i, dist( x, i ) );
            B[x = hp.top().first] = true;
            tot += hp.top().second;
            hp.pop();
        }
        
        printf( "The highest possible quality is 1/%d.\n", tot );
        
    }
    

}
