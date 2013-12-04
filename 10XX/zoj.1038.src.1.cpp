// 8-tree!!
// Simulate!!
// Coding Tree Algorithm!!
// Similar to Huffman!!
// ��ôƯ�����㷨��Ȼ WA ���ù� -_-|
// ����ǿ�poj��λ��ţ���������ҵ������⣬AC�� 
// ԭ��������Ҳ��һ�ִ� 

#include <cstdio>
#include <cstring>

/*************** ���� ***************/
// ��ĸ�������������Ӧ�������Ķ��ӵı�� 
const char code[26] = { 0, 0, 0, 1, 1, 1, 2, 2, 2, 3, 
		                3, 3, 4, 4, 4, 5, 5, 5, 5, 6,
                        6, 6, 7, 7, 7, 7 }; 

/*************** �ඨ�� ***************/
// �������ṹ 
struct Tree {
    // �ýڵ���ַ���(����)
    char*   word;
    // ��������
    int     prob;
    // ����ָ��(��8������Ӧ2~9������)
    Tree*   son[8]; 
};
// ���ָ�����������ݣ������ΪҶ�� 
inline void clear( Tree* root ) {
    memset( root, 0, sizeof( Tree ) );
}
// ���ٸ�Ϊ root �ı����� 
void destroy( Tree* root ) {
    if( root ) {
        destroy( root -> son[0] );
        destroy( root -> son[1] );
        destroy( root -> son[2] );
        destroy( root -> son[3] );
        destroy( root -> son[4] );
        destroy( root -> son[5] );
        destroy( root -> son[6] );
        destroy( root -> son[7] );
        delete    root;
    }
}
// ������������뵥���ַ��� 
void insert( Tree* root, char* s, int p, char c ) {
    if( !( root -> son[code[c - 'a']] ) ) {
        root -> son[code[c - 'a']] = new Tree;
        root = root -> son[code[c - 'a']];
        clear( root );
    }
    else if( ( root -> son[code[c - 'a']] -> prob ) >= p )    return;
    else    root = root -> son[code[c - 'a']];
        root -> word = s; 
        root -> prob = p;
} 
 
/*************** ���� ***************/
// ���ʵ���ִ��� 
char    C[1001][101],    P[1000],    Q[1000];
// �ַ������������� 
int     idx[1000];
char*   D[1001];

// �����е��ַ������� 
void build( Tree* root, int x1, int x2, int t ) {
    int    x = x1,    p = 0;
    char    c = D[x1][t];
    while( 1 ) {
        if( x > x2 ) break;
        bool    match = true; 
        for( int i = 0; i <= t; i++ ) {
            if( D[x1][i] != D[x + 1][i] ) {
                match = false;
                break; 
            }
        }
        if( !match ) break;
        x++;
    } 
    for( int i = x1; i <= x; i++ )    p += P[i];
    insert( root, D[x1], p, c );
    // �������
    if( D[x1][t + 1] )
        build( root -> son[code[c - 'a']], x1, x, t + 1 );
    else if( x1 < x2 && D[x1 + 1][t + 1] )
        build( root -> son[code[c - 'a']], x1 + 1, x, t + 1 );
    // ��������
    if( x < x2 )
        build( root, x + 1, x2, t );
}

int main() {
    // �������ĸ� 
    Tree*    root = NULL;
    int    T,    N;
    scanf( "%d", &T );
    for( int t = 0; t < T; t++ ) {
        printf( "Scenario #%d:\n", t + 1 ); 
        // ����ÿ��������ͷ��ձ�����һ�� 
        destroy( root );
        root = new Tree;
        clear( root );
        // ����ַ��������� 
        memset( C, 0, 101101 ); 
        memset( idx, 0, 1001 * sizeof( int ) );
        scanf( "%d", &N );
        // �����ַ������Լ����ʱ������������������� 
        for( int n = 0; n < N; n++ ) {
            scanf( "%s%d", C[n], &Q[n] );
            for( int m = 0; m < n; m++ )
                if( strcmp( C[n], C[m] ) >= 0 )    idx[n]++;
                else                idx[m]++;
        }
        // �������������ַ��� 
        for( int n = 0; n < N; n++ ) {
            D[idx[n]] = C[n];
            P[idx[n]] = Q[n];
        } 
        // �ڱ�(Sentinel)����ֹ����ʱԽ��Ƚ� 
        memset( C[N], '~', 101 ); 
        D[N] = C[N]; 
        // ���� 
        if( N ) build( root, 0, N - 1, 0 );
        // ��ѯ 
        int    M;
        scanf( "%d", &M );
        while( M-- ) {
            char    check[101];
            scanf( "%s", check );
            if( !N ) {
                for( unsigned int i = 0; i < strlen( check ) - 1; i++ )
                    printf( "MANUALLY\n" );
                putchar( '\n' );
                continue; 
            }
            Tree*    v = root;
            for( int i = 0; check[i] != '1'; i++ ) {
                if( v )    v = v -> son[check[i] - '2'];
                if( v ) for( int j = 0; j <= i; j++ )
                    putchar( v -> word[j] );
                else    printf( "MANUALLY" );
                putchar( '\n' );
            }
            putchar( '\n' );
        }
        putchar( '\n' ); 
    }
} 
