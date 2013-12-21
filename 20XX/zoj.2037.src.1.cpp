// ��������һ�����������Ų�֣�ʹ���ֺ�ĳ˻���� 
// ̰�ģ��� N <= 4��ֱ�����
// �����ȴ� 2 ��ʼ����� 31 = 2 + 3 + 4 + 5 + 6 + 7 ... 4
// Ȼ��ʣ�����һ�����������������ȥ
// 31 = 2 + 3 + 5 + 6 + 7 + 8
// ���������������
// 34 = 2 + 3 + 4 + 5 + 6 + 7 ... 7����� 
// 34 = 3 + 4 + 5 + 6 + 7 + 8 ... 1����ʣ�� 1 
// �����������©�����ӵ����һ������ȥ
// 34 = 3 + 4 + 5 + 6 + 7 + 9
// 2830932 2008-04-08 14:47:59 Accepted 2037 C++ 00:00.00 840K ���͵����� 

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int     N,  T;
    cin >> T;
    while( T-- ) {
        cin >> N;
        if( N < 5 ) {
            cout << N << endl;
            continue;
        }
        vector<int> V( 1, 2 );
        N -= 2;
        while( N > V.back() ) {
            V.push_back( V.back() + 1 );
            N -= V.back();
        }
        int     pos = V.size() - 1;
        while( N ) {
            N--;
            V[pos--]++;
            if( pos < 0 )
                break;
        }
        if( N ) V.back()++;
        cout << V[0];
        for( int i = 1; i < V.size(); i++ )
            cout << ' ' << V[i];
        cout << endl;
        if( T )   cout << endl;
    }
}
