// 3487620 2013-12-08 15:14:16 Accepted 3665 C++ 210 272 ���͵�����
// 1. Ч�ʿ��ú�����ƿ������ find_q �����ж������� r ��ȡֵ��
// 2. �� c++ �´�����������⣬��˶��ڼ��� pow ����������Ҫ�ر�С�Ĵ��� 

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

i64 find_q(i64 s, i64 n) {
    i64 l = 1, r = i64(pow(s, 1.0/n)) + 1;
    while(l < r - 1) {
        i64 q = (l + r) / 2;
        i64 pwqn = pow(double(q), double(n)) > 1e14 ? 0 : i64_pow(q, n);
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
