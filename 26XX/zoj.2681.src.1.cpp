// �򵥣���Լ�֣�Ȼ����ֱ������������н���
// ���ݽ������ڵ��߶�����������֣�Ȼ���������
// 2822577 2008-04-04 14:10:32 Accepted 2681 C++ 00:01.28 856K ���͵����� 

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Intersect {
    double  x,  y;
    char    type;
public:
    Intersect() {}
    Intersect( double x, double y, char type ) :
        x(x), y(y), type(type) {}
    friend bool operator < ( const Intersect& i1, const Intersect& i2 )
        { return    i1.x < i2.x; }
    void disp() { cout << type << ' '; }
};

int main() {
    int     T,  x,  y;
    cin >> T;
    vector<Intersect>   V;
    while( T-- ) {
        cin >> x >> y;
        int m = ( x > y ) ? x : y;
        int n = ( x > y ) ? y : x;
        while( n ) {
            int r = m % n;
            m = n;
            n = r;
        }
        x /= m;
        y /= m;
        V.resize( 0 );
        for( int i = 1; i < x; i++ )
            V.push_back( Intersect( double( i * y ) / double( x ), double( i ),
                    ( i & 1 ) ? 'N' : 'S' ) );
        for( int j = 1; j < y; j++ )
            V.push_back( Intersect( double( j ), double( j * x ) / double( y ),
                    ( j & 1 ) ? 'E' : 'W' ) );
        sort( V.begin(), V.end() );
        cout << V.size() << endl;
        for( int i = 0; i < V.size(); i++ )
            V[i].disp();
        // �� x ż y ż������ 1 �Ŵ� 
        if( !( x & 1 ) && !( y & 1 ) )
            cout << 1 << endl;
        // �� x ż y �棬���� 2 �Ŵ� 
        if( !( x & 1 ) &&  ( y & 1 ) )
            cout << 2 << endl;
        // �� x �� y �棬���� 3 �Ŵ�
        if(  ( x & 1 ) &&  ( y & 1 ) )
            cout << 3 << endl;
        // �� x �� y ż������ 4 �Ŵ�
        if(  ( x & 1 ) && !( y & 1 ) )
            cout << 4 << endl;
    }
}
