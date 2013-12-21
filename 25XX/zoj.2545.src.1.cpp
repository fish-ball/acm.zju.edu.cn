// 2893100 2008-05-06 14:47:33 Accepted 2545 C++ 00:00.08 3968K ���͵����� 

// �����ۣ����ñȽ�Ѫ��
// Ҫ�󲻱� 2^D ��� N! ����� N
// ת��һ�£����� log( N! ) < log( 2^D )
// �� log2( N! ) < D
// �� sum( log2(i), i = 1..N ) < D
// �������� sum( log2(i), i = 1..n ) �Ĳ��ֺ�
// Ȼ����� D ���� 

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

double  D[400000];

int main() {
    
    int     N;
    double  bit;
    const double log2 = log( 2.0 );

    D[0] = 0.0;
    for( int i = 1; i < 400000; ++i )
        D[i] = D[i - 1] + log( double( i ) ) / log2;

    while( ( cin >> N ) && N ) {

        N = ( N - 1960 ) / 10;
        bit = 4;
        while( N-- > 0 )    bit *= 2;
        cout << ( lower_bound( D, D + 400000, bit ) - D ) - 1 << endl;

    }
    
}
