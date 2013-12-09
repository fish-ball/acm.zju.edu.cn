/* 3488118 2013-12-09 22:26:50 Accepted 3633 C++ 720 48020 ���͵�����

����ʵ������һ�� RMQ��������Լ����ʮ�ֵ����ԣ�
1. ��Ԥ�����һ�����飬��ʾǰһ��������ͬ��λ�ã�
2. Ȼ����������Ԥ���� RMQ�����ڲ�ѯ�������ֵ��
3. ÿ����һ�����䣬��ѯ�� RMQ ���ֵ�������������ȳ����ظ���λ�ã�
4. ������λ���� l ֮��˵�����ظ��������λ�õ����֣�
5. ����˵�����������û���ظ������ OK��
*/

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
using namespace std;

int n, m, a[500000];
int rmq[19][500000];

int bit_length(int b) {
    int ans = 0;
    while(b) {
        ++ans;
        b >>= 1;
    }
    return ans;
}

void rmq_build() {
    for(int i = 1; (1<<i) < n; ++i)
        for(int j = 0; j + (1<<i) <= n; ++j)
            rmq[i][j] = max(rmq[i-1][j], rmq[i-1][j+(1<<(i-1))]);
}

int rmq_query(int l, int r) {
    if(l == r) return -1;
    int len = bit_length(r - l) - 1;
    return max(rmq[len][l], rmq_query(l+(1<<len), r));
}

int main() {
    
    while(scanf("%d", &n) != EOF) {
        
        map<int, int> pre;
        memset(rmq, -1, sizeof(rmq));
        
        for(int i = 0, s = 0; i < n; ++i) {
            scanf("%d", a+i);
            map<int, int>::iterator it = pre.find(a[i]);
            if(it != pre.end()) rmq[0][i] = it->second;
            pre[a[i]] = i;
        }
        
        rmq_build();
        
        for(scanf("%d", &m); m--;) {
            int l, r, p;
            scanf("%d%d", &l, &r);
            p = rmq_query(l-1, r);
            if(p < l-1) puts("OK");
            else printf("%d\n", a[p]);
        }
        
        puts("");
        
    }
    
}
