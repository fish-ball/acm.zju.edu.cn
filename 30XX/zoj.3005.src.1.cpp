// 3036945 2008-08-15 18:39:32 Accepted 3005 C++ 00:00.18 976K ���͵����� 

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
#include <set>
#include <algorithm>
using namespace std;

set<int>    MP[501];
set<int>::iterator  iter;

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
            MP[z.clr].insert( r.clr );
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

RectCut rcut;

Rect    R;

int     N,  Q,  idx;

int main() {
    
    while( cin >> N ) {
        
        rcut.clear();
        
        for( int i = 1; i <= N; ++i )
            MP[i].clear();
        
        for( int i = idx = 0; i < N; ++i ) {
            cin >> R.x1 >> R.y1 >> R.x2 >> R.y2;
            R.clr = ++idx;
            rcut.insert( R );
        }
        
        for( cin >> Q; Q--; ) {
            cin >> idx;
            cout << MP[idx].size();
            for( iter = MP[idx].begin(); iter != MP[idx].end(); ++iter )
                cout << ' ' << *iter;
            puts( "" );
        }
        
        puts( "" );
        
    }
    
}
