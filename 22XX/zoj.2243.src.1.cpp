// 2958012 2008-06-28 20:08:08 Accepted 2243 C++ 00:01.24 9264K ���͵����� 

// ̫�ж���...���ڹ���...
// ���������һ���������Ĵ����Ȱ��ն�����Ҷѵķ�ʽ��������Ȼ���������

// �ؼ��������ڽ����Ĺ��̣�����Ч�ʵ�ԭ��
//      Ҫʹ�� RMQ ���Ż���Ϊ�˿����Һܳ�ʱ��
// �ȶ������������нڵ㰴���������źã�nlogn 
// Ȼ����������Ľڵ����һ�� RMaxQ Ԥ����nlogn 

// Ȼ�󣬿�ʼ������ 
// ע�⣬��ʼ�����ڵ㶼�ǰ�ָ������һ��������ģ��������Ҷ��Ӷ��� NULL 
// Ȼ�󣬵ݹ齨��������ȫ���� RMaxQ���ҳ�������Ϊ��
// Ȼ������������������н�һ��������������������н�һ��������������
// �������ͽ����� 
// ���������������� RMaxQ �� O(1) �ģ��������Ӷ�Ϊ O(n) 

// ������������������� '(' Ȼ����������Ȼ�󱾽ڵ㣬Ȼ����������Ȼ�� ')'
// �󹦸�ɣ������൱�ľ��䣬��˳�����˸� RMQ ģ�壬�о���ˬ�� 

#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
using namespace std;

template <class T, class Op = less<T> >
class RMQ {
    
    int     size;
    int     depth;
    T**     table;
    int**   pos_table;
    
public:
    
    RMQ( T* A, int sz ) : size( sz ) {
        depth = 1;
        while( sz >>= 1 )
            depth += 1;
        table = new T*[depth];
        pos_table = new int*[depth];
        table[0] = new T[size];
        pos_table[0] = new int[size];
        for( int i = 0; i < size; ++i ) {
            table[0][i] = A[i];
            pos_table[0][i] = i;
        }
        for( int i = 1; i < depth; ++i ) {
            int step = 1 << ( i - 1 );
            int len = size - step * 2 + 1;
            table[i] = new T[len];
            pos_table[i] = new int[len];
            for( int j = 0; j < len; ++j ) {
                if( Op()( table[i-1][j], table[i-1][j+step] ) ) {
                    table[i][j] = table[i-1][j];
                    pos_table[i][j] = pos_table[i-1][j];
                }
                else {
                    table[i][j] = table[i-1][j+step];
                    pos_table[i][j] = pos_table[i-1][j+step];
                }
            }
        }
    }
    
    pair<T, int> operator () ( int x, int y ) const {
        if( x == y )    return  make_pair( table[0][x], x ); 
        int width = y - x + 1;
        int dph = 0;
        while( ( 1 << dph ) < width )    ++dph;
        --dph; 
        y = y - ( 1 << dph ) + 1;
        if( Op()( table[dph][x], table[dph][y] ) )
            return  make_pair( table[dph][x], pos_table[dph][x] );
        else
            return  make_pair( table[dph][y], pos_table[dph][y] );
    }
    
    ~RMQ() {
        for( int i = 0; i < depth; ++i ) {
            delete [] table[i];
            delete [] pos_table[i];
        }
        delete [] table;
        delete [] pos_table;
    }
    
};


struct Elem {

    int     num;
    Elem*   left;
    Elem*   right;
    string  label;

    Elem() {}

    Elem( int ) : left( NULL ), right( NULL ) {
        char    str[15];
        scanf( "%s", str );
        for( num = 0; str[num] != '/'; num++ );
        str[num] = 0;
        label = str;
        num = atoi( str + num + 1 );
    }
     
};

int     N;

Elem*   root;
Elem*   V[50004];

class val_cmp {
public:
    bool operator () ( Elem* e1, Elem* e2 ) {
        return  e1 -> num > e2 -> num;
    }
};

inline bool label_cmp ( Elem* e1, Elem* e2 ) {
    return  e1 -> label < e2 -> label;
}

void build( Elem* root, int l, int m, int r, const RMQ<Elem*, val_cmp> &rmq ) {
    if( l < m ) {
        int pos = rmq( l, m - 1 ).second; 
        root -> left = V[pos];
        build( root -> left, l, pos, m - 1, rmq ); 
    } 
    if( m < r ) {
        int pos = rmq( m + 1, r ).second;
        root -> right = V[pos];
        build( root -> right, m + 1, pos, r, rmq ); 
    } 
}

void disp( Elem* root ) {
    if( !root ) return;
    putchar( '(' );
    disp( root -> left );
    printf( "%s/%d", root -> label.c_str(), root -> num );
    disp( root -> right );
    putchar( ')' );
    return;
}

void destroy( Elem* root ) {
    if( !root ) return;
    destroy( root -> left );
    destroy( root -> right );
    delete( root );
}

int main() {
    
    while( scanf( "%d", &N ) && N ) {
        
        for( int i = 0; i < N; i++ )
            V[i] = new Elem( 1 );

        sort( V, V + N, label_cmp );
        
        RMQ<Elem*, val_cmp> rmq( V, N );
        
        root = rmq( 0, N - 1 ).first;
        
        build( root, 0, rmq( 0, N - 1 ).second, N-1, rmq );

        disp( root );
        putchar( '\n' );
        destroy( root );
        
    }

}
