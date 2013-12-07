// 3487574 2013-12-07 14:33:23 Accepted 3665 C++ 1030 272 呆滞的慢板
// 1. 效率卡得很死，瓶颈在于 find_q 函数中二分上限 r 的取值。
// 2. 在 c++ 下存在溢出的问题，因此对于计算 pow 溢出的情况需要特别小心处理。 

#include<iostream> 
#include<string> 
#include<cmath> 
#include<algorithm> 
using namespace std;

typedef long long i64;

i64 i64_pow(i64 a, i64 n) {
    if(n == 0) return 1;
    i64 ans = i64_pow(a, n>>1);
    ans *= ans;
    return (n&1) ? ans * a : ans;
}

i64 my_pow(i64 a, i64 n) {
    return pow(double(a), double(n)) > 1e14 ? 0 : i64_pow(a, n);
}

i64 find_q(i64 s, i64 n) {
    i64 l = 1, r = i64(pow(s, 1.0/n)) + 1;
    while(l < r - 1) {
        i64 q = (l + r) / 2;
        i64 pwqn = my_pow(q, n);
        i64 ss = (pwqn-1)/(q-1)*q;
        if(pwqn && (ss == s || ss == s-1)) return q;
        else if(pwqn == 0 || ss > s) r = q;
        else l = q;
    }
    return 0;
}

int main() {
    
    for(i64 n; cin >> n;) {
        pair<i64, i64> a = make_pair(1, n - 1);
        for(i64 r = 2; r < 41; ++r) {
            i64 k = find_q(n, r);
            if(k && r * k < a.first * a.second)
                a = make_pair(r, k);
        }
        cout << a.first << ' ' << a.second << endl;
    }
    
}
