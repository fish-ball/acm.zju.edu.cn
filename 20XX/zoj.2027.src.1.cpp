// 1811499 2009-03-31 12:19:54 Accepted  2027 C++ 0 224 ���͵����� 

// �ܾ�������·�⣬һ����Ȩ����ͼ����Դ�㵽��㣬
// ��һ�����·��������ı���ѣ���������Ҫ����ʱ�䡣
// ���ڹ�ģ��С������ö�ٴ��ڵ����бߣ�����ñ߱�����ˡ�
// Ȼ���������·��������ö�ٵ��ı߳��ȱ�Ϊ 0��
// ����ֻ�г���С�ڵ��������ߵ���������ͨ�ġ� 

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <queue>
using namespace std;

map<string, int> mapper;

struct Edge { int v, w, l; };

vector<Edge> E;

int G[100][100], V;

int getIndex(string s) {
    if(mapper.find(s) == mapper.end())
        return mapper[s] = V++;
    else return mapper[s];
}

int SPFA(int s, int t, Edge e) {
    vector<int> B(V, INT_MAX);
    queue<int> Q;
    B[s] = 0;
    Q.push(s);
    while(!Q.empty()) {
        int v = Q.front();
        Q.pop();
        if(v == t) continue;
        for(int w = 0; w < V; ++w) {
            if(v == e.v && w == e.w && B[w] > B[v]) {
                B[w] = B[v];
                Q.push(w);
            }
            else if(G[v][w] <= e.l && G[v][w] != -1 && B[w] > B[v] + G[v][w]) {
                B[w] = B[v] + G[v][w];
                Q.push(w);
            }
        }
    }
    return B[t];
}

int main() {
    string s, t;
    int si, ti, N;
    while(cin >> s >> t) {
        mapper.clear();
        V = 0;
        si = getIndex(s);
        ti = getIndex(t);
        cin >> N;
        memset(G, -1, sizeof(G));
        E.resize(N);
        for(int i = 0; i < N; ++i) {
            cin >> s >> t >> E[i].l;
            E[i].v = getIndex(s);
            E[i].w = getIndex(t);
            G[E[i].v][E[i].w] = E[i].l;
        }
        int ans = INT_MAX;
        for(int i = 0; i < N; ++i) {
            int now = SPFA(si, ti, E[i]);
            if(now < ans) ans = now;
        }
        cout << ans << endl;
    }
}
