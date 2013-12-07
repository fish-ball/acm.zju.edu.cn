// 2897683 2008-05-08 00:03:55 Accepted 1245 C++ 00:00.05 860K ���͵����� 

// ������������ע��С�ļ�С�ģ��������� 1AC
// ע�ⶥ����������ֻ�������γ����ǣ�ż����ֻ�������γ����� 

#include <iostream>
using namespace std;

char    A[100][200];
int     N,  T = 0;

int main() {
    
    while( ( cin >> N ) && N ) {
        
        cin >> ws;
        
        for( int i = 0; i < N; ++i )
            gets( A[i] );
            
        int total = 0,  max_count = 0;
        
        for( int i = 0; i < N; ++i ) {
            
            for( int j = i; j < N + N - 1 - i; j += 2 ) {
                total = 0;
                bool  enough = false;
                for( int k = 0; i - k >= 0; ++k ) {
                    for( int l = j - k; l <= j + k; ++l ) {
                        if( A[i - k][l] != '-' ) {
                            enough = true;
                            break;
                        }
                    }
                    if( enough ) break;
                    total += ( 1 + k + k );
                }
                if( total > max_count )
                    max_count = total;
            }
            
            for( int j = i + 1; j < N + N - 1 - i; j += 2 ) {
                total = 0;
                bool  enough = false;
                for( int k = 0; j - k >= i + k; ++k ) {
                    for( int l = j - k; l <= j + k; ++l ) {
                        if( A[i + k][l] != '-' ) {
                            enough = true;
                            break;
                        }
                    }
                    if( enough ) break;
                    total += ( 1 + k + k );
                }
                if( total > max_count )
                    max_count = total;
            }
            
        }
        
        cout << "Triangle #" << ++T
             << "\nThe largest triangle area is " << max_count << ".\n\n";
        
    }
    
}
