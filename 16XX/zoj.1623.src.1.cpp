// 2910713 2008-05-13 10:17:18 Accepted 1623 C++ 00:00.01 860K ���͵����� 

// hdu ������������ģ�Ҫ�侲���ţ�
// ������������һ�����м��һ�� '\n'
// Ȼ��/* �� */ ƥ�� // �� '\n' ƥ��
// ������ /* �Ȳ���ƥ�䣬���������ƥ�䣬���Դ�ע��ͷ
// �������ƥ�䣬��ƥ�䲿��ת�ɴ�д��������������ƥ��
// ����� // ��ض�����ƥ�䣬ֱ��ת��д������ 

#include <iostream>
#include <cctype>
#include <string>
using namespace std;

int main() {
    
    int     T,  N;
    string  input,  temp;
    
    for( cin >> T; T--; ) {
    
        for( cin >> N, getline( cin, temp ), input = ""; N--; ) {
            getline( cin, temp );
            input += temp;
            input += '\n';
        }
        
        int status = 0;
        for( int pos = 0; pos + 1 < input.size(); ) {
            if( input[pos] == '/' && input[pos + 1] == '*' ) {
                pos += 2;
                int posx = pos;
                while( posx + 1 < input.size() )
                    if( input[posx] == '*' && input[posx + 1] == '/' )
                        break;
                    else    ++posx;

                if( posx + 1 == input.size() ) continue;

                ++status;

                while( !( input[pos] == '*' && input[pos+1] == '/' ) ) {
                    input[pos] = toupper( input[pos] );
                    ++pos;
                }
                pos += 2;
            }
                
            else if( input[pos] == '/' && input[pos + 1] == '/' ) {
                ++status;
                pos += 2;
                while( input[pos] != '\n' ) {
                    input[pos] = toupper( input[pos] );
                    ++pos;
                }
                ++pos;
            }
            
            else    ++pos;
            
        }
        
        cout << status << endl << input << endl;
    
    }
    
}
