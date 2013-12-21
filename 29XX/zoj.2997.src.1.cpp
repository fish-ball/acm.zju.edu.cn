// 1869870 2009-05-15 01:57:21 Accepted  2997 C++ 10 184 ���͵����� 

// ������������򣬹���һ������Ϊ N �����У�
// ʹ�������������� P ��Ԫ��֮��Ϊ�������������� Q ��Ԫ��֮��Ϊ����
// ������ת��������������е��ۼ����У�
// �൱�ڹ���һ������Ϊ N + 1 ������ S[0..N]��
// ���� S[i+P] - S[i] > 0 �� S[i+Q] - S[i] < 0��
// �����Ļ������Թ��� N+1 �����ͼ��
// ������ S[i] > S[j] �Ĺ�ϵ��������� (i, j) ��
// ��ô�������ͼ��������Ȼ������л����򲻿ɹ��죬
// ���������ѵ�����ű�������Ϊ S[i] ��ֵ�� 

#include <iostream>
#include <vector>
using namespace std;

int N, P, Q, cnt;

bool B[5000];

int val[5000];

void dfs(int v) {
    B[v] = true;
    if(v + Q <= N && !B[v + Q]) dfs(v + Q);
    if(v - P >= 0 && !B[v - P]) dfs(v - P);
    val[v] = cnt++;
}

int main() {
    while(scanf("%d%d%d", &N, &P, &Q) != EOF) {
        memset(B, 0, N+1);
        cnt = 0;
        for(int v = 0; v <= N; ++v)
            if(!B[v]) dfs(v);
        bool hasloop = false;
        for(int v = 0; v <= N; ++v) {
            if(v + Q <= N && val[v] < val[v + Q]) hasloop = true;
            if(v - P >= 0 && val[v] < val[v - P]) hasloop = true;
        }
        if(hasloop) puts("NO");
        else {
            puts("YES");
            for(int i = 0; i < N; ++i) {
                if(i) putchar(' ');
                printf("%d", val[i+1] - val[i]);
            }
            puts("");
        }
    }
    
}
