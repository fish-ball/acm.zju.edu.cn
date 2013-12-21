// 1882485 2009-05-24 01:50:52 Accepted  3212 C++ 240 184 ���͵����� 

// �����죬ʹ��ǡ���� K ���ڲ���Ԫ��ֵ���������ܵ�ֵ֮�͡�
// ����� K ���ڲ���Ԫ�񣬽��䱾�����ܵĵ�Ԫ��Ϳ�� 0��������ȫͿ�� 1 ���ɡ� 

#include <iostream>
using namespace std;

bool B[15][15];
int N, M, K, T, C;

const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

int main() {
    for(cin >> T; T--;) {
        cin >> N >> M >> K;
        C = 0;
        memset(B, 0, sizeof(B));
        for(int i = 1; i + 1 < N && C < K; ++i) {
            for(int j = 1; j + 1 < M && C < K; ++j) {
                for(int d = 0; d < 4; ++d)
                    B[i+dx[d]][j+dy[d]] = true;
                B[i][j] = true;
                ++C;
            }
        }
        for(int i = 0; i < N; ++i) {
            for(int j = 0; j < M; ++j) {
                if(j) putchar(' ');
                if(B[i][j]) putchar('0');
                else printf("1");
            }
            puts("");
        }                
    }
}
