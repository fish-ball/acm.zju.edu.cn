// 1723455 2008-12-11 11:39:08 Accepted  2475 C++ 0 184 ���͵����� 

// ��һ������ͼ����һ������ɴ��λ�����Ƿ����ڻ���
// ���� Floyd��Ȼ��ö�ٸ����Ķ���ɴ�Ķ��㣬
// ���������һ������ʹ�� G[v][w] == G[w][v]����ô����������
// ע�����ⱳ�����Ի��ǲ���ģ�����ڳ�ʼ��ͼ��ʱ��Ҫ���������Ի��� 

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int M, N, E;
    bool G[100][100];
    while(scanf("%d", &M) && M >= 0) {
        memset(G, 0, sizeof(G));
        N = 0;
        for(int i = 0; i < M; ++i) {
            int x, y;
            scanf("%d%d", &x, &y);
            N = max(N, max(x, y));
            if(x != y)
                G[x-1][y-1] = true;
        }
        scanf("%d", &E);
        for(int i = 0; i < N; ++i)
            for(int j = 0; j < N; ++j)
                for(int k = 0; k < N; ++k)
                    if(G[j][i] && G[i][k])
                        G[j][k] = true;
        bool circle = false;
        for(int v = 0; v < N; ++v)
            if(G[E-1][v])
                for(int w = 0; w < N; ++w)
                    if(G[v][w] && G[w][v])
                        circle = true;
        puts(circle ? "No" : "Yes");
    }
    return EXIT_SUCCESS;
}
