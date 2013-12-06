// 2174667 2010-04-24 08:48:03 Accepted  1165 C++ 60 184 ���͵����� 

// Ѱ��һ�������㼯���������㹲�����ϵ�ֱ�ߡ�
// �ȶ����е�����Ȼ��ö�ٵ�һ���� p��
// ��ö�ٵڶ����� q(q!=p)�����䵽��һ�����б��Ϊ��ֵ�Ѹõ�ŵ�һ���ֵ��С�
// �ֵ��ÿ��λ����һ���㼯��
// �ڶ���ö����֮������ֵ䣬����ÿ���������� 3�����׸���������� p �ĵ㼯��
// ����Ҫ���ֱ�ߣ��ŵ���������У�Ȼ��Խ�������������
// ���Ӷ� N * N log(M)������ M �����ֱ�ߵĳ��ȣ����������� N * N * log(N)�� 

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
