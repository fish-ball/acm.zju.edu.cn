// 2967264 2008-07-08 21:18:07 Accepted 1395 C++ 00:00.00 868K ���͵����� 

// �ж�һ��ͼ�Ƿ���ڴ� M �� 0 ��ŷ��·��
// ����ƽ�бߺ͹����㣬Ӧ����ͨ�ԺͶ���ż��׼�򼴿�

// *&%$@$%@#^%# Ī������ WA��������.... 

#include <iostream>
#include <sstream>
#include <string>
using namespace std;

////////////////////////////////////////////////////
//                 ���鼯ģ�� v1.0                //
////////////////////////////////////////////////////
//                                                //
//  1. SZ:      ���鼯���Ԫ������(ģ�����);     //
//  2. init:    ��ʼ�� N ��Ԫ�صĲ��鼯;          //
//  3. check:   �������Ԫ���Ƿ񹲼������ϲ�֮;   //
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
        { U = new int[SZ+1]; }
    void init( const int& );
    bool check( int, int ) const;
    bool merge( const int&, const int& );
    int getSets() const { return subSets; }
    ~Union() { delete [] U; }
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


int main() {
    
    string  input;
    
    int M,  N,  D[30];
    
    Union<30>   U;
    
    while( cin >> input ) {
        
        if( input == "ENDOFINPUT" )
            break;
        
        cin >> M >> N;
        
        getline( cin, input );
        
        U.init( N );
        
        memset( D, 0, sizeof( D ) );
        
        int edges = 0;
        
        for( int i = 0, j; i < N; ++i ) {
            
            getline( cin, input );
            
            istringstream   is( input );
            
            while( is >> j ) {
                ++edges;
                ++D[i];
                ++D[j];
                U.merge( i, j );
            }
            
        }
        
        getline( cin, input );
        
        if( !U.check( 0, M ) || M == 0 && D[0] % 2 ) {
            puts( "NO" );
            continue;
        }
        
        bool    yes = true;
        for( int i = 1; i < N; ++i ) {
            if( i == M )    continue;
            if( D[0] % 2 && D[M] % 2 ) {
                if( D[i] % 2 ) {
                    yes = false;
                    break;
                }
            }
            else if( !( D[0] % 2 || D[M] % 2 ) ) {
                if( D[i] % 2 ) {
                    yes = false;
                    break;
                }
            }
            else {
                yes = false;
                break;
            }
        }
        
        if( yes )   cout << "YES " << edges << endl;
        else        cout << "NO" << endl;
        
    }
    
}
