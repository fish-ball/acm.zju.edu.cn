// 2150829 2010-04-10 11:12:00 Accepted  1177 C++ 10 184 ���͵����� 

// ��ǿ��һ���߾������⣬�� K������С������ X ʹ��ʮ����ѭ������֮��
// �õ��� Y = X / K��
// ������ö�� Y �ĸ�λ����λ(��kλ)���� K ��õ� X �ĵ�kλ�����ǵõ�
// Y �ĵ� k+1 λ���Դ����ƿɵ���������ö��һ�θ�λ���ɡ� 

#include <iostream>
using namespace std;

int main() {
    int T;
    char C[10][20000], D[10][20000];
    int K[10];
    for(cin >>T; T--;) {
        int N;
        cin >> N;
        memset(C, 0, sizeof(C));
        memset(D, 0, sizeof(D));
        memset(K, 0, sizeof(K));
        for(int d = 1; d < 10; ++d) {
            C[d][0] = d;
            for(int i = 0; ; ++i) {
                int v = N * C[d][i];
                for(int j = 0; v; ++j) {
                    D[d][i+j] += v % 10;
                    v = v / 10 + D[d][i+j] / 10;
                    D[d][i+j] %= 10;
                    if(K[d] < i + j) {
                        K[d] = i + j;
                    }
                }
                if(K[d] == i && D[d][K[d]] == d) break;
                C[d][i+1] = D[d][i];
                if(i == 19999) {
                    K[d] = -1;
                    break;
                }
            }
        }
        int mv = INT_MAX, mp = 0;
        for(int d = 1; d < 10; ++d) {
            if(K[d] != -1 && K[d] < mv) {
                mv = K[d];
                mp = d;
            }
        }
        for(int i = K[mp]; i >= 0; --i) {
            putchar('0' + D[mp][i]);
        }
        puts("");
        if(T) puts("");
    }
}
