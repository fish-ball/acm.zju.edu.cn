// 4387330	2018-11-16 12:03:25	Accepted	4036	C++	0	288	呆滞的慢板

/**
 * 水题
 * 注意边界条件，a+b 要是正数才能算
 */

#include <iostream>
using namespace std;

int main() {
    int t, n, a, b;
    for (cin >> t; t--;) {
        bool yes = false;
        for (cin >> n >> b; n--;) {
            cin >> a;
            if (a + b > 0 && (a + b) % 7 == 0) {
                yes = true;
            }
        }
        cout << (yes ? "Yes" : "No") << endl;
    }
    return 0;
}
