// 1896202 2009-06-13 11:46:29 Accepted  2339 C++ 600 6336 ���͵����� 

// �� huffman �������̱�����ı����ȡ�
// ˼·��ģ�� huffman ���Ĺ��죬���ǲ�����Ҫ��ȫ���졣
// ��һ�����ȶ��У��Ž�ȥ���ַ�Ƶ����
// ÿ��ȡ����С���������ܽ���ۼ����ǵĳ���֮�͡�
// Ȼ������֮�ͷ������ȶ��У�ֱ��������ֻʣһ����
// �ܸ��Ӷ� O(NlogN)�� 

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

typedef long long i64;

int main() {
    int T, N;
    for(cin >> T; T--;) {
        cin >> N;
        priority_queue<i64> Q;
        for(int i = 0, p; i < N; ++i) {
            scanf("%d", &p);
            Q.push(-p);
        }
        i64 ans = 0;
        while(Q.size() > 1) {
            i64 p1 = Q.top(); Q.pop();
            i64 p2 = Q.top(); Q.pop();
            ans -= p1 + p2;
            Q.push(p1 + p2);
        }
        cout << ans << endl;
        Q.pop();
        if(T) puts("");
    }
}
