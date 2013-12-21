// �ҿ�����������
// zoj �������ٴ���ƭ�ҵĸ��飡��
// 1 WA������֮��ȥ poj �� Forum������˵ poj ���� zoj ������
// Ȼ����� poj submit����� AC
// �ҿ���Ȼ�������������� zoj Ҳ AC ��
// �޳ܵ� zoj ���ݣ������ǵڶ����ˣ����ϴ�Ҳ��������̫С���� WA����
 
#include <cstdio>
#include <cstring>

int main() {
	// ����������, 1�������� 
	char	A[40000];
	memset( A, 1, 40000 );
	A[0] = A[1] = 0;
	for( int i = 2; i <= 200; i++ )
		if( A[i] )
			for( int j = i + i; j < 40000; j += i )
				A[j] = 0;
	int	Prime[5000],	top = 0;
	for( int i = 2; i < 40000; i++ )
		if( A[i] ) Prime[top++] = i;
	// ��ʼ��ʱ��Ȩ��+���� 
	int	N;
	while( scanf( "%d", &N ) != EOF ) {
		if( !N ) break;
		int	sum = 0;
		int	bnd = ( N + 1 ) / 2;
		for( int i = 0; Prime[i] <= bnd; i++ )
			if( A[N - Prime[i]] )
				sum++;
		printf( "%d\n", sum );
	}
}
