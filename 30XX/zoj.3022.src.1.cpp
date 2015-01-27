// 3856952	2015-01-27 20:28:21	Accepted	3022	C++	0	272	���͵�����

// �ö��ĵ���Ŀ����
// ��֪����ô�����������⣺ÿ����ֻ���� combo ��ʱ�򲻿���ѡǰ��ѡ��������
// ��ʼ�����ǣ�ÿ�����Լ��ϴ�ѡ����һ�ⲻ��ѡ~~
// ����������������� 

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
