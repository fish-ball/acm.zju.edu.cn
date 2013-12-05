// 1652433 2008-09-30 22:15:28 Accepted  1143 C++ 0 460 ���͵����� 

// ���˺þòŶ���������Ŀʲô��˼��
// ǧ������⣺��ʽ������������֮��ᵼ����ݵ���һ������;
// �� i �����(Ci)���ڷ�Χ�� [ai, bi)����ǰ��ʾ���Ϊ yi�����ڴ�������;
// ÿ���� bi ���Զ����ص� ai ��;
// ����һ����ԣ�C[1..n]������ ai, bi, yi, ������ʵ����������ͬ��;
// ����ܵ������ʵ�����ڣ����û�У�����Ӧ���������ʵ������ <10000;

// ��ʵ����һ��ģ���Է����飬�����������ݷ�Χ�����ޣ�������ģ�� WS ��ȥ��
// ����ÿ����һ̨���ԣ�ά�����ܵ���ʵ��ݣ������󽻼�ɸѡ�� 

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> x, y;
int T = 1, N, a, b, c;

int main() {
    while(cin >> N && N) {
        x.clear();
        for(int i = 0; i < 10000; ++i)
            x.push_back(i);
        while(N--) {
            cin >> c >> a >> b;
            y.clear();
            while(c < 10000) {
                y.push_back(c);
                c += b - a;
            }
            x.resize(set_intersection(x.begin(), x.end(),
                y.begin(), y.end(), x.begin()) - x.begin());
        }
        printf("Case #%d:\n", T++);
        if(x.empty()) puts("Unknown bugs detected.\n");
        else printf("The actual year is %d.\n\n", x[0]);
    }
}

