// ֱ�ӵݹ�������
// ����ֻҪ�� 3 �˶ӵ�����
// ��ÿ�η��붼�Ƕ����ģ������
// F(N) -> F(N/2), F((N+1)/2) 
// 2844731 2008-04-15 10:23:37 Accepted 1539 C++ 00:00.33 836K ���͵����� 
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int     count;

void gao( const int& N ) {
    if( N == 3 ) count++;
    if( N <= 3 ) return;
    gao( N / 2 );
    gao( ( N + 1 ) / 2 );
}

int main() {
    int     N;
    while( cin >> N ) {
        count = 0;
        gao( N );
        cout << count << endl;
    }
}
