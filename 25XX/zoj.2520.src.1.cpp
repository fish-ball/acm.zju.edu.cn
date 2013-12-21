// 1781651 2009-03-08 00:39:52 Accepted  2520 C++ 1040 184 ���͵����� 

// ����һ������(A, B)������ A ������(���� 1, ������������)֮�͵��� B��
// B ������֮�͵��� A������ K����� K ��������������ʲô�� 
// �� K û����Χ����ʵ��С��ֱ���������ɡ� 

#include <iostream>
using namespace std;

int isAmicable(int v) {
    int w = 1;
    for(int i = 2; i * i <= v; ++i) {
        if(v % i == 0) {
            w += i;
            if(i * i != v)
                w += v / i;
        }
    }
    if(w <= v) return -1;
    int u = 1;
    for(int i = 2; i * i <= w; ++i) {
        if(w % i == 0) {
            u += i;
            if(i * i != w)
                u += w / i;
        }
    }
    if(u == v) return w;
    else return -1;
}

int P[100], Q[100], N = 1, K;

int main() {
    P[0] = 220;
    Q[0] = 284;
    while(cin >> K) {
        for(int i = P[N - 1] + 1; K > N; ++i) {
            int j = isAmicable(i);
            if(j != -1) {
                P[N] = i;
                Q[N] = j;
                ++N;
            }
        }
        cout << P[K - 1] << ' ' << Q[K - 1] << endl;
    }
}
