// ��׳˵�λ�����Խ׳�ȡ log10�����Ա�� log10 �ĺͣ�Ȼ����Զ��׼��ˡ�

// double ������ʱ���õú�ˬ
// �������ú��� *_*
// 2812284 2008-03-30 20:44:03 Accepted 1526 C++ 00:05.14 848K ���͵�����  

#include <iostream>
#include <cmath>
using namespace std;

struct Factorial {
    Factorial() {}
    Factorial( double xx, double d ) :
        x(xx), digit(d) {}
    double  x;
    double  digit;
    void increase( const int& n );
};

void Factorial :: increase( const int& n ) {
    x *= double( n );
    double  d = floor( log10( x ) );
    x /= pow( 10.0, d );
    digit += d;
}

int main() {
    int     T,  N;
    Factorial   num;
    cin >> T;
    cout.setf( ios :: fixed );
    cout.precision( 0 );
    while( T-- ) {
        cin >> N;
        num = Factorial( 1.0, 1.0 );
        for( int i = 1; i <= N; i++ )
            num.increase( i );
        cout << round( num.digit ) << endl;
    }
}
