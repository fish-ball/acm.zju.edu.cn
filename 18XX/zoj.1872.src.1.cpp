// 3050050 2008-08-25 16:37:09 Accepted 1872 C++ 00:00.00 844K ���͵����� 

// ��С��������Prim �㷨 V^2 logV 

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
#include <cmath>
using namespace std;

double  X[100], Y[100];

double dist( int x, int y ) {
    return  hypot( X[x] - X[y], Y[x] - Y[y] );
}

int         N;

MBH<100, double>    hp;

bool        B[100];

int main() {
    
    while( cin >> N ) {
        
        hp.clear();
        
        for( int i = 0; i < N; ++i )
            cin >> X[i] >> Y[i];

        double  tot = 0;
            
        hp.push( 0, 0 );
        
        memset( B, 0, sizeof( B ) );
        
        while( !hp.empty() ) {
            
            int now = hp.top().first;
            
            tot += hp.top().second;
            
            hp.pop();
            
            B[now] = true;
            
            for( int i = 0; i < N; ++i ) {
                if( !B[i] )
                    hp.push( i, dist( now, i ) );
            }
            
        }
        
        printf( "%.2lf\n", tot );
        
    }
    
}
