// �бպϹ�ʽ�����û��ɷ��������ʽ��ע�����ݷ�Χ 

#include <iostream>
using namespace std;

int main() {
	int	N;
	long long	X;
	cin >> N;
	for( int i = 1; i <= N; i++ ) {
		cin >> X;
		cout << i << ' ' << X << ' ' <<
		( X * ( X * ( X * ( X + 6 ) + 11 ) + 6 ) / 8 ) << endl;
	}
}
