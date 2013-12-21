// 3004330 2008-07-25 13:44:42 Accepted 2048 C++ 00:00.98 2404K ���͵����� 

////////////////////////////////////////////////////
//              ���鼯ģ��(UFS) v1.2              //
////////////////////////////////////////////////////
//                                                //
// 1. SZ:         ���鼯���Ԫ������(ģ�����);   //
// 2. make_set:   ��ʼ�� N ��Ԫ�صĲ��鼯;        //
// 3. find_set:   �ҳ�ĳ��Ԫ�����ڵļ���;         //
// 4. union_set:  �ϲ���������;                   // 
// 5. get_sets:   ���ز��鼯�Ӽ��ĸ���;           //
// 6. get_size:   ����Ԫ�������Ӽ��Ĵ�С;         //
//                                                //
// v1.2 �����ԣ�                                  // 
//   ����ʽ���ԣ� ���Ⱥϲ���·��ѹ��              //
//   �����ӿڣ�   �Ӽ��������Ӽ���С              // 
//                                                //
////////////////////////////////////////////////////
//            2008 CopyRight(c) by elf            //
////////////////////////////////////////////////////

template<int SZ> class UFS {

    int p[SZ+1], rank[SZ+1], size[SZ+1], sets; 

public:
    
    void make_set( int sz ) {
        for( int i = 0; i <= sz; ++i ) {
            p[i] = i;
            rank[i] = 0;
            size[i] = 1;
        }
        sets = sz;
    }
    
    int find_set( int x ) {
        if( x != p[x] )
            p[x] = find_set( p[x] );
        return  p[x];
    }

    bool union_set( int x, int y ) {
        x = find_set( x );
        y = find_set( y );
        if( x == y )    return  false;
        --sets;
        if( rank[x] > rank[y] ) {
            size[x] += size[y];
            p[y] = x;
        }
        else {
            size[y] += size[x];
            p[x] = y;
        }
        if( rank[x] == rank[y] )
            ++rank[y];
        return  true;
    }
    
    int get_sets() const { return sets; }
    
    int get_size( int x ) { return size[find_set( x )]; }
    
};

////////////////////////////////////////////////////
//            2008 CopyRight(c) by elf            //
////////////////////////////////////////////////////

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Edge {
    int v,  w,  l;
    Edge() {}
    Edge( int v, int w, int l ) :
        v( v ), w( w ), l( l ) {}
};

bool operator < ( const Edge& e1, const Edge& e2 ) {
    return  e1.l < e2.l;
}

int T,  N,  E;

vector<Edge>    V;

int X[751], Y[751];

UFS<750>    U;

int main() {
    
    for( scanf( "%d", &T ); T--; ) {
        
        scanf( "%d", &N );
        for( int i = 1; i <= N; ++i )
            scanf( "%d%d", X + i, Y + i );
            
        U.make_set( N );
        scanf( "%d", &E );
        while( E-- ) {
            int x,  y;
            scanf( "%d%d", &x, &y );
            U.union_set( x, y );
        }
        
        V.clear();
        for( int i = 1; i <= N; ++i )
            for( int j = i + 1; j <= N; ++j )
                if( U.find_set( i ) != U.find_set( j ) )
                    V.push_back( Edge( i, j, 
                        (X[j]-X[i])*(X[j]-X[i]) +
                        (Y[j]-Y[i])*(Y[j]-Y[i]) ) );
                        
        sort( V.begin(), V.end() );
        
        for( int i = 0; i < V.size(); ++i ) {
            if( U.find_set( V[i].v ) != U.find_set( V[i].w ) ) {
                printf( "%d %d\n", V[i].v, V[i].w );
                U.union_set( V[i].v, V[i].w );
            }
            if( U.get_sets() == 1 ) break;
        }
        
        if( T ) puts( "" );
        
    }
    
}
