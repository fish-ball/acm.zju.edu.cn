// ��������ͷ�󲻸ķ��򻥻����
// ��˵ȼ���ֻ��ֱ��
// �� iostream �ᳬʱ 
#include <cstdio>

int main() {
	int	T,	N,	L,	X,	Y,	temp;
	scanf( "%d", &T );
	while( T-- ) {
		scanf( "%d%d", &L, &N );
		X = Y = 0;
		while( N-- ) {
			scanf( "%d", &temp );
			if( L - temp > Y ) Y = L - temp;
			if( temp > Y ) Y = temp;
			if( temp > L / 2 ) temp = L - temp;
			if( temp > X ) X = temp; 
		}
		printf( "%d %d\n", X, Y );
	}
} 
