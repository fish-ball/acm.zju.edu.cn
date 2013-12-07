// 3035308 2008-08-14 18:50:47 Accepted 1229 C++ 00:00.06 840K ���͵����� 

// ���� DP
// ���������� WS��N �� 1e6 �Ĺ�ģ�ģ���ô�㶼�ᳬʱ
// Ȼ��������һ�����ۣ�N > 50 ʱ���϶����ԣ���������ȷ����֤������

// ���ǿհ�... �൱ WS 

#include <iostream>
#include <bitset>
using namespace std;

bitset<50>  B,  C;

int     M,  N;

int main() {
    
    while( cin >> N >> M && N ) {
        
        if( N > 50 ) { puts( "Let me try!" ); continue; }

        C.reset();
        for( int i = 0; i < N; ++i )
            C.set( i );
        
        B = 1;
        
        int pos = 3;
        while( B.any() && !B[M - 1] ) {
            B = C & ( ( B << pos ) | ( B >> pos ) );
            pos += 2;
        }
        
        puts( B[M - 1] ? "Let me try!" : "Don't make fun of me!" );
        
    }
    
}
