// 3028031 2008-08-08 18:14:21 Accepted 1871 C++ 00:00.06 2892K ���͵�����

// д��ǰ��������ҳ����ɣ�Ȼ�󷴺����ۼӣ����ֲ��Ҽ��� 

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<long long>   V;

long long S = 0,    C = 1;

int main() {
    
    V.push_back( 0 );
    
    while( V.back() < 1ll << 32 ) {
        V.push_back( V.back() + C );
        V.push_back( V.back() + C++ );
    }
    
    while( cin >> S >> C )
        cout << lower_bound( V.begin(), V.end(), C - S ) - V.begin() << endl;
    
}
