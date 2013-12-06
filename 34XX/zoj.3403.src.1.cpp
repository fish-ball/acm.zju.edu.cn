// 数论，简单题，求特殊进制的年份转换。
// 做法：先将日调整到 1，再将月调整到 1，再将年份调整到整 12
// 调整时更新日期差，然后计算闰年附加的日数；
// 最后加上整 12 年的日期数。 

#include <cstdio>
#include <iostream>
using namespace std;

typedef long long i64;

i64 days(i64 yy, i64 mm, i64 dd) {
    i64 ans = 0;
    // 整 12 年的。 
    ans += yy / 12 * 18382;
    // 闰年数。 
    ans += (yy + 10) / 11;
    // 调整年数 
    for(int y = 0; y < yy % 12; ++y) {
        ans += (y+2) * (y+2) * (y+1) * (y+1) / 4;
    }
    // 调整月数
    for(int m = 1; m < mm; ++m) {
        if(m == 1 && yy % 11 == 0) ++ans;
        ans += m * m * m;
    }
    // 调整天数
    ans += dd; 
    return ans;
}

int main() {
    int y1, m1, d1, y2, m2, d2;
    while(scanf("%d-%d-%d %d-%d-%d", &m1, &d1, &y1, &m2, &d2, &y2) != EOF) {
        i64 ans = days(y2, m2, d2) - days(y1, m1, d1);
        ans = ans < 0 ? 1 - ans : 1 + ans;
        cout << ans << endl;
    }
}