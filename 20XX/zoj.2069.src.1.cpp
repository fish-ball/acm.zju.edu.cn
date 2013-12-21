// ������...
// ֱ�ӽ���Ȼ MLE���Ǵ���ģ���ǵĻ�����������д 


////////////////////////////////////////////////////
//                 ������ģ�� v1.1                //
////////////////////////////////////////////////////
//  1. ֧���������ӡ��ˡ�10������λ����;          //
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
    
    friend BigNum  operator << ( BigNum& num, int n );
    
    friend BigNum& operator *= ( BigNum& num, const int& k );
    
    friend BigNum  operator *  ( BigNum& num1, BigNum num2 );
    
    friend bool operator == ( const BigNum& num1, const BigNum& num2 );
    
    friend bool operator <  ( const BigNum& num1, const BigNum& num2 );

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




///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////


const int MAX_PRIME = 1000;
const int SQRT_MAX = 33;

bool    isPrime[MAX_PRIME];
int     Prime[169] = { 1 },  totPrime;

BigNum  DP[169][1001],  ans[1001];

int main() {

    // ɸ������������
    memset( isPrime, 1, sizeof( isPrime ) );
    
    for( int i = 2; i <= SQRT_MAX; ++i )
        if( isPrime[i] )
            for( int j = i + i; j < MAX_PRIME; j += i )
                isPrime[j] = false;
                
    totPrime = 1;
    for( int i = 2; i <= MAX_PRIME; ++i )
        if( isPrime[i] )
            Prime[totPrime++] = i;

    // DP
    for( int i = 0; i < 169; ++i )
        DP[i][0] = DP[i][1] = 1;
    
    ans[0] = ans[1] = 1;
    
    for( int j = 2; j < 550; ++j ) {
        
        ans[j] = DP[0][j] = 1;
             
        for( int i = 1; i < 169; ++i ) {

            DP[i][j] = DP[i - 1][j];
            int     temp = Prime[i];

            while( temp <= j ) {
                if( DP[i][j] < DP[i - 1][j - temp] * temp )
                    DP[i][j] = DP[i - 1][j - temp] * temp;
                temp *= Prime[i];
            }
            
            if( ans[j] < DP[i][j] )
                ans[j] = DP[i][j];

        }
        
    }

    int     N;
    
    while( cin >> N )
        cout << ans[N] << endl;
    
}
