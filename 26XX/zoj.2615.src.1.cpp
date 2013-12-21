// 2950897 2008-06-16 14:21:12 Accepted 2615 C++ 00:02.01 237312K ���͵����� 

// DFS ʱ�����cp ��ţ�̵ģ����� O(1) �б��и��������ڵ��Ƿ������ȹ�ϵ
// Ȼ�������������ʱ�仹�ǿռ䣬���ö��ǳ���
// ͼ�Ĵ��������·�ʽ��ֻ��Ҫ����һ�� DFS �õ�ʱ������ɣ��� 
// ����ǰ�� N ���ڵ㣬��¼���Ķ����� cnt[n]���Լ���һ�����ӵ���� child[n] 
// ��ô�����Ķ��Ӿ��� child[n], child[n] + 1 ... child[n] + cnt[n] - 1
// �����Ϳ����� 2 * N ���ڴ洢������������һ�� DFS �õ������

// ���⣬����̫��ֱ�ӵݹ� DFS �ǻ�ջ����ģ����Ҫ�Լ��ø����鵱ջ�� DFS
// ��������¼��ǰ�Ľڵ㼴�ɣ�Ȼ�������ѿ����ƻ� child �� stk �����У���ʡ�ռ� 
// DFS ��ʱ����һ�� tm ��¼ʱ�䣬ÿѹջ����ջ 1 ����tm ����һ 
// ������ÿ DFS ��һ���㣬��¼����ʱ�� in ��������ʱ���¼�˳�ʱ�� out 
// ���ǣ�X �� Y �ĳ�Ҫ�������ǣ�
// X �� Y ����룬���� Y ���˳��� 

#include <cstdio>

int     in[20010000],   out[20010000];
int     child[310000],  cnt[310000];
int     stk[20010000],  top;

int main() {

    int     T,  N,  K;

    scanf( "%d", &T );
    
    for( int t = 1; t <= T; ++t ) {
        
        scanf( "%d", &N );
        
        for( int i = K = 0; i < N; ++i ) {
            scanf( "%d", cnt + i );
            child[i] = K;
            K += cnt[i];
        }

        int     tm = 0, temp;
        stk[top = 0] = 0;
        in[0] = tm++;

        while( top >= 0 ) {
            if( stk[top] >= N || cnt[stk[top]] <= 0 )
                out[stk[top--]] = tm++;
            else {
                temp = child[stk[top]] + cnt[stk[top]]--;
                in[temp] = tm++;
                stk[++top] = temp;
            }
        }

        if( t > 1 ) putchar( '\n' );
        printf( "Case %d:\n", t );

        int     Q,  X,  Y;
        for( scanf( "%d", &Q ); Q--; ) {
            scanf( "%d%d", &X, &Y );
            if( in[X] < in[Y] &&
                out[X] > out[Y] )
                puts( "Yes" );
            else
                puts( "No" );
        }   
        
    }

}
