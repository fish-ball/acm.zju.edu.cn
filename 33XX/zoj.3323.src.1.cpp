// 2168926 2010-04-19 13:33:34 Accepted  3323 C++ 0 184 ���͵����� 

// -____-b�����⼦���е��ף� 
 
#include <iostream>
#include <cstring>
using namespace std;

int main() {
    int N;
    string A;
    for(cin >> N; N--;) {
        cin >> A;
        for(int i = 0; i < A.size(); ++i) {
            if(!isdigit(A[i]))
                putchar(A[i]);
        }
        puts("");
    }
}
