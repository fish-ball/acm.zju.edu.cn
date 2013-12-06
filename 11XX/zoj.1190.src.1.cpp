// 2181876 2010-05-01 13:20:59 Accepted  1190 C++ 410 184 呆滞的慢板 

// 向量处理机给 Input 和 Output 求指令，暴搜。 

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int N;
vector<vector<int> > stk;
vector<int> in, out;
vector<string> trc, ans;

void solve() {
    if(stk.back() == out) {
        if(ans.size() > trc.size() || trc < ans) {
            ans = trc;
        }
        return;
    }
    if(trc.size() == ans.size()) return;
    vector<int> a, b;
    bool flag;
    // DUP
    stk.push_back(stk.back());
    trc.push_back("DUP");
    solve();
    trc.pop_back();
    stk.pop_back();
    if(stk.size() == 1) return;
    // SUB
    b = stk.back(); stk.pop_back();
    a = stk.back();
    flag = true;
    for(int i = 0; i < a.size(); ++i) {
        stk.back()[i] -= b[i];
        if(stk.back()[i] < -30000 || stk.back()[i] > 30000) {
            flag = false;
            break;
        }
    }
    trc.push_back("SUB");
    if(flag) solve();
    trc.pop_back();
    stk.pop_back();
    stk.push_back(a);
    stk.push_back(b);
    // ADD
    b = stk.back(); stk.pop_back();
    a = stk.back();
    flag = true;
    for(int i = 0; i < a.size(); ++i) {
        stk.back()[i] += b[i];
        if(stk.back()[i] < -30000 || stk.back()[i] > 30000) {
            flag = false;
            break;
        }
    }
    trc.push_back("ADD");
    if(flag) solve();
    trc.pop_back();
    stk.pop_back();
    stk.push_back(a);
    stk.push_back(b);
    // MUL
    b = stk.back(); stk.pop_back();
    a = stk.back();
    flag = true;
    for(int i = 0; i < a.size(); ++i) {
        stk.back()[i] *= b[i];
        if(stk.back()[i] < -30000 || stk.back()[i] > 30000) {
            flag = false;
            break;
        }
    }
    trc.push_back("MUL");
    if(flag) solve();
    trc.pop_back();
    stk.pop_back();
    stk.push_back(a);
    stk.push_back(b);
    // DIV
    b = stk.back(); stk.pop_back();
    a = stk.back();
    flag = true;
    for(int i = 0; i < a.size(); ++i) {
        if(b[i] == 0) {flag = false; break;}
        stk.back()[i] /= b[i];
        if(stk.back()[i] < -30000 || stk.back()[i] > 30000) {
            flag = false;
            break;
        }
    }
    trc.push_back("DIV");
    if(flag) solve();
    trc.pop_back();
    stk.pop_back();
    stk.push_back(a);
    stk.push_back(b);
}

int main() {
    int T = 1;
    while(cin >> N && N) {
        cout << "Program " << T++ << endl;
        stk.clear();
        trc.clear();
        in.resize(N);
        for(int i = 0; i < N; ++i) {
            cin >> in[i];
        }
        out.resize(N);
        for(int i = 0; i < N; ++i) {
            cin >> out[i];
        }
        stk.push_back(in);
        ans.assign(10, "ZZZ");
        solve();
        if(ans.size() == 10 && ans[0] == "ZZZ") {
            puts("Impossible");
        }
        else {
            if(ans.size() == 0) puts("Empty sequence");
            else {
                for(int i = 0; i < ans.size(); ++i) {
                    if(i) putchar(' ');
                    cout << ans[i];
                }
                puts("");
            }
        }
        puts("");
    }
}
