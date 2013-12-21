// 1801496 2009-03-24 09:01:08 Accepted  3175 C++ 170 184 ���͵����� 

// �����е�С�������ɣ��� SUM(N div i - 1), i = 1..N��
// ö�� i��p = N div i�����Եõ���ǰ i �Ľ���� p + 1��
// Ȼ������ͬ��������ж��ٸ���ȡ t = N / i + 1��
// ��ôͬ���Ľ���� (p - 1) * (t - i)���ۼ�������
// Ȼ�󲽽�������Ϊ i = t �滻��������Ч��Լ O(sqrt(N))�� 

#include <iostream>
using namespace std;

int main() {
    int T, N;
    for(cin >> T; T--;) {
        cin >> N;
        long long ans = 0;
        for(int p = 1, q, t; p < N;) {
            q = N / p;
            t = N / q + 1;
            ans += (q - 1) * (t - p);
            p = t;
        }
        cout << ans << endl;
    }
}
