// 3045844 2008-08-22 14:17:38 Accepted 1158 C++ 00:00.55 872K ���͵����� 

// ��ǽ������������ȥ�����迪����Ϊ�������߶θ��м��ǽ�߶εĽ����� 

//////////////////////////////////////////////////////
//                  ���㼸���� v1.8                 //
//////////////////// Documentation ///////////////////
//                                                  //
//                  Default                         // 
//                                                  //
// 1.3 ���Ӷ�����࣬���������������               //
// 1.4 ���Ӷ���η������жϵ��Ƿ��ڶ�����ڡ�       //
// 1.5 ���Ӷ���η�����������͹����               //
// 1.6 ���Ӷ���η��������������ġ�               //
// 1.7 ��������ֵ���ַ�����                         // 
// 1.8 �����˵���������㡢�����ߵĹ�ϵ���㡣       // 
//                                                  //
//////////////////////////////////////////////////////
//            2008 CopyRight(c) by elf              //
//////////////////////////////////////////////////////

#include <iostream>
#include <vector>
#include <limits> 
#include <cmath> 
#include <algorithm> 
using namespace std; 

class Point;    // �㡢ʸ���ࣨx ����� y ���꣩ 
class Arrow;    // �����߶��ࣨ�����յ㣩 
class Line;     // ֱ���� 
class Circle;   // Բ�� 
class Polygon;  // ����� 

// ����������������ݲPI 
const double INF = numeric_limits<double>::infinity();
const double NaN = numeric_limits<double>::quiet_NaN();
const double EPS = 1e-6;
const double PI = acos( -1.0 );

// �����ݲ��Ƚ� 
inline bool eq( double x, double y ) { return x-y < EPS && y-x < EPS; }
inline bool ne( double x, double y ) { return x-y > EPS || y-x > EPS; }
inline bool gt( double x, double y ) { return x-y > EPS; }
inline bool ge( double x, double y ) { return y-x < EPS; }
inline bool lt( double x, double y ) { return y-x > EPS; }
inline bool le( double x, double y ) { return x-y < EPS; }

// �����㡢�������������Ǹ������������� 
inline bool zr( double x ) { return x < EPS && x > -EPS; }
inline bool ps( double x ) { return x > EPS; }
inline bool ng( double x ) { return x < -EPS; }
inline bool nn( double x ) { return x > -EPS; }
inline bool np( double x ) { return x < EPS; }
inline bool nz( double x ) { return x > EPS || x < -EPS; }


// ͨ�ú���

// ����ת�Ƕȡ��Ƕ�ת���ȡ�������ֵ [-PI,PI] 
inline double rad2deg( double x ) { return x / PI * 180.0; }
inline double deg2rad( double x ) { return x * PI / 180.0; }
inline double wrap( double x ) { x = fmod( x, 2.0 * PI );
    if(x>PI) return x-2.0*PI; if(x<-PI) return x+2.0*PI; return x; } 
inline double wrap_deg( double x ) { x = fmod( x, 360.0 );
    if(x>180.0) return x-360.0; if(x<-180.0) return x+360.0; return x; } 
 
// ���Լ������С������
int gcd( int m, int n ) { while(n) { int r = m%n; m=n; n=r; } return m; }
int lcm( int m, int n ) { return  m * n / gcd( m, n ); }

// ���㺯�����ֹ�ʽ 
double integral( double a, double b, double (*f)( double ) ) {
    int     n,  i;
    double  h = b - a, temp, ret, T, C, x;
    for( T = f( a ) + f( b ), n = 1; ; ) {
        for( x = a + 0.5 * h, C = 0.0, i = 0; i < n; x += h, ++i )
            C += f( x );
        ret = ( T + 4.0 * C ) * h / 6.0;
        if( fabs( ret - temp ) < EPS )
            return  ret;
        temp = ret, T += 2.0 * C, h *= 0.5, n <<= 1;
    }
}


 
// ����ʵ�� 
struct Point {
    double  x,  y;
    Point( double x = 0, double y = 0 ) : x( x ), y( y ) {}
    inline double angle();
    inline double length() { return hypot( x, y ); } 
    inline bool origin() { return zr( x ) && zr( y ); }
    inline bool nan() { return x!=x || y!=y; }
    inline bool inf() { return fabs(x)==INF || fabs(y)==INF; } 
};

