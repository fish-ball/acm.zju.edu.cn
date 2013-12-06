// 2544443 2011-05-25 13:06:53 Accepted 3486 C++ 0 188 ´ôÖÍµÄÂı°å

#include <iostream>
#include <map>
using namespace std;

int main() {
    int T;
    cin >> T;
    while(T--) {
        int N;
        cin >> N;
        map<int, int> count;
        int maxval = 0, key;
        while(N--) {
            int tmp;
            cin >> tmp;
            int cnt = ++count[tmp];
            if(cnt > maxval || cnt == maxval && tmp > key) {
                maxval = cnt;
                key = tmp;
            }
        }
        cout << key << endl;
    }
}