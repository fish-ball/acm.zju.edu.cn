// 1886447 2009-05-28 04:49:03 Accepted  2913 C++ 530 5748 ���͵����� 

// ͼ���⣬��һ��ͼ�����ĵ㣬ʹ������ĳЩ�ض������Զ�������
// ����Щ�ض���ֱ� BFS ��һ����̾ࡣȻ��ö�����ĵ㣬
// ���ĵ㵽��Щ��̾�����ֵ����������ĵ���Դﵽ��ֵ��ȡ��С�⼴�ɡ� 

#include <iostream>
#include <queue>
#include <vector>
#include <set>
using namespace std;

int T, C, N, Q, K;
int MP[10000];
int NM[10000];
int DIS[100][10000];

vector<vector<int> > G;

set<int> ST;

int getIndex(int c) {
    if(MP[c] != -1) return MP[c];
    else {
        NM[C] = c;
        return MP[c] = C++;
    }
}

int main() {
    for(cin >> T; T--;) {
        cin >> N >> Q;
        C = 0;
        memset(MP, -1, sizeof(MP));
        G.assign(N, vector<int>());
        for(int i = 0, x, y, k; i < N; ++i) {
            cin >> x;
            x = getIndex(x);
            for(cin >> k; k--;) {
                cin >> y;
                y = getIndex(y);
                G[x].push_back(y);
                G[y].push_back(x);
            }
        }
        ST.clear();
        while(Q--) {
            for(cin >> K; K--;) {
                int x;
                cin >> x;
                x = getIndex(x);
                ST.insert(x);
            }
        }
        int q = 0;
        for(set<int>::iterator iter = ST.begin(); iter != ST.end(); ++iter, ++q) {
            memset(DIS[q], -1, sizeof(DIS[q]));
            int x = *iter;
            queue<int> QU;
            QU.push(x);
            DIS[q][x] = 0;
            while(!QU.empty()) {
                int y = QU.front();
                QU.pop();
                for(int i = 0, w; i < G[y].size(); ++i) {
                    w = G[y][i];
                    if(DIS[q][w] == -1) {
                        DIS[q][w] = DIS[q][y] + 1;
                        QU.push(w);
                    }
                }
            }
        }
        Q = q;
        int ans = -1, mn = INT_MAX;
        for(int i = 0; i < N; ++i) {
            int mx = 0;
            for(q = 0; q < Q; ++q) {
                if(DIS[q][i] > mx)
                    mx = DIS[q][i];
            }
            if(mx < mn) {
                mn = mx;
                ans = i;
            }
            else if(mx == mn) {
                if(ans == -1 || NM[ans] > NM[i])
                    ans = i;
            }
        }
        cout << mn + 1 << ' ' << NM[ans] << endl;
            
    }
}
