// 2951169 2008-06-16 22:15:49 Accepted 2964 C++ 00:00.16 844K ���͵����� 

// �൱���������⣬��ŷ�������к�ǿ�Ľ��ۣ�
// ������Ҫ�� a ^ l = a ^ m = a ^ n ( mod z )
// ���� l > m > n > 0 ���� m + n > l
// ���� a �� z ���ʣ����
// ��������С�������� k ʹ�� a ^ k = 1 mod z
// ��ô����� a ^ p = y
// a ^ ( p + ? * k ) = Y������ʵ��ͬ��

// ��ʱ������ת��Ϊ��һ����С�� k, ʹ�� a ^ k = mod z
// Ȼ��һ���� k Ϊ����ĵȲ����У�3 ����������Ϊ���
// ����Ϊ���� m + n > l������ȡ�� 
//     n = k + 1, m = 2k + 1, l = 3k + 1
//     ��Ϊ������������С�� l + m + n = 6k + 3

// ������ k ���󷨣�
// �ɷ���С�����֪��a ^ phi(z) = 1 mod z, phi ��ŷ������
// Ȼ��phi(z) ������С�ģ����ǲ����뵽
// һ������ phi(z) ��ĳ�����ӣ�ʹ�� a ^ k = 1 mod z
// Ȼ������� phi(z)����ö���������ӣ������С�߼���

// ��л ����г���ۡ�Ⱥ�� [����Ҳ AC] �� ������ţ 


#include <iostream>
using namespace std;

int phi( int n ) {

    int ret = 1;

    for( int i = 2; i * i <= n; i++ ) {

        if( n % i == 0 ) {
            n /= i;
            ret *= ( i - 1 );
            while( n % i == 0 ) {
                n /= i;
                ret *= i;
            }
        }
    
    }
        
    if( n > 1 )
        ret *= ( n - 1 );
    
    return ret;

}

int pw( const int& A, const int& K, const int& Z ) {
    
    if( K == 0 )
        return  1;
        
    long long P = pw( A, K >> 1, Z );
        
    if( K % 2 == 0 )
        return  P * P % Z;
    else
        return  ( P * P % Z * A ) %Z;
    
}

int main() {

    int     T,  A,  Z;
    
    for( scanf( "%d", &T ); T--; ) {
    
        scanf( "%d%d", &A, &Z );
        
        if( Z == 1 ) {
            puts( "9" );
            continue;
        }
    
        int step = phi( Z ),    ans;
        
        for( int i = 1; i * i <= step; ++i ) {
            if( step % i == 0 ) {
                if( pw( A, i, Z ) == 1 ) {
                    ans = i;
                    break;
                }
                if( pw( A, step / i, Z ) == 1 )
                    ans = step / i;
            }
        }
        
        cout << 6ll * ans + 3 << endl;
    
    }

}
