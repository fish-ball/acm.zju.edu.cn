// 2968788 2008-07-09 21:42:23 Accepted 1919 C++ 00:00.08 972K ���͵����� 

// ��������ͼ��ŷ��·�����൱ BT + XE 
// ע���Ի���ƽ�бߵĴ��� 
// ���⻹Ҫ��ϸ�ؿ�������õõ���·���ֵ�����С
// *&^%#^%$ ��ģ����ֵ���̫ xe �ˣ�Special Judge ��ð�...555.. 

#include <string>
#include <vector>
#include <iostream> 
#include <algorithm> 
#include <functional> 
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



// �ڽӾ����ʾ��ÿ���ڵ������б� 
vector<string>  G[26]; 
// path �ǻ�ȡ��ŷ��·����trace �ǵݹ�ʱ��·�� 
vector<string>  path,   trace; 
// ....
int         T,  N; 
// ����ĳ���� 
int         IN[26], OUT[26]; 
// ���鼯������ͨ�� 
Union<26>   U; 


// ��ȡŷ��·�� 
void Tour( int v ) {
    
    while( G[v].size() ) {
        trace.push_back( G[v].back() );
        G[v].pop_back(); 
        Tour( trace.back()[trace.back().size() - 1] - 'a' );
        path.push_back( trace.back() );
        trace.pop_back(); 
    }
    
} 

int main() {
    
    for( cin >> T; T--; ) {
      
        U.init( 26 ); 
        
        for( int i = 0; i < 26; ++i ) {
            G[i].clear(); 
            IN[i] = OUT[i] = 0; 
        }

        for( cin >> N; N--; ) {
            string  input;
            cin >> input;
            int x = input[0] - 'a',
                y = input[input.size() - 1] - 'a';
            IN[x]++;
            OUT[y]++; 
            U.merge( x, y );
            G[x].push_back( input );
        } 

        bool    yes = true;
        int     V = 0,  cnt = 0;
        int     begin_pos = 0; 
        for( int i = 0; i <26; ++i ) {
            V += IN[i] || OUT[i]; 
            if( IN[i] == OUT[i] )
                continue;
            if( IN[i] - OUT[i] > 1 ||
                IN[i] - OUT[i] < -1 ) {
                yes = false;
                break;
            } 
            ++cnt;
            if( IN[i] - OUT[i] == 1 )
                begin_pos = i; 
        }

        // ������������ȵ����
        // �в�ƽ���(�������� 1 ����) ���� 
        // ����ͨ������Ϊ��ŷ��·�� 
        if( cnt > 2 || !yes || U.getSets() + V != 27 ) {
            puts( "***" );
            continue; 
        }

        // �����Ѿ�ȷ����ŷ��·������ʼѰ· 
        path.clear();
        trace.clear(); 

        // ��֤�ֵ���
        for( int i = 0; i < 26; ++i )
            if( G[i].size() > 1 )
                sort( G[i].begin(), G[i].end(), greater<string>() );

        // ע�������һ���� ��� = ���� + 1
        // ���������㿪ʼ���� 
        if( begin_pos == 0 )
            while( !IN[begin_pos] && !OUT[begin_pos] )
                ++begin_pos; 
        Tour( begin_pos );

        cout << path.back();
        path.pop_back(); 
        while( path.size() ) {
            cout << '.' << path.back();
            path.pop_back(); 
        }

        cout << endl; 
        
    } 
    
} 
