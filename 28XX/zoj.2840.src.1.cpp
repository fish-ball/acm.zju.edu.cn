// �����̫�����ˣ�ϵͳһֱ˵�� Restrict Function
// ���Ұ��Ұ�������û�취��
// ɾ�� vector
// ɾ�� string :: find()
// ɾ�� string :: substr()

// ȫ���Լ�д -_-| �����ŷŹ���...
// �Ҷ����ƣ���ǰ��û�µİ��� 

#include <string>
#include <iostream>
using namespace std;

bool fit( string s1, string s2 ) {
	if( s1.size() > s2.size() + 1 )	return false;
	int	x = -1;
	for( int i = 0; i < s1.size(); i++ ) {
		if( s1[i] == '*' ) {
			x = i;
			break;
		}
	}
	if( x == -1 )	return s1 == s2;
	for( int i = 0; i < x; i++ ) {
		if( i == s2.size() )	return false;
		if( s1[i] != s2[i] )	return false;
	}
	for( int i = x + 1, j = s2.size() - s1.size() + i; i < s1.size(); i++, j++ ) {
		if( i < 0 )		return false;
		if( s1[i] != s2[j] )	return false;
	}
	return	true;
}


int main() {
	string	D[1000];
	int	M,	T,	N = 0;
	string	temp;
	while( cin >> M ) {
		if( N++ ) cout << endl;
		for( int i = 0; i < M; i++ )	cin >> D[i];
		cin >> T;
		while( T-- ) {
			cin >> temp;
			bool	found = false;
			for( int i = 0; i < M; i++ ) {
				if( fit( temp, D[i] ) ) {
					if( !found )	found = true;
					else		cout << ", ";
					cout << D[i];
				}
			}
			if( !found ) cout << "FILE NOT FOUND";
			cout << endl;
		}
	}
}
