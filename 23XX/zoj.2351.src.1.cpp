// XXXX��а����⣬���ⳬ�Ѷ�
// ���˺ܾò�֪��ԭ����������
// ��������һ���ᣬ���ŵ�ˮ��������һ�����ܻ������H+������һ���ֲ��ܣ�û��H+��
// �����ܻ����������[acid ions]�����ܵ�����[acid]�� 
// ��ô��Ka = [H+][acid ions]/[acid];
// ����[H+]��ʾ��[acid ions]��ô���������ж��ٸ�[H+]
// ��ΪKa�ǹ̶��ģ���ô�����Һ����ٷֱ���a*100%
// ��1(L)����Һ����a(mol)������ӣ�������������x(mol)�ᱻ�ܽ�
// ����1���ܽ������Ӻ�m��[H+]��n��������ӣ����ǣ�
// [H+] = x*m 
// [acid ions] = x*n
// [acid] = a - x
// �������ǵó���ʽ:
// Ka = ( x * x * n * m ) / ( a - x )
// ����Ҫ�����[H+]�����Ӧ�û���t[H+] = x*m���õ�
// Ka = ( t * t * n / m ) / ( a - t / m ) 
// ����һ�¹�ʽ���õ���
// n * t * t + Ka * t - Ka * m * a = 0
// ������η��������ʽ�� t 
// t = ( sqrt( Ka * Ka + 4. * n * Ka * m * a ) - Ka ) / 2. / n 
// ������� - log10(t) 

#include <cstdio>
#include <cmath>

int main() {
	int	T;
	scanf( "%d", &T ); 
	while( T-- ) {
		double	Ka, a, m, n;
		while( 1 ) {
			scanf( "%lf%lf%lf%lf", &Ka, &a, &m, &n );
			if( Ka == 0 && a == 0 && m == 0 && n == 0 )
				break;
			printf( "%.3lf\n", -log10( ( sqrt( Ka * Ka + 4. * n * Ka * m * a ) - Ka ) / 2. / n ) );
		}
		if( T ) putchar( '\n' ); 
	} 
} 
