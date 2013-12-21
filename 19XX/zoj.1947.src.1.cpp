// 3016822 2008-08-01 16:25:11 Accepted 1947 C++ 00:00.01 832K ���͵����� 

// �ҳ�һ��ͼ���ŷ��·������ͼ��ģ��С���Ҽ���ϡ�裬Ӳ��ɾ���ܹ� 

#include <iostream>
#include <vector>
using namespace std;

bool    V[25][25]; 

int     N,  M,  x,  y,  mx, now;

void DFS( int v ) {
    for( int w = 0; w < N; ++w ) {
        if( V[v][w] ) {
            if( ++now > mx )    mx = now; 
            V[v][w] = V[w][v] = false; 
            DFS( w );
            V[v][w] = V[w][v] = true; 
            --now; 
        }
    }
} 

int main() {
    
    while( cin >> N >> M && N ) {
        
        memset( V, 0, sizeof( V ) );
            
        for( int i = 0; i < M; ++i ) {
            cin >> x >> y;
            V[x][y] = V[y][x] = true; 
        }
        
        now = mx = 0;
        
        for( int i = 0; i < N; ++i ) DFS( i ); 
        
        cout << mx << endl; 
        
    }
    
}
