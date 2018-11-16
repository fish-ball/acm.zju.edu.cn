// 4387310	2018-11-16 11:53:13	Accepted	4024	C++	620	288	呆滞的慢板

/**
 * 水题，判断一个输入数组是否先递增后递减
 * 审题注意边界条件：
 * 1. 上升段和下降段都是必须的，因为 1<k<n
 * 2. 不能相等，必须严格单调
 * 明显 o(n) 时间，但是空间可以做到 O(1)
 */

#include <iostream>
using namespace std;

int main() {
    int t, n, a, b;
    for (cin >> t; t--;) {
        int stage = 0;
        a = -1;
        b = -1;
        for (cin >> n; n--;) {
            a = b;
            cin >> b;
            if (a == -1) continue;
            if (a == b) {
                stage = -1;
            } else if (stage == 0) {
                if (a < b) stage = 1;
                else stage = -1;
            } else if (stage == 1) {
                if (a > b) stage = 2;
            } else if (stage == 2) {
                if (a < b) stage = -1;
            }
        }
        cout << (stage == 2 ? "Yes" : "No") << endl;
    }
    return 0;
}