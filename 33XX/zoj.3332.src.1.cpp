// 2210419 2010-06-10 11:52:55 Accepted  3332 C++ 340 184 呆滞的慢板 

// 给一个有向图，每两个顶点之间有且仅有一条未定方向的边，找哈密顿路(不是回路)。
// 由于边数性质独特，直接蛮力 dfs 的效率是可以接受的。 

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > G;
vector<bool> B;
vector<int> trc;
int T, N;

bool dfs(int x) {
    trc.push_back(x);
    B[x] = true;
    if(trc.size() == N) return true;
    for(int i = 0, y; i < G[x].size(); ++i) {
        y = G[x][i];
        if(!B[y] && dfs(y)) {
            return true;
        }
    }
    B[x] = false;
    trc.pop_back();
    return false;
}

int main() {
    for(cin >> T; T--;) {
        cin >> N;
        if(N == 1) { puts("1"); continue; }
        G.assign(N, vector<int>());
        B.assign(N, false);
        trc.clear();
        for(int k = 1; k <= N * (N - 1) / 2; k++) {
            int x, y;
            cin >> x >> y;
            G[--x].push_back(--y);
        }
        int pos = -1;
        for(int k = 0; k < N && pos == -1; ++k) {
            if(dfs(k)) {
                pos = k;
            }
        }
        if(pos == -1) {
            puts("Impossible");
        }
        else {
            for(int i = 0; i < trc.size(); ++i) {
                if(i) cout << ' ';
                cout << trc[i] + 1;
            }
            cout << endl; 
        }
    }
}
