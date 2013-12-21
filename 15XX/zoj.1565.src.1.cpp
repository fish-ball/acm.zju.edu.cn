// 1665564 2008-10-13 21:15:16 Accepted  1565 C++ 0 184 ���͵����� 

// �̵ذ�ש���þ����и�ɽ���������⣺
// ������������ < ��������ͣ�˵�����ص���
// ������κ� x<0 || x>W || y<0 || y>H��˵��û�а�����
// ����������������� W*H ˵��û����ȫ���ǣ� 
// ���� OK�� 

//////////////////////////////////////////////////////
//                    �����и� v1.0                 //
///////////////////Documentation//////////////////////
//                                                  //
// 1. struct Rect:  ���νṹ�壬���������������ɫ; //
// 2. clear:        ������о���;                   //
// 3. insert:       ����һ������;                   //
// 4. get_color:    ��ȡ������ɫ�����ͳ��;         // 
//                                                  //
//////////////////////////////////////////////////////
//             2008 CopyRight(c) by elf             //
//////////////////////////////////////////////////////

#include <deque>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

// clr >= 0 Ϊ�Ϸ���ɫ, clr = -1 �ķ���Ϊ�ڱ� 
struct Rect { 
    int x1, y1, x2, y2, clr;
    Rect() {}
    Rect( int a, int b, int c, int d, int clr ) :
        x1(a), y1(b), x2(c), y2(d), clr(clr) {}
    int area() const { return (y2-y1)*(x2-x1); }
};

const Rect SENTINEL( 0, 0, 0, 0, -1 );

class RectCut {
public:
    deque<Rect>     Q;
    map<int, int>   M;
    
public:
    
    // �ڶ����з���һ�� sentinel 
    void clear() { Q.assign( 1, SENTINEL ); M.clear(); }
    
    void insert( int a, int b, int c, int d, int clr ) {
        insert( Rect( a, b, c, d, clr ) );
    }
    
    void insert( Rect r ) {
        M[r.clr] += r.area();
        Q.push_back( r );
        while( Q.front().clr != -1 ) {
            Rect    z = Q.front();
            Q.pop_front();
            if( z.x1 >= r.x2 || z.x2 <= r.x1 ||
                z.y1 >= r.y2 || z.y2 <= r.y1 ) {
                Q.push_back( z );
                continue;
            }
            if( z.x1 < r.x1 ) {
                Q.push_back( Rect( z.x1, z.y1, r.x1, z.y2, z.clr ) );
                z.x1 = r.x1;
            }
            if( z.x2 > r.x2 ) {
                Q.push_back( Rect( r.x2, z.y1, z.x2, z.y2, z.clr ) );
                z.x2 = r.x2;
            }
            if( z.y1 < r.y1 ) {
                Q.push_back( Rect( z.x1, z.y1, z.x2, r.y1, z.clr ) );
                z.y1 = r.y1;
            }
            if( z.y2 > r.y2 ) {
                Q.push_back( Rect( z.x1, r.y2, z.x2, z.y2, z.clr ) );
                z.y2 = r.y2;
            }
            if( ( M[z.clr] -= z.area() ) == 0 ) M.erase( M.find( z.clr ) );
        }
        Q.push_back( Q.front() );
        Q.pop_front();
    } 
    
    vector<pair<int, int> > get_color() const {
        return  vector<pair<int, int> >( M.begin(), M.end() );
    }
    
};

//////////////////////////////////////////////////////
//             2008 CopyRight(c) by elf             //
//////////////////////////////////////////////////////



#include <iostream>
using namespace std;

int main() {
    
    RectCut rc;
    
    int N, T, W, H;
    int xmin, xmax, ymin, ymax, a;
    
    for(cin >> T; T--;) {
        cin >> W >> H >> N;
        rc.clear();
        int x1, x2, y1, y2;
        xmin = ymin = INT_MAX;
        xmax = ymax = INT_MIN;
        a = 0;
        for(int i = 0; i < N; ++i) {
            cin >> x1 >> y1 >> x2 >> y2;
            if(x1 > x2) swap(x1, x2);
            if(y1 > y2) swap(y1, y2);
            xmin = min(x1, xmin);
            xmax = max(x2, xmax);
            ymin = min(y1, ymin);
            ymax = max(y2, ymax);
            a += (y2-y1)*(x2-x1);
            rc.insert(x1, y1, x2, y2, 1);
        }
        if(rc.M[1] != a) puts("NONDISJOINT");
        else if(xmax>W || ymax>H || xmin < 0 || ymin < 0) puts("NONCONTAINED");
        else if(a != W * H) puts("NONCOVERING");
        else puts("OK");
    }
    
}
