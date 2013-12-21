// 2955573 2008-06-24 01:14:40 Accepted 2072 C++ 00:00.04 840K ���͵����� 

// n = 2 �� Josephu ������ J(n) ��һ����ǿ�Ľ���
// J(n) = ROL(n) ROL ��ѭ������
// ע�⣬ѭ���ǰ��������Ƴ�����ѭ����
// Ȼ����� Ǳ�����޴Σ����ս�������ȫ 1 �ľ���
// ÿ���б�һ���ǲ����Ѿ�������ȫ�ˣ���������
// �����Ϳ��ԶԸ�Ƕ�״������������� 

#include <iostream>
using namespace std;

typedef unsigned long long u64;

int main () {
    
    u64 n,  k,  p,  v;
    
    while( cin >> n >> k ) {
        
        while( k-- ) {
            p = 1;
            while( p <= n )
                p <<= 1;
            v = n;
            n <<= 1;
            n ^= p;
            n |= 1;
            if( v == n )
                break;
        }
        
        cout << n << endl;
        
    }
    
}
