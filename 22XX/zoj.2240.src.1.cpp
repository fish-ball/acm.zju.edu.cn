// 2953594 2008-06-20 23:02:30 Accepted 2240 C++ 00:00.01 848K ���͵����� 

// ���Ĳ��⣬����Ӣ���Ķ�...

/* Quote ���� From Jesse

����������
    
    ��һ���ַ�����Ҫ�������ѹ����ı����ʽ��ѹ���������£�

    1.  �����2-9����ͬ�������ַ����򱻱�д��2���ַ���ʽ��
        ��һ���������ַ��ĸ������ڶ����Ǹ��ַ�����
    
    2.  �����9��������ͬ�������ַ�����ǰ9��������һ���ַ�����ѹ����
        ���µİ�һ���ַ�����ѹ����

    3.  ���������ͬ�������ַ����������ǵ�ǰ��ͺ���ֱ����1��
        �м�Ϊ�����ַ�������
        
    4.  ��������ַ�1����������� 1���� 11��

    *.  ע�������ֻ�����ڷ�������ʱ��������ʱ���ñ�� 11
        ���Թ�֮��Ÿ�����ģ���Ŀ˵�Ĳ���� 

*/ 

#include <iostream>
#include <string>
using namespace std;

int main() {
    
    string  input;
    
    while( getline( cin, input ) ) {
    
        while( input.size() ) {
                        
            int i = 1;
            for( ; i < input.size(); ++i )
                if( input[i] != input[i-1] || i == 9 )
                    break;
            
            if( i != 1 ) {
                cout << i << input[0];
                input.erase( 0, i );
                continue;
            }

            while( i < input.size() && (
                   i + 1 == input.size() ||
                   input[i+1] != input[i] ) ) ++i;

            cout << '1';
            
            for( int j = 0; j < i; ++j ) {
                if( input[j] == '1' )
                    cout << '1';
                cout << input[j];
            }
            
            cout << '1';
            
            input.erase( 0, i );
            
        }
    
        cout << endl;
    
    }
    
}
