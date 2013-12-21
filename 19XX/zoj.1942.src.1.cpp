// 2996113 2008-07-22 13:13:50 Accepted 1942 C++ 00:00.02 904K ���͵����� 

// ��һ��ŷ�����ͼ�ϣ���һ��·��ʹ��;�������ֵ��С
// ��������Сֵ

// �� Kruscal ��������Ч���е�� 

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

    void union_set( int x, int y ) {
        x = find_set( x );
        y = find_set( y );
        if( x == y )    return;
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
    }
    
    int get_sets() const { return sets; }
    
    int get_size( int x ) { return size[find_set( x )]; }
    
};

////////////////////////////////////////////////////
//            2008 CopyRight(c) by elf            //
////////////////////////////////////////////////////


#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

struct Edge {
    int x,  y,  dist;
    Edge( int x, int y, int d ) :
        x( x ), y( y ), dist( d ) {}
};

inline bool operator < ( Edge e1, Edge e2 ) {
    return  e1.dist < e2.dist;
}

UFS<200>    U;

vector<Edge>    V;
vector<pair<int, int> > P;

int     N,  T = 0;

int main() {
    
    while( cin >> N && N ) {
        
        P.resize( N );
        V.clear();
        
        for( int i = 0; i < N; ++i ) {
            cin >> P[i].first >> P[i].second;
            for( int j = 0; j < i; ++j ) {
                int x = P[i].first - P[j].first,
                    y = P[i].second- P[j].second;
                V.push_back( Edge( i, j, x*x + y*y ) );
            }
        }
        
        sort( V.begin(), V.end() );
        
        U.make_set( N );
        
        for( int i = 0; i < V.size(); ++i ) {
            U.union_set( V[i].x, V[i].y );
            if( U.find_set( 0 ) == U.find_set( 1 ) ) {
                printf( "Scenario #%d\nFrog Distance = %.3lf\n\n",
                    ++T, sqrt( double( V[i].dist ) ) );
                break;
            }
        }

    }
    
    
}
