////////////////////////////////////////////////////
//                 ������ģ�� v1.1                //
////////////////////////////////////////////////////
//  1. ֧���������ӡ������ˡ�10������λ����;      //
//  2. ֧�ֱȽ������ < �� == ;                   // 
//  3. ֧������ȡ������������(����ȡ��������Χ��);// 
////////////////////////////////////////////////////
//            2008 CopyRight(c) by elf            //
////////////////////////////////////////////////////

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
    
    friend BigNum  operator +  ( BigNum num1, BigNum num2 );
    
    friend BigNum  operator -=  ( BigNum num1, int num2 );
    
    friend BigNum  operator << ( BigNum& num, int n );
    
    friend BigNum& operator *= ( BigNum& num, const int& k );
    
    friend BigNum  operator *  ( BigNum& num1, BigNum num2 );
    
    friend bool operator == ( const BigNum& num1, const BigNum& num2 );
    
    friend bool operator <  ( const BigNum& num1, const BigNum& num2 );

    friend bool operator <=  ( const BigNum& num1, const BigNum& num2 );

    friend ostream& operator << ( ostream& os, BigNum num );
    
    friend istream& operator >> ( istream& is, BigNum& num );
    
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
    
    return  num1;

}

// �������� 
BigNum operator + ( BigNum num1, BigNum num2 ) {
    
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
    
    return  num1;

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
    return  num;

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

// ��ȱȽ������ 
bool operator == ( const BigNum& num1, const BigNum& num2 ) {
    
    return  num1.V == num2.V;
    
}

// С�ڱȽ������ 
bool operator <  ( const BigNum& num1, const BigNum& num2 ) {
    
    if( num1.V.size() < num2.V.size() ) return  true;
    if( num1.V.size() > num2.V.size() ) return  false;
    for( int i = num1.V.size() - 1; i >= 0; --i ) {
        if( num1.V[i] < num2.V[i] ) return  true;
        if( num1.V[i] > num2.V[i] ) return  false;
    }
    return  false;
    
}

// С�ڵ��ڱȽ������ 
bool operator <= ( const BigNum& num1, const BigNum& num2 ) {
    
    if( num1.V.size() < num2.V.size() ) return  true;
    if( num1.V.size() > num2.V.size() ) return  false;
    for( int i = num1.V.size() - 1; i >= 0; --i ) {
        if( num1.V[i] < num2.V[i] ) return  true;
        if( num1.V[i] > num2.V[i] ) return  false;
    }
    return  true;
    
}

// ��������������� 
ostream& operator << ( ostream& os, BigNum num ) {
    
    os << num.V.back();
    
    for( int i = num.V.size() - 2; i >= 0; --i )
        os << setw( 4 ) << setfill( '0' ) << num.V[i];
    
    return  os;
    
}

// ��������ȡ����� 
istream& operator >> ( istream& is, BigNum& num ) {
    
    num.V.resize( 1 );
    
    return  is >> num.V[0];

}

/////////////////////// MAIN PROCEDURE ///////////////////////


// 2915891 2008-05-15 15:00:16 Accepted 1819 C++ 00:00.03 2424K ���͵����� 

// DP������������������������ģ�� 

int main() {
    
    // ��һά���ܳ��ȣ��ڶ�ά��������ĸ�� 
    BigNum  DP[51][51], ans[51];
    
    DP[0][0] = 1;
    
    for( int i = 1; i <= 50; ++i ) {
        
        for( int j = 1; j <= i; ++j ) {
            
            DP[i][j] = DP[i-1][j-1] + DP[i-1][j] * j; 
            ans[i] += DP[i][j];
        }
        
    }
    
    int N;
    
    while( ( cin >> N ) && N )
        cout << N << ' ' << ans[N] << endl;
    
}
