// 1810949 2009-03-30 21:02:37 Accepted  1633 C++ 30 184 ���͵����� 

// �ݹ飬��Ϊǰ׺��һ�µġ������֪������������ָ�����ģ����� Fibonacci ��һ����
// ������ǿ����� log(N) ��ʱ��֪�������� N ���ڵڼ��ε����м���ġ�
// Ҳ����˵������� f(k) ����ʾ�� k �ε���ʱ�ܴ��ĳ��ȣ�
// ��ô f(0) = 4, f(1) = 3, f(2) = 7, f(k+1) = f(k) + f(k-1)��
// ������ a = f(k-1) < N < f(k) = b����ôҲ���Եõ��ݹ�ʽ��
// f(N) = f(N - a)��Ȼ��ê���� f(1~7) = "T.T^__^"��

#include <iostream>
using namespace std;

typedef long long i64;

char* str = "T.T^__^";

char gao(i64 n) {
    if(n <= 7) return str[n - 1];
    i64 a = 3, b = 7;
    while(b < n) {
        i64 c = a + b;
        a = b;
        b = c;
    }
    return gao(n - a);
}

int main() {
    i64 N;
    while(cin >> N) cout << gao(N) << endl;
}
