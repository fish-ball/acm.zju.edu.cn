// 3067120 2008-09-12 09:26:43 Accepted 2814 C++ 00:00.00 2988K ���͵����� 

//     ��ģ�⣬������ͺã���һ���ַ��������ղ�ͬ�ļ�� D Ϊ�ȼ���ȡ�����ַ��ԣ� 
// ���������еȼ��������Ķ�û���ظ��ģ����� surprising����֮���ǡ� 

#include <iostream> 
#include <cstring> 
#include <vector>
using namespace std;

int main()
{ 
	char	x[80],	y[80];
	bool	flag[80];
	while( cin >> x) {
		if( *x == '*' )	break; 
		strcpy( y, x );
		int	L = strlen(x);
		bool	exit = 0;
		for( char* p = y + 1; p - y < L - 1; p++ ) {
			int	N = L - (p - y);
			for( int i = 0; i < N; i++ )
				flag[i] = 0;
			for( int i = 0; i < N; i++ ) {
				if( flag[i] )	continue;
				flag[i] = 1;
				char temp = x[i];
				vector<char> garbage;
				garbage.resize(0);
				garbage.push_back(p[i]);
				for( int j = i + 1; p[j] != 0; j++ ) {
					if( x[j] == temp ) {
						flag[j] = 1;
						garbage.push_back(p[j]);
					}
				}
				for( int j = 0; j < garbage.size(); j++ ) {
					for( int k = j + 1; k < garbage.size(); k++ ) {
						if( garbage[j] == garbage[k] ) {
							exit = 1;
							break;
						}
					}
					if( exit )	break;
				}
				if( exit )	break;
			}
			if( exit )	break;
		}
		if(exit)	cout << x << " is NOT surprising." << endl;
		else		cout << x << " is surprising." << endl;
	}
}
