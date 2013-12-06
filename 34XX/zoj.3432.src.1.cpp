// 2540952 2011-05-20 18:11:35 Accepted  3432 C++ 960 180 呆滞的慢板 
// 给出一系列定长字符串，返回只出现了一次的唯一一个。
// 做法是将字符串转二进制全部进行异或运算最后剩下的结果。 

#include <cstring>
#include <cstdio>

int main() {
    int count;
    char tmp[8];
    while(scanf("%d ", &count) != EOF) {
        count  = count * 2 - 1;
        long long mask = 0;
        long long next = 0;
        while(count--) {
            gets(tmp);
            mask ^= *((long long *)tmp);
        }
        puts((char*)(&mask));
    }
    return 0;
}
