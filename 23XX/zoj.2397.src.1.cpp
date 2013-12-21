// 2891820 2008-05-05 21:31:18 Accepted 2397 C++ 00:00.59 848K ���͵�����

// ̰�ģ������˵Ľ��ⱨ����ģ�̰�ĵķ����� algorithm.txt ���С�
// AC ֮ǰ�Լ�Ҳ����̰�ģ�����ȷ��û����֤����������޾��� WA
// �Ժ���̰��һ��Ҫ�����ϸ����֤���� 

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int     N,  A[1000],    B[1000];
    
    int     pA, pB, qA, qB, win, lose;
    
    while( ( cin >> N ) && N ) {
    
        for( int i = 0; i < N; ++i )
            cin >> A[i];
    
        for( int i = 0; i < N; ++i )
            cin >> B[i];
    
        sort( A, A + N );
        sort( B, B + N );
    
        pA = pB = 0;
        qA = qB = N;
        win = lose = 0;
    
        while( pA < qA ) {
            
            if( A[pA] > B[pB] ) {
                ++win;
                ++pB;
                ++pA;
            }
            else if( A[pA] < B[pB] ) {
                ++lose;
                --qB;
                ++pA;
            }
            else {
                if( A[qA - 1] > B[qB - 1] ) {
                    ++win;
                    --qA;
                    --qB;
                }
                else if( A[pA] < B[qB - 1] ) {
                    ++lose;
                    ++pA;
                    --qB;
                }
                else {
                    ++pA;
                    --qB;
                }

            }

        }

        printf( "%d\n", 200 * (win - lose) );
    }
}
