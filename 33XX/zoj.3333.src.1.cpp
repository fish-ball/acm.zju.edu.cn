// 2168909 2010-04-19 13:19:33 Accepted  3333 C++ 0 184 呆滞的慢板 

// -____-b，很华丽的题号，很肉鸡的内涵。 

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int N, P, A, B;
    for(cin >> N; N--;) {
        cin >> P >> A >> B;
        cout << (abs(P-A) <= abs(P-B) ? "A" : "B") << endl;
    }
}
