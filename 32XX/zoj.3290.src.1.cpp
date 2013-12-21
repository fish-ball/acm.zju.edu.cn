// 2084961 2010-01-31 23:58:49 Accepted  3290 C++ 0 184 ���͵����� 

// ���⣬������������в�֣����� a(n+1) = a(n) * 2 + 1 ���죬 
// ��ʣ��ȫ���ӵ����һ�������ˡ� 

#include <iostream>
#include <vector>
using namespace std;

int main() {
    long long n;
    bool br = false;
    while(cin >> n) {
        if(br) puts("");
        br = true;
        vector<long long> v(1, 1);
        n--;
        while(v.back() * 2 + 1 <= n) {
            v.push_back(v.back() * 2 + 1);
            n -= v.back();
        }
        v.back() += n;
        cout << v.size() << endl;
        while(!v.empty()) {
            cout << v.back();
            v.pop_back();
            if(!v.empty()) putchar(' ');
        }
        puts("");
    }
}
