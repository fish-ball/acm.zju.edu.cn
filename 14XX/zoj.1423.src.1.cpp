// 1831826 2009-04-13 01:03:06 Accepted  1423 C++ 0 184 ���͵����� 

// ���ʽ���������������������߼�Ӧ�������������������
// 1����ͷ�����ţ����� (A+B)+C �� 
// 2��ǰ���� '(' ���� '+' �����ţ����� ((A+B)-C) ��(A+(B-C)) �� 
// 3�������ŵ�һ����Χ��û�г��ַ��ŵ����ţ����� ((A+B))�� 

#include <iostream>
#include <string>
using namespace std;

int main() {
    int N;
    string s;
    cin >> N;
    getline(cin, s);
    while(N--) {
        getline(cin, s);
        s = "+" + s;
        for(int i = 0; i < s.size(); ++i)
            if(s[i] == ' ' || s[i] == '\t')
                s.erase(i--, 1);
        while(true) {
            int pos = 1;
            while(pos < s.size()) {
                if((s[pos-1] == '+' || s[pos-1] == '(') && s[pos] == '(')
                    break;
                pos++;
            }
            if(pos == s.size()) break;
            int pos2 = pos + 1;
            int cnt = 1;
            while(cnt) {
                if(s[pos2] == '(') cnt += 1;
                if(s[pos2] == ')') cnt -= 1;
                if(cnt == 0) break;
                pos2 += 1;
            }
            s.erase(pos2, 1);
            s.erase(pos, 1);
        }
        while(true) {
            int pos = 1;
            while(pos < s.size()) {
                if(s[pos] == '(') {
                    int pos2 = pos + 1;
                    int cnt = 1, sign = 0;
                    while(cnt) {
                        if(s[pos2] == '(') cnt += 1;
                        if(s[pos2] == ')') cnt -= 1;
                        if(cnt == 1 && (s[pos2] == '+' || s[pos2] == '-')) sign += 1;
                        if(cnt == 0) break;
                        pos2 += 1;
                    }
                    if(sign == 0) {
                        s.erase(pos2, 1);
                        s.erase(pos, 1);
                        break;
                    }
                }
                pos++;
            }
            if(pos == s.size()) break;
        }
        cout << s.substr(1) << endl;
    }
}
