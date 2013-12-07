// 2210540 2010-06-10 15:10:26 Accepted  3331 C++ 140 184 呆滞的慢板 

// 维护一个 A 递增、B 递减的边缘列表

#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

int main() {
    int N, T, a, b;
    for(cin >> T; T--;) {
        cin >> N;
        vector<pair<int, int> > V;
        V.push_back(make_pair(0, 0));
        for(int k = 1; k <= N; ++k) {
            cin >> a >> b;
            vector<pair<int, int> > W;
            for(int i = 0; i < V.size(); ++i) {
                int ka = V[i].first, kb = V[i].second;
                if(ka > kb) {
                    W.push_back(make_pair(ka, kb + b));
                    W.push_back(make_pair(ka + a, ka));
                }
                else {
                    W.push_back(make_pair(ka + a, kb));
                    W.push_back(make_pair(kb, kb + b));
                }
            }
            V.clear();
            sort(W.begin(), W.end());
            for(int i = 0; i < W.size(); ++i) {
                if(i == 0 || W[i].second < W[i-1].second) {
                    V.push_back(W[i]);
                }
            }
        }
        int ans = INT_MAX;
        for(int i = 0; i < V.size(); ++i) {
            ans = min(ans, max(V[i].first, V[i].second));
        }
        cout << ans << endl;
    }
}
