// 3493735 2013-12-21 22:38:46 Accepted 3590 C++ 20 272 ´ôÖÍµÄÂı°å

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    
    long long n, i, a, a1, a2, x, ans;
    
    while(cin >> n) {
        for(i = a = a1 = a2 = 0; i < n; ++i) {
            cin >> x;
            a += x / 3;
            switch(x % 3) {
                case 1: ++a1; break;
                case 2: ++a2; break;
            }
        }
        ans = a;
        if(a > 0) ans += a2;
        while(a > 1 && a1 > 0) {
            x = min(a1, a/2);
            ans += x;
            a1 -= x;
            a = a - x;
        }
        if(a > 0) ans += (a - 1) / 2;
        cout << ans << endl;
    }
        
}
