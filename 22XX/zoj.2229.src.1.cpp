// 2865982 2008-04-24 14:07:00 Accepted 2229 C++ 00:00.00 396K ���͵�����  
// ̰�ģ�O(n) 
// 1. ��ʼʱ�� < 0 �ģ����迼�ǣ�̫��ĸϲ��ϣ�̫���ĸ���Ҳû��
// 2. ��ʼʱ�� > 0 �ģ�Charley �����絽��ĳ���һ�𵽴� 

#include <cstdio>
#include <cmath>

int main() {
    int T,  x,  y;
    double  min, temp;
    while( scanf( "%d", &T ) && T ) {
        min = 1e99;
        for( int i = 0; i < T; i++ ) {
            scanf( "%d%d", &x, &y );
            if( y >= 0 ) {
                temp = 4500.0 * 3.6 / x + y;
                if( temp < min )
                    min = temp;
            }
        }
        printf( "%.0lf\n", ceil( min ) );
    }
}
