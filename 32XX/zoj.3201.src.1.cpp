// 1862215 2009-05-10 04:23:58 Accepted  3201 C++ 0 184 ���͵����� 

// �������һ����״ DP����һ����Ȩ�����Ķ�����Ϊ K ��������
// ע����������Ӧ���Ϊ���е���һ����ͨ�顣
// �����������״ DP �ֶβſ��Խ��������⣬
// �����ӽṹΪ dfs ��ĳ���ڵ���������ȡ 0~? ���ڵ�����ʱ�ɴ�����ֵ�� 

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, K, S, TOT;

vector<vector<int> > G;
vector<int> W;
vector<vector<int> > BEST;

void dfs(int v) {
    BEST[v].push_back(W[v]);
    for(int i = 0, w; i < G[v].size(); ++i) {
        w = G[v][i];
        if(!BEST[w].empty()) continue;
        dfs(w);
        vector<int> nxt(BEST[v].size() + BEST[w].size() + 1, 0);
        for(int p = 0; p < BEST[v].size(); ++p) {
            nxt[p] = max(nxt[p], BEST[v][p]);
            for(int q = 0; q < BEST[w].size(); ++q)
                nxt[p+q+1] = max(nxt[p+q+1], BEST[v][p] + BEST[w][q]);
        }
        BEST[v] = nxt;
    }
    if(BEST[v].size() >= K)
        S = max(S, BEST[v][K-1]);
}

int main() {
    while(cin >> N >> K) {
        W.resize(N);
        TOT = 0;
        for(int i = 0; i < N; ++i) {
            cin >> W[i];
            TOT += W[i];
        }
        G.assign(N, vector<int>());
        for(int i = 1, x, y; i < N; ++i) {
            cin >> x >> y;
            G[x].push_back(y);
            G[y].push_back(x);
        }
        if(N == K) cout << TOT << endl;
        else {
            S = 0;
            BEST.assign(N, vector<int>());
            dfs(0);
            cout << S << endl;
        }
    }
}
