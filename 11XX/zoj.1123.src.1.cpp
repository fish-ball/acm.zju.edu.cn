// 2867871 2008-04-25 08:37:53 Accepted 1123 C++ 00:00.00 856K ���͵����� 

// ��Ȼ�е� BT������Ϊ�㷨��������
// ��Ϊ����ֻ�� -9~9��������е������Ӧ��ֻ������ 17^2 = 289 ��
// ���Ǽ�ʹ�������е�Ч��Ҳ����͡�
// ����� (minX, maxX)��(minY, maxY)��ö�������������������ڵ�������
// Ȼ�����ÿ���㣬����Ƿ�����������(�����бߵ�ͬ��)
// ������ڣ����Ǹ����ַ�����Ϣ�������ַ���Ϊ�հ�ռλ��(����)
// ��󣬰��н�����Ĵ����ӳ��ַ������õ�β���ո�
// ���ַ�����Ϊ�գ��������ַ�����������һ������ 
// ע�⿪ͷ��β�Ǿ仰��Ҫԭ������ģ���� WA �˼��Σ���Ŀû˵��� 

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct Point {
    int X,  Y;
    string  S;
    Point( int x = 0, int y = 0 ) :
        X( x ), Y( y ) {}
};

int x[3], y[3];

bool Inside( const Point& p ) {
    int val1 = ( p.X  - x[0] ) * ( y[1] - y[0] ) - 
               ( x[1] - x[0] ) * ( p.Y  - y[0] );
    int val2 = ( p.X  - x[1] ) * ( y[2] - y[1] ) - 
               ( x[2] - x[1] ) * ( p.Y  - y[1] );
    int val3 = ( p.X  - x[2] ) * ( y[0] - y[2] ) - 
               ( x[0] - x[2] ) * ( p.Y  - y[2] );
    if( !val1 || !val2 || !val3 )
        return  false;
    return  ( val1 > 0 ) == ( val2 > 0 ) == ( val3 > 0 ); 
}

string  toString( const Point& p ) {
    string  ans( "(" );
    if( p.X < 0 ) {
        ans += "-";
        ans += ( '0' - p.X );
    }
    else {
        ans += " ";
        ans += ( '0' + p.X );
    }
    
    ans += ", ";
    
    if( p.Y < 0 ) {
        ans += "-";
        ans += ( '0' - p.Y );
    }
    else {
        ans += " ";
        ans += ( '0' + p.Y );
    }
    
    ans += ") ";
    
    return ans;
    
}

int main() {
    
    vector<Point>   V;

    puts( "Program 4 by team X" );

    while( cin >> x[0] >> y[0]
               >> x[1] >> y[1]
               >> x[2] >> y[2] ) {

        int minX = min( min( x[0], x[1] ), x[2] );
        int maxX = max( max( x[0], x[1] ), x[2] );
        int minY = min( min( y[0], y[1] ), y[2] );
        int maxY = max( max( y[0], y[1] ), y[2] );
        
        V.clear();
        for( int i = maxY - 1; i > minY; i-- )
            for( int j = minX + 1; j < maxX; j++ )
                V.push_back( Point( j, i ) );

        for( int i = 0; i < V.size(); i++ ) {
            if( Inside( V[i] ) )
                V[i].S = toString( V[i] );
            else
                V[i].S = "         ";
        }

        int pos = 0;
        for( int i = maxY - 1; i > minY; i-- ) {
            string str( "" );
            for( int j = minX + 1; j < maxX; j++ )
                str += V[pos++].S;
            int pos = 0;
            for( int j = 0; j < str.length(); j++ )
                if( str[j] != ' ' )
                    pos = j;
            if( pos != 0 ) {
                str.erase( pos + 1 );
                cout << str << "\n";
            }
        }
        putchar( '\n' );

    }
    
    puts( "End of program 4 by team X" );

}
