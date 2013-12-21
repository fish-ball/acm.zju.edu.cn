// 1788597 2009-03-14 14:13:12 Accepted  3094 C++ 2010 9316 ���͵����� 

// �����ӣ��ܾ����һ���⣬���� + BFS�� 
// ������Ҫ��һ��Ԥ���������ÿһ������������ĵ�Ӫ�ľ��룺 
// �����ͨ�������е�Ӫ����� BFS �ó���
// Ȼ�����һ��������룬������Ӧ�ô��� 0 �� X + Y ֮�䡣 
// ���ڶ��ֵ�ÿһ��ֵ bound������� (xi, yi) BFS ���յ� (xr, yr)��
// ���ߵĵ�Ϊ���е���Ӫ���� >= bound �ĸ��ӡ�
// �����ĳ�� bound ��ͨ����С��������Ĵ����������Ϳ��Զ����ˡ� 

#include <iostream>
#include <queue>
using namespace std;

int T, N, X, Y, xi, yi, xr, yr;
int G[1000][1000];
int P[1000][1000];

const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

// ���������־��� >= bound ������µ����·����ͨ���� -1 
// P[][] ��ʾ����ĳ��λ�õ����·���� 
int checkAtBound(int bound) {
    if(G[xi][yi] < bound) return -1;
    memset(P, -1, sizeof(P));
    queue<pair<int, int> > Q;
    P[xi][yi] = 0;
    Q.push(make_pair(xi, yi));
    while(!Q.empty()) {
        int x = Q.front().first;
        int y = Q.front().second;
        int l = P[x][y];
        if(x == xr && y == yr) break;
        Q.pop();
        for(int d = 0; d < 4; ++d) {
            x += dx[d];
            y += dy[d];
            if(x >= 0 && x < X && y >= 0 && y < Y &&
                P[x][y] == -1 && G[x][y] >= bound) {
                P[x][y] = l + 1;
                Q.push(make_pair(x, y));
            }
            x -= dx[d];
            y -= dy[d];
        }
    }
    return P[xr][yr];
}

int main() {
    for(cin >> T; T--;) {
        cin >> N >> X >> Y;
        cin >> xi >> yi >> xr >> yr;
        
        // G[][] ��ʾ��ͼ����һ�㵽������ĵ�Ӫ�ľ���
        // ͨ����Դ���·(�˴�Ϊֱ�� BFS)��� 
        memset(G, -1, sizeof(G));
        queue<pair<int, int> > Q;
        for(int i = 0, x, y; i < N; ++i) {
            scanf("%d%d", &x, &y);
            G[x][y] = 0;
            Q.push(make_pair(x, y));
        }
        while(!Q.empty()) {
            int x = Q.front().first;
            int y = Q.front().second;
            int l = G[x][y];
            Q.pop();
            for(int d = 0; d < 4; ++d) {
                x += dx[d];
                y += dy[d];
                if(x >= 0 && x < X && y >= 0 && y < Y && G[x][y] == -1) {
                    G[x][y] = l + 1;
                    Q.push(make_pair(x, y));
                }
                x -= dx[d];
                y -= dy[d];
            }
        }
                
        int r = X + Y, l = 0, m, len;
        while(r > l + 1) {
            m = r + l >> 1;
            if(checkAtBound(m) == -1) r = m;
            else l = m;
        }
        cout << l << ' ' << checkAtBound(l) << endl;
    }
}
