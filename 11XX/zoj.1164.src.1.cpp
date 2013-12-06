// 2174159 2010-04-23 17:03:13 Accepted  1164 C++ 0 184 呆滞的慢板 

// 循环冗余验证码，CRC，串联求出余数之后乘以 256 * 256 取补即可。 

#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    while(getline(cin, s) && s != "#") {
        int rem = 0;
        for(int i = 0; i < s.size(); ++i) {
            rem *= 256;
            rem += s[i];
            rem += 34943;
            rem %= 34943;
        }
        rem = rem * 256 % 34943 * 256 % 34943;
        rem = (34943 - rem) % 34943;
        int a = rem % 16;
        rem /= 16;
        int b = rem % 16;
        rem /= 16;
        int c = rem % 16;
        rem /= 16;
        int d = rem % 16;
        string cd = "0123456789ABCDEF";
        putchar(cd[d]);
        putchar(cd[c]);
        putchar(' ');
        putchar(cd[b]);
        putchar(cd[a]);
        putchar('\n');
    }
}
