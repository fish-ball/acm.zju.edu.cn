// ����Ҳ�Ƚ�Ѫ�ȣ�Ӧ�����й�ʽ�ģ����������� 
#include <iostream>
using namespace std;

int main() {
	int	N;
	while( cin >> N ) {
		if( N % 2 == 0 || N == 1 ) {
			cout << "2^? mod " << N << " = 1" << endl;
			continue;
		}
		int	n = 2 % N;
		for( int i = 1; i <= 2 * N; i++ ) {
			if( n == 1 ) {
				cout << "2^" << i << " mod " << N << " = 1" << endl;
				break;
			}
			else	n = ( 2 * n ) % N;
		}
	}
}
