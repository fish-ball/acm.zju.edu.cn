// 3024316 2008-08-06 12:22:59 Accepted 1626 C++ 00:00.06 864K ���͵����� 

// ��С���ǵ㼯-����ƥ��� Konig ���� 

//////////////////////////////////////////////////////////
//                 ����ƥ���㷨��ģ�� v1.0              //
//////////////////////////////////////////////////////////
//                                                      //
// ��һ����Ȩ����ͼ�����ƥ��                           //
// 1. init:     �����ƥ���ϵ��;                       //
// 2. insert:   ����һ���µ�ƥ���ϵ;                   //
// 3. run:      ��ȷ����С��ƥ���ϵ�����м���;         //
// 4. matchCnt: �������ƥ����;                         // 
//                                                      //
//////////////////////////////////////////////////////////
//               2008 CopyRight(c) by elf               //
//////////////////////////////////////////////////////////

#include <vector>
#include <algorithm>
using namespace std;
 
class BinMatch {
    
    int     X,  Y,  M; 
    vector<vector<int> >   G;
    vector<int>     back;
    vector<bool>    mark;
    
    bool find( int v ) {
        for( int i = 0, w; i < G[v].size(); ++i ) {
            w = G[v][i]; 
            if( !mark[w] ) {
                mark[w] = true;
                if( back[w] == -1 || find( back[w] ) ) {
                    back[w] = v;
                    return  true;
                }
            }
        } 
        return  false;
    }
    
public:
    
    void init( int x, int y ) {
        X = x;  Y = y; 
        G.assign( X + 1, vector<int>( 0 ) );
    } 
    
    void insert( int v, int w ) { G[v].push_back( w ); }
    
    void run() {
        back.assign( Y + 1, -1 );
        for( int v = M = 0; v <= X; ++v ) {
            mark.assign( Y + 1, false ); 
            M += find( v );
        }
    } 
    
    int matchCnt() const { return M; }
    
}; 


//////////////////////////////////////////////////////////
//               2008 CopyRight(c) by elf               //
//////////////////////////////////////////////////////////


#include <iostream>
#include <string>
using namespace std;

char    A[100][100];
bool    B[26];

int     N,  K,  T;

BinMatch    binmatch;

string  ans;

int main() {
    
    for( cin >> T; T--; ) {
    
        cin >> N >> K;
        
        memset( B, 0, sizeof( B ) );
        
        for( int i = 0; i < N; ++i ) {
            cin >> A[i];
            for( int j = 0; j < N; ++j )
                B[A[i][j] - 'A'] = true;
        }
            
        ans.erase();
            
        for( int i = 0; i < 26; ++i ) if( B[i] ) {
            binmatch.init( N, N );
            for( int j = 0; j < N; ++j )
                for( int k = 0; k < N; ++k )
                    if( A[j][k] == 'A' + i )
                        binmatch.insert( j, k );
            binmatch.run();
            if( binmatch.matchCnt() > K )
                ans += ( 'A' + i );
        }
        
        if( ans != "" )
                cout << ans << endl << endl;
        else    puts( "Poor WishingTree!\n" );
    
    }
    
}
