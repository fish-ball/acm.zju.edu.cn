// 2540952 2011-05-20 18:11:35 Accepted  3432 C++ 960 180 ���͵����� 
// ����һϵ�ж����ַ���������ֻ������һ�ε�Ψһһ����
// �����ǽ��ַ���ת������ȫ����������������ʣ�µĽ���� 

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
