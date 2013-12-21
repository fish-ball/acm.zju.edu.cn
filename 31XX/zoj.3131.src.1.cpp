// 1867963 2009-05-14 01:45:30 Accepted  3131 C++ 20 568 ���͵����� 

// �����ӣ������ӵ�ʱ�� hhmmss ���Ӷ��ɵ�������ʱ������
// ��һ����ʱ�����䣬�ʵ���ʱ�����ܱ� 3 �������м�����
// �����Ļ����θ��ӶȲ��ߣ�����ѯ�����ܶࡣ
// ���������һ���ж������򽫺Ϸ����ܱ� 3 ����������ʱ�����浽˳����С�
// Ȼ��ÿ��һ�����䣬�ö��ֲ����ҵ�λ�ã�Ȼ��һ�����ɵõ������
// ���������ڵ��δ����Ч���ϴ�һ�������� 

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Clk {
    int hh, mm, ss;
    int value() { return ((hh * 100) + mm) * 100 + ss; }
    int get() { scanf("%2d:%2d:%2d", &hh, &mm, &ss); }
    void inc() { ss += 1; if(ss == 60) { mm += 1; ss = 0; if(mm == 60) { hh += 1; mm = 0; } } }
};

int main() {
    int N;
    Clk a, b;
    vector<int> v;
    a.hh = a.mm = a.ss = 0;
    while(true) {
        if(a.value() % 3 == 0) v.push_back(a.value());
        a.inc();
        if(a.value() == 475959) break;
    }
    for(scanf("%d", &N); N--;) {
        a.get();
        b.get();
        if(b.value() < a.value()) b.hh += 24;
        int dis =
            upper_bound(v.begin(), v.end(), b.value()) -
            lower_bound(v.begin(), v.end(), a.value());
        printf("%d\n", dis);
    }
}
