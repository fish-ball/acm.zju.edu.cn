// 3022206 2008-08-05 10:20:49 Accepted 1140 C++ 00:00.81 1064K ���͵����� 

//////////////////////////////////////////////////////////
//                 ����ƥ���㷨��ģ�� v1.1              //
//////////////////////////////////////////////////////////
//                                                      //
// ��һ����Ȩ����ͼ�����ƥ��                           //
// 1. init:     �����ƥ���ϵ��;                       //
// 2. insert:   ����һ���µ�ƥ���ϵ;                   //
// 3. run:      ��ȷ����С��ƥ���ϵ�����м���;         //
// 4. matchCnt: �������ƥ����;                         // 
// 5. getMatch: ����ƥ���ŵ� vector<pair>;            // 
//                                                      //
// 1.1 ������������ƥ�书��;                            // 
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
    
    vector<pair<int, int> > getMatch() const {
        vector<pair<int, int> > ans;
        for( int i = 0; i < Y; ++i )
            if( back[i] != -1 )
                 ans.push_back( make_pair( back[i], i ) );
        return  ans;
    } 
    
}; 

//////////////////////////////////////////////////////////
//               2008 CopyRight(c) by elf               //
//////////////////////////////////////////////////////////



#include <iostream>
using namespace std;

BinMatch    binMatch; 

int main() {

    int T,  P,  N; 
    
    for( scanf( "%d", &T ); T--; ) {
        
        scanf( "%d%d", &P, &N );
        
        binMatch.init( P, N ); 
        
        for( int i = 1; i <= P; ++i ) {
            int k,  x;
            for( scanf( "%d", &k ); k--; ) {
                scanf( "%d", &x );
                binMatch.insert( i, x );
            }
        }
        
        binMatch.run(); 
        
        puts( binMatch.matchCnt() == P ? "YES" : "NO" );
                 
    } 
    
} 
