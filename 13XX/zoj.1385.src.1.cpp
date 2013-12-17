// 1652487 2008-10-01 00:14:54 Accepted  1385 C++ 0 268 ���͵����� 

// ģ 2 ����������Ƶ���ͨ�����:
// S(n,m) == (Comb(n-1-m div 2, (m-1) div 2)) mod 2 
// ���������ô��Ͳ���˵�˰ɡ� 

#include <iostream>
using namespace std;

int fact(int n) {
    int ans = 0;
    while(n) ans += (n>>=1);
    return ans;
}

int comb(int x, int y) {
    return fact(x) <= fact(x-y) + fact(y);
}

int main() {
    int T, m, n;
    for(cin >> T; T--;) {
        cin >> n >> m;
        cout << comb(n-1-m/2, (m-1)/2) << endl;
    }
}
