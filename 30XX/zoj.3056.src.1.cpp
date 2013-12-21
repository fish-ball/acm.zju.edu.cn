// 1694274 2008-11-09 17:22:34 Accepted  3056 C++ 70 976 ���͵����� 

// ���ľ��Ǹ�һ���ֵ䣬��һ�� key Ҫ�ҳ��ֵ��е���ȷ���ʣ�
// ͷβ��ȷ���������ң�ֱ�� map ���У���Ȼ����� Trie��
// ͷβ���䣬�м�������Ϊ key����ȷ�ַ�����Ϊ value�� 
// ע��һ�㣬ͷβ�ַ�һ������ȷ�ġ� 

#include <string>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;

map<string, string> M;

int main() {
    string s, w;
    while(cin >> s && s != "DICTIONARY_DEFINE_OVER") {
        w = s;
        if(w.size() > 2)
        sort(w.begin()+1, w.end()-1);
        M[w] = s;
    }
    getline(cin, s);
    w.erase();
    char c;
    while((c = getchar()) != EOF) {
        if(isalpha(c)) w += c;
        else {
            if(w.size() != 0) {
                if(w.size() > 2)
                    sort(w.begin()+1, w.end()-1);
                cout << M[w];
                w.erase();
            }
            putchar(c);
        }
    }
    cout << w;
}
