// 1882477 2009-05-24 01:39:05 Accepted  3203 C++ 0 184 ���͵����� 

// Ӱ�ӳ������ֵ���Լ�ת������һ�����庯�����ֵ���⣬ֱ�Ӷ��ֿɵý⡣

#include <iostream>
#include <cmath>
using namespace std;

int T;
double H, h, D;
    
double eval(double x) {
    double ans = 0;
    double y = H * x / (H - h);
    if(y <= D) return y - x;
    return D - x + h * (y - D) / (y - x);
}
    
int main() {
    for(cin >> T; T--;) {
        cin >> H >> h >> D;
        double l = 0, r = D;
        while(r - l > 1e-5) {
            double m = (r + l) / 2;
            double v1 = eval(m - 1e-6);
            double v3 = eval(m + 1e-6);
            if(v1 > v3) r = m;
            else l = m;
        }
        printf("%.3lf\n", eval(r));
    }
}
