// �������м���������
// ����˼·�ǣ��������򷨣�����������(index)��ͬʱ����ԭʼ�� inversion ��Ŀ
// ��һ����O(n^2) 
// Ȼ����� rotation ������� rotation �ǲ������������ģ�
//     rotate ĳ��Ԫ�ػ�������ٸ� inversion �ĸı���Դ����� index �з�ӳ����
// �ڶ�����O(n) 

// ���ۣ�����������ĺܺ���
// ���ǣ��ύ���ԭ����������ô���룬��Ȼ 1AC������ 0.19s��420K�������Ų��ϰ� 

#include <cstdio>

int main() {
	int	N,	A[5000];
	short	index[5000];
	while( scanf( "%d", &N ) != EOF ) {
		int	inv = 0;
		for( int i = 0; i < N; i++ ) {
			index[i] = 0;
			scanf( "%d", A + i );
			for( int j = 0; j < i; j++ ) {
				if( A[i] > A[j] )
					index[i]++;
				else {
					index[j]++;
					inv++;
				}
			}
		}
		int	min = inv;
		for( int i = 0; i < N; i++ ) {
			inv += ( N - ( index[i] << 1 ) - 1 );
			if( inv < min ) min = inv;
		}
		printf( "%d\n", min );
	}
}
