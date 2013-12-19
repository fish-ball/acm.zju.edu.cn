// 3492413 2013-12-19 23:09:05 Accepted 3508 C++ 0 412 ´ôÖÍµÄÂý°å
#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector> 
using namespace std;

int n, m, i, j, ans, s[2500], w[40000], x, y;
priority_queue<int, vector<int>, greater<int> > q;

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
        while(!q.empty()) q.pop();
        
        for(i = j = 0; i < m; ++i) {
            
            while(j < n && (s[j]>>16) <= w[i]) q.push(s[j++]&0xFFFF);
            
            while(!q.empty() && q.top() < w[i]) q.pop();
            
            if(!q.empty()) {
                q.pop();
                ans += 1;
            }
            
        }

        printf("%d\n", ans);
    
    }

}