istream& operator >> ( istream& is, Point& p ) { return is >> p.x >> p.y; }
ostream& operator << ( ostream& os, Point p ) { return os << "(" << p.x << ", " << p.y << ")"; }

// �ȼۡ����ȡ��ӡ�������ˡ��ڻ���������롢������������ǡ��н�
inline bool operator==( Point a, Point b ) { return eq(a.x, b.x) && eq(a.y, b.y); }
inline bool operator!=( Point a, Point b ) { return ne(a.x, b.x) || ne(a.y, b.y); }
inline bool operator<( Point a, Point b )  { return lt(a.x,b.x) || eq(a.x,b.x) && lt(a.y,b.y); }
inline Point operator+( Point a, Point b ) { return Point( a.x+b.x, a.y+b.y ); }
inline Point operator-( Point a, Point b ) { return Point( a.x-b.x, a.y-b.y ); }
inline double operator*( Point a, Point b ) { return a.x*b.y - a.y*b.x; }
inline double operator^( Point a, Point b ) { return a.x*b.x + a.y*b.y; }
const Point operator*( Point a, double k ) { return Point( a.x*k, a.y*k ); }
const Point operator*( double k, Point a ) { return Point( a.x*k, a.y*k ); }
const Point operator+( Point a, double k ) { return Point( a.x+k, a.y+k ); }
const Point operator+( double k, Point a ) { return Point( a.x+k, a.y+k ); }
const Point operator-( Point a, double k ) { return Point( a.x-k, a.y-k ); }
const Point operator-( double k, Point a ) { return Point( k-a.x, k-a.y ); }
const Point operator-( Point a ) { return Point( -a.x, -a.y ); }
const Point operator/( Point a, double k ) { return Point( a.x/k, a.y/k ); }
inline double dist( Point a, Point b ) { return hypot(a.x-b.x, a.y-b.y ); }
inline double area( Point a, Point b, Point p3 ) { return fabs((a-b)*(a-p3))/2.0; }
inline double Point::angle()
    { if( zr(x)&&zr(y) ) return NaN;
      if( zr(x)&&ps(y) ) return PI / 2.0;
      if( zr(x)&&ng(y) ) return -PI / 2.0;
      if( ps(x)&&zr(y) ) return 0.0;
      if( ps(x) ) return atan( y / x );
      if( ng(x) ) return wrap( PI + atan( y / x ) );
    }
inline double angle( Point a, Point b ) { return Point( a^b, a*b ).angle(); }
inline bool parallel( Point a, Point b ) 
    { return a.origin() || b.origin() || eq( a.angle(), b.angle() ); }

// �����ι�ʽ�� 


// �����߶���ʵ�� a ָ�� b 
struct Arrow {
    Point   a,  b;
    Arrow() {}
    Arrow( Point a, Point b ) : a( a ), b( b ) {}
    inline double angle() { return ( b - a ).angle(); }
    inline double length() { return ( b - a ).length(); }
    inline bool on_arrow( Point p ) { return parallel( p-a, b-p ); } 
}; 

// �߶��Ƿ��ཻ(�����غϵ�)���غ�(���е��غ�)��ƽ�У��ص�(�в�ֹһ���غ�) 
inline bool cross( Arrow v, Arrow w ) {
    if( v.on_arrow( w.a ) || v.on_arrow( w.b ) ||
        w.on_arrow( v.a ) || w.on_arrow( v.b ) ) return true;
    return ( ps((v.a-w.a)*(w.b-w.a)) ^ ps((v.b-w.a)*(w.b-w.a)) )
        && ( ps((w.a-v.a)*(v.b-v.a)) ^ ps((w.b-v.a)*(v.b-v.a)) );
}
inline bool superp( Arrow v, Arrow w )
    { return v.a==w.a && v.b==w.b || v.b==w.a && v.a==w.b; }
inline bool parallel( Arrow v, Arrow w )
    { return parallel(v.a-v.b, w.a-w.b) || parallel(v.a-v.b, w.b-w.a); }
