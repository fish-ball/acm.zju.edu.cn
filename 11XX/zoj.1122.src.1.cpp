// 1659127 2008-10-06 22:37:06 Accepted  1122 C++ 0 184 ���͵����� 

// ģ�⣬�Ƕȵĵ�λ�� 1��ÿһ�����Ӹ����� 12 ����λ��һ��Բ���� 60*12 ����λ 
// Ҳ����ÿ���ӷ����� 12 ����λ��ʱ���� 1 ����λ������ٶȷ���׷�� 11 ����λ
// ����� t2-t1 �ж��ٷ��� t���Լ���ʼʱ���볬ǰ�ĽǶ� a(��ʼλ��)
// ׷���ٶ� 11������ʱ���λ�� t*11+a�����׷���� (t*11+a)/(12*60) �� 

#include <iostream>
using namespace std;

int main() {
    puts("Program 3 by team X");
    puts("Initial time  Final time  Passes");
    int h1, m1, h2, m2, t1, t2, a, t;
    while(cin >> h1 >> m1 >> h2 >> m2) {
        t1 = m1 + h1 * 60;
        t2 = m2 + h2 * 60;
        t = t2 - t1;
        if(t < 0) t += 12 * 60;
        a = m1 * 12 - h1 * 5 * 12 - m1;
        if(a < 0) a += 12 * 60;
        printf("       %02d:%02d", h1, m1);
        printf("       %02d:%02d", h2, m2);
        printf("%8d\n", (t * 11 + a) / (12 * 60));
    }
    puts("End of program 3 by team X");
}
