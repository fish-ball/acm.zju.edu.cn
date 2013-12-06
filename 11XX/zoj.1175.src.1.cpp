// 2886908 2008-05-03 16:09:43 Accepted 1175 C++ 00:00.05 916K ���͵�����
 
// ��ģ���⣬ֻ�Ƕ���һ��Ҫ�������
// �����ַ����� N �д��Ӷ��ɣ����з����ԣ��ո񲻺���
// ָ���ַ���ȡ�� # ʱ�������ո��ж�����
// ����ַ�������г��� 80 ���۶ϳ� 80 �ַ�һ����ʾ
// ��Ϊ���һ��û���� WA �˼��� 

#include <string>
#include <iostream>
using namespace std;

int main() {
    
    int     T,  N;
    string  s1, s2;
    
    cin >> T;
    
    while( T-- ) {
        
        cin >> N;
        getchar();
        
        s1 = "";
        while( N-- ) {
            getline( cin, s2 );
            s1 += s2;
        }
        
        int     head = 0, rear = s1.size();
        char    c;
        bool    type = true;
        
        s2 = "";
        while( ( c = getchar() ) != '#' ) {
            if( head >= rear )
                continue;
            if( c == 'G' ) {
                if( type )
                    s2 += s1[head++];
                else
                    s2 += s1[--rear];
            }
            if( c == 'R' )
                type = !type;
        }
        
        while( s2.size() > 80 ) {
            
            cout << s2.substr( 0, 80 ) << endl;
            s2.erase( 0, 80 );
            
        }
        
        cout << s2 << endl;
        
        if( T ) cout << endl;
        
    }
    
}
