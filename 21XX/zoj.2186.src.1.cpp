// �����ǣ�ɶ����˵�ˣ���������Ӣ���Ķ�
// ֻ�������������ҳ���һ�� <= 168 ����
// �����Ҳ���... 

#include <iostream>
using namespace std;

int main() {
    int     A[3];
    cin >> A[0] >> A[1] >> A[2];
    for( int i = 0; i < 3; i++ ) if( A[i] <= 168 ) {
        cout << "CRASH " << A[i] << endl;
        return  EXIT_SUCCESS;
    }
    cout << "NO CRASH" << endl;
}
