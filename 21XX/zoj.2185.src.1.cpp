// 2925845 2008-05-20 23:39:48 Accepted 2185 C++ 00:00.00 844K ���͵����� 

// �ѹ����ҳ��������ѣ�ע����Ŀ�������� S �������������ע����ż 

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    
    int index,  num,  rem;
    
    while( cin >> index ) {
    
        num = int( sqrt( 2.0 * index ) ) - 1;
        
        while( num * ( num + 1 ) / 2 < index )
            ++num;
        
        --num;
        
        rem = index - num * ( num + 1 ) / 2;
        
        if( num % 2 )
            printf( "TERM %d IS %d/%d\n", index, rem, num - rem + 2 );
        else
            printf( "TERM %d IS %d/%d\n", index, num - rem + 2, rem );
    }
    
}
