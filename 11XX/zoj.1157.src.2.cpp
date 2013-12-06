// 3025417 2008-08-06 21:19:18 Accepted 1157 C++ 00:00.37 1032K ���͵����� 

// �ڽӾ���ʵ�֣��� 

// ÿ����ͷ��һ�����ͣ�ÿ�������һ������ 
// ����������Ӧ�����Ϳ�ת���Ĵ��ݱհ�������������ݱհ�
 
// Ҫ�ò�ͷ�Ͳ�������ƥ�� 
// ���ɶ���ͼ�����ĳ����ͷ���������пɴ�ĳ����׵����ͣ���ô����һ���� 


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
#include <string>
#include <map>
using namespace std;

BinMatch    binmatch;

int     T,  x,  y;
int     type_cnt,   receptacle_cnt,
        device_cnt, adapter_cnt;

map<string, int>    type;

string  input;

int     receptacle[100],    device[100];

bool    adapter[400][400];

int getIndex( string name ) {
    if( type.find( name ) == type.end() )
            return  type[name] = type_cnt++;
    else    return  type[name];
}

int main() {
    
    for( cin >> T; T--; ) {
        
        type_cnt = 0;
        type.clear();
        
        cin >> receptacle_cnt;
        for( int i = 0; i < receptacle_cnt; ++i ) {
            cin >> input;
            receptacle[i] = getIndex( input );
        }
        
        cin >> device_cnt;
        for( int i = 0; i < device_cnt; ++i ) {
            cin >> input >> input;
            device[i] = getIndex( input );
        }
        
        cin >> adapter_cnt;
        memset( adapter, 0, sizeof( adapter ) );
        
        for( int i = 0; i < adapter_cnt; ++i ) {
            cin >> input;
            x = getIndex( input );
            cin >> input;
            y = getIndex( input );
            adapter[x][y] = true;
        }

        // ���ݱհ� 
        for( int i = 0; i < type_cnt; ++i )
            for( int j = 0; j < type_cnt; ++j )
                for( int k = 0; k < type_cnt; ++k )
                    if( adapter[j][i] && adapter[i][k] )
                        adapter[j][k] = true;

        for( int i = 0; i < type_cnt; ++i )
            adapter[i][i] = true;
        
        binmatch.init( device_cnt, receptacle_cnt );
        
        for( int i = 0; i < device_cnt; ++i )
            for( int j = 0; j < receptacle_cnt; ++j )
                if( adapter[device[i]][receptacle[j]] )
                    binmatch.insert( i, j );
                    
        binmatch.run();
        
        cout << device_cnt - binmatch.matchCnt() << endl; 
        
        if( T ) puts( "" ); 

    }
    
}
