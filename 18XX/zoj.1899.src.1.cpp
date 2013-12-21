// 1664650 2008-10-12 20:07:35 Accepted  1899 C++ 3460 316 ���͵����� 

// �ֵ䣬�򵥵�ӳ��һ�¼��ɣ��� STL map �㹻�ˡ� 

#include <map>
#include <string>
#include <iostream>
using namespace std;

int main() {
    map<string, double> M;
    map<string, double>::iterator it;
    int T = 0;
    while(!cin.eof()) {
        if(T++) puts("");
        string s;
        double N = 0;
        M.clear();
        while(getline(cin, s) && s != "") {
            M[s] += 1.0;
            N += 1.0;
        }
        for(it = M.begin(); it != M.end(); ++it) {
            cout << it->first;
            printf(" %.4lf\n", it->second / N * 100);
        }
    }
}
