// 2955157 2008-06-23 10:31:11 Accepted 2488 C++ 00:00.01 848K ���͵����� 

// ����֮��̰�ģ�����ǰ i - 1 �������ˣ���ôʣ������ȡ���ڵ� i ��
// ���ң�����ʣ�� ( n - i ) ������ô��ǰ�ĳ���Ϊ A[i] * ( n - i )
// ɨ��һ�����������ֵ����

// ���� O(nlogn)��̰�� O(n) 

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    
    int T,  N,  A[1000];
    
    for( cin >> T; T--; ) {
        cin >> N;
        for( int i = 0; i < N; ++i )
            cin >> A[i];
        sort( A, A + N );
        int mx = 0;
        for( int i = 0; i < N; ++i ) {
            int now = ( N - i ) * A[i];
            mx = max( mx, now );
        }
        cout << mx << endl;
    }
    
}
