// 4387618	2018-11-16 18:27:04	Accepted	3958	C++	0	288	呆滞的慢板

/**
 * 弱智题
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

typedef long long i64;

int main() {
    int t, n, a, b, x;
    int da[] = {1, 0, 1, -1};
    int db[] = {0, 1, 1, -1};

    for (cin >> t; t--;) {
        a = b = 0;
        for (cin >> n; n--;) {
            cin >> x;
            a += da[x - 1];
            b += db[x - 1];
        }
        cout << (a == b ? "Draw" : a > b ? "Kobayashi" : "Tohru") << endl;
    }
    return 0;
}
