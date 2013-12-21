// 1664106 2008-10-11 21:35:29 Accepted  1716 C++ 0 224 ���͵����� 

// �򵥵Ķ�ά����������ͣ����ۼӣ�Ȼ���ݳ�һ��
// Ԥ���� O(W*H)����ѯ O(1) ���� (W-w)*(H-h) �β�ѯ

#include <iostream>
using namespace std;

int B[101][101];
int N, W, H, w, h, x, y, ans;

int main() {
    while(cin >> N && N) {
        cin >> W >> H;
        memset(B, 0, sizeof(B));
        while(N--) {
            cin >> x >> y;
            B[x][y] = 1;
        }
        cin >> w >> h;
        for(int i = 1; i <= W; ++i)
            for(int j = 1; j <= H; ++j)
                B[i][j] += B[i][j-1];
        for(int j = 1; j <= H; ++j)
            for(int i = 1; i <= W; ++i)
                B[i][j] += B[i-1][j];
        ans = 0;
        for(int i = w; i <= W; ++i)
            for(int j = h; j <= H; ++j)
                ans = max(ans, B[i][j] - B[i-w][j] - B[i][j-h] + B[i-w][j-h]);
        cout << ans << endl;
    }
}
