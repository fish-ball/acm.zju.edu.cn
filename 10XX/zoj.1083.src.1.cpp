// 2894654 2008-05-06 21:44:35 Accepted 1083 C++ 00:00.01 840K ���͵�����

// �����Һþúþõ��Ⱑ����
// ���������򣡣�
// �Ƚ����п��ܵ���ĸ���������¼��һ��ͼ
// ��ÿ����ĸ�����ķ��������������ĸ����ô�������һ������ͼ�ı�
// Ȼ��˳����������������򣡣�
// д�ö������ˣ�����д��֮���Ȼ����ֱ�ӳɹ� + AC ���� 

#include <set>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int     L[256];
char    A[30][31];
int     H,  W,  N;
set<char>   S;
vector<char>  Node;
vector<char>  stk;
bool    E[30][30];
bool    n_visit[30];


void DFS( int remain ) {
    
    if( remain == 0 ) {
        for( int i = 0; i < stk.size(); ++i )
            putchar( stk[i] );
        putchar( '\n' );
        return;
    }
    
    for( int i = 0; i < N; ++i ) {
        if( n_visit[i] ) {
            bool  yes = true;
            for( int j = 0; j < N; ++j ) {
                if( E[j][i] ) {
                    yes = false;
                    break;
                }
            }
            if( yes ) {
                vector<int> path( 0 );
                for( int j = 0; j < N; ++j ) {
                    if( E[i][j] ) {
                        path.push_back( j );
                        E[i][j] = false;
                    }
                }
                n_visit[i] = false;
                stk.push_back( Node[i] );
                DFS( remain - 1 );
                stk.pop_back();
                n_visit[i] = true;
                for( int j = 0; j < path.size(); ++j )
                    E[i][path[j]] = true;
            }
        }
    }
    
}


int main() {
    
    while( cin >> H >> W ) {
        
        S.clear();
        
        for( int i = 0; i < H; ++i ) {
            cin >> A[i];
            for( int j = 0; j < W; ++j )
                if( A[i][j] != '.' )
                    S.insert( A[i][j] );
        }
        
        Node.clear();
        for( set<char>::iterator iter = S.begin();
                iter != S.end(); ++iter ) {
            Node.push_back( *iter );
        }

        N = Node.size();
        
        for( int i = 0; i < N; ++i )
            for( int j = 0; j < N; ++j )
                E[i][j] = false;
                
        for( int i = 0; i < 256; ++i )  L[i] = -1;
        
        for( int i = 0; i < N; ++i )    L[Node[i]] = i;
        
        // ��������ͼ�ڽӾ��� 
        for( int i = 0; i < N; ++i ) {
            
            int x1 = 10, x2 = 0, y1 = 10, y2 = 0;
            for( int j = 0; j < H; ++j ) {
                for( int k = 0; k < W; ++k ) {
                    if( A[j][k] == Node[i] ) {
                        x1 = min( x1, j );
                        x2 = max( x2, j );
                        y1 = min( y1, k );
                        y2 = max( y2, k );
                    }
                }
            }
            
            for( int j = x1; j <= x2; ++j ) {
                if( A[j][y1] != '.' && A[j][y1] != Node[i] )
                    E[i][L[A[j][y1]]] = true;
                if( A[j][y2] != '.' && A[j][y2] != Node[i] )
                    E[i][L[A[j][y2]]] = true;
            }
            
            for( int j = y1; j <= y2; ++j ) {
                if( A[x1][j] != '.' && A[x1][j] != Node[i] )
                    E[i][L[A[x1][j]]] = true;
                if( A[x2][j] != '.' && A[x2][j] != Node[i] )
                    E[i][L[A[x2][j]]] = true;
            }
            
        }
        
        // ������������������� 
        for( int i = 0; i < N; ++i )
            n_visit[i] = true;
        stk.clear();
        DFS( N );

    }
    
}
