// �ǵ���һ���Ƚ���������������
// �ܼ� 

#include <cstdio>

int main() {
	unsigned	N;
	while( scanf( "%d", &N ) && N ) {
		int	sum = 0;
		while( N > 1 ) {
			N = ( N + 1 ) / 2;
			sum++;
		}
		printf( "%d\n", sum );
	}
}
