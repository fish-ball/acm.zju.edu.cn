// 1888871 2009-06-01 01:39:15 Accepted  3163 C++ 150 184 ���͵����� 

// ƻ���⣬x �� y ���ù���� n-1������� 0 ��� 0�� 

#include <iostream>
using namespace std;

int main() {
    int N, x, y;
    while(cin >> N >> x >> y)
        cout << (N ? N - 1 : N) << endl;
}
