// 2907763 2008-05-11 21:58:13 Accepted 1597 C++ 00:00.00 848K ���͵����� 

// ���ѵļ����⣬ϸ�ģ�����
// ���������ۣ�1-���뼰���У�2-���룬3-�ཻ
// �ཻʱ�����ε������ȥ�����ε�����û��ε���������
// Բ�Ľ������Ҷ�����ע��۽ǵ�ʱ��ͨ�� 

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
    
    const double PI = 2.0 * asin( 1.0 );
    double  x1, y1, r1, x2, y2, r2;
    
    cout.setf( ios::fixed );
    cout.precision( 3 );
    
    while( cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2 ) {
        
        double  d = hypot( x1 - x2, y1 - y2 );

        if( d - r1 - r2 > -1e-5 ) {
            cout << 0.0 << endl;
            continue;
        }
        
        if( r1 < r2 )   swap( r1, r2 );
        
        if( d - r1 + r2 < 1e-5 ) {
            cout << PI * r2 * r2 << endl;
            continue;
        }
        
        else {
            double  area = 0.0;
            double  theta = acos( ( r2*r2 + d*d - r1*r1 )
                                / d / r2 / 2.0 );
            area += theta * r2 * r2;
            area -= r2 * r2 * cos( theta ) * sin( theta );
            double  alpha = acos( ( r1*r1 + d*d - r2*r2 )
                                / d / r1 / 2.0 );
            area += alpha * r1 * r1;
            area -= r1 * r1 * cos( alpha ) * sin( alpha );
            cout << area << endl;
            continue;
        }

    }
    
}
