// 2884261 2008-05-02 16:16:24 Accepted 2495 C++ 00:00.02 840K ���͵����� 
// �����壬ģ���⣬WA �˺ܶ��
// ע�� left most ������ top most
// ע�ⳤ������������5�������� 

#include <iostream>
using namespace std;

int main() {
    
    int     T;
    int     A[19][19];
    bool    isValid;
    
    cin >> T;
    
    while( T-- ) {

        for( int i = 0; i < 19; ++i )
            for( int j = 0; j < 19; ++j )
                cin >> A[i][j];
        
        for( int j = 0; j < 19; ++j ) {
            
            for( int i = 0; i < 19; ++i ) {
                
                isValid = false;
                
                if( !A[i][j] ) continue;
                
                // ��ֱ�� 
                if( i < 15 ) {
                    isValid = A[i][j] == A[i + 1][j] &&
                              A[i][j] == A[i + 2][j] &&
                              A[i][j] == A[i + 3][j] &&
                              A[i][j] == A[i + 4][j] &&
                              ( i < 1 || A[i - 1][j] != A[i][j] ) &&
                              ( i == 14 || A[i + 5][j] != A[i][j] );
                    if( isValid ) {
                        cout << A[i][j] << '\n'
                             << i + 1 << ' '
                             << j + 1 << '\n';
                        break;
                    }
                }
                
                // ˮƽ�� 
                if( j < 15 ) {
                    isValid = A[i][j] == A[i][j + 1] &&
                              A[i][j] == A[i][j + 2] &&
                              A[i][j] == A[i][j + 3] &&
                              A[i][j] == A[i][j + 4] &&
                              ( j < 1 || A[i][j - 1] != A[i][j] ) &&
                              ( j == 14 || A[i][j + 5] != A[i][j] );
                    if( isValid ) {
                        cout << A[i][j] << '\n'
                             << i + 1 << ' '
                             << j + 1 << '\n';
                        break;
                    }
                }
                
                //��б���� 
                if( i < 15 && j < 15 ) {
                    isValid = A[i][j] == A[i + 1][j + 1] &&
                              A[i][j] == A[i + 2][j + 2] &&
                              A[i][j] == A[i + 3][j + 3] &&
                              A[i][j] == A[i + 4][j + 4] &&
                              ( j < 1 || i < 1 || A[i - 1][j - 1] != A[i][j] ) &&
                              ( j == 14 || i == 14 || A[i + 5][j + 5] != A[i][j] );
                    if( isValid ) {
                        cout << A[i][j] << '\n'
                             << i + 1 << ' '
                             << j + 1 << '\n';
                        break;
                    }
                }
                
                // б���� 
                if( i >= 4 && j < 15 ) {
                    isValid = A[i][j] == A[i - 1][j + 1] &&
                              A[i][j] == A[i - 2][j + 2] &&
                              A[i][j] == A[i - 3][j + 3] &&
                              A[i][j] == A[i - 4][j + 4] &&
                              ( i < 5 || j < 1 || A[i - 5][j + 5] != A[i][j] ) &&
                              ( i == 18 || j == 14 || A[i + 1][j - 1] != A[i][j] );
                    if( isValid ) {
                        cout << A[i][j] << '\n'
                             << i + 1 << ' '
                             << j + 1 << '\n';
                        break;
                    }
                }
                
                isValid = false;
                
            }
            
            if( isValid )   break;
            
        }
        
        if( !isValid )    cout << "0\n";

    }

}
