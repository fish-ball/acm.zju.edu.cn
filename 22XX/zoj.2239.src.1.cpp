// ���� Josephu �� ���⣬m = 2 �����Σ��г�ǿ���㷨
// ���� n ѭ������ 1 λ���ɣ�����˵�������ⱨ��
// 2885671 2008-05-03 01:39:13 Accepted 2239 C++ 00:00.00 388K ���͵�����

#include <cstdio>

int main() {
    
    int     x,  e;
    
    while( scanf( "%de%d", &x, &e ) && x ) {
        
        while( e-- ) x *= 10;
        for( e = 1; e <= x; e <<= 1 );
        printf( "%d\n", ( x << 1 ) - e + 1 );
        
    }
    
}
