// 2147595 2010-04-08 16:47:45 Accepted  1105 C++ 0 184 ���͵����� 

// �����⣬��ʵ˫���ߵ�ͼֱ�Ӱ���DFS·�߿϶���һ��ŷ����·��
// ��ˣ�ֻ��Ҫͳ�����б߳�����20km/s�ٳ�1000m/km�͵õ�Сʱ���� 

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
    double x1, y1, x2, y2;
    while(cin >> x1 >> y1 >> ws) {
        double len = 0;
        while(cin.peek() != 'j') {
            cin >> x1 >> y1 >> x2 >> y2 >> ws;
            len += hypot(x1-x2, y1-y2);
        }
        string buf;
        cin >> buf;
        int ans = (int)(len / 1000 * 6 + 0.5);
        printf("%d:%02d\n", ans / 60, ans % 60);
    }
}
