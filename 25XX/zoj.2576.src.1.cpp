// 2960058 2008-07-02 19:51:16 Accepted 2576 C++ 00:00.22 908K ���͵����� 

// �������ת��Ϊ�� 2 * k �������з֣�ʹ����С�ڵ��� k 

// �� DFS ���ɾͺ��ˣ���ȷ�����Ԫ�صĸ���...
// ע�������˳����Ҫ���е��ֵ����������˵��ȴ����� sort һ�� 

#include <iostream>
#include <vector>
#include <iterator> 
#include <algorithm>
using namespace std;

int     K;
int     V[21]; 
vector<vector<int> >    ans; 

void DFS( int N, int top, int remain ) {
    
    if( top > N ) {
        if( remain )    return; 
        vector<int> v;
        copy( V + 1, V + 1 + N, back_inserter( v ) );
        ans.push_back( v ); 
        return;
    }
    
    for( V[top] = V[top-1]; V[top] <= K; ++V[top] ) {
        if( ( N - top + 1 ) * V[top] > remain ) break;
        DFS( N, top + 1, remain - V[top] );
    }
    
}

int main() {

    V[0] = 1;

    while( scanf( "%d", &K ) && K ) {
        
        ans.clear(); 

        for( int i = 2 * K; i >= 2; --i )
            DFS( i, 1, 2 * K );
            
        sort( ans.begin(), ans.end() );
        
        for( int i = 0; i < ans.size(); ++i ) {
            cout << '{' << ans[i][0];
            for( int j = 1; j < ans[i].size(); ++j )
                cout << ',' << ans[i][j];
            cout << '}' << endl; 
        } 
        
        puts( "" );

    }

}
