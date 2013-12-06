// �������Σ��ö��ȷֵ����ȽϷ���
// ������������Ǵ��ض��� 
// 2809532 2008-03-29 16:40:07 Accepted 1199 C++ 00:00.00 836K ���͵����� 

#include <iostream>
#include <cmath>
using namespace std;

const double EPS = 1e-5;

int main() {
    int     T,  x1, y1, r1, x2, y2, r2;;
    double  x3, y3;
    cin >> T;
    cout.setf( ios :: fixed );
    cout.precision( 2 );
    while( T-- ) {
        cin >> x1 >> y1 >> r1;
        cin >> x2 >> y2 >> r2;
        if( r1 == r2 ||
            ( x1 - x2 ) * ( x1 - x2 ) +
            ( y1 - y2 ) * ( y1 - y2 ) <=
            abs( ( r1 - r2 ) * ( r1 - r2 ) ) ) {
            cout << "Impossible.\n";
            continue;
        }
        // ע�������þ���֮��cout << 1.555; �Ľ���� 1.55������Ҫ��( Ӧ�����뵽 1.56 )
        // ��˳�һ�� 100 round ֮���ٳ� 100��Ȼ�����ʱ�򾫶���Σ�գ��ټ�һ�� EPS ���
        // ��Ϊͬ�������ɣ�cout << 1.99999999; �Ľ���� 1.99����ʹ�� WA �˺ܶ�� 
        x3 = round( double( r2 * x1 - r1 * x2 ) / double( r2 - r1 ) * 100.0 ) / 100.0 + EPS;
        y3 = round( double( r2 * y1 - r1 * y2 ) / double( r2 - r1 ) * 100.0 ) / 100.0 + EPS;
        cout << x3 << ' ' << y3 << endl;
    }
}
