// 3856952	2015-01-27 20:28:21	Accepted	3022	C++	0	272	呆滞的慢板

// 好恶心的题目啊！
// 不知道怎么读出来的题意：每个人只有在 combo 的时候不可以选前面选过的所有
// 开始理解的是，每个人自己上次选的那一题不能选~~
// 但结果就是这样。。 

#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main() {
    int n;
    while(cin >> n) {
        double P[20] = {}, Q[20] = {};
        P[n] = 1;
        int kc = 0, wc = 0;
        for(string s; cin >> s, s != "End";) {
            memset(Q, 0, sizeof(Q));
            if(s == "Kimi") {
                if(kc >= n) continue;
                for(int i = 0; i <= n; ++i) {
                    int j = n - i;
                    Q[i] += P[i] * max(i-kc,0) / (n-kc);
                    Q[i+1] += P[i] * j / (n-kc);
                }
                ++kc; 
                wc = 0;
            } else if(s == "Watashi") {
                if(wc >= n) continue;
                for(int i = 0; i <= n; ++i) {
                    int j = n - i;
                    Q[i] += P[i] * max(j-wc,0) / (n-wc);
                    if(i) Q[i-1] += P[i] * i / (n-wc);
                }
                ++wc;
                kc = 0;
            }
            memcpy(P, Q, sizeof(Q)); 
        }
        printf("%.02lf\n", P[n]);
    }
}
