// 1665663 2008-10-13 22:50:46 Accepted  1518 C++ 0 212 ���͵����� 

// ת����һ��ͼ����ɫ���⣬ÿ�仰��һ�����㣺
// ����� i �仰˵�� j �仰����ģ�����һ��ͬɫ�ߣ�˫��ߣ���
// ����� i �仰˵�� j �仰�Ǽٵģ�����һ����ɫ�ߣ�˫��ߣ��� 
// Ȼ�� dfs Ⱦɫ�������Ⱦɫì�ܣ�Ҳ����ì�ܣ�
// ���򣬶���ͬһ����ͨ������������ɫ�Ķ������ֱ�Ϊ X �� Y��
// �����ս������ max(X, Y)�� 

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int N, X, Y;

int C[1001];

vector<int> S[1001], D[1001];

char s[20];

bool dfs(int v, int c) {
    C[v] = c;
    (c == 1 ? X : Y) += 1;
    for(int i = 0, w; i < S[v].size(); ++i) {
        w = S[v][i];
        if(C[w] == 3 - c) return false;
        if(C[w] == 0 && !dfs(w, c)) return false;
    }
    for(int i = 0, w; i < D[v].size(); ++i) {
        w = D[v][i];
        if(C[w] == c) return false;
        if(C[w] == 0 && !dfs(w, 3 - c)) return false;
    }
    return true;
}

int main() {
    while(scanf("%d", &N) && N) {
        for(int i = 1; i <= N; ++i) {
            S[i].clear();
            D[i].clear();
        }
        for(int i = 1; i <= N; ++i) {
            scanf("%s%d%s%s", s, &X, s, s);
            if(*s == 't') {
                S[i].push_back(X);
                S[X].push_back(i);
            }
            else {
                D[i].push_back(X);
                D[X].push_back(i);
            }
        }
        memset(C, 0, sizeof(C));
        bool yes = true;
        int ans = 0;
        for(int i = 1; i <= N; ++i) {
            if(C[i] == 0) {
                X = Y = 0;
                if(!dfs(i, 1)) {
                    yes = false;
                    break;
                }
                ans += max(X, Y);
            }
        }
        if(!yes) puts("Inconsistent");
        else printf("%d\n", ans);
    }
}
