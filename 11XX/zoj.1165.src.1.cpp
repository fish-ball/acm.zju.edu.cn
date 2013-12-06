// 2174667 2010-04-24 08:48:03 Accepted  1165 C++ 60 184 呆滞的慢板 

// 寻找一个整数点集的所有三点共线以上的直线。
// 先对所有点排序，然后枚举第一个点 p。
// 再枚举第二个点 q(q!=p)，按其到第一个点的斜率为键值把该点放到一个字典中。
// 字典的每个位置是一个点集。
// 第二层枚举完之后遍历字典，对于每个容量大于 3，且首个点坐标大于 p 的点集，
// 就是要求的直线，放到结果集当中，然后对结果集排序，输出。
// 复杂度 N * N log(M)，其中 M 是最大直线的长度，因此最坏不超过 N * N * log(N)。 

#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> P;

int gcd(int x, int y) {
    int sign;
    if(x < 0) {
        sign = -1;
    }
    else if(x > 0) {
        sign = 1;
    }
    else if(y < 0) {
        sign = -1;
    }
    else {
        sign = 1;
    }
    int m = x < 0 ? -x : x, n = y < 0 ? -y : y, r;
    while(n != 0) {
        r = m % n;
        m = n;
        n = r;
    }
    return m * sign;
}

void disp(P p) {
    printf("(%4d,%4d)", p.first, p.second);
}

void output(set<P> s) {
    for(set<P>::iterator iter = s.begin();
            iter != s.end(); ++iter) {
        disp(*iter);
    }
    puts("");
}

int main() {
    int x, y;
    while(cin >> x >> y && (x || y)) {
        vector<P> v;
        do {
            v.push_back(make_pair(x, y));
        } while(cin >> x >> y && (x || y));
        sort(v.begin(), v.end());
        vector<set<P> > ans;
        for(int i = 0; i < v.size(); ++i) {
            map<P, set<P> > mp;
            for(int j = 0; j < v.size(); ++j) {
                if(j == i) continue;
                int dx = v[j].first - v[i].first;
                int dy = v[j].second - v[i].second;
                int g = gcd(dx, dy);
                mp[make_pair(dx/g, dy/g)].insert(v[j]);
            }
            for(map<P, set<P> >::iterator iter = mp.begin();
                    iter != mp.end(); ++iter) {
                if(iter->second.size() > 1 && *(iter->second.begin()) > v[i]) {
                    iter->second.insert(v[i]);
                    ans.push_back(iter->second);
                }
            }
        }
        sort(ans.begin(), ans.end());
        if(ans.size() > 0) {
            puts("The following lines were found:");
            for(int i = 0; i < ans.size(); ++i) {
                output(ans[i]);
            }
        }
        else {
            puts("No lines were found");
        }
    }
}
