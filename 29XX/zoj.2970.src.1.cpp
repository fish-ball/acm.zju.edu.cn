// 2921819 2008-05-18 20:25:13 Accepted 2970 C++ 00:00.05 836K ���͵����� 

// ��˵ɶ�ˣ�ʡ���� ms �� 

#include <iostream>
#include <string>
using namespace std;

int main() {
    
    int     T,  N,  m_val;
    
    string  str;
    
    for( cin >> T; T--; ) {
        
        cin >> str;
        if( str[0] == 'H' ||
            str[0] == 'S' ) {
            m_val = 0;
            for( cin >> N; N--; ) {
                int     temp;
                cin >> temp;
                if( temp > m_val )
                    m_val = temp;
            }
            cout << m_val << endl;
        }
        else {
            m_val = 9999;
            for( cin >> N; N--; ) {
                int     temp;
                cin >> temp;
                if( temp < m_val )
                    m_val = temp;
            }
            cout << m_val << endl;
        }
        
    }
    
}
