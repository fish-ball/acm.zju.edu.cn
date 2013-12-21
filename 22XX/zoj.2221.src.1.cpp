// 3028508 2008-08-09 14:27:11 Accepted 2221 C++ 00:00.42 1248K ���͵����� 

// ���Թ�Լ��һ����С·�����ǣ�Ȼ���ö���ƥ��� 

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
#include <vector>
#include <cmath>
using namespace std;

int     T,  N,  x,  y;
char    s;

BinMatch    binmatch;

struct Taxi {
    int begin,  end;
    int a,  b,  c,  d;
};

vector<Taxi > V;

int main() {
    
    for( cin >> T; T--; ) {
        
        cin >> N;
        
        V.resize( N );
        
        for( int i = 0; i < N; ++i ) {
            cin >> x >> s >> y;
            V[i].begin = x * 60 + y; 
            cin >> V[i].a >> V[i].b >> V[i].c >> V[i].d;
            V[i].end = V[i].begin + 
                       abs( V[i].a - V[i].c ) + 
                       abs( V[i].b - V[i].d );
        }
        
        binmatch.init( N, N );
        
        for( int i = 0; i < N; ++i )
            for( int j = 0; j < N; ++j )
                if( V[i].end + 
                    abs( V[j].a - V[i].c ) + 
                    abs( V[j].b - V[i].d ) < V[j].begin )
                    binmatch.insert( i, j );
                    
        binmatch.run();
        
        cout << N - binmatch.matchCnt() << endl;
        
    }
    
}
