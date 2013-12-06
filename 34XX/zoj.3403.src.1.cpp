// ���ۣ����⣬��������Ƶ����ת����
// �������Ƚ��յ����� 1���ٽ��µ����� 1���ٽ���ݵ������� 12
// ����ʱ�������ڲȻ��������긽�ӵ�������
// �������� 12 ����������� 

#include <cstdio>
#include <iostream>
using namespace std;

typedef long long i64;

i64 days(i64 yy, i64 mm, i64 dd) {
    i64 ans = 0;
    // �� 12 ��ġ� 
    ans += yy / 12 * 18382;
    // �������� 
    ans += (yy + 10) / 11;
    // �������� 
    for(int y = 0; y < yy % 12; ++y) {
        ans += (y+2) * (y+2) * (y+1) * (y+1) / 4;
    }
    // ��������
    for(int m = 1; m < mm; ++m) {
        if(m == 1 && yy % 11 == 0) ++ans;
        ans += m * m * m;
    }
    // ��������
    ans += dd; 
    return ans;
}

int main() {
    int y1, m1, d1, y2, m2, d2;
    while(scanf("%d-%d-%d %d-%d-%d", &m1, &d1, &y1, &m2, &d2, &y2) != EOF) {
        i64 ans = days(y2, m2, d2) - days(y1, m1, d1);
        ans = ans < 0 ? 1 - ans : 1 + ans;
        cout << ans << endl;
    }
}