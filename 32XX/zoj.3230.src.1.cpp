// 2073579 2010-01-09 23:23:34 Accepted  3230 C++ 170 1992 ���͵����� 

// ���⣬ÿ����Ҫ������ ai��������������� bi��
// �� n ���⣬ԭʼ���� p������ m ����֮���ܹ��ﵽ���������Ƕ��٣�
// �Ȱ���Ŀ�� <ai, bi> ��С��������Ȼ�����ѭ����
// ά��һ���ѣ�������һ��������Ҳ���ǻ�û���ģ���������Ŀ�� b ֵ�� 
// ÿ��ѭ������ʣ����Ŀ�г�ȡ������������Ŀ��ɾ���������� b ֵ��ѣ�
// ֱ��ʣ���������������Ҳ�����������ˡ�
// Ȼ��Ӷ���ȡ������ b ֵ(�����)�����ӵ� p �ϣ����� m ��һ��
// ֱ�� m Ϊ 0 ���߶��Ѿ�Ϊ�ա�
// ���� p ֵ��Ϊ���� 

#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
    
int n, m, p;
pair<int, int> V[100000];

int main() {
    while(scanf("%d%d%d", &n, &m, &p) == 3) {
        for(int i = 0; i < n; ++i)
            scanf("%d%d", &V[i].first, &V[i].second);
        sort(V, V + n);
        int top = 0;
        priority_queue<int> PQ;
        do {
            while(top < n && p >= V[top].first)
                PQ.push(V[top++].second);
            if(PQ.empty()) break;
            p += PQ.top();
            PQ.pop();
        } while(--m);
        printf("%d\n", p);
    }
} 
