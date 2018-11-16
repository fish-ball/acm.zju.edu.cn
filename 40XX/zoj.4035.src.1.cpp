// 4387603	2018-11-16 17:44:04	Accepted	4035	C++	10	288	呆滞的慢板

/**
 * 水题
 * 排序输出即可
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

typedef long long i64;

int main() {
    i64 t, n, m;
    vector<pair<i64, string> > d;

    for (cin >> t; t--;) {
        d.clear();
        for(cin >> n >> m; n--;) {
            string s;
            int v;
            cin >> s >> v;
            d.push_back(make_pair(v, s));
        }
        sort(d.rbegin(), d.rend());
        i64 score = 0;
        for (i64 i = 0; i < m; ++i) {
            score += d[i].first * (m - i);
        }
        cout << score;
        for (i64 i = 0; i < m; ++i) {
            cout << ' ' << d[i].second;
        }
        cout << endl;
    }
    return 0;
}
