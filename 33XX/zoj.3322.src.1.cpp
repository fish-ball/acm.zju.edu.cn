// 2168909 2010-04-19 13:19:33 Accepted  3333 C++ 0 184 ���͵����� 

// -____-b���ܻ�������ţ����⼦���ں��� 

// 2168921 2010-04-19 13:28:30 Accepted  3322 C++ 10 184 ���͵����� 

// -____-b ���Ѳ����⼦�ı��ʡ��� 

#include <iostream>
#include <cmath>
using namespace std;

int eval(int a, int b, int c) {
    --a; --b; --c;
    return (a * 12 + b) * 31 + c;
}

int main() {
    int N, A1, A2, A3, B1, B2, B3;
    for(cin >> N; N--;) {
        cin >> A1 >> A2 >> A3 >> B1 >> B2 >> B3;
        if(eval(A1, A2, A3) == eval(B1, B2, B3)) puts("same");
        else if(eval(A1, A2, A3) < eval(B1, B2, B3)) puts("javaman");
        else puts("cpcs");
    }
}
