// 3049946 2008-08-25 15:33:23 Accepted 1893 C++ 00:00.01 980K ���͵����� 

// ���ģ��ұ������仯����������֮ǰ����״̬ѹ��

// ��Ϊ��ʵ�����п��Դﵽ�������ǽ��� 2 3 5 7 Ϊ���ӵ���

// �������ķ�Χ�ڣ��������������м�ǧ��������������Щ�������� 

// Ȼ��Ϳ��Լ��仯�����ˣ��Һ��״̬��ʱ������Ȱ������ɳ����ڶ��ֲ��� 

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long i64;

vector<i64> V( 0 );

i64 D[4] = { 2, 3, 5, 7 };

i64 MX = 4294967295ll;

void DFS( i64 x, int bg ) {
    if( x > MX )    return;
    V.push_back( x );
    for( int i = bg; i < 4; ++i )
        DFS( x * D[i], i );
}

i64     x;
    
size_t  pos;

vector<bool>    found,  win;

bool getval( int p ) {
    if( found[p] )  return  win[p];
    found[p] = true;
    if( V[p] * 9 >= x ) return  win[p] = true;
    bool ans = false;
    for( i64 i = 2; i <= 9; ++i ) {
        if( !getval( lower_bound( V.begin(), V.end(), V[p]*i ) - V.begin() ) ) {
            ans = true;
            break;
        }
    }
    return  win[p] = ans;
}

int main() {
    
    DFS( 1, 0 );
    
    sort( V.begin(), V.end() );
    
    while( cin >> x ) {
        pos = lower_bound( V.begin(), V.end(), x )
                - V.begin() - 1;
        found.assign( pos, false );
        win.assign( pos, false );
        puts( getval( 0 ) ? "Stan wins." : "Ollie wins." );
    }
    
}
