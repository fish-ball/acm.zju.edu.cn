// 3025488 2008-08-06 21:36:23 Accepted 1197 C++ 00:00.01 860K ���͵����� 

// ������ƥ�䣬����һ����ͨƥ�䣬Ȼ��Ҫ����ȫƥ�� 

// Ȼ���������ƥ��ߣ�����ɾ���ñߣ�����ƥ�� 
// ���ɾ��֮��ƥ�����������ı䣬��ƥ�䲻Ωһ 

// ����Ҫ������ƥ�䣬���м���������ƥ����������... 
// ��ˣ��ڼ����ʱ���������������Ҫ��Ӧ��ɾ����ƥ���... 


//////////////////////////////////////////////////////////
//   ����ƥ���㷨��ģ�壨�ڽӾ���ʵ�֣�֧��ɾ�ߣ� v1.1  //
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
    vector<vector<bool> >   G;
    vector<int>     back;
    vector<bool>    mark;
    
    bool find( int v ) {
        for( int w = 0; w <= Y; ++w ) {
            if( G[v][w] && !mark[w] ) {
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
        G.assign( X + 1, vector<bool>( Y + 1, false ) );
    } 
    
    void insert( int v, int w ) { G[v][w] = true; }
    
    void erase( int v, int w ) { G[v][w] = false; }
    
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
        sort( ans.begin(), ans.end() );
        return  ans;
    } 
    
}; 

//////////////////////////////////////////////////////////
//               2008 CopyRight(c) by elf               //
//////////////////////////////////////////////////////////


#include <iostream>
using namespace std;

BinMatch    binmatch; 

struct  Rectangle {
    int     x1, x2, y1, y2;
    void get() { cin >> x1 >> x2 >> y1 >> y2; }
    bool inside( int x, int y ) const {
        return  x >= x1 && x <= x2 &&
                y >= y1 && y <= y2;
    }
};

int     T = 1,  N,  x,  y;

vector<Rectangle>   V; 

vector<pair<int, int> > P;

int main() {
    
    while( cin >> N && N ) {
        
        binmatch.init( N, N );
        
        V.resize( N );
        
        for( int i = 0; i < N; ++i )
            V[i].get();
            
        for( int i = 0; i < N; ++i ) {
            cin >> x >> y;
            for( int j = 0; j < N; ++j )
                if( V[j].inside( x, y ) )
                    binmatch.insert( j, i );
        }
        
        binmatch.run();

        cout << "Heap " << T++ << endl;

        bool    success = true; 

        P = binmatch.getMatch();

        for( int i = 0; i < P.size(); ++i ) {
            binmatch.erase( P[i].first, P[i].second );
            binmatch.run();
            binmatch.insert( P[i].first, P[i].second );
            if( binmatch.matchCnt() == N ) {
                swap( P[i--], P.back() );
                P.pop_back();
            }
        } 

        if( P.size() == 0 ) {
            puts( "none\n" );
            continue;
        }
        
        sort( P.begin(), P.end() ); 
        for( int i = 0; i < P.size(); ++i ) {
            if( i ) putchar( ' ' );
            printf( "(%c,%d)", char( P[i].first + 'A' ), P[i].second + 1 );
        }
        puts( "\n" );
        
    }
    
}
