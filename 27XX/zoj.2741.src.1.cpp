// 2937954 2008-05-31 10:04:35 Accepted 2741 C++ 00:00.01 844K ���͵����� 

// ��������Խλ������ж���ע�����¼��㣺
// 1. �ø���
// 2. ����֮��������൱��Ķ���ո�
// 3. ���Լ��İ볡�����Ϊ x <= 0 

#include <iostream>
#include <vector>
using namespace std;

typedef pair<double, double>  Pos;

int main() {
    
    Pos     player,  ball,  temp;
    vector<Pos> V;
    char    c;
    
    while( cin >> c >> player.first
               >> c >> player.second >> c ) {
        
        V.clear();
        
        cin >> c >> ball.first
            >> c >> ball.second >> c;
        
        while( getchar() == ' ' ) {
            cin >> c >> temp.first
                >> c >> temp.second >> c;
            V.push_back( temp );
        }
        
        if( player.first <= 0.0 ||
            player.first <= ball.first ) {
            puts( "PlayOn" );
            continue;
        }
        
        int     cnt = 0;
        
        for( int i = 0; i < V.size(); ++i )
            if( V[i].first >= player.first )
                ++cnt;
        
        puts( cnt >= 2 ? "PlayOn" : "Offside" );
        
    }
    
}
