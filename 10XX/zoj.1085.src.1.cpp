// 2976651 2008-07-14 11:53:18 Accepted 1085 C++ 00:00.00 880K ���͵����� 

// ����ͼ...

// ��һ�������㵽Ŀ�ĵ��·�����У��ؾ��Ķ����У���Ŀ�ĵ�����Ķ���

// ���ж�һ�������Ƿ�Ϊ�ؾ��㣺
//     �Ƚ��ոö���(���Ϊ�ѷ���)��Ȼ�� DFS �ж� 0->ET �Ŀɴ���
//     ������ɴ��ô���յĶ���Ϊ�ؾ���
//     �ڽӾ��󵥴� DFS ���Ӷ� V^2����ô�бؾ��� O(V^3)
// Ȼ�� Floyd һ�£�ö�ٱؾ��㣬ȡ������ģ��ܸ��Ӷ� O(V^3) 


#include <iostream>
using namespace std;

const int MAXN = 101; 

int     T,  N,  ET, x,  y;

int     V[MAXN][MAXN];
bool    Y[MAXN], P[MAXN]; 

char    WS[10]; 

bool DFS( int v ) {
    if( v == ET )   return  true; 
    P[v] = true; 
    for( int i = 0; i <= N; ++i )
        if( !P[i] && V[v][i] && DFS( i ) )
            return  true; 
    return  false; 
} 

int main() {
    
    for( scanf( "%d", &T ); T--; ) {
        
        scanf( "%d%d", &N, &ET );
        gets( WS ); 
        
        memset( V, 0, sizeof( V ) );
        
        while( cin.peek() != '\n' && cin.peek() != -1 ) {
            
            scanf( "%d%d", &x, &y );
            
            V[x][y] = 1;
            
            gets( WS );
            
        } 
        
        Y[0] = true; 
        for( int i = 1; i <= N; ++i ) {
            // ����ĳ���㣬Ȼ�� DFS �ж� 0 �� ET �Ƿ���ͨ
            memset( P, 0, sizeof( P ) );
            P[i] = true;
            Y[i] = i != ET && !DFS( 0 ); 
        }
        
        // floyed 
        for( int i = 0; i <= N; ++i )
            for( int j = 0; j <= N; ++j )
                if( V[j][i] ) 
                for( int k = 0; k <= N; ++k )
                    if( V[i][k] && !V[j][k] ||
                        V[j][k] > V[j][i] + V[i][k] )
                        V[j][k] = V[j][i] + V[i][k];
                        
        int p = 0;
        for( int i = 0; i <= N; ++i )
            if( Y[i] && V[i][ET] && V[i][ET] < V[p][ET] )
                p = i; 
                
        printf( "Put guards in room %d.\n", p );
        
        if( T ) puts( "" ); 
                
    }
    
}