inline bool overlap( Arrow v, Arrow w ) {
    if( !parallel(v, w) || zr(v.length()) || zr(w.length()) ) return false;
    if( superp( v, w ) ) return true;
    if( v.b < v.a ) swap( v.a, v.b );
    if( w.b < w.a ) swap( w.a, w.b );
    if( w.a < v.a ) swap( v, w );
    return v.b!=w.a && parallel( v.a-v.b, w.a-v.b );
}


// ֱ���࣬������һ��ʽ������ϵ�� 
struct Line {
    double  A,  B,  C;
    // һ��ʽ 
    Line( double A = 0, double B = 0, double C = 0 ) :
        A( A ), B( B ), C( C ) {} 
    // ����ʽ 
    Line( Point a, Point b ) : A( b.y-a.y ), B( a.x-b.x ),
        C( a.x*(a.y-b.y) + a.y*(b.x-a.x) ) {}
    // ��бʽ
    Line( double k, Point p ) : A( k ), B( -1 ),
        C( p.y - k * p.x ) {}
    Line( Point p, double k ) : A( k ), B( -1 ),
        C( p.y - k * p.x ) {}
    // �߶�����ֱ�� 
    explicit Line( Arrow v ) { *this = Line( v.a, v.b ); }
    // ����б�� 
    double slope() const
        { return  zr( B ) ? zr( A ) ? NaN : INF : -A / B; }
}; 

// ֱ���غϡ��ཻ��ƽ�С�ֱ�߽��㡢�߶ν��㡢��ֱ��Χ��� 
inline bool superp( Line p, Line q )
    { return eq( p.A*q.B, p.B*q.A ) && eq( p.A*q.C, p.C*q.A ); }
inline bool cross( Line p, Line q )
    { return ne( p.A*q.B, p.B*q.A ); }
inline bool parallel( Line p, Line q ) 
    { return eq( p.A*q.B, p.B*q.A ) && ne( p.A*q.C, p.C*q.A ); }
inline Point intersect( Line p, Line q ) {
    if( superp( p, q ) )    return Point( NaN, NaN ); 
    if( parallel( p, q ) )  return Point( INF, INF );
    return Point( (p.B*q.C-q.B*p.C)/(q.B*p.A-p.B*q.A),
                  (p.A*q.C-q.A*p.C)/(q.A*p.B-p.A*q.B) );
}
inline Point intersect( Arrow v, Arrow w ) {
    if( !cross(v, w) || overlap(v, w) ) return Point( NaN, NaN ); 
    if( !parallel(v, w) ) return intersect( Line(v), Line(w) );
    if( w.on_arrow(v.a) ) return v.a;
    if( w.on_arrow(v.b) ) return v.b;
    if( v.on_arrow(w.a) ) return w.a;
    if( v.on_arrow(w.b) ) return w.b;
}
inline double area( Line p, Line q, Line r )
    { return area( intersect(p, q), intersect(q, r), intersect(r, p) ); }
    
// ���㣬����㣬���߾࣬���߾� 
const Point pedal( Line l, Point p ) {
    if( zr( l.slope() ) ) return intersect( Line( 1.0, 0.0, -p.x ), l );
    return intersect( Line( p, -1.0 / l.slope() ), l );
}
const Point pedal( Point p, Line l ) { return pedal( l, p ); }
const Point reflect( Line l, Point p ) { return pedal( l, p ) * 2.0 - p; }
const Point reflect( Point p, Line l ) { return pedal( l, p ) * 2.0 - p; }
double dist( Point p, Line l ) { return fabs(l.A*p.x+l.B*p.y+l.C)/hypot(l.A,l.B); }
double dist( Line l, Point p ) { return fabs(l.A*p.x+l.B*p.y+l.C)/hypot(l.A,l.B); }
double dist( Arrow a, Point p ) {
    double  ans = min( dist( p, a.a ), dist( p, a.b ) );
    if( a.on_arrow( pedal( p, Line( a ) ) ) )
        ans = min( ans, dist( p, Line( a ) ) );
    return  ans;
}
double dist( Point p, Arrow a ) { return dist( a, p ); }
double dist( Line l, Line m ) {
    if( !parallel( l, m ) ) return 0.0;
    if( zr( l.A ) ) return  fabs(m.C/m.B*l.B-l.C)/hypot(l.A,l.B);
    else            return  fabs(m.C/m.A*l.A-l.C)/hypot(l.A,l.B);
}

