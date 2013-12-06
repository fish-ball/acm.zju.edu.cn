#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

bool G[100][100] = {};
    
int T, n, m, k, x, y, z, i, j;
int sz, bsz, ans;

int main() {

    for(scanf("%d", &T); T--;) {
        
        scanf("%d%d%d", &n, &m, &k);
        memset(G, 0, sizeof(G));
        
        for(i = 0; i < m; ++i) {
            scanf("%d%d", &x, &y);
            G[x][y] = G[y][x] = true;
        }
        
        sz = 0;
        
        do {
            
            ans = sz;
            sz = 0;
            
            for(x = 0; x < n; ++x) {
                for(y = x+1; y < n; ++y) {
                    for(z = bsz = 0; z < n; ++z)
                        bsz += (G[x][z] && G[y][z]);
                    if(bsz >= k) G[x][y] = G[y][x] = true;
                    sz += G[x][y];
                }
            }
            
        
        } while(sz > ans);
        
        printf("%d\n", ans - m);
        
    }
    
}
