// 3028160 2008-08-09 00:16:38 Accepted 1823 C++ 00:00.50 836K ���͵����� 

// ����ԶԶû����Ŀ��������ô�ֲ�����ʵ���ܳ�����������㷨������
// ����û�У�Ӳ������� 

#include <iostream>
using namespace std;

long long X,    Y;

int main() {
    
    while( cin >> X && X != -1 ) {
        
        for( Y = 2; Y * Y <= X; ++Y ) {
            while( X % Y == 0 ) {
                X /= Y;
                cout << Y << endl;
            }
        }
        
        if( X != 1 )    cout << X << endl;
        
        cout << endl;
        
    }
    
}