// �������ʵ�� 
struct Polygon {
    vector<Point>   V;
    void clear() { V.clear(); }
    int size() const { return V.size(); } 
    void get( Point a ) { V.push_back( a ); } 
    double area() const; 
    double perimeter() const;
    bool inside( Point ) const;
    Point Polygon::center() const;
    Polygon convex() const; 
    static Point refP;  // ��̬�ο��� 
    friend bool arg_cmp( Point a, Point b )
        { return (a-refP).angle()<(b-refP).angle(); }
}; 

Point Polygon::refP = Point();

// ���ض������� 
double Polygon::area() const {
    double  ans = 0; 
    for( int i = 0; i < V.size(); ++i )
        ans += V[i] * V[(i+1)%V.size()];
    return  fabs( ans ) / 2.0; 
}

// ���ض�������� 
Point Polygon::center() const {
    Point   ans,    now;
    double  v,  w = 0.0;
    for( int i = 0; i < V.size(); ++i ) {
        now = V[i] + V[(i+1)%V.size()];
        now.x /= 3.0;
        now.y /= 3.0; 
        v = V[i] * V[(i+1)%V.size()];
        ans.x *= w; ans.y *= w;
        now.x *= v; now.y *= v;
        ans = ans + now; w += v;
        if( nz( w ) ) { ans.x /= w; ans.y /= w; } 
    }
    return  ans; 
}

// ���ض�����ܳ�
double Polygon::perimeter() const {
    double  ans = 0; 
    for( int i = 0; i < V.size(); ++i )
        ans += dist( V[i], V[(i+1)%V.size()] );
    return  ans;
}

// ��ѯһ�����Ƿ��ڶ������(�ڱ���Ҳ��) 
bool Polygon::inside( Point a ) const {
    double tot = 0;
    for( int i = 0; i < V.size(); ++i ) {
        if( Arrow( V[i], V[(i+1)%V.size()] ).on_arrow( a ) )
            return  true;
        tot += angle( V[i]-a, V[(i+1)%V.size()]-a );
    }
    return  nz( tot );
}

// �����ε�͹��
Polygon Polygon::convex() const {
    if( V.size() < 3 )  return  *this; 
    vector<Point> G = V;
    int pos = 0;
    for( int i = 1; i < G.size(); ++i )
        if( G[i].y < G[pos].y )
            pos = i;
    swap( G[0], G[pos] );
    refP = G[0];
    sort( G.begin() + 1, G.end(), arg_cmp );
    Polygon H;
    H.get( G[0] );  H.get( G[1] );
    for( int i = 2; i < G.size(); ++i ) {
        while( H.V.size() >= 2 &&
            np((H.V.back()-*(H.V.end()-2))*(G[i]-*(H.V.end()-2))) ) 
            H.V.pop_back();
        H.get( G[i] );
    }
    return  H;
} 

////////////////////////////////////////////////////
//            2008 CopyRight(c) by elf            //
////////////////////////////////////////////////////

int     T,  N;

Arrow   V[30];

Point   P;

int main() {

    for( cin >> T; T--; ) {
        
        cin >> N;
        
        for( int i = 0; i < N; ++i )
            cin >> V[i].a >> V[i].b;

        cin >> P;
        
        int mn = INT_MAX,   now;
        
        for( int i = 1; i < 100; ++i ) {
            
            now = 0;
            for( int j = 0; j < N; ++j )
                if( cross( Arrow( Point( 0, double( i ) - 0.5 ), P ), V[j] ) )
                    ++now;
            mn <?= now;
            
            now = 0;
            for( int j = 0; j < N; ++j )
                if( cross( Arrow( Point( double( i ) - 0.5, 0 ), P ), V[j] ) )
                    ++now;
            mn <?= now;
            
            now = 0;
            for( int j = 0; j < N; ++j )
                if( cross( Arrow( Point( double( i ) - 0.5, 100 ), P ), V[j] ) )
                    ++now;
            mn <?= now;
            
            now = 0;
            for( int j = 0; j < N; ++j )
                if( cross( Arrow( Point( 100, double( i ) - 0.5 ), P ), V[j] ) )
                    ++now;
            mn <?= now;
            
        }
        
        cout << "Number of doors = " << mn + 1 << endl;

        if( T ) puts( "" );

    }
    
}
