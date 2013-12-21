// 3019857 2008-08-03 19:42:47 Accepted 1985 C++ 00:00.32 2408K ���͵����� 

// O(n) ���ÿ��������ߵ�һ���������ĺ��ұߵ�һ����������
// Ȼ��ö�ٸ������飬�����������O(n)

// ������ô O(n) ���ÿ��������ߵ�һ���������ĺ��ұߵ�һ����������
// ������һ��ջ����������͹���� Graham ɨ�跨 

#include <iostream>
#include <vector>
using namespace std;

int L[100002],  R[100002],  N;

long long H[100002];

vector<int> stk;

int main() {
    
    while( cin >> N && N ) {
        
        for( int i = 1, x; i <= N; ++i )
            scanf( "%lld", H+i );
        
        H[0] = H[N + 1] = -1;
        
        stk.clear();
        stk.push_back( 0 );
        for( int i = 1; i <= N; ++i ) {
            while( H[stk.back()] >= H[i] )
                stk.pop_back();
            L[i] = stk.back();
            stk.push_back( i );
        }
        
        stk.clear();
        stk.push_back( N + 1 );
        for( int i = N; i > 0; --i ) {
            while( H[stk.back()] >= H[i] )
                stk.pop_back();
            R[i] = stk.back();
            stk.push_back( i );
        }
        
        long long mx = 0;
        
        for( int i = 1; i <= N; ++i )
            if( mx < H[i] * ( R[i] - L[i] - 1 ) )
                mx = H[i] * ( R[i] - L[i] - 1 );
                
        cout << mx << endl;
        
    }
    
}
