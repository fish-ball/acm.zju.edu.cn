// 1795838 2009-03-21 02:19:12 Accepted  2688 C++ 470 4092 ���͵����� 

// �������һ�����Ż��⣬��ſ�������̰�ĵķ��롣
// ��ĿҪ��һ�� 5 ά�ռ�� Manhattan ���� N ����Զ��Ծ��룬
// ������ O(2 ^ 5 * N) �ķ��������������ⱨ�档 

#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int N;

double V[100000][5];

double MAX[16], MIN[16];

double eval(double A[5], int K) {
    double ans = A[4];
    for(int i = 0; i < 4; ++i) {
        if(K % 2) ans += A[i];
        else ans -= A[i];
        K /= 2;
    }
    return ans;
}

int main() {
    while(cin >> N && N) {
        for(int i = 0; i < 16; ++i) {
            MIN[i] = 1e99;
            MAX[i] = -1e99;
        }
        for(int i = 0; i < N; ++i) {
            for(int j = 0; j < 5; ++j)
                scanf("%lf", &V[i][j]);
            for(int k = 0; k < 16; ++k) {
                MAX[k] = max(MAX[k], eval(V[i], k));
                MIN[k] = min(MIN[k], eval(V[i], k));
            }
        }
        double ans = 0;
        for(int i = 0; i < N; ++i) {
            for(int k = 0; k < 16; ++k) {
                ans = max(ans, eval(V[i], k) - MIN[k]);
                ans = max(ans, MAX[k] - eval(V[i], k));
            }
        }
        printf("%.2lf\n", ans);
    }
}
