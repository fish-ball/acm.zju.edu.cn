// 2164853 2010-04-16 13:01:04 Accepted  3311 C++ 0 184 ���͵����� 

// ZOJ�����飬�߼��ȼ۱任������ȼ��ڣ�
// ���ҽ���һ�� Z�����ҽ���һ�� J��J �� Z �����Ҳ��ܽ����ں��棬
// ���⣬�м���ӵ����� O �ֱ��� a, b, c �ĳ��ȣ��������� a + b = c�� 

#include <string>
#include <iostream>
using namespace std;

int main() {
    string s;
    while(cin >> s) {
        int z1, z2, j1, j2;
        z1 = s.find_first_of('Z');
        z2 = s.find_last_of('Z');
        j1 = s.find_first_of('J');
        j2 = s.find_last_of('J');
        puts(z1==z2&&j1==j2&&z1!=-1&&j1!=-1&&j1-z1>1&&s.size()==j1+j1 ?
            "Accepted" : "Wrong Answer");
    }
}
