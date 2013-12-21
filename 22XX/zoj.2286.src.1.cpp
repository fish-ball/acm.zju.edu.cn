// �������úÿడ����
// 2866153 2008-04-24 15:43:00 Accepted 2286 C++ 00:00.72 4344K ���͵����� 
// �㷨�Ǵ�������ʼ�𲽸Ľ��ģ�������ⱨ��
// ֻ�ǲ�Ը������Ȼ�綼���� 

#include <cstdio>
#include <algorithm>
using namespace std;


int main() {
    
    int* const B = new int[1000001];
    
    for( int i = 0; i < 1000001; i++ )  B[i] = 1;

    for( int i = 2; i * i < 1000001; i++ ) {
        int c = i + 1;
        B[i * i] += i;
        for( int j = i * c; j < 1000001; j += i ) {
            B[j] += ( i + c );
            ++c;
        }
    }

    sort( B, B + 1000001 );

    int N;
    while( scanf( "%d", &N ) != EOF ) {
        printf( "%d\n", lower_bound( B, B + 1000001, N + 1 ) - B - 1 );
    }
    
}
