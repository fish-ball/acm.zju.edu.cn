// ��ѧ���⣬���ɻ��� log(b)/b �� log(a)/a �ıȽ�
// ��֤�� f(x) = log(x) / x �� (0, e]�ϵ������� [e, +inf) �ϵ��� 
// ����ö�����ֵ�㷨���� 

#include <cstdio>
#include <cmath>

const double EXP = exp( 1. );
const double EPS = 1e-8;

int main() {
	double	a,	c,	x,	lb,	ub;
	while( scanf( "%lf", &a ) != EOF ) {
		if( a >= EXP ) {
			puts( "-1" );
			continue;
		}
		c = log( a ) / a;
		lb = EXP;
		x = ub = 44.;
		while( ub - lb > EPS ) {
			if( c - log( x ) / x > 0. )		ub = x;
			else					lb = x;
			x = ( ub + lb ) / 2.;
		}
		printf( "%.5lf\n", x );
	}
}
