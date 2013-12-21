// 2967359 2008-07-08 23:05:44 Accepted 2977 C++ 00:00.31 392K ���͵����� 

// λ���㣬�ؼ�����λ���������

// ��ö�ٵ�һ�е����ⷴת��ʽ��Ȼ�����������ȷ����

// ���ڵ� i ���Ѿ�ȷ����λ x 
// ��ô�� i + 2 ��ֻ�ܷ�ת x Ϊ 1 ��λ
// �� i + 1 �з�ת��Щλ�� +1 λ�� -1 λ
// ���ǿ��Եõ� i + 1 �еķ�ת����Ϊ x ^ (x<<1) ^(x>>1)

// Ȼ�������һ���Ƿ�Ϊȫ�㣬�����м䷴תλ�ĸ������� 

#include <cstdio>
#include <cstring>
#include <bitset>
using namespace std;

int     MASK[17] = { 0, 1 };
int     MIDD[16] = { 3, 7 };
int     PULS[16] = { 1, 2 };
int     GRID[17],   TEMP[17];
int     R,  C,  tot,    ans;
char    X[17];

void init() {
    for( int i = 1; i < 17; ++i )
        MASK[i+1] = ( MASK[i] << 1 ) + 1;
    for( int i = 2; i < 16; ++i ) {
        MIDD[i] = MIDD[i-1] << 1;
        PULS[i] = PULS[i-1] << 1;
    }
}

inline int GetMask( int x ) {
    return  x ^ ( x << 1 ) ^ ( x >> 1 );
}

int main() {

    init();
    
    while( scanf( "%d%d", &R, &C ) && R ) {
    
        gets( X );
        for( int i = 0; i < R; ++i ) {
            gets( X );
            GRID[i] = 0;
            for( int j = 0; j < C; ++j ) {
                GRID[i] <<= 1;
                if( X[j] == 'X' )
                    GRID[i] |= 1;
            }
        }
        
        ans = 10000;
        
        for( int inv = 0; inv < MASK[C] + 1; ++inv ) {
            
            memcpy( TEMP, GRID, sizeof( TEMP ) );
            tot = bitset<16>( inv & MASK[C] ).count();
            TEMP[0] ^= GetMask( inv );
            TEMP[1] ^= inv;
            
            
            for( int i = 1; i < R; ++i ) {
                tot += bitset<16>( TEMP[i-1] & MASK[C] ).count();
                TEMP[i] ^= GetMask( TEMP[i-1] & MASK[C] );
                TEMP[i+1] ^= TEMP[i-1];
            }
            if( tot >= ans || MASK[C] & TEMP[R-1] )
                continue;
            else    ans = tot;
            
        }
        
        if( ans == 10000 )  puts( "Damaged billboard." );
        else    printf( "You have to tap %d tiles.\n", ans );
    
    }
    
}
