// 3010907 2008-07-28 18:32:35 Accepted 1019 C++ 00:00.02 932K ���͵����� 

// ��Ŀ�����ǻ�������һϵ�е�ָ����ĸ������ߡ� 
// �����ߵĲ���������һ�����������ֵ�� 
// ��ͼ�������ɸ��ϰ���ʴ���Щ�㿪ʼ���п��ܲ������ϰ�� 
// ��������ĵ�ĸ����� 

// �� DP �����������⣺
// ��һ������ά�����е㣬��ʼ��ʱ�������������װ������û���ϰ���ĵ�
// Ȼ�󣬴����һ��ָ�ʼ��ɨ�����������Ԫ�أ��õ���һ�ֺϷ��ĵ��
// һֱ�������ʣ�µĺϷ��������Ϊ���
// ���ڶ���Ԫ�ز����ظ�����˲��� set ���� 

#include <iostream>
#include <set>
#include <cstdio> 
using namespace std; 

int     T,  M,  N;

bool    B[100][100];

int     X[100], Y[100], K;

char    D[101];

set<pair<int, int> >    S,  R;
set<pair<int, int> >::iterator  iter;

int main() {
    
    for( scanf( "%d", &T ); T--; ) {
        
        scanf( "%d%d", &M, &N );
        
        S.clear();
        
        for( int i = 0; i < M; ++i ) {
            for( int j = 0; j < N; ++j ) {
                cin >> B[i][j];
                if( !B[i][j] ) S.insert( make_pair( i, j ) );
            }
        }
        
        K = 0;
        while( scanf( "%d%d", X + K, Y + K ) && ( X[K] || Y[K] ) )
            cin >> D[K++];
            
        while( --K >= 0 ) {
        
            R.clear();
        
            int dx, dy, x,  y,  px, py;
            
            switch( D[K] ) {
                case 'D': dx = -1; dy =  0; break;
                case 'U': dx =  1; dy =  0; break;
                case 'R': dx =  0; dy = -1; break;
                case 'L': dx =  0; dy =  1; break;
            }
            
            for( iter = S.begin(); iter != S.end(); ++iter ) {
                x = iter -> first;  y = iter -> second;
                for( int i = 1; i <= Y[K]; ++i ) {
                    px = x + i * dx;
                    py = y + i * dy;
                    if( px < 0 || px >= M || py < 0 || py >= N 
                               || B[px][py] )   break;
                    if( i >= X[K] ) R.insert( make_pair( px, py ) );
                }
            }
            
            S = R;
            
        }
        
        cout << S.size() << endl;
            
    }
    
} 
