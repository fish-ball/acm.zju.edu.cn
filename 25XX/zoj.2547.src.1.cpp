// 2890291 2008-05-05 11:51:49 Accepted 2547 C++ 00:00.00 832K ���͵����� 
// ������һ�ֵ��ƹ�ϵ����������֮ǰ�����Ƿ��η� 

#include <iostream>
using namespace std;

int main() {
    
    int C[31] = { 1, 0, 3, 0 }, N;

    for( int i = 4; i < 31; ++i ) {
        if( i % 2 == 0 ) {
            C[i] = C[i - 2];
            for( int j = 0; j < i; j += 2 )
                C[i] += 2 * C[j];
        }
        else
            C[i] = 0;
    }

    while( ( cin >> N ) && N >= 0 )
        cout << C[N] << endl;

}
