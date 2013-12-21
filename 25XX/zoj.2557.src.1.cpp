// 1888879 2009-06-01 02:41:25 Accepted  2557 C++ 0 184 ���͵����� 

// �ļ����������⣬�������غ㶨���ɡ�
// ����ղķ˹��µ����ŵ�ʱ�� ���� = ��ʼ�������� - ĩβʱ�������ܡ� 
// Ȼ��ͨ�����ܼ������ĩ�ٶȡ�ע�⵱ s < l ʱ��������Ϊ 0�� 

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double k, l, s, w, g = 9.81;
    while(cin >> k >> l >> s >> w && (k || l || s || w)) {
        if(l > s) {
            double v = sqrt(2.0 * g * s);
            if(v < 10.0) puts("James Bond survives.");
            else puts("Killed by the impact."); 
            continue;
        }
        double E = w * g * s - 0.5 * k * (s-l) * (s-l);
        if(E < 0) puts("Stuck in the air.");
        else {
            double v = sqrt(E * 2.0 / w);
            if(v < 10.0) puts("James Bond survives.");
            else puts("Killed by the impact.");
        }
    }
}
