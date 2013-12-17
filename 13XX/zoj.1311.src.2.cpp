// 2970706 2008-07-11 04:50:00 Accepted 1311 C++ 00:00.23 888K ���͵����� 

// ������ĸ��� 

// ���Ǹ�������������һ��һ����ɾ��������ͨ�� 

#include <sstream>
#include <string>
#include <iostream>
#include <vector>
using namespace std;

////////////////////////////////////////////////////
//                 ���鼯ģ�� v1.1                //
////////////////////////////////////////////////////
//                                                //
//  1. SZ:      ���鼯���Ԫ������(ģ�����);     //
//  2. init:    ��ʼ�� N ��Ԫ�صĲ��鼯;          //
//  3. check:   �������Ԫ���Ƿ񹲼������ϲ�֮;   //
//  4. getSets: ���ز��鼯���Ӽ�����;             //
//  5. single:  ���һ�����Ƿ����;               // 
//                                                //
////////////////////////////////////////////////////
//            2008 CopyRight(c) by elf            //
////////////////////////////////////////////////////

template<int SZ> class Union {
    int elem,   subSets;
    int* U;
    bool* B; 
public:
    Union( int N = 0 ) : elem( N ), subSets( N )
        { U = new int[SZ+1]; B = new bool[SZ+1]; }
    void init( const int& );
    bool check( int, int ) const;
    bool merge( const int&, const int& );
    bool single( const int& v ) { return !B[v]; } 
    int getSets() const { return subSets; }
    ~Union() { delete [] U; delete [] B; }
};

template<int SZ> void Union<SZ>::init( const int& N ) {
    elem = subSets = N;
    for( int i = 0; i <= N; i++ )   U[i] = i;
}

template<int SZ> bool Union<SZ>::check( int x, int y ) const {
    while( U[x] != x ) x = U[x];
    while( U[y] != y ) y = U[y];
    return x == y;
}

template<int SZ> bool Union<SZ>::merge( const int& x, const int& y ) {
    B[x] = B[y] = true; 
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

////////////////////////////////////////////////////
//            2008 CopyRight(c) by elf            //
////////////////////////////////////////////////////


int     N;

vector<pair<int, int> > E;

Union<100>  U;

int main() {
    
    string  input;
    
    while( cin >> N && N ) {

        E.clear();
        
        int x,  y;
        
        while( cin >> x && x ) {
            getline( cin, input );
            istringstream   is( input );
            while( is >> y )
                E.push_back( make_pair( x, y ) );
        }
        
        int cnt = 0;
        
        for( int i = 1; i <= N; ++i ) {
            U.init( N );
            for( int j = 0; j < E.size(); ++j )
                if( E[j].first != i && E[j].second != i )
                    U.merge( E[j].first, E[j].second );
            if( U.getSets() > 2 )
                ++cnt;
        }
        
        cout << cnt << endl; 

    }
    
}
