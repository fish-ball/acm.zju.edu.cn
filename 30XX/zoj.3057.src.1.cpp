// 1694300 2008-11-09 17:27:49 Accepted  3057 C++ 890 26816 ���͵����� 

// ���� DP��ֱ��ǰ�ƣ�DP[i][j][k]����֤ i<=j<=k��Ȼ��ö�� i,j,k ǰ�ơ� 
// ��ʼȫ��Ĭ�ϱ��䣬Ȼ��ö�٣��ӱ���㷢չ���������±��Ϊ��Ӯ�������Թ��� 

#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

bool M[301][301][301] = {};

inline bool& at(int x, int y, int z) {
    if(y > z) swap(y, z);
    if(x > y) swap(x, y);
    if(y > z) swap(y, z);
    return M[x][y][z];
}

int main() {

    int a[3];

    for(a[0] = 0; a[0] <= 300; ++a[0]) {
        for(a[1] = a[0]; a[1] <= 300; ++a[1]) {
            for(a[2] = a[1]; a[2] <= 300; ++a[2]) {

                if(M[a[0]][a[1]][a[2]]) continue;

                for(int v = 1; a[0] + v <= 300; ++v)
                    at(a[0] + v, a[1], a[2]) = true;
                for(int v = 1; a[1] + v <= 300; ++v)
                    at(a[0], a[1] + v, a[2]) = true;
                for(int v = 1; a[2] + v <= 300; ++v)
                    at(a[0], a[1], a[2] + v) = true;

                for(int v = 1; a[1] + v <= 300; ++v)
                    at(a[0] + v, a[1] + v, a[2]) = true;
                for(int v = 1; a[2] + v <= 300; ++v)
                    at(a[0], a[1] + v, a[2] + v) = true;
                for(int v = 1; a[2] + v <= 300; ++v)
                    at(a[0] + v, a[1], a[2] + v) = true;
            }
        }
    }

    while(cin >> a[0] >> a[1] >> a[2])
        cout << at(a[0], a[1], a[2]) << endl;

}
