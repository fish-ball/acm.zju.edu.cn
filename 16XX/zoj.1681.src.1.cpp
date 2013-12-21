// 2002776 2009-09-26 10:14:51 Accepted  1681 C++ 20 184 ���͵����� 

// һ������ı������⣬��һ����������һ�����������ı����� 
// ��ʵֻ��Ҫ��һ�� set �������е���ϼ��ɡ�
// ������������� N�����Ӷ�Ϊ O(N^2/3)����ȫ����ʤ�Ρ� 

#include <iostream>
#include <set>
using namespace std;

int main() {
    set<int> S;
    for(int i = 0, iii; (iii = i * i * i) <= 151200; ++i) {
        S.insert(iii);
        for(int j = 1, jjj; jjj = j*(j+1)*(j+2)/6; ++j) {
            if(iii + jjj > 151200) break;
            S.insert(iii + jjj);
        }
    }
    int x;
    while(cin >> x && x) {
        set<int>::iterator it = S.upper_bound(x);
        cout << *(--it) << endl;
    }
}
