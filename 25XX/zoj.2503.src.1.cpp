// 1653819 2008-10-02 14:13:42 Accepted  2503 C++ 20 260 ���͵����� 

// ����ͨ����΢�ַ����Ƴ���ʽ��T = 1/(1-cos(2*PI/N)) 

#include <cmath>
#include <cstdio>

const double PI = acos(-1.0);

int main() {
    int T;
    double N;
    for(scanf("%d", &T); T--;) {
        scanf("%lf", &N);
        printf("%.3lf\n", 1.0/(1.0-cos(2.0*PI/N)));
    }
}
