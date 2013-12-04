// matching !!

#include <cstdio>
#include <cstring> 

int main() {
    
    // N Ϊ���ݹ�ģ��T Ϊ������� 
    int    N,    T = 1;
    
    // A �� B Ϊ�ַ������飬�������뵵�� 
    char    A[64][5],    B[64][5];
    
    // testΪ��ʱ�����itestΪ��ʱ���������codeΪ��������� 
    char    test[20],    itest[20],    code[20];
    
    // ƥ������߼��� ( 4 * 4 ) ���� 
    // ���� match[0][2] = 1 �����1��λ�ô�д��ĸ�����3��λ��Сд��ĸƥ�� 
    int    match[4][4];
    
    while( scanf( "%d", &N ) && N ) {
        
        printf( "Test #%d:\n", T++ );
        
        // �������� 
        for( int i = 0; i < N; i++ )    scanf( "%s", A[i] );
        for( int i = 0; i < N; i++ )    scanf( "%s", B[i] );
        
        // ����ÿһ�鵵����ֻ��һ��ƥ������ȹ��� 
        memset( match, 0, 16 * sizeof( int ) );
        
        // m, n Ϊ�� m ����д��ĸ��ͼ��� n ��Сд��ĸƥ�� 
        for( int m = 0; m < 4; m++ ) {
            
            for( int n = 0; n < 4; n++ ) {
                // ����ì�ܷ񶨵ķ�ʽ 
                bool    fit = 1;
            
                // ��ʼ����ʱ�����0����δ���� 
                memset( test, 0, 20 );
                memset( itest, 0, 20 );
            
                for( int j = 0; j < N; j++ ) {
                    // ����� j �����������Ǻϣ�ֱ��ͨ�� 
                    if( test[A[j][m] - 'A'] == B[j][n] )    continue;
                    // ���˫���δ�������˫����֮ 
                    if( !test[A[j][m] - 'A'] && !itest[B[j][n] - 'a'] ) {
                        test[A[j][m] - 'A'] = B[j][n];
                        itest[B[j][n] - 'a'] = A[j][m];
                    }
                    // �������ì�ܣ����̷� 
                    else { fit = 0; break; }
                }
                
                // ���ƥ�� 
                if( fit ) {
                    // ��ƥ������м�¼��λ�� 
                    match[m][n] = 1;
                    // ����λ�õ���ʱ�����ת�Ƶ���������� 
                    for( int j = 0; j < 5; j++ )
                        code[j + m * 5] = test[j + m * 5];
                }
            }
        }
        
        // �Դ����п��ܵ�ƥ���Ѿ�����
        // ����ж�ƥ���������ǲ�ȷ���ģ������� 5 ����ĸ����Ϊδ֪ 
        for( int m = 0; m < 4; m++ )
            if( match[m][0] + match[m][1] + match[m][2] + match[m][3] != 1 )
                for( int j = 0; j < 5; j++ )
                    code[j + m * 5] = 0;
        
        // �����ĳһ�����Ѿ�֪�������� 4 ����ĸƥ�䣬��ô�� 5 ����ĸ������Ҳ����֪ 
        for( int x = 0; x < 20; x += 5 ) {
        
            // ƥ����ĸ�����ļ��� 
            int    total = 0,    p,    q;
        
            // ��ĸ��Ӧ�߼���
            bool    v[2][5];
        
            memset( v, 0, 10 * sizeof( bool ) );
            for( int y = 0; y < 5; y++ ) {
        
                if( code[x + y] ) {
        
                    q = ( code[x + y] - 'a' ) / 5;
                    total ++;
                    v[0][y] = true;
                    v[1][( code[x + y] - 'a' ) % 5] = true; 
        
                }
        
                else            p = y;
        
            } 
        
            if( total == 4 )
                for( int r = 0; r < 5; r++ )
                    if( !v[1][r] )
                        code[x + p] = 'a' + q * 5 + r;
        
        }
        // ������
        for( int i = 0; i < 20; i++ ) {
        
            printf( "%c-%c", char( 'A' + i ), code[i] ? code[i] : '?' );
        
            if( i % 5 == 4 )    putchar( '\n' );
        
            else             putchar( ' ' ); 
        
        }
    
    }
     
} 
