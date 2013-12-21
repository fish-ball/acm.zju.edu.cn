// 1865326 2009-05-11 21:23:50 Accepted  3187 C++ 10 184 ���͵����� 

// ���ִ�(�ܹ���������)��Ȼ���ж�ÿ���䷽������ô���˵�ʱ�������ö���Ǯ
// �������ٵ�Ǯ�Ƿ�������е�Ǯ�Ϳ���ʵ�������Ķ����ˡ� 

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;

struct Record {
    int x, y, s1, p1, s2, p2;
    void get() { scanf("%d%d%d%d%d%d", &x, &y, &s1, &p1, &s2, &p2); }
    int ask(int n) {
        int tot = x * n - y;
        int ans = INT_MAX;
        for(int i = 0; s1 * (i - 1) <= tot; ++i) {
            int j;
            if(tot - s1 * i < 0) j = 0;
            else if((tot - s1 * i) % s2 != 0)
                j = (tot - s1 * i) / s2 + 1;
            else
                j = (tot - s1 * i) / s2;
            ans = min(ans, i * p1 + j * p2);
        }
        //printf("ask(%d) = %d\n", n, ans);
        return ans;
    }
    int bound(int money) {
        return (money / p1 * s1 + money / p2 * s2 + y) / x;
    }
};

int main() {
    while(scanf("%d%d", &N, &M) && N) {
        vector<Record> V(N);
        for(int i = 0; i < N; ++i) V[i].get();
        int l = -1, r = V[0].bound(M) + 1;
        while(r > l + 1) {
            int m = (l + r) / 2;
            int s = 0;
            for(int i = 0; i < N; ++i) {
                s += V[i].ask(m);
                if(s > M) break;
            }
            if(s > M) r = m;
            else l = m;
            //printf("l = %d, r = %d\n", l, r);
            //system("pause");
        }
        printf("%d\n", l);
    }
}
