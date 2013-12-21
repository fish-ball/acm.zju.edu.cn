// 1653354 2008-10-01 21:40:54 Accepted  1577 C++ 0 260 ���͵����� 

// ֪�� p��q ����󹫱�������С��Լ������ p �� q �����ж�����ȡֵ��
// �����ת����x = lcm/gcd������ x = m * n��m, n ���ʵ�ȡֵ�ж�����
// ���� x �� k ����ͬ�������ӣ�������� 2^k��ע�⣬�п��� lcm ���ܱ� gcd ������

#include <cstdio>

int x, y;

int main() {
    while(scanf("%d%d", &x, &y) != EOF) {
        if(y % x != 0) {puts("0"); continue;}
        y /= x;
        x = 0;
        for(int i = 2; i * i <= y; ++i) {
            if(y % i == 0) {
                ++x;
                while(y % i == 0)
                    y /= i;
            }
        }
        if(y != 1) ++x;
        printf("%d\n", 1<<x);
    }
}
