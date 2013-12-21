// 2943863 2008-06-06 16:51:13 Accepted 2058 C++ 00:00.01 844K ���͵����� 

// ���ѷ��֣�ÿ�� @ �� * ��Ҫ������֣����˹��ɾͺ÷����� 
// ע�������WA ��������: 
// The input is terminated by a negative integer. 

#include <iostream>
#include <string>
using namespace std;

int main() {
    
    int     N,  X,  Y,  mx, mn;
    string  S;
    
    while( cin >> N && N >= 0 ) {
        
        mx = mn = 0;
        
        for( int i = 1; i <= N; ++i ) {
            
            cin >> S;
            X = S.find( '@' );
            Y = S.find( '*' );
            
            if( X != string::npos ) {
                if( X % 2 ) {
                    mx += i / 2;
                    mn += i / 2;
                }
                else {
                    mx += ( i - i / 2 );
                    mn += ( i - i / 2 );
                }
            }
            else if( Y != string::npos ) {
                if( Y % 2 == 0 ) {
                    mx += i / 2;
                    mn += i / 2;
                }
                else {
                    mx += ( i - i / 2 );
                    mn += ( i - i / 2 );
                }
            }
            else {
                mx += ( i - i / 2 );
                mn += i / 2;
            }
            
        }
        
        cout << mx << ' ' << mn << endl;
        
    }
    
}
