// ���� + ��֦���ܾ����һ���� 
// 2861079 2008-04-22 18:18:43 Accepted 1909 C++ 00:00.01 436K ���͵����� 
#include <cstdio>
#include <algorithm>
#include <iterator>
using namespace std;

typedef pair<int, int>  Stick;
int A[3],   L;
Stick   B[20];
Stick* const begin = B;
Stick*  end;

inline bool gt ( const Stick& s1, const Stick& s2 ) {
    return  s1.first > s2.first;
}

// ���ڵݼ������ʣ��ݹ��ʱ�������ԭ���� pos ���������·�չ
// ������ÿ�ζ���ͷ��ʼ�ѣ�����Ч�ʵ���ߺ���Ҫ 
bool DFS( const int& seg, Stick* pos ) {
    Stick*  iter;
    bool    ans = false;
    if( seg == 3 )  return  true;
    if( A[seg] == 0 )  return  DFS( seg + 1, begin );
    // ���һ���δ�δ����ľ������������ 
    if( A[seg] == L ) {
        for( iter = begin; iter != end; iter++ )
            if( iter -> second )
                break;
        A[seg] -= iter -> first;
        iter -> second--;
        ans = DFS( seg, iter );
        iter -> second++;
        A[seg] += iter -> first;
        return  ans;
    }
    // ˳���������ܷ��õ�ľ�� 
    for( iter = pos; iter != end; iter++ ) {
        if( iter -> second && iter -> first <= A[seg] ) {
            // ���һ����ʣ��ĳ���һ��ľ������������ֱ������ 
            if( iter -> first == A[seg] ) {
                A[seg] -= iter -> first;
                iter -> second--;
                ans = DFS( seg + 1, begin );
                iter -> second++;
                A[seg] += iter -> first;
                break;
            }
            // ���������̽ 
            else {
                A[seg] -= iter -> first;
                iter -> second--;
                ans = DFS( seg, iter );
                iter -> second++;
                A[seg] += iter -> first;
                if( ans )   break;
            }
        }
    }
    return  ans;
}

int main() {
    int     T,  temp,   n,  pos;
    Stick*  tp;
    scanf( "%d", &T );
    while( T-- ) {
        scanf( "%d", &n );
        L = 0;
        end = begin;
        // ����ľ�� 
        while( n-- ) {
            scanf( "%d", &temp );
            L += temp;
            for( tp = begin; tp != end; tp++ )
                if( tp -> first == temp )
                    break;
            if( tp == end )
                *(end++) = make_pair( temp, 1 );
            else
                tp -> second++;
        }
        // ǰ�������ж� 
        if( L % 4 != 0 ) {
            puts( "no" );
            continue;
        } 
        L /= 4;
        A[0] = A[1] = A[2] = L;
        sort( begin, end, gt );
        puts( L >= B[0].first && DFS( 0, begin ) ? "yes" : "no" );
    }
}
