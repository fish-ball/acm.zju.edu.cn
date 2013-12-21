// 2951397 2008-06-17 13:05:03 Accepted 1950 C++ 00:00.00 840K ���͵����� 

// DP��DP[i][j] ��¼�� i �� �� j �� ʤ���ĸ��� 

#include <iostream>
#include <string>
using namespace std;

string  team[16];
double  DP[16][5];
double  R[16][16];

int main() {
    
    for( int i = 0; i < 16; ++i ) {
        cin >> team[i];
        team[i] += string( 11 - team[i].size(), ' ' );
    }
    
    for( int i = 0; i < 16; ++i ) {
        for( int j = 0; j < 16; ++j ) {
            cin >> R[i][j];
            R[i][j] /= 100.0;
        }
    }
    
    for( int t = 0; t < 16; ++t )
        DP[t][0] = 1.0;
    
    for( int r = 1; r < 5; ++r ) {
        for( int t = 0; t < 16; ++t ) {
            int bg = t >> r << r;
            for( int p = 0; p < 1 << r; ++p ) {
                if( bg + p == t )   continue;
                if( ( bg + p ) >> ( r - 1 ) << ( r - 1 ) ==
                    t >> ( r - 1 ) << ( r - 1 ) )
                    continue;
                DP[t][r] += DP[t][r-1] * DP[bg+p][r-1] * R[t][bg+p];
            }
        }
    }
       
    for( int i = 0; i < 16; ++i ) {
        printf( "%sp=%.2lf%c\n",
            team[i].c_str(), DP[i][4] * 100.0, '%' );
    }
        
}
