// 3042230 2008-08-19 21:06:20 Accepted 1132 C++ 00:01.53 3744K ���͵����� 

// Dijsktra���������ҳ����絽��ʱ�䣬�ٷ����ҳ��������ʱ�� 

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
#include <string>
#include <vector>
using namespace std;

int N,  M,  C = 0;
char    input[10000];
map<string, int>    idx;
vector<string>      name;

// ��һ���ǵ���ʱ�䣬�ڶ����ǳ�վ��� 
vector<map<int, int>* > V[100]; 

map<int, int>    buf[1000];
map<int, int>::iterator it, it2;

MBH<100, int, less<int> >       hp1;
MBH<100, int, greater<int> >    hp2; 

int pre[100],   tim[100];

int main() {
    
      
    while( scanf( "%d", &N ) && N ) {
        
        idx.clear();
        
        name.resize( N );
        
        for( int i = 0; i < N; ++i ) {
            scanf( "%s", input );
            name[i] = input;
            idx[name[i]] = i;
            V[i].clear(); 
        }
        
        scanf( "%d", &M );
        for( int i = 0; i < M; ++i ) {
            int K, X, P; 
            buf[i].clear();
            for( scanf( "%d", &K ); K--; ) {
                scanf( "%d", &X );
                scanf( "%s", input );
                P = idx[input];
                buf[i][X] = P;
                V[P].push_back( buf + i ); 
            }
        }
        
        int T, bg, ed;
        
        scanf( "%d", &T );
        scanf( "%s", input );
        bg = idx[input];
        scanf( "%s", input );
        ed = idx[input];

        memset( pre, -1, sizeof( pre ) );
        
        hp1.clear();
        
        int now = bg;
        
        for( int i = 0; i < V[bg].size(); ++i ) {
            bool    yes = false;
            for( it = V[bg][i] -> lower_bound( T );
                 it != V[bg][i] -> end(); ++it ) {
                if( it -> second == bg )
                    yes = true;
                if( yes ) {
                    hp1.push( bg, it -> first );
                    break;
                }
            }
        }
        
        while( !hp1.empty() ) {
            int sta = hp1.top().first;
            int tm = hp1.top().second;
            hp1.pop();
            pre[sta] = now;
            tim[sta] = tm;
            now = sta;
            for( int i = 0; i < V[sta].size(); ++i )
                for( it = V[sta][i] -> upper_bound( tm );
                     it != V[sta][i] -> end(); ++it )
                    if( pre[it -> second] == -1 )
                        hp1.push( it -> second, it -> first );
            if( pre[ed] != -1 ) break;
        }

        printf( "Scenario #%d\n", ++C );
        
        if( pre[ed] == -1 ) {
            puts( "No connection" );
            puts( "" );
            continue;
        }



        T = tim[ed];
        swap( bg, ed );

        memset( pre, -1, sizeof( pre ) );
        
        now = bg;
        
        hp2.clear();
        
        hp2.push( bg, tim[bg] );
        pre[bg] = bg;
        
        while( !hp2.empty() ) {
            int sta = hp2.top().first;
            int tm = hp2.top().second;
            hp2.pop();
            pre[sta] = now;
            tim[sta] = tm;
            now = sta;
            for( int i = 0; i < V[sta].size(); ++i ) {
                for( it2 = V[sta][i] -> begin(); ; ++it2 )
                    if( it2 -> second == sta )
                        break;
                if( it2 -> first > tim[sta] )   continue;
                for( it = V[sta][i] -> begin(); it != it2; ++it )
                    if( pre[it -> second] == -1 )
                        hp2.push( it -> second, it -> first );
            }
            if( pre[ed] != -1 ) break;
        }
        

        printf( "Departure %04d ", tim[ed] );
        puts( name[ed].c_str() );
        printf( "Arrival   %04d ", tim[bg] );
        puts( name[bg].c_str() );
        puts( "" );
            

    }
    
}
