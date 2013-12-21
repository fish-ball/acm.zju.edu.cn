// 2943871 2008-06-06 17:10:07 Accepted 1756 C++ 00:00.02 872K ���͵����� 

// ̰��... ���� O(n^2)
// �ò��½�������ȥ����һ�����У�������Ҫ���ٸ����½������С�

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    
    vector<pair<int, int> > V;
    int     X,  Y;
    
    while( 1 ) {
        
        cin >> X >> Y;
        if( X < 0 ) break;
        
        while( 1 ) {
            
            V.push_back( make_pair( X, Y ) );
            cin >> X >> Y;
            
            if( !( X && Y ) ) {
                V.push_back( make_pair( X, Y ) );
                break;
            }
            
        }
        
        sort( V.begin(), V.end() );
        
        int     tot = 0;
        
        for( int i = 0; i < V.size(); ++i ) {
            if( V[i].second ) {
                int now = V[i].second;
                ++tot;
                for( int j = now; j < V.size(); ++j ) {
                    if( V[j].second >= now ) {
                        now = V[j].second;
                        V[j].second = 0;
                    }
                }
            }
        }
        
        cout << tot << endl;
        
    }
    
}
