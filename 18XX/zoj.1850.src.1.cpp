// 1664572 2008-10-12 18:07:34 Accepted  1850 C++ 0 184 ���͵����� 

// �� x! �ܷ� y ������
// �� y ��ʽ�ֽ⣬������һ�������� i����� y �� t ������ i�� 
// �� x! �� i ���� < t �����������������û�еĻ������������� 
// ע�⴦�������� 0 ������� 

#include <iostream>
using namespace std;

typedef long long i64;

int main() {
    i64 x, y, z, n, t, p;
    while(cin >> x >> y) {
        if(y == 0) {
            cout << y << " does not divide " << x << "!" << endl;
            continue;
        }
        p = x;
        if(x == 0) x = 1;
        bool yes = true;
        z = y;
        for(i64 i = 2; i * i <= z; ++i) {
            if(z % i == 0) {
                t = 0;
                while(z % i == 0) {
                    z /= i;
                    ++t;
                }
                n = x;
                while(n /= i) t -= n;
                if(t > 0) yes = false;
            }
        }
        if(x < z) yes = false;
        if(yes) cout << y << " divides " << p << "!" << endl;
        else cout << y << " does not divide " << p << "!" << endl;
    }
}
