// 3059199 2008-09-04 12:23:56 Accepted 1582 C++ 00:00.00 836K ���͵����� 

// ��ô�򵥵��ַ����⣬��Ȼ 1WA
// ԭ����û���ǿո�Ҳ���ַ�����һ����
// ���ֻ���� getline �������� cin >> s 

#include <iostream>
#include <string>
using namespace std;

int main() {
	int	T,	dt,	pos;
	string	corr,	mstk;
	cin >> T;
	while( T-- ) {
		cin >> dt;
		getchar();
		getline( cin, corr );
		getline( cin, mstk );
		for( pos = 0; pos < corr.size() && pos < mstk.size(); pos++ )
			if( corr[pos] != mstk[pos] ) break;
		cout << dt * ( mstk.size() + corr.size() - pos - pos ) << endl;
	}
}
