// 2147408 2010-04-08 15:37:46 Accepted  1102 C++ 1000 712 ���͵����� 

// һ����ȫ�����ִ������ڵ��ǵȳ�L(L<=1000)�ִ�����ȨΪ�ַ�����Ӧλ�ò�ͬ���ַ�����
// ֻ������������Ҷ�ӣ�����һ����ʹ�ñ�Ȩ����С�������������С��Ȩ�͡� 
// �鲢�������������ӽṹ��̰�ķ��������Կ��������������ַ������ԣ�Ҳ����
// ���Զ��ַ���ÿ��λ�õ��ַ�������һ�β�����
// �������£����ַ�����ÿ���ַ�λ����һ�Σ���һ�����У����һ�����ڵ㣬
// �ڵ㱣���������ڵ�ȡĳ���ַ�����ô����ڵ�Ϊ����������Ȩ�͵���Сֵ��
// ά����������ӽṹ��ÿ�δӶ�����ȡ�������ڵ㣬�鲢��Żض��У�ֱ������ֻ��һ���ڵ㡣
// �鲢�������£����Ҫ�鲢�������ڵ�(�ֵ�)ȡ������ĸʱ����Сֵ��Ȼ��ö�ٿ���ʹ�õ�
// 20����ĸ��������ֱ�������ڵ㣬����ĸλ��ȡֵǡ�õ�����Сֵ����ô�������ĸ��
// �µ�ֵȡ�����Сֵ������ȡ������ĸ��Сֵ��1��Ϊ�µ���Сֵ��
// ���Ӷ�Ϊ O(L*N*20)

#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

const string charset = "ARNDCQEGHILKMFPSTWYV";

pair<char, int> parse(string s) {
    queue<vector<int> > Q;
    for(int i = 0; i < s.size(); ++i) {
        vector<int> V(20);
        for(int j = 0; j < 20; ++j) {
            V[j] = charset[j] != s[i];
        }
        Q.push(V);
    }
    while(Q.size() > 1) {
        vector<int> A = Q.front(); Q.pop();
        vector<int> B = Q.front(); Q.pop();
        int mina = INT_MAX, minb = INT_MAX;
        for(int i = 0; i < 20; ++i) {
            mina = min(A[i], mina);
            minb = min(B[i], minb);
        }
        for(int i = 0; i < 20; ++i) {
            if(A[i] != mina) A[i] = mina + 1;
            A[i] += B[i] == minb ? minb : minb + 1;
        }
        Q.push(A);
    }
    vector<int> V = Q.front(); Q.pop();
    int minv = INT_MAX, minp = -1;
    for(int i = 0; i < 20; ++i) {
        if(minv > V[i]) {
            minv = V[i];
            minp = i;
        }
    }
    return make_pair(charset[minp], minv);
}

int main() {
    int N, L;
    while(cin >> N >> L && N) {
        vector<string> S(N);
        for(int i = 0; i < N; ++i) {
            cin >> S[i];
        }
        string ans = "";
        int val = 0;
        for(int i = 0; i < L; ++i) {
            string tmp = "";
            for(int j = 0; j < N; ++j) {
                tmp += S[j][i];
            }
            pair<char, int> ret = parse(tmp);
            ans += ret.first;
            val += ret.second;
        }
        cout << ans << " " << val << endl;
    }
}
