// 3493756 2013-12-21 23:12:26 Accepted 3573 C++ 3020 272 ´ôÖÍµÄÂý°å

#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    
    int L, l, r, x, mx, i, v[15002];
    
    while(cin >> L) {
        memset(v, 0, sizeof(v));
        while(cin >> l >> r >> x) {
            if(l < 0) break;
            v[l] += x;
            v[r+1] -= x;
        }
        mx = 0;
        x = 0;
        for(i = 0; i <= L+1; ++i) {
            x += v[i];
            if(x > mx) {
                mx = x;
                l = r = i;
            }
            else if(x == mx) {
                r = i;
            }
        }
        cout << l << ' ' << r << endl;
    }
        
}
