// 1863326 2009-05-10 18:44:24 Accepted  3197 C++ 60 184 ���͵����� 

// �������ɸ��߶Σ�������� [0,N] �����串����Ҫ���ٶ������߶Ρ� 
// �Ƚ������̰�ķ������ȶ�������������
// Ȼ��˳��ö�٣���¼����ǰ�������ֹ���ٵĴ��� K����ʼ�� K Ϊ 1�� 
// �� K-1 ��ʱ�ܵ�������λ�� A���Լ���һ��������ܵ����ҵ�λ�� B��
// ���ڵ�ǰö�ٵ����߶Σ������� > A+1����ô A = B���� K++ 
// Ȼ��������������µ� B��

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int T, N;
    for(scanf("%d", &T); T--;) {
        scanf("%d", &N);
        pair<short, short> S[5000];
        for(int i = 0, x, y; i < N; ++i)
            scanf("%d%d", &S[i].first, &S[i].second);
        sort(S, S + N);
        short A = 0, B = 0, K = 1;
        for(int i = 0; i < N; ++i) {
            if(S[i].first > A + 1) {
                A = B;
                K++;
            }
            B = max(B, S[i].second);
            if(B == N) break;
        }
        printf("%d\n", K);
    }
}
