// 1665599 2008-10-13 21:34:37 Accepted  1563 C++ 0 184 ���͵����� 

// �鱦�ɹ������Ʊ�����n^3 �� DP��DP[k] Ϊ����� k ���鱦֮�����С���ѡ�
// Ȼ�󣬶���ÿ�� k�����Կ�����������ǰ��� j..k ���鱦��
// Ȼ��ѡ��ͬ�� j �Ը�����Сֵ��������� DP�� 

#include <iostream>
using namespace std;

int DP[101], P[101], A[101], N, T;

int main() {
    
    for(cin >> T; T--;) {
        cin >> N;
        for(int i = 1; i <= N; ++i) {
            cin >> A[i] >> P[i];
            DP[i] = INT_MAX;
        }
        DP[0] = 0;
        for(int i = 1; i <= N; ++i) {
            for(int j = 0; j < i; ++j) {
                int sum = 0;
                for(int k = j+1; k <= i; ++k)
                    sum += A[k];
                DP[i] = min(DP[i], DP[j] + (10 + sum) * P[i]);
            }
        }
        cout << DP[N] << endl;
    }
    
}
