// 1882480 2009-05-24 01:44:27 Accepted  3207 C++ 0 184 ���͵����� 

// �򵥵��ַ����ֵ����⣬ֱ���� set �����ˡ�

#include <set>
#include <string>
#include <iostream>
using namespace std;

int main() {
    set<string> ST;
    int N;
    for(cin >> N; N--;) {
        string s;
        cin >> s;
        ST.insert(s);
    }
    int K;
    for(cin >> K; K--;) {
        int M, A = 0;
        for(cin >> M; M--;) {
            string s;
            cin >> s;
            if(ST.find(s) != ST.end())
                ++A;
        }
        cout << A << endl;
    }
}
