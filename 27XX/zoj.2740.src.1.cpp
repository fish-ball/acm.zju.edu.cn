// 2937833 2008-05-31 00:05:43 Accepted 2740 C++ 00:00.06 844K ���͵����� 

// �ж�һ��ͼ�ǲ�������ֱ�Ӳ��鼯���� 

#include <iostream>
#include <vector>
using namespace std;

////////////////////////////////////////////////////
//                 ���鼯ģ�� v1.0                //
////////////////////////////////////////////////////
//                                                //
//  1. SZ: ���鼯���Ԫ������(ģ�����);          //
//  2. init:  ��ʼ�� N ��Ԫ�صĲ��鼯;            //
//  3. check: �������Ԫ���Ƿ񹲼������ϲ�֮;     //
//  4. getSets: ���ز��鼯���Ӽ�����;             //
//                                                //
////////////////////////////////////////////////////
//            2008 CopyRight(c) by elf            //
////////////////////////////////////////////////////

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

int main() {
    
    int             M,  N,  X,  Y;
    Union<1001>     U;
    
    while( cin >> M >> N && M ) {
        
        bool    isTree = M == N + 1;
        
        U.init( M );
        
        while( N-- ) {
            cin >> X >> Y;
            if( U.merge( X, Y ) )
                isTree = false;
        }
        
        puts( isTree ? "Yes" : "No" );
        
    }
    
    
}
