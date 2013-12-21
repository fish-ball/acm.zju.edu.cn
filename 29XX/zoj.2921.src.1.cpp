// 1693069 2008-11-08 12:46:59 Accepted  2921 C++ 340 2900 ���͵����� 

// ��Ʊ�����������̰�ģ��ȼ�¼���е�����Ȼ���β��ͷ������
// ����֮ǰ����һ�����ȶ��� 
// ��ŵ���֮��ʣ��ļ۸� p ��ʣ���������Ϊ���ȼ������е�����
// ÿ����һ�죬���뵱��۸�Ϳ������������ȶ��У�Ȼ�󽫵�������Ĺ�Ʊ���꣺
// һֱ�����ȶ�����ȡ��������ȡ�����Ŀ϶������ģ�һֱ���� 
// ֱ������Ϊ�ջ��ߵ�������Ĺ�Ʊ�Ѿ����ꡣ 

#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

const int MAXN = 100005;

int T, N, x[MAXN], p[MAXN], m[MAXN], ans, tmp;

int main() {
    for(scanf("%d", &T); T--;) {
        scanf("%d", &N);
        for(int i = 0; i < N; ++i)
            scanf("%d%d%d", x+i, p+i, m+i);
        priority_queue<pair<int, int> > Q;
        pair<int, int> P;
        ans = 0;
        for(int i = N-1; i >= 0; --i) {
            Q.push(make_pair(p[i], m[i]));
            while(!Q.empty()) {
                P = Q.top();
                Q.pop();
                tmp = min(x[i], P.second);
                ans += P.first * tmp;
                P.second -= tmp;
                x[i] -= tmp;
                if(P.second > 0) Q.push(P);
                if(x[i] == 0) break;
            }
        }
        printf("%d\n", ans);
    }
}
