// 3038311 2008-08-16 21:53:33 Accepted 3019 C++ 00:00.18 960K ���͵����� 

// ���ʾ������������ϵĽ���������ֱ���� STL �ͺ� 

#include <iostream>
#include <algorithm>
using namespace std;

int M,  N;
int A[10000],   B[10000],   C[10000];

int main() {
    
    while( cin >> M >> N ) {
        for( int i = 0; i < M; ++i )
            scanf( "%d", A + i );
        for( int i = 0; i < N; ++i )
            scanf( "%d", B + i );
        sort( A, A + M );
        sort( B, B + N );
        cout << set_intersection( A, A + M, B, B + N, C ) - C << endl;
    }
    
}
