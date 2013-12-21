// 3067124 2008-09-12 09:29:44 Accepted 2818 C++ 00:00.00 840K ���͵����� 

// ���� N �η����Ĺ���ֵ���� double WS ֮�� 

#include <iostream>
#include <cmath> 
using namespace std;

int main()
{
	double	B,	N;
	while( cin >> B >> N ) {
		if( !B && !N ) break; 
		double	A = floor( pow( B, 1 / N ) ); 
		double	t1 = B - pow( A, N );
		double	t2 = pow( A + 1, N ) - B;
		cout.setf( ios::fixed );
		cout.precision( 0 ); 
		if( t2 > t1 )
			cout << A << endl;
		else
			cout << A + 1 << endl;
	} 
} 
