// 3042713 2008-08-20 11:48:59 Accepted 1693 C++ 00:00.04 872K ���͵����� 

// ģ��...��һ���Ĺ���:
    
// ��¼����ͼ���ڽӱ���¼ÿ�������ʣ���

// ��¼�����߶ȵĶ��㣬Ȼ�����߸���...

// �Ȳ����һ����

// �������Ϊ�����ڵ�ǰ��ߵĶ�������һ������

// �������Ϊ�����ڵ�ǰ��߽ڵ������ĵ� -x ��������һ����

// ע��ά��ʣ��ȱ� 
 
// Ȼ��ÿ������֮�󣬵������е�ǰû��ʣ��ȵ���߶��� 

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int     T,  now;

vector<vector<int> >    V;

vector<int>     deg,    hgt;

int main() {
    
    for( cin >> T; T--; ) {
        
        cin >> now;
        
        V.assign( 1, vector<int>( 0 ) );
        
        deg.assign( 1, now );
        
        hgt.assign( 1, 0 );
        
        while( cin >> now && now ) {
            
            if( now > 0 ) {
                V.push_back( vector<int>( 0 ) );
                deg[hgt.back()] -= 1;
                deg.push_back( now - 1 );
                V.back().push_back( hgt.back() );
                V[hgt.back()].push_back( V.size() - 1 );
                hgt.push_back( V.size() - 1 );
            }

            else {
                V[hgt.back()].push_back( hgt[hgt.size() - 1 + now] );
                V[hgt[hgt.size() - 1 + now]].push_back( hgt.back() );
                deg[hgt.back()] -= 1;
                deg[hgt[hgt.size() - 1 + now]] -= 1;
            }
            
            while( hgt.size() && deg[hgt.back()] == 0 )
                hgt.pop_back();

        }
        
        for( int i = 0; i < V.size(); ++i ) {
            cout << i + 1;
            sort( V[i].begin(), V[i].end() );
            for( int j = 0; j < V[i].size(); ++j )
                cout << ' ' << V[i][j] + 1;
            puts( "" );
        }
        
    }
    
}
