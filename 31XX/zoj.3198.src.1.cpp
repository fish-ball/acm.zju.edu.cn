// 1862209 2009-05-10 03:31:44 Accepted  3198 C++ 180 184 ���͵����� 

// �Ƚ�ˮ�����򼯺��󽻼���O(n) �ĽⷨӦ�����൱������ 

#include <iostream>
using namespace std;

int main() {
    int T;
    for(cin >> T; T--;) {
        int N, A[100000];
        cin >> N;
        for(int i = 0; i < N; ++i)
            scanf("%d", A + i);
        int M, C = 0;
        cin >> M;
        for(int i = 0, j = 0, v; i < M; ++i) {
            scanf("%d", &v);
            while(v > A[j] && j < N) j++;
            if(v == A[j] && j < N) { j++; C++; }
        }
        cout << C << endl;
    }
}
