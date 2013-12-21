// 3028560 2008-08-09 15:14:39 Accepted 2370 C++ 00:00.00 840K ���͵����� 

// ��������ͼ�ο��Եõ����¹�ʽ

// 2 * R * sin( x ) = L
// 2 * R * x = L1
// �� R * ( 1 - cos( x ) )

// ���У�x ��Բ�Ľǵ�һ�룬L ���ҳ�������ǰ��
// L1 �ǻ��������Ⱥ󣩣�R ��Բ�뾶

// ���У�ֻ������ L �� L1
// ����ǰ��ʽ���õ� sin( x ) * L1 = x * L
// ������ýǶ� x�����µ�ӭ�ж���  

// ע��һЩ�߽����ݵ������������ L = 0 ��ʱ�� 

#include <cmath>
#include <iostream>
using namespace std;

double  L,  L1, n,  C;

inline double fun( double x ) { return  sin( x ) - x * L; }

int main() {
    
    while( cin >> L >> n >> C && L >= 0.0 ) {
        
        if( L == 0.0 || n == 0.0 || C == 0.0 ) {
            puts( "0.000" );
            continue; 
        } 
        
        L1 = L * ( 1.0 + n * C );
        
        L /= L1; 
        
        double  mn = 0.0, mx = acos( -1.0 ) / 2.0;
        
        while( ( mx - mn ) / mx > 1e-12 ) {
            double  mid = ( mx + mn ) / 2.0;
            if( fun( mid ) > 0.0 )
                    mn = mid;
            else    mx = mid;
        }
        
        printf( "%.3lf\n", L1 / 2.0 / mx * ( 1.0 - cos( mx ) ) );
        
    }
    
}
