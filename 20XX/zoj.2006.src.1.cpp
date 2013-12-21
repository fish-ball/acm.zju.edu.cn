// O(n)
// ��Ϊ�ֲڵļ��ɾ��ǰ�ͬ�����ַ������Լ�ƴ�ӣ�����ѭ���б�
// 2829241 2008-04-07 18:29:17 Accepted 2006 C++ 00:00.32 424K ���͵�����  

#include <cstdio>
#include <cstring>

int     len;
char    str[20001], temp[10001];

bool icmp( const int& x, const int& y ) {
    for( int i = 0; i < len; i++ ) {
        if( str[x + i] < str[y + i] )
            return  true;
        if( str[x + i] > str[y + i] )
            return  false;
    }
    return  x < y;
}

int main() {
    int     N;
    scanf( "%d", &N );
    while( N-- ) {
        scanf( "%s", str );
        len = strlen( str );
        strcpy( temp, str );
        strcat( str, temp );
        int pos = 0;
        for( int i = 0; i < len; i++ ) {
            if( icmp( i, pos ) )
                pos = i;
        }
        printf( "%d\n", pos + 1 );
    }
}
