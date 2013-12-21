// 3037510 2008-08-16 10:46:09 Accepted 2192 C++ 00:00.00 864K ���͵����� 

// �����׹�Լ��һ��ƥ������ 

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
#include <string>
using namespace std;

BinMatch    binmatch;

int     N,  S[5];

string  X[20],  input;

int     MP[128];

int main() {
    
    MP['S'] = 0;
    MP['M'] = 1;
    MP['L'] = 2;
    MP['X'] = 3;
    MP['T'] = 4;
    
    while( cin >> input && input == "START" ) {
        
        cin >> N;
        
        for( int i = 0; i < N; ++i )
            cin >> X[i];
            
        for( int i = 0; i < 5; ++i )
            cin >> S[i];
            
        cin >> input;
            
        binmatch.init( N, S[0] + S[1] + S[2] + S[3] + S[4] );
        
        int pos,    cnt; 
        for( cnt = pos = 0; pos < 5; ++pos ) {
            for( int i = 0; i < S[pos]; ++i, ++cnt ) {
                for( int j = 0; j < N; ++j ) {
                    int x = MP[X[j][0]],    y = MP[X[j][1]];
                    if( x <= pos && y >= pos )
                        binmatch.insert( j, cnt );
                }
            }
        }
        
        binmatch.run();
        
        puts( 
            binmatch.matchCnt() == N ?
            "T-shirts rock!" :
            "I'd rather not wear a shirt anyway..."
        );
        
    }
    
}
