// 2960121 2008-07-02 22:06:58 Accepted 2548 C++ 00:00.19 408K ���͵����� 

// ����һ����ֱ��Ѱַ�����ˣ���Ϊֻ�� 10000 ���γ̡�
// ����ע�ⲻҪ�� iostream���� TLE 

#include <cstdio>
#include <cstring>

bool    B[10000];

int main() {
    
    int x,  y,  z,  w;
    
    while( scanf( "%d", &x ) && x ) {
        
        scanf( "%d", &y );
        
        memset( B, 0, sizeof( B ) );
        for( int i = 0; i < x; ++i ) {
            scanf( "%d", &z );
            B[z] = true;
        }
        
        bool    yes = true;
        for( int i = 0; i < y; ++i ) {
            int cnt = 0;
            scanf( "%d%d", &x, &z );
            for( int j = 0; j < x; ++j ) {
                scanf( "%d", &w );
                if( B[w] )  ++cnt;
            }
            if( cnt < z )
                yes = false;
        }
        
        puts( yes ? "yes" : "no" );
        
    }
    
}
