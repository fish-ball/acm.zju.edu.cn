// 1863815 2009-05-11 00:19:15 Accepted  3191 C++ 0 184 ���͵����� 

// ����ʱ��ĽǶ��ж�ʱ����ָ��ʱ��Σ��򵥵ĽǶ�ת�����ɽ���� 

#include <iostream>
using namespace std;

int main() {
    int N;
    while(cin >> N && N != -1) {
        N = (450 - N) % 360;
        if(N % 30 == 0)
            printf("Exactly %d o'clock\n", N / 30);
        else {
            printf("Between %d o'clock and %d o'clock\n", N / 30, (N / 30 + 1) % 12);
        }
    }
}
