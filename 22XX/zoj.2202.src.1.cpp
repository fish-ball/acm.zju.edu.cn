// ���ѵ� 1 ά DP��O(n)���������һ��������Բ��ܺ��ԣ�
// ��Ϊ 0 ��û�б���ģ�
// 2866342 2008-04-24 17:07:17 Accepted 2202 C++ 00:00.02 876K ���͵����� 

#include <iostream>
#include <string>
using namespace std;

int main() {
    string  s;
    while( ( cin >> s ) && s != "0" ) {
        int x = 1, y = 1, z;
        for( int i = 1; i < s.size(); i++ ) {
            if( s[i] == '0' ) y = x;
            else if( s[i - 1] == '1' ||
                s[i - 1] == '2' &&
                s[i] <= '6' ) {
                z = x + y;
                x = y;
                y = z;
            }
            else x = y;
        }
        cout << y << endl;
    }
}
