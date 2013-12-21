

#include <iostream>
#include <vector>
#include <cmath> 
#include <algorithm> 
using namespace std; 

class Point;    // �㡢ʸ���ࣨx ����� y ���꣩ 
class Arrow;    // �����߶��ࣨ�����յ㣩 
class Line;     // ֱ���� 
class Circle;   // Բ�� 
class Polygon;  // ����� 

const double INF = 1e30;
const double EPS = 1e-8;
const double PI = acos( -1.0 );

inline bool eq( double x, double y ) { return x-y < EPS && y-x < EPS; }
inline bool ne( double x, double y ) { return x-y > EPS || y-x > EPS; }
inline bool gt( double x, double y ) { return x-y > EPS; }
inline bool ge( double x, double y ) { return y-x < EPS; }
inline bool lt( double x, double y ) { return y-x > EPS; }
inline bool le( double x, double y ) { return x-y < EPS; }

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
    { if( zr(x)&&ps(y) ) return PI / 2.0;
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
    inline bool on_arrow( Point p ) { return zr((a-p)*(p-b))&&nn((a-p)^(p-b)); } 
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
}; 

// ֱ���غϡ��ཻ��ƽ�С�ֱ�߽��㡢�߶ν��㡢��ֱ��Χ��� 
inline bool superp( Line p, Line q )
    { return eq( p.A*q.B, p.B*q.A ) && eq( p.A*q.C, p.C*q.A ); }
inline bool cross( Line p, Line q )
    { return ne( p.A*q.B, p.B*q.A ); }
inline bool parallel( Line p, Line q ) 
    { return eq( p.A*q.B, p.B*q.A ) && ne( p.A*q.C, p.C*q.A ); }
    
// ���㣬����㣬���߾࣬���߾� 
double dist( Point p, Line l ) { return fabs(l.A*p.x+l.B*p.y+l.C)/hypot(l.A,l.B); }
double dist( Line l, Point p ) { return fabs(l.A*p.x+l.B*p.y+l.C)/hypot(l.A,l.B); }
double dist( Arrow a, Point p ) {
    if( le( fabs( angle(a.a-p, a.a-a.b) ), PI/2.0 ) &&
        le( fabs( angle(a.b-p, a.b-a.a) ), PI/2.0 ) )
        return  dist( p, Line( a ) );
    return  min( dist( p, a.a ), dist( p, a.b ) );
}
double dist( Point p, Arrow a ) { return dist( a, p ); }
double dist( Line l, Line m ) {
    if( !parallel( l, m ) ) return 0.0;
    if( zr( l.A ) ) return  fabs(m.C/m.B*l.B-l.C)/hypot(l.A,l.B);
    else            return  fabs(m.C/m.A*l.A-l.C)/hypot(l.A,l.B);
}

////////////////////////////////////////////////////
//            2008 CopyRight(c) by elf            //
////////////////////////////////////////////////////

struct Rect {
    Point   a,  b;
    double  h;
    bool inside( Point p ) {
        return  le( a.x, p.x ) && le( p.x, b.x ) &&
                le( a.y, p.y ) && le( p.y, b.y );
    }
};

bool cross( Arrow k, Rect r ) {
    if( r.inside( k.a ) || r.inside( k.b ) ) return true;
    Point   P[4] = { r.a, Point( r.b.x, r.a.y ), r.b, Point( r.a.x, r.b.y ) };
    for( int i = 0; i < 4; ++i )
        if( cross( Arrow( P[i], P[(i+1)%4] ), k ) ) return  true;
    return  false;
}

double dist( Arrow k, Rect r ) {
    if( cross( k, r ) ) return  0.0;
    double  d = INF;
    Point   P[4] = { r.a, Point( r.b.x, r.a.y ), r.b, Point( r.a.x, r.b.y ) };
    for( int i = 0; i < 4; ++i ) {
        d <?= dist( P[i], k );
        d <?= dist( k.a, Arrow( P[i], P[(i+1)%4] ) );
        d <?= dist( k.b, Arrow( P[i], P[(i+1)%4] ) );
    }
    if( ge( r.h, d ) )  return  d;
    return  (d*d+r.h*r.h)/2.0/r.h;
}

int main() {

    int     N;
    Point   a,  b;
    Rect    r;

    while( scanf( "%d", &N ) && N ) {
        scanf( "%lf%lf%lf%lf", &a.x, &a.y, &b.x, &b.y );
        double  ans = INF;
        while( N-- ) {
            scanf( "%lf%lf%lf%lf%lf", &r.a.x, &r.a.y, &r.b.x, &r.b.y, &r.h );
            ans <?= dist( Arrow( a, b ), r );
        }
        printf( "%.4lf\n", ans );
    }
    
}
