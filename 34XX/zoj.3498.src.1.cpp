// 2544486 2011-05-25 14:13:32 Accepted 3498 C++ 0 188 ´ôÖÍµÄÂý°å

#include <iostream>
using namespace std;

int main() {
    int t, n, x;
    cin >> t;
    while(t--) {
        cin >> n;
        x = 0;
        while(n) {
            ++x;
            n /= 2;
        }
        cout << x << endl;
    }
}