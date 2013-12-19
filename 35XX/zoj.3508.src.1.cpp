// 3492409 2013-12-19 23:03:06 Accepted 3508 C++ 10 412 ´ôÖÍµÄÂý°å
#include <cstdio>
#include <algorithm>
#include <set>
using namespace std;

int n, m, i, j, ans, s[2500], w[40000], x, y;
multiset<int> q;

int main() {

    while(scanf("%d%d", &n, &m) != EOF) {

        // input and pre-process.
        for(i = 0; i < n; ++i) {
            scanf("%d%d", &x, &y);
            s[i] = ((x<<16)|y);
        }
        sort(s, s+n);

        for(i = 0; i < m; ++i) scanf("%d", w+i);
        sort(w, w+m);

        // run the greedy process.
        ans = 0;
        q.clear();
        
        for(i = j = 0; i < m; ++i) {
            
            while(j < n && (s[j]>>16) <= w[i]) q.insert(s[j++]&0xFFFF);
            
            while(!q.empty() && *q.begin() < w[i]) q.erase(q.begin());
            
            if(!q.empty()) {
                q.erase(q.begin());
                ans += 1;
            }
            
        }

        printf("%d\n", ans);
    
    }

}
