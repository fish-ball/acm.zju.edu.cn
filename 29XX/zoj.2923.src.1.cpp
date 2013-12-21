// 1869829 2009-05-15 00:43:54 Accepted  2923 C++ 600 13548 ���͵����� 

// ��һ��ͼ��ĳЩ�����б�ǡ�
// �ʴ� 0 �� N �����·�У����С�� K ���ж�������
// ע��������ᷨ�����������·��������С�� K ʱ�����·��
// ���������״̬�� ���� DP ���ɽ����
// DP[v][k] ��¼���� v �������Ѿ����� k �α�ǵ��·�����ȣ�
// �Լ�����������ϵ�·������ 
// �����ķ�ʽ�������б߳�Ϊ 1��ֻ��Ҫֱ�ӹ��Ѽ��ɡ� 

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

pair<int, int> DP[5000][51];

int I[5001];

int M, N, K;

vector<vector<int> > G;

int main() {
    
    
    while(scanf("%d%d%d", &M, &N, &K) != EOF) {
        
        
        for(int i = 0, j; i < N; ++i) {
            scanf("%d", &j);
            scanf("%d", I + j - 1);
        }
        G.assign(N, vector<int>());
        while(M--) {
            int x, y;
            scanf("%d%d", &x, &y);
            G[x-1].push_back(y-1);
            G[y-1].push_back(x-1);
        }
        
        
        int D[5000];
        memset(D, -1, sizeof(D));
        queue<int> QQ;
        D[0] = 0;
        QQ.push(0);
        while(!QQ.empty()) {
            int v = QQ.front();
            if(v == N - 1) break;
            QQ.pop();
            for(int i = 0, w; i < G[v].size(); ++i) {
                w = G[v][i];
                if(D[w] == -1) {
                    D[w] = D[v] + 1;
                    QQ.push(w);
                }
            }
        }
        
        
        for(int i = 0; i < N; ++i)
            for(int j = 0; j <= K; ++j)
                DP[i][j] = make_pair(INT_MAX, 0);
        queue<int> Q;
        if(I[0] == 1) {
            DP[0][1] = make_pair(0, 1);
            Q.push(1);
        }
        else {
            DP[0][0] = make_pair(0, 1);
            Q.push(0);
        }
        while(!Q.empty()) {
            int k = Q.front() % 100;
            int v = Q.front() / 100;
            Q.pop();
            if(v == N - 1 && k <= K) break;
            for(int i = 0, w; i < G[v].size(); ++i) {
                w = G[v][i];
                if(I[w] == 0) {
                    if(DP[w][k].first > DP[v][k].first + 1) {
                        DP[w][k].first = DP[v][k].first + 1;
                        DP[w][k].second = DP[v][k].second;
                        Q.push(w * 100 + k);
                    }
                    else if(DP[w][k].first == DP[v][k].first + 1) {
                        DP[w][k].second += DP[v][k].second;
                    }
                }
                else if(k + 1 <= K) {
                    if(DP[w][k+1].first > DP[v][k].first + 1) {
                        DP[w][k+1].first = DP[v][k].first + 1;
                        DP[w][k+1].second = DP[v][k].second;
                        Q.push(w * 100 + k + 1);
                    }
                    else if(DP[w][k+1].first == DP[v][k].first + 1) {
                        DP[w][k+1].second += DP[v][k].second;
                    }
                }
            }
        }
        int ans = 0;
        for(int i = 0; i <= K; ++i) {
            if(DP[N-1][i].first == D[N-1])
                ans += DP[N-1][i].second;
        }
        if(ans != 0) printf("%d\n", ans);
        else puts("Impossible!");
    }
}
