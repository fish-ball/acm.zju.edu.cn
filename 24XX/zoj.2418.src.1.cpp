// 1683777 2008-10-31 00:44:09 Accepted  2418 C++ 330 184 ���͵����� 

// Ҫö�������еĲ�ͬ��λ��������ϣ���� n^n �֣�����Ҫ��֦��
// 1. ��һ�п��Բ�����������λ 0��
// 2. ����ֵ��ʱ�����ӷ�֧�޽磬��ĳһ���ܺʹ������н����ֱ�� break�� 
 

#include <iostream>
#include <algorithm>
using namespace std;

int N, P[7], A[7][7], ans;

void dfs(int k) {
    int tot = 0;
    for(int i = 0; i < N; ++i) {
        int val = 0;
        for(int j = 0; j < N; ++j)
            val += A[j][(i+P[j])%N];
        tot = max(tot, val);
        if(tot > ans) break;
    }
    ans = min(ans, tot);
    if(P[k] + 1 < N) {
        P[k] += 1;
        dfs(k);
        P[k] -= 1;
    }
    if(k + 1< N) dfs(k+1);
}

int main() {
    while(cin >> N && N != -1) {
        for(int i = 0; i < N; ++i)
            for(int j = 0; j < N; ++j)
                cin >> A[i][j];
        memset(P, 0, sizeof(P));
        ans = INT_MAX;
        dfs(1);
        cout << ans << endl;
    }
}
