// 3012921 2008-07-29 20:20:48 Accepted 1906 C++ 00:00.00 836K ���͵����� 

// �Ƚ����ַֽ�����������ӣ�Ȼ���ݳ�ԭ��
// ö��������Щ�����ӵ����(���� 1 )�ĳ˻� p��
// ����������� ���� N/p�����򣬼�ȥ N/p 

#include <vector>
#include <iostream>
using namespace std;

int     N,  M,  tot, now, cnt;

vector<int> P;

void DFS( int i ) {
    if( i >= P.size() ) return;
    DFS( i + 1 );
    ++cnt;
    now *= P[i];
    if( cnt && cnt % 2 == 1 )
        tot -= N / now;
    if( cnt && cnt % 2 == 0 )
        tot += N / now;
    DFS( i + 1 );
    now /= P[i];
    --cnt;
}

int main() {
    
    while( cin >> N && N ) {
        
        if( N < 3 ) { puts( "0" ); continue; }
        
        M = N;
        P.clear();
        for( int i = 2; i * i < M; ++i ) {
            if( M % i == 0 ) {
                P.push_back( i );
                while( M % i == 0 ) M /= i;
            }
        }
        
        if( M != 1 )  P.push_back( M );
        
        tot = N;
        now = 1;
        cnt = 0;
        
        DFS( 0 );

        cout << tot << endl;
        
    }
    
}
