// 3024905 2008-08-06 17:26:21 Accepted 1137 C++ 00:06.27 940K ���͵����� 

// ����С����֧�伯�Ĳ��� 

// ���� DFS����ͼ���� 2 ��ɫ��Ȼ����ݶ��ּ��������ͼ 

// ���� Konig ����������ͼ�����ƥ����������С�������伯�Ĵ�С

// Ȼ�����Ĳ�����С����ȫ����ȥ������ƥ���� 


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
using namespace std; 

int     N,  X,  Y;

vector<int> V[2000]; 

enum Color { GRAY, WHITE, BLACK }; 
Color   clr[2000];
int     idx[2000];

BinMatch    binmatch; 

void DFS( int v, Color c ) {
    clr[v] = c;
    if( c == WHITE )
            idx[v] = X++; 
    else    idx[v] = Y++; 
    c = c == WHITE ? BLACK : WHITE;
    for( int i = 0; i < V[v].size(); ++i )
        if( clr[V[v][i]] == GRAY )
            DFS( V[v][i], c ); 
} 

int main() {
    
    while( cin >> N ) {
        
        for( int i = 0; i < N; ++i ) {
            char    c; 
            clr[i] = GRAY; 
            cin >> X >> c >> c >> Y >> c;
            V[X].resize( Y );
            for( int j = 0; j < Y; ++j )
                cin >> V[X][j]; 
        }
        
        for( int i = X = Y = 0; i < N; ++i )
            if( clr[i] == GRAY )
                DFS( i, BLACK );

        binmatch.init( X, Y );

        for( int i = 0; i < N; ++i )
            if( clr[i] == WHITE )
                for( int j = 0; j < V[i].size(); ++j )
                    binmatch.insert( idx[i], idx[V[i][j]] );
        
        binmatch.run();
        
        cout << N - binmatch.matchCnt() << endl; 
        
    } 
    
} 
