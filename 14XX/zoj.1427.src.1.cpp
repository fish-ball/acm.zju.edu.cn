// 1930181 2009-07-18 10:43:54 Accepted  1427 C++ 0 184 ���͵����� 

// ��״ DP��ֱ�� dfs ����������򵽴�ĳ���ڵ�ʱ���������������Ҫ���ٿ�ʯ�ӡ�
// ����û�ж���(Ҷ��)�ڵ㣬����ֵ�� 1��
// �������� dfs ������Ҷ�ӽڵ㣬�õ�������� vec���������У� 
// Ȼ���յ�һ�� i = 0������������ vec���� i + vec[i] ȥ���½�������ֵ�� 
// Ȼ�󷵻ؽ�����ɡ� 

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int T, N;

vector<vector<int> > G;

int dfs(int v) {
    if(G[v].size() == 0) return 1;
    vector<int> vec;
    for(int i = 0; i < G[v].size(); ++i)
        vec.push_back(dfs(G[v][i]));
    sort(vec.begin(), vec.end(), greater<int>());
    int ans = 0;
    for(int i = 0; i < vec.size(); ++i)
        ans = max(i + vec[i], ans);
    return ans;
}

int main() {
    for(cin >> T; T--;) {
        cin >> N;
        G.assign(N, vector<int>());
        for(int i = 0; i < N; ++i) {
            int K, v;
            for(cin >> v >> K; K--;) {
                int w;
                cin >> w;
                G[v-1].push_back(w-1);
            }
        }
        cout << dfs(0) << endl;
    }
}
