// 2886615 2008-05-03 14:46:43 Accepted 1629 C++ 00:00.01 840K ���͵����� 

// DP�����·�����һ���ߣ�DP[n] = DP[n-1] + ...
// ... �����˱߳�Ϊ k = 1..n �������Σ���Щ�����ζ�Ҫ��һ�������¼���ȥ�ı���
// �������ŵģ��� n - k + 1 ��
// Ȼ���㵹�ŵģ��� n - k - k + 1 (���ҽ��� > 0)��������Ϊ 0 �� 

#include <iostream>
using namespace std;

int main() {

    int DP[501] = { 0 },    N;
    
    for( int i = 1; i < 501; ++i ) {
        
        DP[i] = DP[i - 1];
        
        for( int j = 1; j <= i; ++j ) {
            
            DP[i] += ( i - j + 1 );
            
            if( i - j - j + 1 > 0 )
                DP[i] += ( i - j - j + 1 );
            
        }
        
    }
    
    while( cin >> N )
        cout << DP[N] << endl;

}
