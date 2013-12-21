// 2941869 2008-06-04 17:57:30 Accepted 1787 C++ 00:00.09 936K ���͵����� 

// nlogn �� LIS(����½�������) 
// �㷨�� 1986���ڱ��⣬�Ȱ� l ά�������� m ά��������������� 

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int> > V;
int     D[10001],   N,  len;

int main() {
    
    while( cin >> N && N ) {
        
        V.resize( N );
        for( int i = 0; i < N; ++i )
            cin >> V[i].first >> V[i].second;
        sort( V.begin(), V.end() );

        D[len = 0] = 0;
        for( int i = 0; i < N; ++i ) {
            if( D[len] <= V[i].second )
                D[++len] = V[i].second;
            else {
                int*    pos = upper_bound( D, D + len, V[i].second );
                *pos = V[i].second;
            }
        }
        
        cout << len << endl;
        
    }
    
    puts( "*" );
    
}
