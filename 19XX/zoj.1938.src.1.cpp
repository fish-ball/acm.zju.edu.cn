// �������� n �ã���ԶҲ��֪��Ϊʲô������ TLE 

#include <iostream>
using namespace std;

int main() {
    double  sum;
    int     i,  n,  k;
    while( ( cin >> n >> k ) && ( k || n ) ) {
        sum = 1.0;
        if( k + k > n ) k = n - k;  
        // ����������£�һ���ܴ�� k������������һ���������Ǿ�ѭ������ 
        for( i = 1; i <= k; i++ )
            sum *= ( double( n - k + i ) / double( i ) );
        cout << int( sum ) << endl;
    }
    return  0;
}
