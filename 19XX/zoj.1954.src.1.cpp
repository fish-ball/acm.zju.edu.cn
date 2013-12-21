// 3014060 2008-07-30 16:26:36 Accepted 1954 C++ 00:00.04 1096K ���͵����� 

// �ҹ��ɣ�ÿһȦ������͵��Ǹ�ʼ
// ����߳�Ϊ step����ô��
// 1. ���� step
// 2. ���� step
// 3. ���� step
// 4. ���� step
// 5. ���� step + 1
// 6. ���� step
// 7. step = step + 1���� 1. 

#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int> > V;

pair<int, int> operator + ( pair<int, int> p1, pair<int, int> p2 ) {
    return  make_pair( p1.first + p2.first, p1.second + p2.second );
}

int main() {
    
    V.push_back( make_pair( 0, 0 ) );
    V.push_back( make_pair( 0, 0 ) );
    V.push_back( make_pair( 0, 1 ) );
    
    for( int step = 1; step < 90; ++step ) {
        for( int i = 0; i < step; ++i )
            V.push_back( V.back() + make_pair( -1, 0 ) );
        for( int i = 0; i < step; ++i )
            V.push_back( V.back() + make_pair( 0, -1 ) );
        for( int i = 0; i < step; ++i )
            V.push_back( V.back() + make_pair( 1, -1 ) );
        for( int i = 0; i < step; ++i )
            V.push_back( V.back() + make_pair( 1, 0 ) );
        for( int i = 0; i <= step; ++i )
            V.push_back( V.back() + make_pair( 0, 1 ) );
        for( int i = 0; i < step; ++i )
            V.push_back( V.back() + make_pair( -1, 1 ) );
    }
    
    int     N;
    
    while( cin >> N )   
        cout << V[N].first << ' '
             << V[N].second << endl;
    
}
