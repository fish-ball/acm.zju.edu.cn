// 2882906 2008-05-01 19:44:52 Accepted 2811 C++ 00:00.12 836K ���͵����� 
// ��һ���(����ֻȡ����)�ܲ�����ɶ����
// �� DP��һ�������������γɵȼ�Ϊ���������� [low, high] �ı�
// �ӽ�ȥ�µıߣ�������ֻ�����󣬲�����С��ֱ�� low <= 0 ���ɡ� 

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    
    double  low,    high;
    double  val[20];
    int     N;
    
    while( ( cin >> N ) && N ) {
        
        for( int i = 0; i < N; ++i )
            cin >> val[i];
            
        sort( val, val + N );
        
        bool flag = false;
        low = high = *val;
        for( int i = 1; i < N; ++i ) {
            if( low - 1e-5 < val[i] &&
                val[i] < high + 1e-5 ) {
                flag = true;
                break;
            }
            low = min( low, val[i] - high );
            high = val[i] + high;
        }
        
        puts( flag ? "YES" : "NO" );
        
    }
    
}
