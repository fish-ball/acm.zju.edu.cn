// 1693161 2008-11-08 14:14:09 Accepted  2912 C++ 410 1232 ���͵����� 

// ��״ DP��һ�� dfs �㶨���������·�����ܳ��ȡ�
// ����ĳ����Ӧ�ñ������� P * Q �Σ�P �� Q �ֱ��������ߵ�������С�� 

#include <iostream>
#include <vector>
using namespace std;

int T, N;
vector<pair<int, int> > G[10005];
bool B[10005];
double total;

int dfs(int x) {
    B[x] = true;
    int cnt = 1, n;
    for(int i = 0; i < G[x].size(); ++i) {
        if(B[G[x][i].first] == false) {
            n = dfs(G[x][i].first);
            total += double(G[x][i].second) * n * (N - n);
            cnt += n;
        }
    }
    return cnt;
}

int main() {
    for(cin >> T; T--;) {
        cin >> N;
        for(int i = 0; i < N; ++i)
            G[i].clear();
        for(int i = 1, x, y, w; i < N; ++i) {
            cin >> x >> y >> w;
            G[x].push_back(make_pair(y, w));
            G[y].push_back(make_pair(x, w));
        }
        memset(B, 0, sizeof(B));
        total = 0;
        dfs(0);
        int p = N * (N-1) / 2;
        cout.setf(ios::fixed);
        cout.precision(5);
        cout << total / p << endl;
    }
    return 0;
}
