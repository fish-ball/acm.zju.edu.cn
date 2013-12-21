// 1833475 2009-04-14 17:25:19 Accepted  2021 C++ 480 184 ���͵����� 

// ��������������1423 �ļ�ǿ�� 

// ���ʽ���������������������߼�Ӧ���������¼��������
// 1����ͷ�����ţ�
// 2��ǰ���� '(' �� '+' �� '('�����ƥ��� ')' ������ '+' �����������
//    ������� ')' ������ '*' �� '/' ����һ����Χ�ڲ����� '+' �� '-' ��������
// 3��'-' �� '*' ����� '(' �����һ����Χû�г��� '+' �� '-' ��������
// 4��'/' ����� '(' �����һ����Χû�г��� '+', '-', '*' �� '/' ��������

#include <iostream>
#include <string>
using namespace std;

int main() {
    int N;
    string s;
    cin >> N;
    while(N--) {
        cin >> s; 
        s = "+" + s + "+";
        // �޳� +( ������� 
        while(true) {
            int pos = 1;
            while(pos < s.size()) {
                if((s[pos-1] == '+' || s[pos-1] == '(') && s[pos] == '(') {
                    int pos2 = pos + 1;
                    int cnt = 1, add = 0, sub = 0;
                    while(cnt) {
                        if(s[pos2] == '(') cnt += 1;
                        if(s[pos2] == ')') cnt -= 1;
                        if(cnt == 1 && s[pos2] == '+') add += 1;
                        if(cnt == 1 && s[pos2] == '-') sub += 1;
                        if(cnt == 0) break;
                        pos2 += 1;
                    }
                    if( add + sub == 0 || s[pos2+1] != '*' && s[pos2+1] != '/') {
                        s.erase(pos2, 1);
                        s.erase(pos, 1);
                        break;
                    }
                }
                pos++;
            }
            if(pos == s.size()) break;
        }
        // �޳� -( �� *( ������� 
        while(true) {
            int pos = 1;
            while(pos < s.size()) {
                if((s[pos-1] == '-' || s[pos-1] == '*') && s[pos] == '(') {
                    int pos2 = pos + 1;
                    int cnt = 1, add = 0, sub = 0, mul = 0, div = 0;
                    while(cnt) {
                        if(s[pos2] == '(') cnt += 1;
                        if(s[pos2] == ')') cnt -= 1;
                        if(cnt == 1 && s[pos2] == '+') add += 1;
                        if(cnt == 1 && s[pos2] == '-') sub += 1;
                        if(cnt == 1 && s[pos2] == '*') mul += 1;
                        if(cnt == 1 && s[pos2] == '/') div += 1;
                        if(cnt == 0) break;
                        pos2 += 1;
                    }
                    if(add + sub == 0) {
                        s.erase(pos2, 1);
                        s.erase(pos, 1);
                        break;
                    }
                }
                pos++;
            }
            if(pos == s.size()) break;
        }
        // �޳� /( �������
        while(true) {
            int pos = 1;
            while(pos < s.size()) {
                if(s[pos-1] == '/' && s[pos] == '(') {
                    int pos2 = pos + 1;
                    int cnt = 1, add = 0, sub = 0, mul = 0, div = 0;
                    while(cnt) {
                        if(s[pos2] == '(') cnt += 1;
                        if(s[pos2] == ')') cnt -= 1;
                        if(cnt == 1 && s[pos2] == '+') add += 1;
                        if(cnt == 1 && s[pos2] == '-') sub += 1;
                        if(cnt == 1 && s[pos2] == '*') mul += 1;
                        if(cnt == 1 && s[pos2] == '/') div += 1;
                        if(cnt == 0) break;
                        pos2 += 1;
                    }
                    if(add + sub + mul + div == 0) {
                        s.erase(pos2, 1);
                        s.erase(pos, 1);
                        break;
                    }
                }
                pos++;
            }
            if(pos == s.size()) break;
        }
        cout << s.substr(1, s.size() - 2) << endl;
    }
}
