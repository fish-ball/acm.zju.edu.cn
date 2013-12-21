// 2958957 2008-06-30 21:38:35 Accepted 2731 C++ 00:00.10 860K ���͵����� 

// ��ģ�⣬ģ�⵽��ǰҪɱ�� Josephus ��ʱ��ֹͣ
// Ȼ�󣬼���ʣ�� x ������ô�� J ������� x - 1 ʣ�����һ���ı���Ƕ���
// ���� x - 1 ��ɱ������ y ������Ӧ��ɱ��һ���ˣ�
//     ʹ�� Josephus ��ɱ����֮��λ�ڵ� y ��λ��
// ��ô������ģ�������ʱ��ʣ�� L ����ָ��ָ�� Josephus
// Ҫ�� Jpsephus �ŵ���λ�ã���Ӧ�ý�ָ����� x - J(x-1, n) - 1
// ��ʱָ��ָ�ŵľ��Ǹ�ɱ���� 

#include <iostream>
#include <list>
using namespace std;

int J( int n, int k ) {
    
    int s = 0;
    
    for ( int i = 2; i <= n; i++ )
        s = ( s + k ) % i;
    
    return  s;
    
}

int main() {
    
    int m,  n,  p;
    
    list<int>   L;
    
    while( cin >> m >> n >> p && m ) {
        
        L.clear();
        
        for( int i = 1; i <= m; ++i )
            L.push_back( i );
        
        list<int>::iterator iter = L.begin();

        while( L.size() ) {
            
            for( int n1 = ( n - 1 ) % L.size(); n1--; ) {
                if( ++iter == L.end() )
                    iter = L.begin();
            }
            
            if( *iter == p )    break;

            iter = L.erase( iter );

            if( iter == L.end() )
                iter = L.begin();

        }
        
        if( L.size() == 1 ) {
            cout << p << endl;
            continue;
        }
        
        int x = L.size() - J( L.size() - 1, n ) - 1;
        
        for( int i = 0; i < x; ++i ) {
            if( ++iter == L.end() )
                iter = L.begin();
        }
        
        cout << *iter << endl;
        
    }
    
}
