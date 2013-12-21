// 2887313 2008-05-03 19:36:25 Accepted 2424 C++ 00:00.13 940K ���͵�����

// ����ʽ���ѣ�������ֵ��Χ��̬��һ�㣬�󲿷ֵ�ƪ�������ڴ��������� 
// ����ʽ�������ģ����� n ������� DP[n] �֣�DP[0] = DP[1] = 1 
// ��ô������ÿ�� DP[n]��ѡȡ����һ������Ϊ����
// Ȼ����Ҫѡȡ��һ�������ߣ���Щ��ֻ����ż����ŵ�
//      (ʹ�û��ֵ����߶���ż������)
// Ȼ������ǰ���µ����Ӧ���ǻ������ߵ����� DP[] ֵ֮�� (�˷�ԭ��)
// Ȼ����Щ������ۼ�(�ӷ�ԭ��)�����ɵõ����ƹ�ʽ��DP���ɡ� 

#include <deque>
#include <iostream>
#include <iomanip>
using namespace std;

class BigNum {

    deque<int>  V;

public:
    
    BigNum() : V( 1, 0 ) {}
    
    BigNum( const BigNum& num ) : V( num.V ) {}
    
    BigNum( int val ) : V( 0 ) {
        while( val > 10000 ) {
            V.push_back( val % 10000 );
            val /= 10000;
        }
        V.push_back( val );
    }
    
    friend BigNum& operator += ( BigNum& num1, BigNum num2 );
    
    friend BigNum  operator << ( BigNum& num, int n );
    
    friend BigNum& operator *= ( BigNum& num, const int& k );
    
    friend BigNum  operator *  ( BigNum& num1, BigNum num2 );
    
    friend ostream& operator << ( ostream& os, BigNum num );

};

// �������������� 
BigNum& operator += ( BigNum& num1, BigNum num2 ) {
    
    if( num1.V.size() > num2.V.size() )
        num2.V.resize( num1.V.size() );
    else
        num1.V.resize( num2.V.size() );

    int carry = 0;
    
    for( int i = 0; i < num1.V.size(); ++i ) {
        num1.V[i] += ( num2.V[i] + carry );
        carry = num1.V[i] / 10000;
        num1.V[i] %= 10000;
    }

    if( carry ) num1.V.push_back( 1 );

}

// ������������� 
BigNum operator << ( BigNum& num, int n ) {

    BigNum  ans( num );
    while( n-- > 0 )
        ans.V.push_front( 0 );
    return  ans;

}

// �����Ը�ֵ����� 
BigNum& operator *= ( BigNum& num, const int& k ) {

    int carry = 0;
    for( int i = 0; i < num.V.size(); ++i ) {
        num.V[i] *= k;
        num.V[i] += carry;
        carry = num.V[i] / 10000;
        num.V[i] %= 10000; 
    }
    if( carry ) num.V.push_back( carry );

}

// �������� 
BigNum operator * ( BigNum& num1, BigNum num2 ) {

    BigNum  temp,   ans;

    for( int i = 0; i < num1.V.size(); ++i ) {
        temp = num2 << i;
        temp *= num1.V[i];
        ans += temp;
    }
    
    return  ans;

}

// ��������������� 
ostream& operator << ( ostream& os, BigNum num ) {
    
    os << num.V.back();
    
    for( int i = num.V.size() - 2; i >= 0; --i )
        os << setw( 4 ) << setfill( '0' ) << num.V[i];
    
    return  os;
    
}

int main() {
    
    BigNum  DP[101];
    int     N;
    
    DP[0] = 1;
    DP[1] = 1;
    
    for( int i = 2; i < 101; ++i ) {

        DP[i] = 0;

        for( int j = 0; j < i; ++j )
            DP[i] += DP[j] * DP[i - j - 1]; 

    }

    while( ( cin >> N ) && N != -1 )
        cout << DP[N] << endl;

}
