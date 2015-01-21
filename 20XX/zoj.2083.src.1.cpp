// 3853445	2015-01-21 23:38:23	Accepted	2083	C++	0	272	呆滞的慢板
// 博弈论：Sprague Grundy 定理 

#include <iostream>
#include <set>
using namespace std;

int main() {
    
    int mex[51] = {0, 0, 1};
    for(int i = 3; i < 51; ++i) {
        set<int> MEX;
        for(int j = 0; j + 2 <= i; ++j) {
            MEX.insert(mex[j] ^ mex[i-2-j]);
        }
        while(MEX.find(mex[i]) != MEX.end()) {
            mex[i] += 1;
        }
    }
    
    int N, k;
    while(cin >> N) {
        int ans = 0;
        while(N--) {
            cin >> k;
            ans ^= mex[k];
        }
        cout << (ans ? "Yes": "No") << endl;
    }
    return 0;
}
