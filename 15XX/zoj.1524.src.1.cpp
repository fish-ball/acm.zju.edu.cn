// 2939301 2008-06-01 19:51:26 Accepted 1524 C++ 00:00.30 1564K ���͵����� 

// DP, ����ˢ�£�ע����� 

// ά��һ������ V[M]����ʾ��ǰ�����򵽲˵���ĳһ������������ֵ
// Ȼ��ӵ� 0 ����Ʒ�������ߣ�ɨ��ÿ�� X[i] ���ƥ�䣬���ˢ�� V[M]
// �����Ľ��Ӧ���� V[M - 1] 

#include <cstdio>
#include <cstring>

int     X[100], M,  K[100000],  N;
double  V[100],     P[100000];

int main() {
    
    while( scanf( "%d%d", &M, &N ) && M ) {
        
        for( int i = 0; i < M; ++i ) {
            scanf( "%d", X + i );
            V[i] = 1e100;
        }
            
        for( int i = 0; i < N; ++i )
            scanf( "%d%lf", K + i, P + i );
            
        for( int i = 0; i < N; ++i ) {
            // j ��ö��ע����򣬱���Ӵ�С�� 
            for( int j = M - 1; j >= 0; --j )
                if( K[i] == X[j] && P[i] + V[j-1] < V[j] )
                    V[j] = P[i] + V[j-1];
            if( K[i] == X[0] && P[i] < V[0] )
                V[0] = P[i];
        }
        
        if( V[M - 1] == 1e100 )
            puts( "Impossible" );
        else
            printf( "%.2lf\n", V[M - 1] );
        
    }
    
}
