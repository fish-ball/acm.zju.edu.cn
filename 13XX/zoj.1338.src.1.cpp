#include <iostream>
#include <cstdio> 
using namespace std;

int main() {
	int	N,	A[30];
	while(1) {
		int	N = 0;
		while( cin >> A[N] )
			if( A[N] == 0 )	break;
			else 		N++;
		// Up/Down ���е��ܳ��� 
		double	up = 0,	down = 0;
		// Up/Down ���еĸ��� 
		double	countUp = 0,	countDown = 0;
		// ��ǰ���еĳ��� 
		double	len = 0;
		// ��ǰ��������:0-δ����,1-Up����,2-Down���� 
		int	type = 0; 
		for( int i = 1; i < N; i++ ) {
			switch(type) {
				case 0:	if( A[i] == A[i - 1] ) len++;
					else if( A[i] > A[i - 1] ) {
						type = 1;
						len++; 
						countUp++; 
					}
					else if( A[i] < A[i - 1] ) {
						type = 2;
						len++; 
						countDown++; 
					}
					break; 
				case 1: if( A[i] < A[i - 1] ) {
						up += len;
						countDown++;
						len = 1;
						type = 2; 
					} 
					else	len++; 
					break; 
				case 2: ;if( A[i] > A[i - 1] ) {
						down += len;
						countUp++;
						len = 1;
						type = 1; 
					} 
					else	len++; 
			} 
		}
		if( type == 1 )		up += len;
		else if( type == 2 )	down += len;
		if( countUp != 0 )	up /= countUp; 
		if( countDown != 0 )	down /= countDown; 
		if( !N )	break;
		printf( "Nr values = %d:  %.6f %.6f\n", N, up, down );
	}
} 
