// 1773659 2009-03-01 15:23:07 Accepted  3168 C++ 50 184 ���͵����� 

// �� ZOJ7 ���ĸ��ַ����������������ı�����Ȼ��ƴ�Ӽ��ɣ�ˮ�⡣

#include <string>
#include <iostream>
using namespace std;

int main() {
    string s;
    int cnt[4];
    while(cin >> s) {
        string ans("");
        memset(cnt, 0, sizeof(cnt));
        for(int i = 0; i < s.size(); ++i) {
            if(s[i] == 'Z') cnt[0] += 1;
            else if(s[i] == 'O') cnt[1] += 1;
            else if(s[i] == 'J') cnt[2] += 1;
            else if(s[i] == '7') cnt[3] += 1;
            else ans += s[i];
        }
        ans = string(cnt[0], 'Z') +
              string(cnt[1], 'O') +
              string(cnt[2], 'J') +
              string(cnt[3], '7') +
              ans;
        puts(ans.c_str());
    }
}
