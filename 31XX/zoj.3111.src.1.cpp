// 1842156 2009-04-23 16:59:46 Accepted  3111 C++ 90 184 ���͵����� 

// �����ŵ�����ܷ��̳ɶ�ά�����ڵ�ĳ��ͼ�����ɹ�Լ�ɶ���ƥ�䡣
// ƥ����������㼯ΪҪ����������ż������������������ڣ���ô�������ߡ�
// ����������ϵȴ���ƥ�������ģ���ô������ǿ��ܵģ���֮��Ȼ�� 

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
using namespace std;

int main() {
    BinMatch bm;
    int M, N;
    char G[60][61];
    int T = 1;
    while(cin >> M >> N && M) {
        for(int i = 0; i < M; ++i)
            cin >> G[i];
        cout << "Case " << T++ << ": ";
        vector<int> h, g;
        for(int i = 0; i < M; ++i) {
            for(int j = 0; j < N; ++j) {
                if(G[i][j] == '#') {
                    if(i + j & 1) h.push_back(i * N + j);
                    else g.push_back(i * N + j);
                }
            }
        }
        if(h.size() != g.size()) { puts("Impossible"); continue; }
        bm.init(h.size(), g.size());
        for(int i = 0; i < h.size(); ++i) {
            for(int j = 0; j < g.size(); ++j) {
                int xh = h[i] % N, yh = h[i] / N; 
                int xg = g[j] % N, yg = g[j] / N; 
                if(xh == xg && (yh - yg == 1 || yh - yg == -1) ||
                   yh == yg && (xh - xg == 1 || xh - xg == -1))
                   bm.insert(i, j);
            }
        }
        bm.run();
        puts(bm.matchCnt() == h.size() ? "Possible" : "Impossible");
    }
}
