// 2955178 2008-06-23 11:32:27 Accepted 1799 C++ 00:00.00 848K ���͵����� 

// �Ȼ�ԭԭ������ֱ�����

// ͨ�� key ��һ�������������ֱ��Ⱥһ��
//   �������˳�� text ������ַ�������󣬼��ɻ�ԭ���� 

#include <iostream>
#include <string>
using namespace std;

char    A[10][100];

string  key,    text;
int     C[10],  D[10];

int     M,  N;

int main() {
    
    while( cin >> key >> text ) {
    
        if( key == "THEEND" )
            break;
            
        M = key.size();
        N = ( text.size() - 1 ) / M + 1;
        
        for( int i = 0; i < M; ++i ) {
            C[i] = 0;
            for( int j = 0; j < i; ++j ) {
                if( key[j] > key[i] )   ++C[j];
                else                    ++C[i];
            }
        }
        
        for( int i = 0; i < M; ++i )
            D[C[i]] = i;
        
        int pos = 0;
        for( int i = 0; i < M; ++i )
            for( int j = 0; j < N; ++j )
                A[D[i]][j] = text[pos++];
                
        for( int j = 0; j < N; ++j )
            for( int i = 0; i < M; ++i )
                putchar( A[i][j] );
        
        putchar( '\n' );
    
    }
    
}
