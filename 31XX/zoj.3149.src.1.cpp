// 1748355 2009-01-25 00:14:32 Accepted  3149 C++ 40 184 ���͵�����

// ������������⣬����Ϊ����ı�������ģ�⣬������A[i]��ʾ��ǰ��i�����ӵĽڵ�����
// Ȼ��ֱ�������ģ�⣬�տ�ʼ��ʱ��A[]={1,0,....}���鲻����K��
// ����ת�Ƶ����ʣ���һ��˫�˶�����ά�����������Դﵽһ���ܺõ�Ч�ʡ�

#include <deque>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N, K, P, M, T;
    deque<int> Q;
    while(cin >> N >> K && N) {
        if(K == 0) {
            cout << min(N - 1, 1234567891) << endl;
            continue;
        }
        Q.assign(1, 1);
        P = 0;
        M = 1;
        for(int i = 1; i < N && P <= 1234567890; i++) {
            P += M;
            if(Q.size() <= K) {
                Q.push_front(M);
                M += M;
            }
            else {
                int t = Q.back();
                Q.pop_back();
                Q.back() += t;
                Q.push_front(M - t);
                M += M - t;
            }
        }
        cout << P << endl;
    }
}
