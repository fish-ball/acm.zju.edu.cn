// 3493789 2013-12-22 00:35:48 Accepted 3518 C++ 170 11464 ´ôÖÍµÄÂý°å

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;

int main() {
    
    int L, n1, n2, l, r;
    
    while(scanf("%d%d%d", &L, &n1, &n2) != EOF) {
        map<int, int> mp;
        for(int i = 0; i < n1+n2; ++i) {
            scanf("%d%d", &l, &r);
            mp[l] ^= 1;
            mp[r+1] ^= 1;
        }
        int mx = 0, x = 0;
        for(map<int, int>::iterator it = mp.begin(); it != mp.end(); ++it) {
            if(it->second) {
                if(x ^= 1) l = it->first;
                else mx = max(mx, it->first - l);
            }
        }
        printf("%d\n", mx);
    }
        
}
