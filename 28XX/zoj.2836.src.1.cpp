// �ݳ�ԭ������λ���������ɼ��ϵ������Ӽ�
// ����Ӽ�Ԫ�ظ���Ϊ�棬�� sum += M / �Ӽ�����С������
// ���� sum -= ...
// ԭ�����㷨���Ӷ�Ϊ 2^N  NP��ȫ����ʤ�ڹ�ģ��С������������ 

// ������� WA �����Σ�������������... 

#include <cstdio>
#include <cstring>

int lcm( int x, int y ) {
	int	m = x,	n = y,	r;
	if( m < n ) {
		r = n;
		n = m;
		m = r;
	}
	while( n ) {
		r = m % n;
		m = n;
		n = r;
	}
	return	x * y / m;
}

int main() {
	int	M,	N,	temp,	sum;
	int	A[11];
	while( scanf( "%d%d", &N, &M ) != EOF ) {
		for( int i = 0; i < N; i++ )
			scanf( "%d", A + i );
		int	sum = 0;
		int	v = 1 << N;
		for( int comb = 1; comb < v; comb++ ) {
			int	count = 0,	factor = 1;
			for( int j = 0; j < N; j++ ) {
				if( ( 1 << j ) & comb ) {
					count++;
					factor = lcm( factor, A[j] );
				}
			}
			if( count % 2 )	sum += M / factor;
			else		sum -= M / factor;
		}
		printf( "%d\n", sum );
	}
}
