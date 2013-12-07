// 2210438 2010-06-10 12:50:15 Accepted  3326 C++ 0 2488 呆滞的慢板 
// 日期区间判别，用一种相对比较暴力的方法：
// 枚举合法日期放到线性表中，用二分计数。 

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Date {
    int y, m, d;
    void get() { cin >> y >> m >> d; }
} d1, d2;

bool operator <(const Date& a, const Date& b) {
    if(a.y < b.y) return true;
    else if(a.y > b.y) return false;
    else if(a.m < b.m) return true;
    else if(a.m > b.m) return false;
    return a.d < b.d;
}

int N;
vector<Date> V;

int P[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
int D[2][12] = {
    {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
    , {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int main() {
    Date d;
    for(d.y = 1000; d.y < 3000; ++d.y) {
        bool isLeap = d.y % 100 != 0 && d.y % 4 == 0 || d.y % 400 == 0;
        for(int i = 0; P[i] <= 12; ++i) {
            d.m = P[i];
            for(int j = 0; P[j] <= D[isLeap][d.m-1]; ++j) {
                d.d = P[j];
                V.push_back(d);
            }
        }
    }
    for(cin >> N; N--;) {
        d1.get();
        d2.get();
        cout << upper_bound(V.begin(), V.end(), d2) 
            - lower_bound(V.begin(), V.end(), d1) << endl;
    }
}
