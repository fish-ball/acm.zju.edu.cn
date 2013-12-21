// 1795834 2009-03-21 01:28:45 Accepted  2642 C++ 510 4076 ���͵����� 

// ��ջ̰�ķ�����һ������ A[N]���������� i, j ֮�䣬
// ���� f(i, j) = SUM(A[i..j]) * MIN(A[i..j])��
// �� MAX(f(i, j)), 0 <= i <= j < N��
// ���ȣ����������Ԥ�������ǿ��� O(1) �õ��������͡�
// Ȼ���ö�ջ̰�ķ���
// ����� i ��Ԫ����ߵ�һ������С���±� L[i]��
// ���ұߵ�һ����������±� R[i]��
// Ԥ���� O(N)�����ڿ��������Сֵ�� A[i] ʱ��������伴Ϊ L[i]+1..R[i]-1
// Ȼ��ö�� i�������� A[i] * SUM(A[L[i]+1..R[i]-1])��O(N) ���Դ�����ϡ� 

#include <iostream>
#include <vector>
using namespace std;

typedef long long i64;

int N;

vector<int> A, L, R;

vector<i64> S;

vector<pair<int, int> > stk;

int main() {
    
    while(cin >> N) {
        A.resize(N);
        S.assign(N + 1, 0);
        for(int i = 0; i < N; ++i) {
            scanf("%d", &A[i]);
            S[i + 1] = S[i] + A[i];
        }
        
        R.assign(N, N);
        stk.clear();
        for(int i = 0; i < N; ++i) {
            while(!stk.empty() && stk.back().first > A[i]) {
                R[stk.back().second] = i;
                stk.pop_back();
            }
            stk.push_back(make_pair(A[i], i));
        }
        L.assign(N, -1);
        stk.clear();
        for(int i = N - 1; i >= 0; --i) {
            while(!stk.empty() && stk.back().first > A[i]) {
                L[stk.back().second] = i;
                stk.pop_back();
            }
            stk.push_back(make_pair(A[i], i));
        }
        
        
        i64 ans = 0, left, right;
        for(int i = 0; i < N; ++i) {
            i64 now = S[R[i]] - S[L[i] + 1];
            now *= A[i];
            if(now > ans) {
                ans = now;
                left = L[i] + 2;
                right = R[i];
            }
        }
        cout << ans << endl << left << ' ' << right << endl;
    }
    
}
