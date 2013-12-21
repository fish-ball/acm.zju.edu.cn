// 2956897 2008-06-26 21:04:41 Accepted 2743 C++ 00:00.01 904K ���͵����� 

// ��������������д����ģ�⣬������ DFS

// ������������ DFS һ�Σ������ͬɫ����ͨ��DFS ���� ++cnt�������Ϊ 'E'
// ��ʱ����� cnt < 3����ô��� 0
// ���򣬶Ե� 0 ��(����)���е��� DFS1�����ֻҪ�����ݾ���ͨ
//     ���ü��������ʹ��ı��Ϊ 'E'
// Ȼ�󣬱������е㣬�����������(�������ǲ��붥����ͨ����Ȼ������)��++cnt 

#include <cstdio>
#include <cctype>

char    A[100][101];
int     H,  W,  X,  Y,  cnt;

inline bool isValid( int x, int y ) {
    return  x >= 0 && y >= 0 && x < H && y < W;
}    

void DFS( int x, int y ) {
    
    char p = A[x][y];
    
    A[x][y] = 'E';
    
    ++cnt;
    
    if( x % 2 ) {
        if( isValid( x-1, y )   && A[x-1][y]   == p )   DFS( x-1, y );
        if( isValid( x-1, y+1 ) && A[x-1][y+1] == p )   DFS( x-1, y+1 );
        if( isValid( x+1, y )   && A[x+1][y]   == p )   DFS( x+1, y );
        if( isValid( x+1, y+1 ) && A[x+1][y+1] == p )   DFS( x+1, y+1 );
        if( isValid( x, y-1 )   && A[x][y-1]   == p )   DFS( x, y-1 );
        if( isValid( x, y+1 )   && A[x][y+1]   == p )   DFS( x, y+1 );
    }
    
    else {
        if( isValid( x-1, y )   && A[x-1][y]   == p )   DFS( x-1, y );
        if( isValid( x-1, y-1 ) && A[x-1][y-1] == p )   DFS( x-1, y-1 );
        if( isValid( x+1, y )   && A[x+1][y]   == p )   DFS( x+1, y );
        if( isValid( x+1, y-1 ) && A[x+1][y-1] == p )   DFS( x+1, y-1 );
        if( isValid( x, y-1 )   && A[x][y-1]   == p )   DFS( x, y-1 );
        if( isValid( x, y+1 )   && A[x][y+1]   == p )   DFS( x, y+1 );
    }
    
}

void DFS1( int x, int y ) {
    
    A[x][y] = 'E';
    
    if( x % 2 ) {
        if( isValid( x-1, y )   && A[x-1][y]   > 'E' )   DFS1( x-1, y );
        if( isValid( x-1, y+1 ) && A[x-1][y+1] > 'E' )   DFS1( x-1, y+1 );
        if( isValid( x+1, y )   && A[x+1][y]   > 'E' )   DFS1( x+1, y );
        if( isValid( x+1, y+1 ) && A[x+1][y+1] > 'E' )   DFS1( x+1, y+1 );
        if( isValid( x, y-1 )   && A[x][y-1]   > 'E' )   DFS1( x, y-1 );
        if( isValid( x, y+1 )   && A[x][y+1]   > 'E' )   DFS1( x, y+1 );
    }
    
    else {
        if( isValid( x-1, y )   && A[x-1][y]   > 'E' )   DFS1( x-1, y );
        if( isValid( x-1, y-1 ) && A[x-1][y-1] > 'E' )   DFS1( x-1, y-1 );
        if( isValid( x+1, y )   && A[x+1][y]   > 'E' )   DFS1( x+1, y );
        if( isValid( x+1, y-1 ) && A[x+1][y-1] > 'E' )   DFS1( x+1, y-1 );
        if( isValid( x, y-1 )   && A[x][y-1]   > 'E' )   DFS1( x, y-1 );
        if( isValid( x, y+1 )   && A[x][y+1]   > 'E' )   DFS1( x, y+1 );
    }
    
}

int main() {
    
    while( scanf( "%d%d%d%d", &H, &W, &X, &Y ) != EOF ) {
    
        gets( A[0] );
    
        for( int i = 0; i < H; ++i )
            gets( A[i] );
            
        cnt = 0;
        
        DFS( X - 1, Y - 1 );
        
        if( cnt < 3 ) {
            puts( "0" );
            continue;
        }
        
        for( int i = 0; i < W; ++i ) {
            if( A[0][i] != 'E' )
                DFS1( 0, i );
        }
        
        for( int i = 0; i < H; ++i )
            for( int j = 0; j < W; ++j )
                if( A[i][j] && A[i][j] != 'E' )
                    ++cnt;
        
        printf( "%d\n", cnt );
    
    }
    
}
