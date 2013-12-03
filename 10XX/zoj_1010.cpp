// �Թ����ڹ���~������
// ע�⾫�����⣡���� 

#include <iostream>
#include <cmath> 
using namespace std;

// �����ݲ� 
const double EPS = 1e-5; 

// �����ݲ�ĸ�������� 
inline bool equals( double x, double y ) {
	return	fabs( x - y ) < EPS;
}

// ��ṹ 
struct Point {
	Point() {}
	Point( double x, double y ) : posX( x ), posY( y ) {}
	void getPoint() { cin >> posX >> posY; }
	double	posX,	posY;
};

// �ж������Ƿ��غ� 
bool cover( Point pointA, Point pointB ) {
	return	fabs( pointA.posX - pointB.posX ) +
		fabs( pointA.posY - pointB.posY ) < EPS; 
}

// �߶��� 
class LineSegment {
    public:
	LineSegment() {}
	// ���캯��������һ�� 
	LineSegment( Point pA, Point pB ) : pointA( pA ), pointB( pB ) {}
	// �б�����ߵ���һ�࣬����ֵΪ��� 
	double pointOnItsSide( Point );
	// �б���Ƿ������� 
	bool pointOnLine( Point );
	// �б������Ƿ��ཻ 
	friend	bool cross( LineSegment, LineSegment );
    private:
	Point	pointA,	pointB;
};

double LineSegment :: pointOnItsSide( Point point ) {
	return	( point.posX - pointA.posX ) * ( pointB.posY - pointA.posY ) -
		( point.posY - pointA.posY ) * ( pointB.posX - pointA.posX );
} 

bool LineSegment :: pointOnLine( Point point ) {
	// ���˵��غϣ��ض��ཻ 
	if( cover( point, pointA ) || cover( point, pointB ) ) return	true;
	// �������߶����궥�㷽���⣬�ض����ཻ 
	if( point.posX > pointA.posX && point.posX > pointB.posX ||
	    point.posX < pointA.posX && point.posX < pointB.posX ||
	    point.posY > pointA.posY && point.posY > pointB.posY ||
	    point.posY < pointA.posY && point.posY < pointB.posY ) return false;
	// ���򣬵�ض������ӳ��߻�˵��ϣ�ֻҪ����ֱ�߲�����㼴��������
	return	equals( pointOnItsSide( point ), 0.0 );
}

bool cross( LineSegment lineA, LineSegment lineB ) {
	// ��һ��ֱ�߶˵�����һֱ���ϣ���Ȼ�ཻ 
	if( lineA.pointOnLine( lineB.pointA ) || lineA.pointOnLine( lineB.pointB ) ||
	    lineB.pointOnLine( lineA.pointA ) || lineB.pointOnLine( lineA.pointB ) ) return true;
	double	prod11 = lineA.pointOnItsSide( lineB.pointA ),
		prod12 = lineA.pointOnItsSide( lineB.pointB ),
		prod21 = lineB.pointOnItsSide( lineA.pointA ),
		prod22 = lineB.pointOnItsSide( lineA.pointB );
	return	prod11 * prod12 < -EPS && prod21 * prod22 < -EPS;
}

// �������
class Polygon {
    public:
	Polygon() {}
	int getPolygon();
	bool isValid();
	double area(); 
    private:
	int	size; 
	Point	vertex[1000];
	LineSegment	edge[1000]; 
};

int Polygon :: getPolygon() {
	cin >> size;
	for( int i = 0; i < size; i++ )
		vertex[i].getPoint();
	for( int i = 1; i < size; i++ )
		edge[i] = LineSegment( vertex[i - 1], vertex[i] );
	edge[0] = LineSegment( vertex[size - 1], vertex[0] );
	return	size;
}

bool Polygon :: isValid() {
	if( size < 3 )
		return false;
	if( size == 3 )
		return !fabs( LineSegment( vertex[0], vertex[1] ).pointOnItsSide( vertex[2] ) ) < EPS;
	for( int j = 2; j < size - 1; j++ )
		if( cross( edge[0], edge[j] ) ) return false;
	for( int i = 1; i < size - 2; i++ )
		for( int j = i + 2; j < size; j++ )
			if( cross( edge[i], edge[j] ) )
				return false;
	return	true;
} 

double Polygon :: area() {
	double	ans = 0.0;
	if( size < 3 )	return ans;
	for( int i = 2; i < size; i++ )
		ans += edge[i].pointOnItsSide( vertex[0] );
	return	fabs( ans / 2.0 );
}

int main() {
	Polygon	Pattern;
	int	T = 1;
	cout.setf( ios :: fixed );
	cout.precision( 2 );
	while( Pattern.getPolygon() ) {
		if( T != 1 ) cout << endl;
		cout << "Figure " << T++ << ": ";
		if( !Pattern.isValid() )
			cout << "Impossible" << endl;
		else	cout << Pattern.area() << endl;
	}
}


/* TEST CASES

5
0.01 0.01
0.01 1.01
0.51 0.51
1.01 1.01
1.01 0.01
4
0.01 0.01
0.01 1.01
1.01 0.01
1.01 1.01
4
0.01 0.01
1.01 0.01
2.01 1.01
2.01 0.01
5
0.01 0.01
2.01 0.01
2.01 1.01
1.01 0.01
0.01 1.01
4
0.01 0.01
1.01 -1.01
2.01 1.01
2.01 0.01
6
0.01 1.01
1.01 0.01
4.01 2.01
3.01 3.01
4.01 3.01
2.01 4.01
6
0.01 0.01
1.01 1.01
2.01 0.01
2.01 2.01
3.01 3.01
0.01 3.01
3
0.01 0.01
1.01 1.01
1.01 0.01

Figure 1: 0.75

Figure 2: Impossible

Figure 3: Impossible

Figure 4: Impossible

Figure 5: Impossible

Figure 6: 8.00

Figure 7: 5.50

Figure 8: 0.50

*/
