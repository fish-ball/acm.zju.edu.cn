// ��ԭʽ��΢չ���������������ֿ����� N ��
// Ȼ���� N-1 ��....
// ������ǲ���ĳ���... 
// ���̰���ô�����Ƚ�ϣ�Ԥ���򼴿ɡ� 

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int main() {
    
    vector<double>  V;
    
    int     N;
    
    cout.setf( ios::fixed );
    cout.precision( 3 );
    
    while( cin >> N ) {
        
        V.resize( N );
        
        for( int i = 0; i < N; ++i )
            cin >> V[i];
            
        sort( V.begin(), V.end(), greater<double>() );
        
        double  ans = V[0];
        
        for( int i = 1; i < N; ++i )
            ans = 2.0 * sqrt( V[i] * ans );
            
        cout << ans << endl;
        
    }
    
}
