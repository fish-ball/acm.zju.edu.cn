// ����ˮƽ��һ�������⣬���ѣ���Ҫ��һ����
// �� p = 1..9
// ���磺2222 = 222 * 10 + 2
// ��ô����� 2222 % K = ( 222 * 10 % K + 2 % K ) % K 
// ͬ����һ��ʼ�Ϳ�����֪ Xi = ( Xi-1 * 10 + p % K ) % K
// Ȼ������ Xi ȥ�� K ���༴�� 
// ���ң������������� K ��δ�н������ô Xi ����ѭ������ô����Զ��������
// ���Լ�����~~���������˱����֪���� 

#include <iostream>
using namespace std;

int main() {
	int	N;
	while( cin >> N ) {
		bool	found = false;
		for( int i = 1; i < 10; i++ ) {
			int	sum = 0;
			for( int k = 1; k <= N; k++ ) {
				sum = ( sum * 10 + i ) % N;
				if( !sum ) {
					cout << i << ' ' << k << endl;
					found = true;
					break;
				}
			}
			if( found ) break;
		}
		if( found )	continue;
		cout << -1 << endl;
	}
}
