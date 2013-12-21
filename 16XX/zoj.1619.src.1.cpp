// 2941337 2008-06-04 02:03:42 Accepted 1619 C++ 00:00.02 388K ���͵����� 

// ���Ź�ʽ http://baike.baidu.com/view/668994.htm
// ���� P = N ��ȡ N - M ������ / ȫ���� 
// P = C(N, M) * ����(N - M) / N!
// ����(X) = X! * ( 1/0! - 1/1! + 1/2! - ... ? 1/X! )
// �� ����(X) = X! * Cros(X)
// ����� P = Cros(N-M) / M!
// �� DP ������� 

#include <cstdio>
#include <cmath>

int main() {
    
    double  Fac[100],   Cros[100];
    
    Fac[0] = 1;
    
    for( int i = 1; i < 100; ++i )
        Fac[i] = Fac[i-1] / i;
    
    Cros[0] = Fac[0];
    for( int i = 1; i < 100; ++i ) {
        if( i & 1 )
            Cros[i] = Cros[i - 1] - Fac[i];
        else
            Cros[i] = Cros[i - 1] + Fac[i];
    }
    
    int M,  N;
    while( scanf( "%d%d", &N, &M ) != EOF )
        printf( "%.8lf\n", Cros[N-M] * Fac[M] );
    
}
