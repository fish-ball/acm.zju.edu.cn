// �·�һֱ�ڴ򲹶����ѿ���Ҫ���ĳ���
// ������ʵ���ã���˵û��һԪ�� + - �������Ҳ�൱���� 

#include <cstdio>
#include <cstdlib>
#include <cstring>

int main() {
	char	equ[256];
	int	T;
	scanf( "%d", &T );
	while( T-- ) {
		scanf( "%s", equ );
		// i Ϊ��ǰɨ��ָ�룬j Ϊÿ�����ִ���ʼ��λ�� 
		int	i = 0,	j = 0;
		// x Ϊ x ��ϵ����num Ϊ������ 
		int	x = 0,	num = 0;
		// ���ţ���ǰ����Ϊ sign�������Ѿ������Ⱥţ������һ������ 
		int	sign = 1, past = 1;
		// �˳���� 
		bool	exit = false;
		// ��ȡ���е�ʽ�е���Ϣ 
		while( 1 ) {
			// i ��ǰ��һ���� 
			while( equ[i] && equ[i] != '=' &&
			       equ[i] != '-' && equ[i] != '+' ) i++;
			// �ȴ���÷������� 
			int	label = sign * past;
			if( equ[i] == '+' ) sign = 1;
			else if( equ[i] == '-' ) sign = -1;
			else if( equ[i] == '=' ) { past = -1; sign = 1; } 
			else if( !equ[i] ) exit = true; 
			// ��������Ǻ� x ����
			if( equ[i - 1] == 'x' ) {
				equ[i - 1] = 0;
				int	temp = atoi( equ + j );
				if( !temp ) temp++;
				x += ( label * temp );
			}
			// ������ǳ����� 
			else {
				equ[i] = 0;
				int	temp = atoi( equ + j );
				num += ( label * temp ); 
			}
			// �˳����� 
			if( exit ) break;
			j = ++i;
		}
		if( !x ) if( num ) printf( "IMPOSSIBLE\n" );
		else printf( "IDENTITY\n" );
		else {
			if( num % x == 0 ) printf( "%d\n", num / -x );
			else {
				int	ans = num / -x;
				if( ans < 0 ) ans--;
				printf( "%d\n", ans );
			} 
		}
	}
}
