// 1930558 2009-07-18 14:35:42 Accepted  1477 C++ 200 184 ���͵����� 

// �ַ����ӽ��ܣ���Ҫ���ڽ����߼���
// ���ܵĻ������������ע����������ֻ�����ַ����������ȶ����� 
// ���ܵĻ�̰�Ĵ���
// ������ʽ��֪����ͷ����ĸ�϶����ַ��������õ��ġ�
// ��˶Լ��ܴ������������������ǰ���������ֱ��Ǽ������һ���õ��ľ������к�β�С�
// �ƴ˶�����Ϊ s1 �� s2�� 
// ���ѷ����õ���s2[i] �����ĵĺ�̾��� s1[i]��
// ��������������ĵĵ�һ���ַ��� c����ô����������ȶ��ԣ�
// �����ҳ����һ�����ַ����ڵ�λ�þ��� pos = s1.find_first_of(c)��
// ������ǰ������ȷ���ģ����� s2[i]��������֪����ʱ�� s2[i] �����һ���ַ���
// ��ô��Ҫ�ҵ� s2[i] ʵ�������ַ�����λ�þ�Ӧ���� pos' = s1.find_last_of(s2[pos])�� 
// ��Ϊ����ַ������ģ���������֮��϶�ҲҪ����ͬ����ͷ���ַ����е����
// Ȼ�� pos' ���� pos���ظ����в����� 
// ��ÿ�δ� s1 �в��ҵ�һ�� pos ֮�󣬱���ִ�� s1[pos] = ' '������������
// ����һ�����ڶ�������ȥ�ģ����� "�����ڶ���"��������ơ� 

/*
encode YSFHCISYFSBX
decode SHSYFCYIFBXSY

encode TDBBNICNISUMUXNTURBWNMBYUTBCNOFINMIFBYTDTNDYUCTNDFLMSS
decode DBRMTFIBUTTNNOIDNNFMFUNNLBCXWCITTNUIMSSNUYDCSMTYYBUBBDT
*/

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool cmp(const string& a, const string& b) {
    return a[0] < b[0];
}

string encode(string str) {
    int N = str.size();
    vector<string> MAT(N);
    for(int i = 0; i < N; ++i) {
        MAT[i] = str;
        str = str.substr(1) + str[0];
    }
    stable_sort(MAT.begin(), MAT.end(), cmp);
    string ans("");
    for(int i = 0; i < N; ++i)
        ans += MAT[i][N-1];
    return ans;
}


string decode(string str) {
    int N = str.size() - 1;
    char c = str[N];
    str.erase(N);
    string seq = str;
    sort(seq.begin(), seq.end());
    int pos = seq.find_first_of(c);
    string ans("");
    for(int i = 0; i < N; ++i) {
        ans = str[pos] + ans;
        seq[pos] = ' ';
        pos = seq.find_last_of(str[pos]);
    }
    return ans;
}

int main() {
    
    string op, str;
    
    while(cin >> op >> str) {
        if(op == "encode")
            puts(encode(str).c_str());
        else
            puts(decode(str).c_str());
    }
    
}
