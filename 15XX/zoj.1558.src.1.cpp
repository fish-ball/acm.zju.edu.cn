// 1665612 2008-10-13 21:47:55 Accepted  1558 C++ 20 184 ���͵����� 

// DP����ʵ������ BFS������ÿһ��Ŀ��۸���һ�� BFS��ÿ������һ���ҡ� 
// ������ BFS���õ�����̴�����Ϊ����
// ֵ��ע����ǣ���������Ǯ�ӵ�һ���ܴ������Ȼ���ټ���������� DP ����Ҫ����һ�㡣 

#include <iostream>
using namespace std;

const int LEN = 1001;

bool B[LEN], C[LEN];
int A[6], N;

int check(int k) {
    memset(B, 0, sizeof(B));
    B[0] = 1;
    int cnt = 0;
    while(!B[k]) {
        cnt += 1;
        memset(C, 0, sizeof(C));
        for(int i = 0; i < LEN; ++i) {
            if(B[i]) {
                for(int j = 0; j < 6; ++j) {
                    if(i - A[j] >= 0)
                        C[i-A[j]] = true;
                    if(i + A[j] < LEN)
                        C[i+A[j]] = true;
                }
            }
        }
        for(int i = 0; i < LEN; ++i)
            B[i] |= C[i];
    }
    return cnt;
}

int main() {
    for(cin >> N; N--;) {
        for(int i = 0; i < 6; ++i)
            cin >> A[i];
        double ans = 0;
        int mx = 0;
        for(int i = 1; i <= 100; ++i) {
            int p = check(i);
            ans += p;
            mx = max(mx, p);
        }
        printf("%.2lf %d\n", ans/100, mx);
    }
}
