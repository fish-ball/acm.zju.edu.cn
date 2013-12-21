// 1664783 2008-10-12 22:12:26 Accepted  1847 C++ 10 192 ���͵����� 

// Ӧ�����ڼ��⣬���漰һ��ȡ�����������鷳��
// ��ȷ��Ӧ�������ƽ��ֵ������ƫ�����ֵ�ͳ� 2��
// �������ھ�ȷ���֣����ƽ��ֵ mean��������� ceil �� floor ��ֵ��
// Ȼ�����ÿ���ˣ���Ǯ < mean������ floor ƫ�����ֵ�ӵ��ܺ��У������� ceil ��
// ���⣬��¼ƫ��(��ȡ����ֵ�ܺ�)����������ƫ�Ϊ 0��Ҫ����ƫ�����ֵ�ӵ��ܺ��С�
// �������ܺ�һ�뼴�ɡ� 

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

double A[1000], mean, sum, up, down, diff;
int N;

int main() {
    while(cin >> N && N) {
        mean = 0;
        for(int i = 0; i < N; ++i) {
            cin >> A[i];
            mean += A[i];
        }
        mean /= N;
        up = ceil(mean * 100) / 100;
        down = floor(mean * 100) / 100;
        sum = diff = 0;
        for(int i = 0; i < N; ++i) {
            if(fabs(up - A[i]) < fabs(down - A[i])) {
                sum += fabs(up - A[i]);
                diff += up - A[i];
            }
            else {
                sum += fabs(down - A[i]);
                diff += down - A[i];
            }
        }
        if(diff > 1e-5 || diff < -1e-5)
            sum += fabs(diff);
        printf("$%.2lf\n", sum / 2);
    }
}
