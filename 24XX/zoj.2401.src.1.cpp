// 2927826 2008-05-21 20:10:21 Accepted 2401 C++ 00:00.25 900K ���͵����� 

// ���� DP����������󹫹��Ӵ�
// �� i Ϊ�� 1 ��ָ��λ�ã�j Ϊ�� 2 ��ָ��λ��
// Ȼ��һ�� bool A[i][j] ����ǰ���ܷ�ɹ����
// ���ǣ� A[i][j] = s3[i+j-1] == s1[i-1] && A[i-1][j] ||
//                  s3[i+j-1] == s2[j-1] && A[i][j-1]

#include <iostream>
#include <string>
using namespace std;

bool    A[201][201];

int main() {

    int     T;
    
    string  s1, s2, s3;
    
    cin >> T;
    
    for( int t = 1; t <= T; ++t ) {
    
        cin >> s1 >> s2 >> s3;
        
        memset( A, 0, sizeof( A ) );
        
        for( int i = 0; i < s1.size(); ++i ) {
            if( s1[i] != s3[i] )    break;
            else    A[i+1][0] = true;
        }
        
        for( int j = 0; j < s2.size(); ++j ) {
            if( s2[j] != s3[j] )    break;
            else    A[0][j+1] = true;
        }
        
        for( int i = 1; i <= s1.size(); ++i ) {
            for( int j = 1; j <= s2.size(); ++j ) {
                if( s3[i+j-1] == s1[i-1] && A[i-1][j] ||
                    s3[i+j-1] == s2[j-1] && A[i][j-1] )
                    A[i][j] = true;
            }
        }
        
        #ifndef ONLINE_JUDGE
        for( int i = 0; i <= s1.size(); ++i ) {
            for( int j = 0; j <= s2.size(); ++j )
                cout << A[i][j] << ' ';
            cout << endl;
        }
        #endif
        
        cout << "Data set " << t << ": ";
        puts( A[s1.size()][s2.size()] ? "yes" : "no" );
    
    }

}
