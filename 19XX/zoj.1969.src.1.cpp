// 3013272 2008-07-30 00:13:11 Accepted 1969 C++ 00:00.01 840K ���͵����� 

// �����⣬���Ǹ�һ��ʽ�ӣ����ֶ������ҵ���д�����Ƿ���ȷ 

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string  str,    num;
int     a,  b,  c;

int main() {
    
    while( cin >> str ) {
        
        if( str == "0+0=0" ) {
            puts( "True" );
            break;
        }
        
        num = str.substr( 0, str.find( '+' ) );
        str.erase( 0, str.find( '+' ) + 1 );
        reverse( num.begin(), num.end() );
        sscanf( num.c_str(), "%d", &a );

        num = str.substr( 0, str.find( '=' ) );
        str.erase( 0, str.find( '=' ) + 1 );
        reverse( num.begin(), num.end() );
        sscanf( num.c_str(), "%d", &b );

        reverse( str.begin(), str.end() );
        sscanf( str.c_str(), "%d", &c );
        
        puts( a + b == c ? "True" : "False" );
        
    }
    
}
