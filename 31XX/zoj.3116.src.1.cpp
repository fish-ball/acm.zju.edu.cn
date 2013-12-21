// 1746463 2009-01-21 21:21:27 Accepted  3116 C++ 50 184 ���͵����� 

// ����̰�ģ��Ȱ���ֵ������ȣ�Ȼ�󰴾����ܴ���¼������䡣 

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N, K, R[10001];
    pair<int, int> A[10001];
    while(cin >> N >> K) {
        fill(R, R + 10001, K);
        for(int i = 0; i < N; ++i)
            cin >> A[i].first >> A[i].second;
        sort(A, A + N);
        int ANS = 0;
        for(int i = N - 1; i >= 0; --i) {
            int P = A[i].second;
            while(P >= 0 && R[P] == 0) P--;
            if(P >= 0) {
                R[P]--;
                ANS += A[i].first;
            }
        }
        cout << ANS << endl;
    }
}
