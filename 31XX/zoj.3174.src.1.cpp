// 1801394 2009-03-24 00:48:50 Accepted  3174 C++ 0 184 ���͵����� 

// ���⣬��������֮����ڶ��ٸ��£�
// ʹ���·ݵ�ƽ��������ݵĺ���λ���ߺ���λ�� 
// ֱ��ö������Ȼ���ж����������ɡ� 

#include <iostream>
using namespace std;

int main() {
    int T;
    for(cin >> T; T--;) {
        int x, y;
        cin >> x >> y;
        int ans = 0;
        for(int i = x; i <= y; ++i) {
            for(int j = 1; j <= 12; ++j) {
                if(j * j == i % 100 || j * j == i % 1000)
                    ++ans;
            }
        }
        cout << ans << endl;
    }
}
