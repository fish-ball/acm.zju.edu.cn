// 1663373 2008-10-11 11:46:52 Accepted  1745 C++ 0 184 ���͵����� 

// ��ģ�⣬�ж�һ��Զ�����ɡ� 

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

inline int abs(int x) {return x < 0 ? -x : x;}

int x, y, z, t = 0;
string buf;

int main() {
    while(cin >> z && z != 5280) {
        if(t++) puts("");
        getline(cin, buf);
        istringstream is(buf);
        x = 0;
        while(is >> y) {
            printf("Moving from %d to %d: ", x, y);
            if(y == z) puts("found it!");
            else if(abs(x-z) == abs(y-z)) puts("same.");
            else if(abs(x-z) > abs(y-z)) puts("warmer.");
            else if(abs(x-z) < abs(y-z)) puts("colder.");
            x = y;
        }
    }
}
