// 2968354 2008-07-09 17:09:59 Accepted 2016 C++ 00:04.05 864K ���͵����� 

// 555~~ �ҵĺ���.... ��������������ǵ��� 

// ʵ���Ͼ���������ͼ�Ƿ��ܴ���ŷ��·��������Ҫ�ǻ�·��
// �Ǿ���ͼҪ��ͨ�����ҳ������� 1 �Ľڵ���Ϊ 0 �� 2 

// ע��ͼ�Ľ����Լ����㼯�Ĵ���

#include <vector>
#include <string>
#include <iostream>
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

int main() {

    int     T,  N,  V;
    string  S;
    int     IN[26];
    int     OUT[26]; 
    Union<26>   U; 
    
    for( cin >> T; T--; ) {
        
        U.init( 26 ); 
        memset( IN, 0, sizeof( IN ) ); 
        memset( OUT, 0, sizeof( OUT ) ); 
        
        for( cin >> N; N--; ) {
            cin >> S;
            int x = S[0] - 'a',
                y = S[S.size() - 1] - 'a';
            IN[x]++; 
            OUT[y]++; 
            U.merge( x, y );
        } 
        
        bool    yes = true;
        int     cnt = 0;
        for( int i = V = 0; i <26; ++i ) {
            V += IN[i] || OUT[i]; 
            if( IN[i] == OUT[i] )
                continue;
            if( IN[i] - OUT[i] > 1 ||
                IN[i] - OUT[i] < -1 ) {
                yes = false;
                break;
            }
            ++cnt;
        }
        
        if( cnt > 2 || !yes || U.getSets() + V != 27 ) {
            puts( "The door cannot be opened." );
            continue; 
        }
        
        else    puts( "Ordering is possible." );
                
    } 

} 
