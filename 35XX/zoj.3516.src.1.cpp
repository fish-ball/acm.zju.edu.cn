// 3495540 2013-12-25 10:19:45 Accepted 3516 C++ 1080 1300 呆滞的慢板

#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long i64;

int main() {

    int n, m, i, j, father[10000], child[10000];
    i64 vals[10000];
    vector<int> q;
    vector<vector<i64> > maxvals;
    
    while(cin >> n) {
    
        memset(child, 0, sizeof(child));
        memset(father, -1, sizeof(father));
    
        cin >> vals[0];
        for(i = 1; i < n; ++i) {
            cin >> father[i] >> vals[i];
            child[father[i]]++;
        }
        
        maxvals.resize(n);
        
        q.clear();
        for(i = 0; i < n; ++i) {
            maxvals[i].clear();
            maxvals[i].push_back(vals[i]);
            if(child[i] == 0) q.push_back(i);
        }
        
        
        while(!q.empty()) {
            
            i = q.back();
            j = father[i];
            q.pop_back();
            if(j >= 0) {
                for(int k = 0; k < maxvals[i].size(); ++k)
                    maxvals[j].push_back(maxvals[i][k]);
                sort(maxvals[j].rbegin(), maxvals[j].rend());
                if(maxvals[j].size() > 3) maxvals[j].resize(3);
                if(--child[j] <= 0) q.push_back(j);
            }
            
        }
        
        for(cin >> m; m--;) {
            cin >> i;
            if(maxvals[i].size() == 3) {
                cout << maxvals[i][0] << ' '
                     << maxvals[i][1] << ' '
                     << maxvals[i][2] << endl;
            }
            else {
                cout << -1 << endl;
            }
        }
    
    }

}
