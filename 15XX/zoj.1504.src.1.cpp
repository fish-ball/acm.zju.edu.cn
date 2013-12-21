// 2955554 2008-06-24 00:42:45 Accepted 1504 C++ 00:00.01 848K ���͵����� 

// ����Ч�ʵ��Ҹ㣬̫�����...

// ԭ���ķ������������������ĶԳƵ����������һ��
// Ȼ����ԭ������������ĶԳ�Ҳ��
// ���ǿ��ٻ���һ���Ҹ�ķ���
// ���Ǳ��������������ε������������������
// ��Ȼ���׵ľ� AC �� 

#include <iostream>
#include <string>
#include <set>
#include <iterator>
#include <algorithm>
using namespace std;

char        G[12][12];
int         N,  pos;
string      str;
set<char>   S;
set<char>::iterator it;

// M ���������εĴ�С��x, y �����Ͻǵ������ 
void scan( int M, int x, int y ) {
    int k = M / 2;
    for( int i = 0; i < k; ++i ) {
        for( int j = 0; j < M - 1 - i - i; ++j ) {
            if( G[x+j+i][y+i] == G[x+M-1-i][y+i+j] &&
                G[x+j+i][y+i] == G[x+M-1-i-j][y+M-1-i-j] )
                S.insert( G[x+j+i][y+i] );
        }
    }
}

int main() {
    
    while( cin >> N && N ) {
    
        cin >> str;
        
        memset( G, 0, sizeof( G ) );
        
        int pos = 0;
        for( int i = 0; i < N; ++i )
            for( int j = 0; j <= i; ++j )
                G[i][j] = str[pos++];
    
        S.clear();
        
/*  ���������ʾ�����Σ������׼� '/' ע�ͱ��м��� 
        for( int i = 0; i < N; ++i )
            cout << G[i] << endl;
//*/
        
        for( int i = 0; i < N; ++i ) {
            for( int j = 0; j <= i; ++j ) {
                for( int p = 2; p + i <= N; ++p ) {
                    scan( p, i, j );
                }
            }
        }
        
        if( S.empty() )
            puts( "LOOOOOOOOSER!" );
    
        else {
            copy( S.begin(), S.end(), ostream_iterator<char>( cout ) );
            puts( "" );
        }
        
    
    }
    
}
