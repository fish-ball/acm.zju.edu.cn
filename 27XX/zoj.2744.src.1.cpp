// ��������չ�����ӶȲ��Ǻܸߣ�ֻҪͨ�� 5000 �� A �� worst �������ͻ���û������
// 2822112 2008-04-04 02:05:31 Accepted 2744 C++ 00:00.09 400K ���͵�����  

#include <cstdio>
#include <cstring>

int main() {
    int     count,  len,  lb,  ub;
    char    A[5001];
    while( scanf( "%s", A ) != EOF ) {
        len = strlen( A );
        for( int i = count = 0; i < len; i++ ) {
            count++;
            lb = i - 1;
            ub = i + 1;
            while( lb >= 0 && ub < len && A[lb] == A[ub] ) {
                count++;
                lb--;
                ub++;
            }
            lb = i;
            ub = i + 1;
            while( lb >= 0 && ub < len && A[lb] == A[ub] ) {
                count++;
                lb--;
                ub++;
            }
        }
        printf( "%d\n", count );
    }
}
