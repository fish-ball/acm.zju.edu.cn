// 2866656 2008-04-24 19:04:02 Accepted 2281 C++ 00:01.45 2776K ���͵�����  
// �Ľ��� Kruscal ������ʹ�ò��鼯ģ�壬O(ElogE) 
// �Ƚ�������(�Ӵ�С)�����Ϻϲ��ߣ�ֱ����������յ㹲��
// Ȼ�����ֵ�������ϲ��ı�Ȩֵ 
// ����Ҫ�������㲻��ͨ���������ʱ��Ӧ��� 0����� WA1�� 

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

// ���鼯ģ�壡���� 
template<int SZ> class Union {
    int elem,   subSets;
    int* U;
public:
    Union( int N = 0 ) : elem( N ), subSets( N )
        { U = new int[SZ]; }
    void init( const int& );
    bool check( int, int ) const;
    bool merge( const int&, const int& );
    int getSets() const { return subSets; }
    ~Union() { delete [] U; }
};

template<int SZ> void Union<SZ>::init( const int& N ) {
    elem = subSets = N;
    for( int i = 1; i <= N; i++ )   U[i] = i;
}

template<int SZ> bool Union<SZ>::check( int x, int y ) const {
    while( U[x] != x ) x = U[x];
    while( U[y] != y ) y = U[y];
    return x == y;
}

template<int SZ> bool Union<SZ>::merge( const int& x, const int& y ) {
    int p = x, q = y, r = y;
    while( U[p] != p ) p = U[p];
    while( U[q] != q ) q = U[q];
    if( p == q ) return true;
    U[q] = p;
    while( U[r] != p ) {
        q = U[r];
        U[r] = p;
        r = q;
    }
    subSets--;
    return  false;
}


// �߽ṹ�� 
struct Edge {
    int X,  Y,  L;
    Edge( int x, int y, int l ) :
        X(x), Y(y), L(l) {}
};

inline bool icmp( const Edge& e1, const Edge& e2 ) {
    return  e1.L > e2.L;
}

// ������ 
int main() {
    int V,  E,  S,  D,  temp;
    vector<Edge> edge;
    Union<100001>  U;
    while( scanf( "%d%d", &V, &E ) != EOF ) {
        edge.clear();
        U.init( V );
        for( int i = 0; i < E; i++ ) {
            scanf( "%d%d%d", &S, &D, &temp );
            edge.push_back( Edge( S, D, temp ) );
        }
        scanf( "%d%d", &S, &D );
        sort( edge.begin(), edge.end(), icmp );
        for( temp = 0; temp < E; temp++ ) {
            if( U.check( S, D ) )   break;
            else U.merge( edge[temp].X, edge[temp].Y );
        }
        if( !U.check( S, D ) ) puts( "0" );
        else printf( "%d\n", edge[--temp].L );
    }
}
